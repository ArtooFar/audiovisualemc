/*
 * Demo ANSI-sprite
 *  - anima um círculo girando (sheet PNG)
 *  - mostra um único frame importado
 *  - faz autoconfiguração ANSI em Linux/macOS e Windows 10+ / Windows Terminal
 */
#include "ansi_sprite.h"

#include "dependencias\configs_do_terminal.h"
#include "dependencias\ferramentas_de_terminal.h"

#include <stdio.h>

int main()
{
    term_inicializar();
    if (!term_setar_fonte(13)) printf("O ambiente não permite troca de fonte, altere o tamanho manualmente [Pode funcionar com control + scroll do mouse]\n");

    // Torna o cursor do terminal invisível
    term_ferr_setar_cursor_invisivel();

    //Redimensiona (ou tenta) o terminal para (150,75) caracteres ([Horizontal],[Vertical])
    term_redimensionar(200,60);
    
    // Pausa o programa
    term_pause("Pressione Qualquer tecla..\n");

    /* ---------- Animação -------------------------------------------------- */
    //Cria um ponteiro para um "SpriteSheet", que é carregado de "circle_sheet.png" e tem dimensoes (15x15) [Pixels]
    SpriteSheet *anima1 = sprite_sheet_load("imagens\\circle_sheet.png", 15, 15);
    if (!anima1) return 1;

    // Roda a animação de "anima1", com 4 iterações, delay de ~70 ms entre quadros, Background preto (RGB=0;0;0), Offset em x e y (2,2)
    sprite_animate(anima1, 4, 70000,"0;0;0", 2, 2);

    // Limpa da memória o spritesheet carregado
    sprite_sheet_free(anima1);

    /* ---------- Importador simples (apenas 1 frame) ----------------------- */
    //Cria um ponteiro para um "SpriteSheet", que é carregado de "gatojoinha.png" e tem dimensoes (32x32) [Pixels]
    SpriteSheet *gatojoinha = sprite_sheet_load("imagens\\gatojoinha.png", 32, 32);
    if (!gatojoinha) return 1;

    // Desenha "gatojoinha" em um único frame (o frame 0), com o Background preto (RGB=0;0;0), e Offset em x e y de (60,10)
    sprite_draw_frame(gatojoinha, 0, "0;0;0", /*x*/60, /*y*/10);

    // Limpa da memória o spritesheet carregado
    sprite_sheet_free(gatojoinha);

    /* Move cursor para linha seguinte e reseta atributos */
    printf("\n\033[0m");

    term_pause("Pressione qualquer tecla para fechar");
    return 0;
}
