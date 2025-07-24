# Pixel‑Artoo printf() v0.4.3



## Visão Geral



Pixel‑Artoo printf() é uma ferramenta web que converte imagens PNG (com transparência) em sequências ANSI de 24‑bit, geradas como chamadas `printf()` em C. Com ela você pode transformar qualquer imagem em arte de terminal colorida, pronta para compor demos, intros ou efeitos visuais em programas C.



A página está disponível em: [https://artoofar.github.io/pixel2printf/](https://artoofar.github.io/pixel2printf/)



## Funcionalidades Principais



* **Envio de PNG**: Faça upload de qualquer imagem PNG com transparência.

* **Configuração de Resolução**: Defina largura (W) e altura (H) para redimensionar a imagem no preview e no código.

* **Modos de Cor**:



  * **Foreground** (`38;2` + `██`): colore caracteres.

  * **Background** (`48;2` + espaços): colore fundo.

* **Modos de Impressão**:



  * **Âncora fixa**: gera posicionamento absoluto via `printf("\e[H");`

  * **Âncora embutida** (desativado): futura opção para posicionamento relativo.

* **Preview Interativo**:



  * Baixo, médio ou alto contraste de fundo.

  * Clique para extrair posição do cursor ou cor de pixel.

* **Snippets Rápidos**:



  * Código para mover cursor ou definir cor via radio tools.

* **Gerador de Código C**:



  * Gera função em C (ex.: `void desenhar_minhaImagem() { ... }`).

  * Inclui marca d’água com referência ao Pixel‑Artoo printf().



## Como Usar



1. Abra [Artoo-printf()](https://artoofar.github.io/pixel2printf) em um navegador moderno.

2. Selecione um PNG com transparência.

3. Ajuste **Resolução** (largura × altura em caracteres) que sua impressão terá (Para bons resultados, a resolução da imagem e da impressão devem ser proporcionais)

4. Clique em **Gerar código C**.

5. Copie o código gerado e cole em seu projeto C.


## Configuração de Terminal

A depender do terminal utilizado por seu projeto, pode ser necessária a configuração dele para suportar ANSI Escape Sequences, que são necessários para a função funcionar.

Para isso:

Use sua biblioteca configs_do_terminal.h para preparar o terminal antes de desenhar. Exemplo breve:

#include "dependencias/configs_do_terminal.h"

```c
int main(void) {
    term_inicializar();                   // Ativa ANSI VT e UTF-8
    // ... seu código de desenho gerado pelo Pixel-Artoo printf() ...
    term_pause("Pressione qualquer tecla para continuar");
    return 0;
}
```
### Exemplo de Uso em C



```c

#define _POSIX_C_SOURCE 200112L // no Linux para suportar ANSI VT

#include <stdio.h>



// Cole aqui a função gerada, por exemplo:

// void desenhar_logo() {

//     printf("\e[2J");       // Limpa a tela

//     printf("...m██...\e[0m");

//     /*>> Feito utilizando Artoo printf() */

//     /*>> https://artoofar.github.io/pixel2printf/ */

// }



int main(void) {

    // Inicialização de terminal ANSI, se necessário

    // ...



    desenhar_logo();        // Desenha sua imagem no terminal

    printf("\n");        // Quebra de linha



    return 0;

}

```


