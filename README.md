# audiovisualemc

## Visão Geral

`audiovisualemc` é um conjunto de ferramentas e demos em C/C++ que permite a reprodução simultânea de áudio e a exibição de conteúdo visual (sprites e animações) diretamente no terminal. Através de [ANSI Escape Sequences](https://gist.github.com/fnky/458719343aabd01cfb17a3a4f7296797) para o visual e bibliotecas de áudio para som, você consegue criar demos interativas com som e imagem em um mesmo programa.

## Estrutura do Projeto

```text
.
├── async/                   # Gerencia tarefas assíncronas e sincronização de processos
├── audio/                   # Carrega e reproduz arquivos de áudio (WAV/PCM)
├── imagens_e_animacoes/     # Recursos visuais
│   ├── ansi_sprite/         # Renderizador de sprite-sheets via ANSI Escape Codes
│   └── artooprintf/         # Conversor de imagens PNG em chamadas printf ANSI (Pixel-Artoo)
└── README.md                # Este documento de visão geral
```

## Uso das Bibliotecas

Cada módulo do `audiovisualemc` tem responsabilidade específica:

* **[async](https://github.com/ArtooFar/audiovisualemc/tree/main/async)**: inicializa e coordena execução paralela de funções, garantindo sincronização entre áudio e visual sem bloqueios. Também pode ser usado de outras formas.
* **[audio](https://github.com/ArtooFar/audiovisualemc/tree/main/audio)**: funções para carregar (WAV/MP3), reproduzir em segundo plano e liberar recursos de áudio.
* **[imagens\_e\_animacoes/ansi\_sprite](https://github.com/ArtooFar/audiovisualemc/tree/main/imagens_e_animacoes/ansi_sprite)**: carrega sprite-sheets e gera animações frame a frame no terminal usando sequências ANSI de cores.
* **[imagens\_e\_animacoes/artooprintf](https://github.com/ArtooFar/audiovisualemc/tree/main/imagens_e_animacoes/artooprintf)**: converte qualquer imagem PNG em código C com chamadas `printf()` usando cores ANSI 24-bit para exibição.

Para usar, basta incluir os headers de cada módulo, inicializar o terminal (se necessário) e chamar as funções de setup e execução de cada parte no fluxo do seu `main`.
