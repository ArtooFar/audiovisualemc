/*
 * Demo ANSI-sprite
 *  - anima um círculo girando (sheet PNG)
 *  - mostra um único frame importado
 *  - faz autoconfiguração ANSI em Linux/macOS e Windows 10+ / Windows Terminal
 */
#define ANSI_SPRITE_IMPLEMENTATION
#include "ansi_sprite.h"

#include <stdio.h>

#ifdef _WIN32
  #define WIN32_LEAN_AND_MEAN
  #include <windows.h>
#endif

/*-----------------------------------------------------------------------------*/
/* Configura o terminal para aceitar escape-codes 24 bit.                      */
/* Retorna 1 em caso de sucesso, 0 se não for possível habilitar.             */
static int setup_terminal(void)
{
#ifdef _WIN32
    /* Windows 10 (1511+) ou Windows Terminal: ENABLE_VIRTUAL_TERMINAL_PROCESSING */
    HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    if (hOut == INVALID_HANDLE_VALUE) return 0;

    DWORD mode = 0;
    if (!GetConsoleMode(hOut, &mode)) return 0;

    mode |= ENABLE_VIRTUAL_TERMINAL_PROCESSING;
    if (!SetConsoleMode(hOut, mode)) {
        /* Fallback: sem cores true-color; podemos usar apenas 16 cores ANSI.  */
        fprintf(stderr,
            "Aviso: VT ANSI desabilitado - exibiremos sem cor total.\n");
        return 0;
    }
#else
    /* Em POSIX assume-se UTF-8 e ANSI; se não houver suporte o resultado apenas
       não terá cor, mas continuará visível.                                   */
#endif
    return 1;
}
/*-----------------------------------------------------------------------------*/

int main(void)
{
    if (!setup_terminal()) {
        /* Prosseguimos mesmo assim, apenas com capacidades limitadas */
    }

    /* ---------- Animação -------------------------------------------------- */
    SpriteSheet *sheet = sprite_sheet_load("circle_sheet.png", 15, 15);
    if (!sheet) return 1;

    /* 10 iterações, ~70 ms entre quadros, BG preto, canto sup-esq (2,2)      */
    sprite_animate(sheet, /*iterations*/10, /*delay_us*/70000,
                   /*bg*/"0;0;0", /*x*/2, /*y*/2);
    sprite_sheet_free(sheet);

    /* ---------- Importador simples (apenas 1 frame) ----------------------- */
    SpriteSheet *frame = sprite_sheet_load("circle_single.png", 15, 15);
    if (!frame) return 1;

    /* Desenha frame único 5 colunas à direita da animação anterior */
    sprite_draw_frame(frame, 0, "0;0;0", /*x*/120, /*y*/2);
    sprite_sheet_free(frame);

    /* Move cursor para linha seguinte e reseta atributos */
    printf("\n\033[0m");
    return 0;
}
