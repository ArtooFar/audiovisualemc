# Imagens e Animações

Este diretório reúne os recursos visuais do projeto, organizados em dois submódulos:

* **[ansi\_sprite/](https://github.com/ArtooFar/audiovisualemc/tree/main/imagens_e_animacoes/ansi_sprite)**: implementa um renderizador de sprite-sheets no terminal utilizando ANSI Escape Codes e cores 24‑bit. Inclui funções para carregar imagens (via stb\_image), desenhar frames isolados e animar sequências.

* **[artooprintf/](https://github.com/ArtooFar/audiovisualemc/tree/main/imagens_e_animacoes/artooprintf)**: integra a ferramenta Pixel‑Artoo printf(), que converte qualquer imagem PNG (com canal alfa) em chamadas C de `printf()` com códigos ANSI de cor para reproduzir a arte pixelada diretamente no terminal.

## Como usar

1. Escolha o submódulo desejado (`ansi_sprite` ou `artooprintf`).
2. Inclua o header correspondente em seu código

3. Siga as instruções de cada submódulo para carregar, desenhar ou gerar o código ANSI:
   * No `ansi_sprite`, use `sprite_sheet_load()`, `sprite_draw_frame()` e `sprite_animate()`.
   * No `artooprintf`, utilize a função gerada pelo conversor para imprimir sua imagem.

## Estrutura

```text
imagens_e_animacoes/
├── ansi_sprite/    # Renderer de sprite-sheets via ANSI
└── artooprintf/    # Conversor de PNG em printf() ANSI
```
