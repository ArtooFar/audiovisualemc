#ifndef FERRAMENTAS_DE_TERMINAL_H
#define FERRAMENTAS_DE_TERMINAL_H
#include <stdio.h>

void term_ferr_setar_cursor_invisivel(){
    printf("\e[?25l"); //Deixa o cursor invisível usando ansi escape sequence
}

void term_ferr_setar_cursor_visivel(){
    printf("\e[?25h"); //Deixa o cursor visível usando ansi escape sequence
}

void term_ferr_limparTela() {
//Funciona tipo um system("clear") mas com ANSII Escape Code
//Vai funcionar tanto em LINUX (replit) quanto em WINDOWS (espero)
    printf("\e[H\e[0J\e[H");
}

/////////////////////////////////////////
//
////
////// Utilidades de mapeamento de tecla
////
//
/////////////////////////////////////////

#ifdef _WIN32
    #define WIN32_LEAN_AND_MEAN
    #include <windows.h>
    #include <conio.h>
    #include <ctype.h>

// Converte ASCII p/ Virtual-Key
static int ascii_to_vk(int ascii)
{
    if ('A' <= ascii && ascii <= 'Z') return ascii;
    if ('a' <= ascii && ascii <= 'z') return toupper(ascii);
    if ('0' <= ascii && ascii <= '9') return ascii;

    switch (ascii) {
        //especiais
        case  27: return VK_ESCAPE;
        case  13: return VK_RETURN;
        case   9: return VK_TAB;
        case   8: return VK_BACK;
        case ' ': return VK_SPACE;
        default : return 0;
    }
}

// ------------------------ API pública ------------------------------------

// Verifica se "tecla" está sendo pressionada
int term_ferr_tecla_especifica_pressionada(int tecla)
{
    int vk = ascii_to_vk(tecla);
    if (!vk) return 0;                        /* tecla não mapeável           */
    return (GetAsyncKeyState(vk) & 0x8000) != 0;
}

// Espera até que "tecla" seja pressionada
int term_ferr_tecla_especifica_esperar(int tecla)
{
    for (;;) {
        /* _getch() é bloqueante; devolve byte 0..255               */
        int ch = _getch();
        if (ch == tecla) return ch;
        /* descarta estendido (0 ou 224) + scan code subsequente    */
        if (ch == 0 || ch == 224) _getch();
    }
}

int term_ferr_tecla_pressionada()
{
    if (_kbhit()) {
        int ch = _getch(); // Recebe info sobre tecla pressionada
        if (ch == 0 || ch == 224) { //Não caractere
            _getch();
            return -1;
        }
        return ch;  //retorna o ascii
    }
    return -1;
}

#else   /* ---------------------- POSIX: Linux/macOS ----------------------- */
    #include <termios.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdlib.h>
    #include <sys/ioctl.h>

static void set_raw_mode(int enable)
{
    static struct termios old; static int stored = 0;
    if (enable && !stored) {
        struct termios raw;
        tcgetattr(STDIN_FILENO, &old);
        raw = old;
        raw.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(STDIN_FILENO, TCSANOW, &raw);
        stored = 1;
    } else if (!enable && stored) {
        tcsetattr(STDIN_FILENO, TCSANOW, &old);
        stored = 0;
    }
}

// Verifica se "tecla" está sendo pressionada
int term_ferr_tecla_especifica_pressionada(int tecla)
{
    set_raw_mode(1);

    int nbytes = 0;
    ioctl(STDIN_FILENO, FIONREAD, &nbytes);
    if (nbytes <= 0) { set_raw_mode(0); return 0; }

    unsigned char c;
    if (read(STDIN_FILENO, &c, 1) == 1) {
        int match = (c == tecla);
        /* devolve byte lido para a fila se não for o que queríamos */
        if (!match) ungetc(c, stdin);
        set_raw_mode(0);
        return match;
    }
    set_raw_mode(0);
    return 0;
}

// Espera até que "tecla" seja pressionada
int term_ferr_tecla_especifica_esperar(int tecla)
{
    set_raw_mode(1);
    unsigned char c;
    while (read(STDIN_FILENO, &c, 1) == 1) {
        if (c == tecla) { set_raw_mode(0); return c; }
    }
    set_raw_mode(0);
    return -1;                           /* erro/EOF                          */
}

int term_ferr_tecla_pressionada()
{
    struct termios old, raw;
    tcgetattr(STDIN_FILENO, &old);
    raw = old;
    raw.c_lflag &= ~(ICANON | ECHO);      /* modo raw */
    tcsetattr(STDIN_FILENO, TCSANOW, &raw);

    int nbytes = 0, ch = -1;
    ioctl(STDIN_FILENO, FIONREAD, &nbytes);
    if (nbytes > 0) {
        unsigned char c;
        if (read(STDIN_FILENO, &c, 1) == 1)
            ch = c;                      /* ASCII 0-255 */
    }

    tcsetattr(STDIN_FILENO, TCSANOW, &old); /* restaura */
    return ch;                            /* -1 se vazio */
}

#endif

#endif
