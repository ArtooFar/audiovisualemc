# ANSI Sprite Engine Demo

## Visão geral

`ansi_sprite.h` fornece um renderizador minimalista de sprite-sheets no terminal usando sequências ANSI e cores 24-bit. Inclui suporte a carregamento de imagens via `stb_image.h` e autoconfiguração de terminal em Windows e POSIX.

O diretório contém:

* `ansi_sprite.h`: header único com implementação de renderização de sprite-sheets.
* `stb_image.h`: biblioteca de carregamento de imagens (PNG, JPG, BMP etc.).
* `dependencias/`: configurações e utilitários de terminal.

  * `configs_do_terminal.h`: inicialização de VT ANSI, UTF-8, redimensionamento de janela, fonte, pausa e saída.
  * `ferramentas_de_terminal.h`: controle do cursor, limpeza de tela e leitura de teclas.
* `imagens/`: folhas de sprite e exemplos.

  * `circle_sheet.png`: sequência de frames de um círculo girando (15×15).
  * `gatojoinha.png`: sprite estático (32×32).
* `demo_ansi_sprite.c`: exemplo de uso.

## Estrutura de pastas

```text
ansi_sprite_demo/
├── ansi_sprite.h
├── stb_image.h
├── dependencias/
│   ├── configs_do_terminal.h
│   └── ferramentas_de_terminal.h
├── imagens/
│   ├── circle_sheet.png
│   └── gatojoinha.png
└── demo_ansi_sprite.c
```

## Dependências

| Arquivo                                  | Função no projeto                                                            |
| ---------------------------------------- | ---------------------------------------------------------------------------- |
| `ansi_sprite.h`                          | Header único com implementação ANSI para sprite-sheets                       |
| `stb_image.h`                            | Carregamento de imagens (PNG, JPG, BMP etc.)                                 |
| `dependencias/configs_do_terminal.h`     | Configuração de terminal (VT, UTF-8, fonte, redimensionamento, pausa, saída) |
| `dependencias/ferramentas_de_terminal.h` | Controle de cursor, limpeza de tela e leitura de teclas                      |
| `imagens/*.png`                          | Sprites usados no demo (frames de animação e sprite estático)                |

## API Essencial

### Carregamento e liberação

| Função                                                                            | Descrição                                                                                                  |
| --------------------------------------------------------------------------------- | ---------------------------------------------------------------------------------------------------------- |
| `SpriteSheet *sprite_sheet_load(const char *filename, int frame_w, int frame_h);` | Carrega uma folha de sprites com frames de tamanho `frame_w×frame_h`. Retorna ponteiro ou `NULL` em falha. |
| `void sprite_sheet_free(SpriteSheet *sheet);`                                     | Libera memória alocada pelo `sprite_sheet_load()`.                                                         |

### Desenho e animação

| Função                                                                                                                         | Descrição                                                                                                                    |
| ------------------------------------------------------------------------------------------------------------------------------ | ---------------------------------------------------------------------------------------------------------------------------- |
| `void sprite_draw_frame(const SpriteSheet *sheet, int frame_idx, const char *bg_rgb, int offset_x, int offset_y);`             | Desenha o frame `frame_idx` no terminal, com cor de fundo `bg_rgb` (formato "R;G;B") e deslocamento (`offset_x`,`offset_y`). |
| `void sprite_animate(const SpriteSheet *sheet, int iterations, int delay_us, const char *bg_rgb, int offset_x, int offset_y);` | Anima todos os frames na horizontal. Se `iterations <= 0`, loop infinito. Delay entre frames em microssegundos (`delay_us`). |

## Exemplo rápido

```c
#define ANSI_SPRITE_IMPLEMENTATION
#include "ansi_sprite.h"
#include "dependencias/configs_do_terminal.h"
#include "dependencias/ferramentas_de_terminal.h"

int main(void) {
    term_inicializar(); // Ativa ANSI VT e UTF-8

    // Anima o círculo girando 4 vezes (frames 15×15)
    SpriteSheet *circle = sprite_sheet_load("imagens/circle_sheet.png", 15, 15);
    if (!circle) return 1;
    sprite_animate(circle, 4, 70000, "0;0;0", 2, 2);
    sprite_sheet_free(circle);

    // Desenha um sprite estático "gatojoinha" na posição (60,10)
    SpriteSheet *gato = sprite_sheet_load("imagens/gatojoinha.png", 32, 32);
    if (!gato) return 1;
    sprite_draw_frame(gato, 0, "0;0;0", 60, 10);
    sprite_sheet_free(gato);

    printf("\n\033[0m"); // Reseta atributos e avança linha
    term_pause("Pressione qualquer tecla para sair");
    term_sair(0);
}
```

## Boas práticas

* Carregue todos os sprites no início para evitar travamentos durante a execução.
* Libere com `sprite_sheet_free()` após o uso de cada spritesheet.
