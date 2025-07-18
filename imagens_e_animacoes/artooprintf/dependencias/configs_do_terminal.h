#define _CRT_SECURE_NO_WARNINGS

#ifndef CONFIGS_DO_TERMINAL_H
#define CONFIGS_DO_TERMINAL_H

#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#ifdef _WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <conio.h>
  #include <windows.h>
  #include <io.h>
  #include <fcntl.h>
  static UINT s_origCP = 0;

  /* Guardamos modos originais pra restaurar se necessário */
  static DWORD s_origOutMode = 0, s_origErrMode = 0;
#endif

/*---------------------------------------------------------------------------
 * term_init()  → ativa UTF-8 + VT ANSI (true-color) quando disponível.
 *---------------------------------------------------------------------------*/
int term_inicializar(void)
{
#ifdef _WIN32
    s_origCP = GetConsoleOutputCP();
    /* 1) UTF-8 na codepage ------------------------------ */
    SetConsoleOutputCP(CP_UTF8);

    /* 2) VT Ansi ---------------------------------------- */
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return 0;

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return 0;

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING
          | DISABLE_NEWLINE_AUTO_RETURN;
    if (!SetConsoleMode(hOut, mode)) return 0;

    /* 3) (Opcional) repita para stderr – NÃO muda stdin. */
    HANDLE hErr = GetStdHandle(STD_ERROR_HANDLE);
    DWORD errMode = 0;
    if (hErr != INVALID_HANDLE_VALUE &&
        GetConsoleMode(hErr, &errMode))
        SetConsoleMode(hErr,
                       errMode | ENABLE_VIRTUAL_TERMINAL_PROCESSING);

    return 1;
#else
    /* POSIX: testa só se é TTY, como já estava. */
    if (!isatty(STDOUT_FILENO)) return 0;
    const char *term = getenv("TERM");
    return term && *term && strcmp(term,"dumb") != 0;
#endif
}

static int is_windows_terminal(void)
{
    /* WT define a variável de ambiente WT_SESSION = {GUID} */
    return GetEnvironmentVariableW(L"WT_SESSION", NULL, 0) > 0;
}

/*---------------------------------------------------------------------------
 * term_set_font()  → troca altura da fonte.
 *     - Windows: WinAPI via SetCurrentConsoleFontEx
 *     - POSIX   : enviamos OSC 50 (xterm-compatible). Se o terminal ignorar,
 *                 nada quebra.
 *---------------------------------------------------------------------------*/
int term_setar_fonte(int altura_pixel)
{
#ifdef _WIN32
    if (is_windows_terminal())
        return 0;                      /* WT não permite trocar fonte        */

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    CONSOLE_FONT_INFOEX cfi = { sizeof(cfi) };
    if (!GetCurrentConsoleFontEx(hCon, FALSE, &cfi)) return 0;
    cfi.dwFontSize.Y = altura_pixel;
    return SetCurrentConsoleFontEx(hCon, FALSE, &cfi);
#else
    /* OSC 50 continua como antes ------------------------------------------ */
    char seq[128];
    int n = snprintf(seq, sizeof(seq),
                     "\033]50;xft:Monospace:size=%d\007", altura_pixel);
    return n > 0 && n < (int)sizeof(seq) &&
           fwrite(seq, 1, n, stdout) == (size_t)n && fflush(stdout) == 0;
#endif
}

/*---------------------------------------------------------------------------
 * term_resize()  → Windows redimensiona buffer + janela. POSIX envia ESC [8.
 *---------------------------------------------------------------------------*/
int term_redimensionar(int colunas, int linhas)
{
#ifdef _WIN32
    if (is_windows_terminal()) {
        /* Windows Terminal obedece à sequência CSI 8 ; linhas ; colunas t        */
        char seq[32];
        int n = snprintf(seq, sizeof(seq), "\033[8;%d;%dt", linhas, colunas);
        DWORD wrote;
        return WriteConsoleA(GetStdHandle(STD_OUTPUT_HANDLE),
                             seq, n, &wrote, NULL) && wrote == (DWORD)n;
    }

    /* console host clássico — WinAPI ainda funciona ----------------------- */
    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD size  = { (SHORT)colunas, (SHORT)linhas };
    if (!SetConsoleScreenBufferSize(hCon, size))
        return 0;
    SMALL_RECT rect = { 0, 0, size.X - 1, size.Y - 1 };
    return SetConsoleWindowInfo(hCon, TRUE, &rect);
#else
    /* POSIX: mesmo CSI 8 --------------------------------------------------- */
    return printf("\033[8;%d;%dt", linhas, colunas) >= 0 && fflush(stdout) == 0;
#endif
}

int term_pause(const char *msg)
/* Bloqueia até o usuário pressionar ENTER (ou qualquer tecla no Windows),
   mas só se stdin for realmente um TTY.  Se o programa estiver com entrada
   redirecionada, apenas dá um sleep curto e segue.                         */
{
#ifdef _WIN32
    /* Se entrada não for console, só dorme 1 s e retorna. */
    if (!_isatty(_fileno(stdin))) { Sleep(1000); return 0; }

    fputs(msg ? msg : "Pressione qualquer tecla para continuar… ", stdout);
    fflush(stdout);
    _getch();                        /* espera uma tecla, não ecoa          */
    fputs("\n", stdout);
    return 1;
#else
    if (!isatty(STDIN_FILENO)) { usleep(1000000); return 0; }

    fputs(msg ? msg : "Pressione ENTER para continuar… ", stdout);
    fflush(stdout);
    /* Lê até encontrar '\n' */
    int c;
    while ((c = getchar()) != '\n' && c != EOF) { /* nada */ }
    return 1;
#endif
}

void term_sair(int status)
/* Restaura o modo original do console (Windows) e sai.  Em POSIX não há
   nada a restaurar, mas deixamos essa função para manter simetria.         */
{
#ifdef _WIN32
    /* Restaura modos VT */
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut != INVALID_HANDLE_VALUE && s_origOutMode)
        SetConsoleMode(hOut, s_origOutMode);

    HANDLE hErr = GetStdHandle(STD_ERROR_HANDLE);
    if (hErr != INVALID_HANDLE_VALUE && s_origErrMode)
        SetConsoleMode(hErr, s_origErrMode);

    /* Restaura code-page original */
    if (s_origCP) SetConsoleOutputCP(s_origCP);
#endif
    exit(status);
}

#endif