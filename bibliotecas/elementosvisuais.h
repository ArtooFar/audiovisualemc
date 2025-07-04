//Biblioteca Própria //
#ifndef ELEMENTOSVISUAIS_H
#define ELEMENTOSVISUAIS_H

#include "ansi_sprite.h"

#define TERMINAL_LARGURA 156
#define TERMINAL_ALTURA  44

typedef struct{
    int navegador;
    int confirmador;
} tp_cursor;

void cursor_zerarCursor(tp_cursor *cursor) {
    cursor->navegador=0;
    cursor->confirmador=0;
}

void cursor_setarCursor(tp_cursor *cursor,int num) {
    cursor->navegador=num;
    cursor->confirmador=0;
}

void imprimir__centralizado_float(float valor, int largura) {
    //Imprime um valor dado de forma certralizada (e com 2 casas decimais)
    //OBS: o float deve ocupar no máximo um espaço de 64 caracteres (2 casas decimais + vírgula inclusas)
    //Em largura coloca o espaço maximo que pode ocupar
    char texto[64];
    
    //Converte o valor em string com 2 casas decimais
    snprintf(texto, sizeof(texto), "%.2f", valor);
    
    //Troca ponto por vírgula
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '.') {
            texto[i] = ',';
            break;
        }
    }
    
    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%s\n", texto);
        return;
    }

    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime o número
    printf("%s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void imprimir_centralizado_float_dinheiro(float valor, int largura) {
    //Imprime um valor dado de forma certralizada (e com 2 casas decimais) e com R$
    //OBS: o float+"R$ " deve ocupar no máximo um espaço de 64 caracteres (2 casas decimais + vírgula inclusas)
    //Em largura coloca o espaço maximo que pode ocupar
    char texto[64];
    
    //Converte o valor em string com 2 casas decimais
    snprintf(texto, sizeof(texto), "R$ %.2f", valor);
    
    //Troca ponto por vírgula
    for (int i = 0; texto[i] != '\0'; i++) {
        if (texto[i] == '.') {
            texto[i] = ',';
            break;
        }
    }
    
    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%s\n", texto);
        return;
    }

    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime o número
    printf("%s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void imprimir__centralizado_string_max20(char texto[], int largura) {
    //Imprime uma string (de ate 20 caracteres) dada de forma certralizada
    //Caso a string seja maior q 20 caracteres, o texto vai ser cortado
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.20s\n", texto);
        return;
    }

    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime a string
    printf("%.20s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void imprimir__centralizado_string_max100(char texto[], int largura) {
    //Imprime uma string (de ate 100 caracteres) dada de forma certralizada
    //Caso a string seja maior q 100 caracteres, o texto vai ser cortado
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.100s\n", texto);
        return;
    }

    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime a string
    printf("%.100s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void imprimir__centralizado_string_max200(char texto[], int largura) {
    //Imprime uma string (de ate 200 caracteres) dada de forma certralizada
    //Caso a string seja maior q 200 caracteres, o texto vai ser cortado
    //Em largura coloca o espaço maximo que pode ocupar

    int comprimento = strlen(texto);

    //Se o tamanho do texto for maior que a largura, imprime sem centralizar
    if (comprimento > largura) {
        printf("%.200s\n", texto);
        return;
    }

    int espacos_esquerda = (largura - comprimento) / 2;
    int espacos_direita = largura - comprimento - espacos_esquerda;

    //Pula espaços na esquerda
    for (int i = 0; i < espacos_esquerda; i++) {
        printf("\e[C");
    }

    //Imprime a string
    printf("%.100s", texto);

    //Pula espaços na direita
    for (int i = 0; i < espacos_direita; i++) {
        printf("\e[C");
    }
}

void desenhar_fundopreto() {
    int tempo=0;
    printf("\e[48;2;0;0;0m                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);
    printf("                                                                                                                                                            \e[E");
    Sleep(tempo);

    printf("\e[0m");
    printf("\e[H");
    fflush(stdout);
}

void desenhar_fundoinicial() {
    printf("\e[48;2;17;52;66m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
    fflush(stdout);
}

void desenhar_fichainicial() {
    printf("\e[7E");
    printf("\e[36C\e[38;2;0;0;0m██████████████\e[E");
    printf("\e[30C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[26C██████████████████████████████████\e[E");
    printf("\e[24C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[22C██\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██\e[E");
    printf("\e[20C██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[E");
    printf("\e[18C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████████████████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[16C██████████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[16C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[14C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██████████████████████████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[14C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[14C██████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[12C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████████████\e[38;2;0;0;0m██\e[38;2;255;255;255m██████████████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[14C██████████████\e[38;2;255;255;255m████████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m████████████\e[38;2;0;0;0m██████████████\e[E");
    printf("\e[14C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[14C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██████████████████████████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[16C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████████████████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[16C██████████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[18C██████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████████████████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████████\e[E");
    printf("\e[20C██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[E");
    printf("\e[22C██\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██████████████████\e[38;2;255;255;255m██████████\e[38;2;0;0;0m██\e[E");
    printf("\e[24C██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[E");
    printf("\e[26C██████████████████████████████████\e[E");
    printf("\e[30C████████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m████████\e[E");
    printf("\e[36C██████████████\e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[48;2;17;52;66m");
    printf("\e[12E\e[87C[WASD -> Selecionar]\e[E");
    printf("\e[87C[F -> Confirmar] [X -> Fechar o Jogo]");
    printf("\e[0m");
    printf("\e[H");

    fflush(stdout);
}

void desenhar_jogar(int cor) {
    char cora[]={"38;2;255;255;255"};
    if (cor==1) strcpy(cora,"38;2;213;0;0");
    printf("\e[16E");
    printf("\e[86C\e[%sm██████████\e[2C██████████\e[2C██████████\e[2C██████████\e[2C██████████\e[E",cora);
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[8C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C██████████\e[2C████████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[92C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[86C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[86C██████████\e[2C██████████\e[2C██████████\e[2C████\e[2C████\e[2C████\e[2C████\e[E");
    printf("\e[0m");
    printf("\e[H");
    fflush(stdout);
}

void desenhar_configurar(int cor) {
    char cora[]={"38;2;158;158;158"};
    if (cor==2) strcpy(cora,"38;2;213;0;0");
    printf("\e[27E");
    printf("\e[112C\e[%sm████\e[E",cora);
    printf("\e[106C████\e[2C████\e[2C████\e[E");
    printf("\e[106C████████████████\e[E");
    printf("\e[108C████████████\e[E");
    printf("\e[104C████████\e[4C████████\e[E");
    printf("\e[104C████████\e[4C████████\e[E");
    printf("\e[108C████████████\e[E");
    printf("\e[106C████████████████\e[E");
    printf("\e[106C████\e[2C████\e[2C████\e[E");
    printf("\e[112C████\e[E");
    printf("\e[0m");
    printf("\e[H");
    fflush(stdout);
}

void menuinicial_imprimirSimbolo (int navegador) {
    int cor;
    
    switch(navegador) {
        case 0:
        cor=0;
        break;

        case 1:
        cor=1;
        break;

        case 2:
        cor=2;
        break;
    }
    desenhar_jogar(cor);
    desenhar_configurar(cor);

}

int menuinicial_navegar (tp_cursor *cursor) {
    menuinicial_imprimirSimbolo(cursor->navegador);

    int input;
    do {
        input=-1;
		while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 119 && input != 115 && input != 102 && input != 120); //119 = W / 115 = S / 192 - F

    switch(input) {
        case 119:
        audio_stop("selecao");
        audio_play("selecao",0);
        cursor->navegador=1;
        break;

        case 115:
        audio_stop("selecao");
        audio_play("selecao",0);
        cursor->navegador=2;
        break;

        case 102:
        if(cursor->navegador > 0) return cursor->navegador; 
        break;

        case 120:
            return 3;
        break;
    }

    return 0;
}

void desenhar_fundo() {
    printf("\e[48;2;0;77;64m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}



void desenhar_pote(float totalApostado) {
    printf("\e[62C\e[48;2;244;67;54m                              \e[E");
    printf("\e[62C  \e[48;2;255;255;255m      \e[38;2;255;119;110m     POTE     \e[39m      \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m  \e[48;2;244;67;54m                      \e[48;2;255;255;255m  \e[48;2;244;67;54m  \e[E");
    printf("\e[62C  \e[48;2;255;255;255m                          \e[48;2;244;67;54m  \e[E");
    printf("\e[62C                              \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[3E\e[68C\e[48;2;244;67;54m\e[38;2;252;228;236m");
    imprimir_centralizado_float_dinheiro(totalApostado,18);


    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelho() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;255;255m████████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m██\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;188;210m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C██████\e[38;2;255;116;116m██\e[38;2;255;255;255m████\e[38;2;255;188;210m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;255;255m████\e[E");
    printf("\e[2C\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C██\e[38;2;255;194;0m██\e[38;2;255;255;255m██\e[38;2;255;116;116m██\e[38;2;255;255;255m██\e[38;2;255;194;0m██\e[38;2;255;188;210m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;255;255m██████\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m████\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;255;155;155m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██████\e[38;2;0;0;0m██\e[38;2;255;255;255m████████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C██\e[38;2;0;151;246m██\e[38;2;255;255;255m██\e[38;2;255;116;116m██\e[38;2;255;255;255m██\e[38;2;0;151;246m██\e[38;2;255;188;210m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilo() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;85;49;42m████\e[38;2;255;255;255m████████\e[38;2;85;49;42m████\e[E");
    printf("\e[2C\e[38;2;255;206;211m██\e[38;2;85;49;42m██\e[38;2;120;75;62m████████\e[38;2;85;49;42m██\e[38;2;255;206;211m██\e[E");
    printf("\e[2C\e[38;2;255;210;124m████\e[38;2;120;75;62m████████\e[38;2;255;210;124m████\e[E");
    printf("\e[2C\e[38;2;27;27;27m██\e[38;2;97;97;97m██\e[38;2;255;205;124m██\e[38;2;120;75;62m████\e[38;2;255;210;124m██\e[38;2;27;27;27m██\e[38;2;97;97;97m██\e[E");
    printf("\e[2C██\e[38;2;27;27;27m██\e[38;2;255;210;124m██\e[38;2;153;110;98m████\e[38;2;255;210;124m██\e[38;2;97;97;97m██\e[38;2;27;27;27m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m██\e[38;2;255;210;124m██\e[38;2;120;75;62m██\e[38;2;0;0;0m████\e[38;2;120;75;62m██\e[38;2;255;205;124m██\e[38;2;255;210;124m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m████\e[38;2;153;110;98m██\e[38;2;255;255;255m████\e[38;2;153;110;98m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C██\e[38;2;153;110;98m████████████\e[38;2;120;75;62m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;85;49;42m████\e[38;2;255;255;255m████████\e[38;2;85;49;42m████\e[E");
    printf("\e[2C\e[38;2;255;206;211m██\e[38;2;85;49;42m██\e[38;2;120;75;62m████████\e[38;2;85;49;42m██\e[38;2;255;206;211m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m██\e[38;2;255;194;0m██\e[38;2;120;75;62m████████\e[38;2;255;194;0m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;120;75;62m████\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[E");
    printf("\e[2C██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[38;2;153;110;98m████\e[38;2;255;194;0m██\e[38;2;255;236;18m██\e[38;2;255;194;0m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m██\e[38;2;255;194;0m██\e[38;2;120;75;62m██\e[38;2;0;0;0m████\e[38;2;120;75;62m██\e[38;2;255;194;0m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C████\e[38;2;153;110;98m██\e[38;2;255;255;255m████\e[38;2;153;110;98m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C██\e[38;2;153;110;98m████\e[38;2;255;65;50m████\e[38;2;153;110;98m████\e[38;2;120;75;62m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;85;49;42m████\e[38;2;255;255;255m████████\e[38;2;85;49;42m████\e[E");
    printf("\e[2C\e[38;2;255;206;211m██\e[38;2;85;49;42m██\e[38;2;120;75;62m████████\e[38;2;85;49;42m██\e[38;2;255;206;211m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m████████████████\e[E");
    printf("\e[2C\e[38;2;255;210;124m████\e[38;2;255;205;124m██\e[38;2;120;75;62m████\e[38;2;255;210;124m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m████\e[38;2;255;210;124m██\e[38;2;153;110;98m████\e[38;2;255;210;124m██\e[38;2;0;0;0m████\e[E");
    printf("\e[2C\e[38;2;255;205;124m██\e[38;2;0;151;246m██\e[38;2;120;75;62m██\e[38;2;0;0;0m████\e[38;2;120;75;62m██\e[38;2;0;151;246m██\e[38;2;255;210;124m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m██\e[38;2;0;151;246m██\e[38;2;153;110;98m██\e[38;2;255;255;255m████\e[38;2;153;110;98m██\e[38;2;0;151;246m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C██\e[38;2;0;151;246m██\e[38;2;153;110;98m████████\e[38;2;0;151;246m██\e[38;2;120;75;62m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gato() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████████\e[38;2;255;184;66m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[38;2;255;205;124m████\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m████████\e[38;2;255;82;79m██\e[38;2;255;205;124m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m████████████\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████████\e[38;2;255;184;66m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[38;2;255;236;18m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;255;236;18m██\e[38;2;255;205;124m████\e[38;2;255;236;18m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m████████\e[38;2;255;82;79m██\e[38;2;255;205;124m██████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m████\e[38;2;255;65;50m████\e[38;2;255;205;124m████\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████████\e[38;2;255;184;66m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[38;2;255;255;255m████\e[38;2;255;184;66m██\e[38;2;255;205;124m██\e[38;2;255;184;66m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[38;2;0;0;0m██\e[38;2;255;184;66m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[38;2;255;205;124m████\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;205;124m████\e[38;2;0;151;246m██\e[38;2;255;205;124m██\e[38;2;255;82;79m██\e[38;2;0;151;246m██\e[38;2;255;205;124m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██\e[38;2;255;205;124m██\e[38;2;0;151;246m██\e[38;2;255;205;124m████\e[38;2;0;151;246m██\e[38;2;255;205;124m██\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_rato() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████████\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C██\e[38;2;255;200;206m██\e[38;2;151;151;151m████████\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;0;0m██\e[38;2;151;151;151m████\e[38;2;0;0;0m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C██████\e[38;2;255;146;146m████\e[38;2;151;151;151m██████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m████████████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;151;151;151m████████\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████████\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C██\e[38;2;255;200;206m██\e[38;2;151;151;151m████████\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[38;2;255;235;33m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C██████\e[38;2;255;146;146m████\e[38;2;151;151;151m██████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m████\e[38;2;255;58;43m████\e[38;2;151;151;151m████\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;151;151;151m████████\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████████\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[38;2;255;255;255m████\e[38;2;151;151;151m██\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C██\e[38;2;255;200;206m██\e[38;2;151;151;151m████████\e[38;2;255;200;206m██\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C██\e[38;2;0;0;0m████\e[38;2;151;151;151m████\e[38;2;0;0;0m████\e[38;2;151;151;151m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;255;146;146m████\e[38;2;0;140;244m██\e[38;2;151;151;151m████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;151;151;151m██\e[38;2;0;140;244m██\e[38;2;151;151;151m████\e[38;2;0;140;244m██\e[38;2;151;151;151m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;151;151;151m████\e[38;2;0;140;244m██\e[38;2;255;255;255m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapo() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;135;48m████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m██\e[38;2;0;135;48m██\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;86;23m████████████\e[E");
    printf("\e[2C\e[38;2;0;135;48m████████████████\e[E");
    printf("\e[2C████████████\e[38;2;0;117;39m████\e[E");
    printf("\e[2C\e[38;2;0;154;59m██\e[38;2;0;135;48m████████████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;117;39m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;135;48m████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;255;235;33m██\e[38;2;0;135;48m██\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;255;235;33m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;0;86;23m████████████\e[E");
    printf("\e[2C\e[38;2;0;135;48m████\e[38;2;255;58;43m████████\e[38;2;0;135;48m████\e[E");
    printf("\e[2C████████████\e[38;2;0;117;39m████\e[E");
    printf("\e[2C\e[38;2;0;154;59m██\e[38;2;0;135;48m████████████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;117;39m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;135;48m████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██\e[38;2;0;0;0m████\e[E");
    printf("\e[2C\e[38;2;0;135;48m████\e[38;2;0;140;244m██\e[38;2;0;135;48m██████\e[38;2;0;140;244m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;0;86;23m██████\e[38;2;0;140;244m██\e[38;2;0;86;23m██\e[E");
    printf("\e[2C\e[38;2;0;135;48m████\e[38;2;0;140;244m██\e[38;2;0;135;48m██████\e[38;2;0;140;244m██\e[38;2;0;135;48m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;0;135;48m██████\e[38;2;0;140;244m██\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m██\e[38;2;0;135;48m████████████\e[38;2;0;117;39m██\e[E");
    printf("\e[2C\e[38;2;0;154;59m████\e[38;2;255;255;255m██\e[38;2;0;135;48m██████\e[38;2;255;255;255m██\e[38;2;0;117;39m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_urso() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;120;75;62m██████\e[38;2;255;255;255m████\e[38;2;120;75;62m██████\e[E");
    printf("\e[2C██\e[38;2;255;155;155m██\e[38;2;120;75;62m██\e[38;2;255;255;255m████\e[38;2;120;75;62m██\e[38;2;255;155;155m██\e[38;2;120;75;62m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;120;75;62m██\e[38;2;27;27;27m██\e[38;2;120;75;62m████\e[38;2;27;27;27m██\e[38;2;120;75;62m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;120;75;62m████\e[38;2;0;0;0m██\e[38;2;120;75;62m████\e[38;2;0;0;0m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;133;84;70m██\e[38;2;0;0;0m████\e[38;2;133;84;70m██\e[38;2;120;75;62m████\e[E");
    printf("\e[2C████\e[38;2;133;84;70m████████\e[38;2;120;75;62m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursodinheiro() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;107;68;56m██████\e[38;2;255;255;255m████\e[38;2;107;68;56m██████\e[E");
    printf("\e[2C██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[38;2;255;255;255m████\e[38;2;107;68;56m██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;107;68;56m██\e[38;2;255;189;0m██\e[38;2;107;68;56m████\e[38;2;255;189;0m██\e[38;2;107;68;56m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;107;68;56m████\e[38;2;255;189;0m██\e[38;2;107;68;56m████\e[38;2;255;189;0m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C████\e[38;2;120;76;63m██\e[38;2;0;0;0m████\e[38;2;120;76;63m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████\e[38;2;120;76;63m██\e[38;2;255;58;43m████\e[38;2;120;76;63m██\e[38;2;107;68;56m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursotriste() {
    printf("\e[35E");
    printf("\e[2C\e[38;2;107;68;56m██████\e[38;2;255;255;255m████\e[38;2;107;68;56m██████\e[E");
    printf("\e[2C██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[38;2;255;255;255m████\e[38;2;107;68;56m██\e[38;2;255;146;146m██\e[38;2;107;68;56m██\e[E");
    printf("\e[2C████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m██\e[38;2;107;68;56m██\e[38;2;0;0;0m██\e[38;2;107;68;56m████\e[38;2;0;0;0m██\e[38;2;107;68;56m██\e[38;2;255;255;255m██\e[E");
    printf("\e[2C\e[38;2;107;68;56m██\e[38;2;0;0;0m████\e[38;2;107;68;56m████\e[38;2;0;0;0m████\e[38;2;107;68;56m██\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;0;0;0m████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[E");
    printf("\e[2C████\e[38;2;0;140;244m██\e[38;2;120;76;63m████\e[38;2;0;140;244m██\e[38;2;107;68;56m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_corjog(char cor[]) {
    printf("\e[34E");
    printf("\e[%sm████████████████████\e[E",cor);
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("██\e[16C██\e[E");
    printf("████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cabecalho_jogador_neutro (int ID) {
    switch (ID) {
        case 0:
        desenhar_gato();
        break;

        case 1:
        desenhar_coelho();
        break;

        case 2:
        desenhar_sapo();
        break;

        case 3:
        desenhar_esquilo();
        break;

        case 4:
        desenhar_rato();
        break;

        case 5:
        desenhar_urso();
        break;
    }
}

void desenhar_cabecalho_jogador_triste (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatotriste();
        break;

        case 1:
        desenhar_coelhotriste();
        break;

        case 2:
        desenhar_sapotriste();
        break;

        case 3:
        desenhar_esquilotriste();
        break;

        case 4:
        desenhar_ratotriste();
        break;

        case 5:
        desenhar_ursotriste();
        break;
    }
}

void desenhar_cabecalho_jogador_dinheiro (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatodinheiro();
        break;

        case 1:
        desenhar_coelhodinheiro();
        break;

        case 2:
        desenhar_sapodinheiro();
        break;

        case 3:
        desenhar_esquilodinheiro();
        break;

        case 4:
        desenhar_ratodinheiro();
        break;

        case 5:
        desenhar_ursodinheiro();
        break;
    }
}


void desenhar_cabecalho(char cor[],char nome[],int ID) {
    printf("\e[31E");
    printf("\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[48;2;128;203;196m\e[s                    \e[38;2;0;0;0m██\e[E");
    printf("\e[u");
    imprimir__centralizado_string_max20(nome,20);
    printf("\e[49m\e[E");
    printf("\e[38;2;0;0;0m██████████████████████\e[E");
    printf("\e[20C██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[2C\e[38;2;255;255;255m████████████████\e[2C\e[38;2;0;0;0m██\e[E");
    printf("\e[20C██\e[E");
    printf("\e[0m");
    printf("\e[H");

    desenhar_corjog(cor);
    desenhar_cabecalho_jogador_neutro(ID);
}

void desenhar_dinheiro(float dinheiro) {
    printf("\e[s");
    printf("\e[E");
    printf("\e[8C\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[4C\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[4C\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[2C██████████████████\e[E");
    printf("\e[2C\e[38;2;255;255;255m████\e[38;2;0;0;0m██████████\e[38;2;255;255;255m████\e[E");
    printf("\e[2C\e[38;2;0;0;0m██████████████████\e[E");
    printf("\e[4C██\e[38;2;255;255;255m██\e[38;2;0;0;0m██████\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[4C\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[38;2;0;0;0m████\e[38;2;255;255;255m██\e[E");
    printf("\e[8C\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[2C\e[11B");
    printf("\e[48;2;0;77;64m");
    printf("\e[1m");
    printf("                  ");
    printf("\e[18D");
    imprimir_centralizado_float_dinheiro(dinheiro,18);
    printf("\e[H");
    printf("\e[0m");
}

void desenhar_dinheirocifra() {
    printf("\e[E");
    printf("\e[8C\e[38;2;164;119;32m██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[4C██\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;166;98;12m██\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[4C\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;223;152;18m██████\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[E");
    printf("\e[2C\e[38;2;164;119;32m██\e[38;2;59;35;6m████\e[38;2;223;152;18m██\e[38;2;166;98;12m██\e[38;2;59;35;6m██████\e[38;2;164;119;32m██\e[E");
    printf("\e[2C\e[38;2;102;58;9m██\e[38;2;59;35;6m████\e[38;2;223;152;18m██████\e[38;2;59;35;6m████\e[38;2;102;58;9m██\e[E");
    printf("\e[2C\e[38;2;164;119;32m██\e[38;2;59;35;6m██████\e[38;2;166;98;12m██\e[38;2;223;152;18m██\e[38;2;59;35;6m████\e[38;2;164;119;32m██\e[E");
    printf("\e[4C\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;223;152;18m██████\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[E");
    printf("\e[4C\e[38;2;164;119;32m██\e[38;2;102;58;9m██\e[38;2;59;35;6m██\e[38;2;166;98;12m██\e[38;2;59;35;6m██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[8C██\e[38;2;102;58;9m██\e[38;2;164;119;32m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_dinheirocifra_dinheiro(float dinheiro) {
    printf("\e[2C\e[11B");
    printf("\e[48;2;0;77;64m");
    printf("\e[1m");
    printf("                  ");
    printf("\e[18D");
    imprimir_centralizado_float_dinheiro(dinheiro,18);
    printf("\e[H");
    printf("\e[0m");
}

void desenhar_dinheirocifra_dinheiro_limpar() {
    printf("\e[2C\e[11B");
    printf("\e[48;2;0;77;64m");
    printf("\e[1m");
    printf("                  ");
    printf("\e[H");
    printf("\e[0m");
}



void desenhar_bordaseletor() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[38;2;35;48;54m██████████████████████\e[2C██████████████████████\e[2C██████████████████████\e[E");
    printf("\e[40C██\e[22C██\e[22C██\e[22C██\e[E");
    printf("\e[40C██\e[22C██\e[22C██\e[22C██\e[E");
    printf("\e[40C██\e[22C██\e[22C██\e[22C██\e[E");
    printf("\e[42C██████████████████████\e[2C██████████████████████\e[2C██████████████████████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_aumentar(tp_cursor *cursor) {
    char corletra[3][18]={"38;2;74;74;74","38;2;74;74;74"};
    strcpy(corletra[cursor->navegador],"38;2;255;209;255");

    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");

    printf("\e[39E\e[42C");
    printf("\e[48;2;33;150;243m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("COMO QUER FAZER O AUMENTO?",70);
    printf("\e[E\e[42C");
    printf("\e[%sm",corletra[0]);
    imprimir__centralizado_string_max100("PERCENTUAL",35);
    printf("\e[%sm",corletra[1]);
    imprimir__centralizado_string_max100("VALOR ABSOLUTO",35);
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_limpar_seletorEaumentar() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;0;77;64m                                                                      \e[E");
    printf("\e[40C                                                                          \e[E");
    printf("\e[40C                                                                          \e[E");
    printf("\e[40C                                                                          \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_marcadormaojogador() {
    printf("\e[24E");
    printf("\e[56C\e[38;2;10;209;173m████\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m████\e[E");
    printf("\e[56C██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C\e[38;2;29;78;99m██████████████████████████████████████████\e[E");
    printf("\e[56C\e[38;2;10;209;173m██\e[38;2;29;78;99m██████████████████████████████████████\e[38;2;10;209;173m██\e[E");
    printf("\e[56C████\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m██\e[38;2;29;78;99m██\e[38;2;10;209;173m████\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_porcoaposta() {
    printf("\e[33E");
    printf("\e[138C\e[48;2;255;193;7m  \e[2C  \e[2C\e[48;2;255;235;59m  \e[E");
    printf("\e[138C  \e[48;2;255;193;7m      \e[48;2;255;235;59m  \e[E");
    printf("\e[138C\e[48;2;255;152;0m    \e[48;2;244;67;54m  \e[48;2;255;152;0m    \e[E");
    printf("\e[138C\e[48;2;255;205;210m          \e[E");
    printf("\e[138C\e[48;2;0;0;0m  \e[48;2;255;205;210m      \e[48;2;0;0;0m  \e[E");
    printf("\e[138C\e[48;2;255;205;210m  \e[48;2;229;115;115m  \e[48;2;239;154;154m  \e[48;2;229;115;115m  \e[48;2;255;205;210m  \e[E");
    printf("\e[132C  \e[48;2;239;154;154m  \e[2C\e[48;2;255;205;210m  \e[48;2;239;154;154m      \e[48;2;255;205;210m  \e[2C\e[48;2;239;154;154m  \e[48;2;255;205;210m  \e[E");
    printf("\e[130C\e[48;2;255;152;0m                          \e[E");
    printf("\e[130C  \e[48;2;255;193;7m                      \e[48;2;255;152;0m  \e[E");
    printf("\e[130C  \e[48;2;255;193;7m                      \e[48;2;255;152;0m  \e[E");
    printf("\e[130C                          \e[E");

    

    printf("\e[0m");
    printf("\e[H");
}

void desenhar_inserirjogadormesa() {
    printf("\e[16C\e[38;2;102;65;20m██████████████████████████████████████████████████\e[E");
    printf("\e[12C████\e[38;2;74;47;16m██████████████████████████████████████████████████\e[38;2;102;65;20m████\e[E");
    printf("\e[8C████\e[38;2;74;47;16m████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;74;47;16m████\e[38;2;102;65;20m████\e[E");
    printf("\e[6C████\e[38;2;74;47;16m██\e[38;2;10;87;73m████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;10;87;73m████\e[38;2;74;47;16m██\e[38;2;102;65;20m████\e[E");
    printf("\e[6C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C████\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m████████████████████████████████████████████████████████████\e[38;2;74;47;16m██\e[38;2;102;65;20m████\e[E");
    printf("\e[4C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████\e[38;2;244;67;54m██\e[38;2;255;255;255m██\e[38;2;0;77;64m██\e[38;2;0;0;0m██\e[38;2;255;255;255m██\e[38;2;0;77;64m██████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████\e[38;2;255;255;255m████\e[38;2;0;77;64m██\e[38;2;255;255;255m████\e[38;2;0;77;64m██████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████\e[38;2;255;255;255m██\e[38;2;244;67;54m██\e[38;2;0;77;64m██\e[38;2;255;255;255m██\e[38;2;0;0;0m██\e[38;2;0;77;64m██████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[4C████\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m██████████████████████████████████████████████████████████\e[38;2;10;87;73m██\e[38;2;74;47;16m████\e[38;2;102;65;20m██\e[E");
    printf("\e[6C██\e[38;2;74;47;16m██\e[38;2;10;87;73m██\e[38;2;0;77;64m████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██████████\e[38;2;0;77;64m████\e[38;2;10;87;73m██\e[38;2;74;47;16m██\e[38;2;102;65;20m██\e[E");
    printf("\e[6C████\e[38;2;74;47;16m██\e[38;2;10;87;73m████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;0;77;64m██████████\e[38;2;0;191;165m██\e[38;2;0;121;107m██████\e[38;2;0;191;165m██\e[38;2;10;87;73m████\e[38;2;74;47;16m██\e[38;2;102;65;20m████\e[E");
    printf("\e[8C████\e[38;2;74;47;16m████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;10;87;73m██████████\e[38;2;0;191;165m██████████\e[38;2;74;47;16m████\e[38;2;102;65;20m████\e[E");
    printf("\e[12C████\e[38;2;74;47;16m██████████████████████████████████████████████████\e[38;2;102;65;20m████\e[E");
    printf("\e[16C██████████████████████████████████████████████████\e[E");
    printf("\e[0m");
}

void desenhar_aumentar_aposta_fundo() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");
}

void desenhar_aumentar_aposta_percentual() {
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");
}

void desenhar_aumentar_aposta_percentual_barrinha() {
    printf("\e[40E");
    printf("\e[58C\e[48;2;41;121;255m        \e[6C          \e[6C        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_aumentar_aposta_absoluto() {
    
    printf("\e[s");
    printf("\e[38E");
    printf("\e[42C\e[48;2;35;48;54m                                                                      \e[E");
    printf("\e[40C  \e[48;2;255;255;255m      \e[48;2;33;150;243m                                                                \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;255;255;255m  \e[48;2;33;150;243m                                                                  \e[48;2;255;255;255m  \e[48;2;35;48;54m  \e[E");
    printf("\e[40C  \e[48;2;33;150;243m                                                                \e[48;2;255;255;255m      \e[48;2;35;48;54m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[H");

    printf("\e[39E\e[42C");
    printf("\e[48;2;33;150;243m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("DIGITE O VALOR A SER APOSTADO",70);
    printf("\e[E\e[46C Aperte F para digitar");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadoraposta(float aposta) {
    printf("\e[28E");
    printf("\e[48;2;0;0;0m                      \e[E");
    printf("\e[48;2;140;158;255m                    \e[48;2;0;0;0m  \e[E");
    printf("\e[48;2;140;158;255m                    \e[48;2;0;0;0m  \e[E");
    printf("\e[0m");
    printf("\e[H");
    
    printf("\e[28E");
    printf("\e[E");
    printf("\e[48;2;140;158;255m\e[38;2;0;0;0m");
    imprimir__centralizado_string_max20("Valor Já Apostado",20);
    printf("\e[E");
    imprimir_centralizado_float_dinheiro(aposta,20);
    printf("\e[E");
    printf("\e[0m");
    printf("\e[H");

}

void desenhar_mesaapoiodamesa() {
    printf("\e[9E");
    printf("\e[44C\e[48;2;163;114;49m    \e[48;2;54;45;40m                                                          \e[48;2;163;114;49m    \e[E");
    printf("\e[44C  \e[48;2;54;45;40m                                                              \e[48;2;163;114;49m  \e[E");
    printf("\e[44C\e[48;2;54;45;40m         \e[48;2;163;114;49m                                                 \e[48;2;54;45;40m        \e[E");
    printf("\e[44C       \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                 \e[48;2;163;114;49m  \e[48;2;54;45;40m      \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C     \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                     \e[48;2;163;114;49m  \e[48;2;54;45;40m    \e[E");
    printf("\e[44C       \e[48;2;163;114;49m  \e[48;2;54;45;40m                                                 \e[48;2;163;114;49m  \e[48;2;54;45;40m      \e[E");
    printf("\e[44C         \e[48;2;163;114;49m                                                 \e[48;2;54;45;40m        \e[E");
    printf("\e[44C\e[48;2;163;114;49m  \e[48;2;54;45;40m                                                              \e[48;2;163;114;49m  \e[E");
    printf("\e[44C    \e[48;2;54;45;40m                                                          \e[48;2;163;114;49m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_areacombinacoes() {
    printf("\e[134C\e[48;2;92;107;192m                      \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C  \e[48;2;121;134;203m                  \e[48;2;92;107;192m  \e[E");
    printf("\e[134C                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seletorficoupobre() {
    printf("\e[38E");
    printf("\e[42C\e[48;2;34;44;49m                                                                      \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[39E\e[42C");
    printf("\e[48;2;245;53;51m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Você não tem mais dinheiro para jogar :(",70);
    printf("\e[E\e[42C");
    imprimir__centralizado_string_max100("Aperte F para desistir",70);
    printf("\e[0m");
    printf("\e[H");

}

void desenhar_seletordesistir() {
    printf("\e[38E");
    printf("\e[42C\e[48;2;34;44;49m                                                                      \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[40C  \e[48;2;245;53;51m                                                                      \e[48;2;34;44;49m  \e[E");
    printf("\e[42C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[39E\e[42C");
    printf("\e[48;2;245;53;51m\e[38;2;255;255;255m");
    imprimir__centralizado_string_max100("Deseja mesmo desistir?",70);
    printf("\e[E\e[42C");
    imprimir__centralizado_string_max100("Aperte F para desistir, X para voltar",70);
    printf("\e[0m");
    printf("\e[H");

}

void desenhar_tutorial(char RGBfundo[]){
    printf("\e[43E\e[48;2;%sm",RGBfundo);
    imprimir__centralizado_string_max200("Navegar: [WASD] | Confirmar: [F] | Voltar: [X]",155);
    printf("\e[H\e[0m");
}

void desenhar_popupavisolimpar() {
    printf("\e[18E");
    printf("\e[48;2;0;77;64m                                      \e[E");
    printf("                                    \e[E");
    printf("                                  \e[E");
    printf("                                \e[E");
    printf("                                \e[E");
    printf("                              \e[E");
    printf("                              \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_popupaviso(char texto1[],char texto2[],char texto3[]) {
    printf("\e[18E");
    printf("\e[48;2;49;0;0m                                      \e[E");
    printf("  \e[48;2;89;0;0m                            \e[48;2;71;0;0m  \e[48;2;49;0;0m    \e[E");
    printf("  \e[48;2;89;0;0m                          \e[48;2;71;0;0m  \e[48;2;49;0;0m    \e[E");
    printf("  \e[48;2;89;0;0m                          \e[48;2;71;0;0m  \e[48;2;49;0;0m  \e[E");
    printf("  \e[48;2;89;0;0m                        \e[48;2;71;0;0m  \e[48;2;49;0;0m    \e[E");
    printf("  \e[48;2;89;0;0m                        \e[48;2;71;0;0m  \e[48;2;49;0;0m  \e[E");
    printf("                              \e[E");
    printf("\e[0m");
    printf("\e[H");

    printf("\e[48;2;89;0;0m\e[38;2;255;255;255m\e[20E\e[4C");
    imprimir__centralizado_string_max100(texto1,21);
    printf("\e[E\e[4C");
    imprimir__centralizado_string_max100(texto2,21);
    printf("\e[E\e[4C");
    imprimir__centralizado_string_max100(texto3,19);
    printf("\e[1E\e[4C");
    imprimir__centralizado_string_max100("[Pressione F]",19);
    int input;
    do {
        input=-1;
        while (input == -1) input = getch();  // Verifica se uma tecla foi pressionada
    } while (input != 102);
    printf("\e[H\e[0m");
    desenhar_popupavisolimpar();

}

void desenhar_guia() {
    printf("\e[27E");
    printf("\e[108C\e[38;2;72;125;178m████████████\e[E");
    printf("\e[106C██\e[38;2;180;202;212m██\e[38;2;200;224;236m██\e[38;2;72;125;178m██\e[38;2;180;202;212m██\e[38;2;200;224;236m██\e[38;2;72;125;178m████\e[E");
    printf("\e[104C████\e[38;2;200;224;236m████\e[38;2;72;125;178m██\e[38;2;200;224;236m████\e[38;2;72;125;178m██████\e[E");
    printf("\e[104C████\e[38;2;200;224;236m██\e[38;2;180;202;212m██\e[38;2;147;172;183m██\e[38;2;200;224;236m██\e[38;2;180;202;212m██\e[38;2;147;172;183m██\e[38;2;72;125;178m████\e[E");
    printf("\e[104C██████\e[38;2;147;172;183m████\e[38;2;72;125;178m██\e[38;2;147;172;183m████\e[38;2;72;125;178m████\e[E");
    printf("\e[106C████\e[38;2;147;172;183m██\e[38;2;98;124;136m██\e[38;2;72;125;178m██\e[38;2;147;172;183m██\e[38;2;98;124;136m██\e[38;2;72;125;178m██\e[E");
    printf("\e[108C████████████\e[E");

    printf("\e[1E\e[108C\e[38;2;255;255;255m\e[48;2;0;77;64m");
    imprimir__centralizado_string_max20("Guia",12);

    printf("\e[0m");
    printf("\e[H");
}

void desenhar_guiadesligado() {
    printf("\e[27E");
    printf("\e[108C\e[38;2;34;44;49m████████████\e[E");
    printf("\e[106C██\e[38;2;85;96;100m██\e[38;2;103;117;122m██\e[38;2;34;44;49m██\e[38;2;85;96;100m██\e[38;2;103;117;122m██\e[38;2;34;44;49m████\e[E");
    printf("\e[104C████\e[38;2;103;117;122m████\e[38;2;34;44;49m██\e[38;2;103;117;122m████\e[38;2;34;44;49m██████\e[E");
    printf("\e[104C████\e[38;2;103;117;122m██\e[38;2;85;96;100m██\e[38;2;61;69;70m██\e[38;2;103;117;122m██\e[38;2;85;96;100m██\e[38;2;61;69;70m██\e[38;2;34;44;49m████\e[E");
    printf("\e[104C██████\e[38;2;61;69;70m████\e[38;2;34;44;49m██\e[38;2;61;69;70m████\e[38;2;34;44;49m████\e[E");
    printf("\e[106C████\e[38;2;61;69;70m██\e[38;2;42;46;47m██\e[38;2;34;44;49m██\e[38;2;61;69;70m██\e[38;2;42;46;47m██\e[38;2;34;44;49m██\e[E");
    printf("\e[108C████████████\e[E");

    printf("\e[1E\e[108C\e[38;2;34;44;49m\e[48;2;0;77;64m");
    imprimir__centralizado_string_max20("Guia",12);

    printf("\e[0m");
    printf("\e[H");
}
void desenhar_guialimpar() {
    printf("\e[27E");
    printf("\e[108C\e[48;2;0;77;64m            \e[E");
    printf("\e[106C                \e[E");
    printf("\e[104C                    \e[E");
    printf("\e[104C                    \e[E");
    printf("\e[104C                    \e[E");
    printf("\e[106C                \e[E");
    printf("\e[108C            \e[E");

    printf("\e[1E\e[108C\e[38;2;34;44;49m\e[48;2;0;77;64m");
    imprimir__centralizado_string_max20("    ",12);

    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadores() {
    printf("\e[27E");
    printf("\e[34C\e[38;2;72;125;178m████████████\e[E");
    printf("\e[32C██\e[38;2;3;15;21m████\e[38;2;72;125;178m████\e[38;2;7;22;37m████\e[38;2;72;125;178m██\e[E");
    printf("\e[32C██\e[38;2;3;15;21m████\e[38;2;15;41;79m████\e[38;2;7;22;37m████\e[38;2;72;125;178m██\e[E");
    printf("\e[30C██\e[38;2;3;15;21m██████\e[38;2;15;41;79m████\e[38;2;7;22;37m██████\e[38;2;72;125;178m██\e[E");
    printf("\e[30C██\e[38;2;3;15;21m████\e[38;2;15;41;79m████████\e[38;2;7;22;37m████\e[38;2;72;125;178m██\e[E");
    printf("\e[32C████\e[38;2;15;41;79m████████\e[38;2;72;125;178m████\e[E");
    printf("\e[34C████████████\e[E");
    
    printf("\e[1E\e[34C\e[38;2;255;255;255m\e[48;2;0;77;64m");
    imprimir__centralizado_string_max20("Jogadores",12);

    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadoresdesligado() {
    printf("\e[27E");
    printf("\e[34C\e[38;2;34;44;49m████████████\e[E");
    printf("\e[32C██\e[38;2;28;28;28m████\e[38;2;34;44;49m████\e[38;2;40;40;40m████\e[38;2;34;44;49m██\e[E");
    printf("\e[32C██\e[38;2;28;28;28m████\e[38;2;81;82;83m████\e[38;2;40;40;40m████\e[38;2;34;44;49m██\e[E");
    printf("\e[30C██\e[38;2;28;28;28m██████\e[38;2;81;82;83m████\e[38;2;40;40;40m██████\e[38;2;34;44;49m██\e[E");
    printf("\e[30C██\e[38;2;28;28;28m████\e[38;2;81;82;83m████████\e[38;2;40;40;40m████\e[38;2;34;44;49m██\e[E");
    printf("\e[32C████\e[38;2;81;82;83m████████\e[38;2;34;44;49m████\e[E");
    printf("\e[34C████████████\e[E");

    printf("\e[1E\e[34C\e[38;2;34;44;49m\e[48;2;0;77;64m");
    imprimir__centralizado_string_max20("Jogadores",12);

    printf("\e[0m");
    printf("\e[H");
}

void desenhar_jogadoreslimpar() {
    printf("\e[27E");
    printf("\e[34C\e[48;2;0;77;64m            \e[E");
    printf("\e[32C                \e[E");
    printf("\e[32C                \e[E");
    printf("\e[30C                    \e[E");
    printf("\e[30C                    \e[E");
    printf("\e[32C                \e[E");
    printf("\e[34C            \e[E");

    printf("\e[1E\e[34C");
    imprimir__centralizado_string_max20("         ",12);
    
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seletor(tp_cursor *cursor, float maiorAposta,float jogadorAposta) {
    char corfundo[5][18]={"48;2;96;125;139","48;2;96;125;139","48;2;96;125;139","48;2;96;125;139","48;2;96;125;139"};
    strcpy(corfundo[cursor->navegador],"48;2;33;150;243");
    char corletra[5][18]={"38;2;74;74;74","38;2;74;74;74","38;2;74;74;74","38;2;74;74;74","38;2;74;74;74"};
    strcpy(corletra[cursor->navegador],"38;2;255;209;255");
    if(cursor->navegador==0) desenhar_jogadores();
    else desenhar_jogadoresdesligado();
    if(cursor->navegador==4) desenhar_guia();
    else desenhar_guiadesligado();

    printf("\e[s");
    printf("\e[39E");
    printf("\e[42C\e[48;2;255;255;255m    \e[%sm            \e[48;2;255;255;255m      \e[2C    \e[%sm              \e[48;2;255;255;255m    \e[2C      \e[%sm            \e[48;2;255;255;255m    \e[E",corfundo[1],corfundo[2],corfundo[3]);
    if (maiorAposta != jogadorAposta) printf("\e[42C  \e[%sm     \e[%smAUMENTAR     \e[48;2;255;255;255m  \e[2C  \e[%sm     \e[%smDESISTIR     \e[48;2;255;255;255m  \e[2C  \e[%sm      \e[%smPAGAR       \e[48;2;255;255;255m  \e[E",corfundo[1],corletra[1],corfundo[2],corletra[2],corfundo[3],corletra[3]);
    else     printf("\e[42C  \e[%sm     \e[%smAUMENTAR     \e[48;2;255;255;255m  \e[2C  \e[%sm     \e[%smDESISTIR     \e[48;2;255;255;255m  \e[2C  \e[%sm    \e[%smCONTINUAR     \e[48;2;255;255;255m  \e[E",corfundo[1],corletra[1],corfundo[2],corletra[2],corfundo[3],corletra[3]);
    printf("\e[42C\e[%sm                      \e[2C\e[%sm                      \e[2C\e[%sm                      \e[E",corfundo[1],corfundo[2],corfundo[3]);
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_popupbase() {
    printf("\e[24C\e[48;2;249;189;110m      \e[48;2;207;133;43m        \e[48;2;143;120;89m                                                                              \e[48;2;207;133;43m        \e[48;2;249;189;110m      \e[E");
    printf("\e[24C  \e[48;2;87;72;49m                                                                                                      \e[48;2;249;189;110m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m                                                                                                  \e[48;2;87;72;49m  \e[48;2;249;189;110m  \e[E");
    printf("\e[24C\e[48;2;207;133;43m  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C\e[48;2;143;120;89m  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;143;120;89m  \e[E");
    printf("\e[24C\e[48;2;207;133;43m  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m  \e[48;2;60;50;37m  \e[48;2;44;37;28m                                                                                              \e[48;2;60;50;37m  \e[48;2;87;72;49m  \e[48;2;207;133;43m  \e[E");
    printf("\e[24C\e[48;2;249;189;110m  \e[48;2;87;72;49m  \e[48;2;60;50;37m                                                                                                  \e[48;2;87;72;49m  \e[48;2;249;189;110m  \e[E");
    printf("\e[24C  \e[48;2;87;72;49m                                                                                                      \e[48;2;249;189;110m  \e[E");
    printf("\e[24C      \e[48;2;207;133;43m        \e[48;2;143;120;89m                                                                              \e[48;2;207;133;43m        \e[48;2;249;189;110m      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_popupbaselimpar() {
    printf("\e[24C\e[48;2;0;77;64m                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[24C                                                                                                          \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_popguia() {
    printf("\e[E");
    printf("\e[54C\e[38;2;174;116;44m██████████████████████████████████████████████\e[E");
    printf("\e[56C██\e[38;2;45;34;20m██████████████████████████████████████\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m██████████████████████████████████████\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m████\e[38;2;174;116;44m██████\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m████\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m██████████\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██████\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m████\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m████████\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m██████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m████\e[38;2;174;116;44m██████\e[38;2;45;34;20m██████\e[38;2;174;116;44m████\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[38;2;45;34;20m████\e[38;2;174;116;44m██\e[38;2;45;34;20m██\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██\e[38;2;45;34;20m██████████████████████████████████████\e[38;2;174;116;44m██\e[E");
    printf("\e[56C██████████████████████████████████████████\e[E");
    printf("\e[3E");
    printf("\e[36C\e[38;2;96;74;28m██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[36C\e[38;2;168;120;34m██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[38C██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[E");
    printf("\e[36C\e[38;2;96;74;28m██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[2E");
    printf("\e[36C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[36C\e[38;2;168;120;34m██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[38C██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[E");
    printf("\e[36C\e[38;2;96;74;28m██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[2E");
    printf("\e[36C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[36C\e[38;2;168;120;34m██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[38C██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[E");
    printf("\e[36C\e[38;2;96;74;28m██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[2E");
    printf("\e[36C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[36C\e[38;2;168;120;34m██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[38C██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[E");
    printf("\e[36C\e[38;2;96;74;28m██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[2E");
    printf("\e[36C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[36C\e[38;2;168;120;34m██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[38C██\e[38;2;208;151;39m██\e[38;2;168;120;34m██\e[E");
    printf("\e[36C\e[38;2;96;74;28m██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[38C██\e[38;2;168;120;34m██\e[38;2;96;74;28m██\e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fundojogadores() {
    printf("\e[48;2;0;64;50m                                                                                                                                                            \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("  \e[48;2;0;35;28m                                                                                                                                                        \e[48;2;0;64;50m  \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_njogadores() {
    printf("\e[3E");
    printf("\e[32C\e[48;2;0;143;117m                                                                                              \e[E");
    printf("\e[30C  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m      \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[E");
    printf("\e[28C    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[E");
    printf("\e[28C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m      \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[E");
    printf("\e[28C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[E");
    printf("\e[30C  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m        \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m    \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;0;143;117m  \e[E");
    printf("\e[32C                                                                                              \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_doisjog() {
    printf("\e[12E");
    printf("\e[64C\e[48;2;0;135;135m  \e[48;2;0;137;137m  \e[48;2;0;135;135m                    \e[48;2;0;137;137m  \e[48;2;0;135;135m  \e[E");
    printf("\e[60C\e[48;2;0;143;143m  \e[48;2;0;135;135m  \e[48;2;0;134;134m  \e[48;2;0;128;128m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m          \e[48;2;0;118;118m  \e[48;2;0;120;120m  \e[48;2;0;122;122m  \e[48;2;0;128;128m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;99;99m  \e[48;2;0;83;83m                \e[48;2;0;91;91m  \e[48;2;0;117;117m    \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m    \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;0;27;27m            \e[48;2;0;20;20m  \e[48;2;0;0;0m  \e[48;2;0;91;91m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;135;135m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;133;133m  \e[48;2;0;119;119m  \e[48;2;0;117;117m    \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m            \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;20;20m  \e[48;2;0;117;117m        \e[48;2;0;119;119m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C  \e[48;2;0;134;134m  \e[48;2;0;121;121m  \e[48;2;0;117;117m    \e[48;2;0;66;67m  \e[48;2;0;13;13m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;59;59m  \e[48;2;0;117;117m        \e[48;2;0;121;121m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;127;127m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m  \e[48;2;176;176;176m  \e[48;2;98;98;98m        \e[48;2;146;146;146m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;4;4m  \e[48;2;0;99;99m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m        \e[48;2;79;79;79m  \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;35;35m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[50C\e[48;2;0;135;135m  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m          \e[48;2;98;98;98m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;119;119m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;60;60;60m  \e[48;2;98;98;98m  \e[48;2;60;60;60m  \e[48;2;0;0;0m        \e[48;2;79;79;79m  \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;79;79;79m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;66;67m  \e[48;2;0;0;0m            \e[48;2;60;60;60m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m    \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m            \e[48;2;0;27;27m  \e[48;2;0;0;0m        \e[48;2;60;60;60m  \e[48;2;146;146;146m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m            \e[48;2;0;99;99m  \e[48;2;0;83;83m    \e[48;2;0;43;43m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;20;20m  \e[48;2;0;91;91m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m                \e[48;2;0;83;83m  \e[48;2;0;27;27m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;79;79;79m  \e[48;2;0;0;0m    \e[48;2;0;13;13m  \e[48;2;0;66;67m  \e[48;2;0;117;117m              \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m              \e[48;2;0;99;99m  \e[48;2;0;43;43m  \e[48;2;98;98;98m  \e[48;2;204;204;204m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m                \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;118;118m  \e[48;2;0;117;117m            \e[48;2;0;59;59m  \e[48;2;60;60;60m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;161;161;161m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m                  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;120;120m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m      \e[48;2;0;20;20m  \e[48;2;0;91;91m  \e[48;2;0;117;117m                \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;66;67m  \e[48;2;0;13;13m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m        \e[48;2;0;4;4m  \e[48;2;0;27;27m    \e[48;2;0;35;35m  \e[48;2;0;117;117m            \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m    \e[48;2;230;230;230m  \e[48;2;204;204;204m            \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;0;74;74m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;35;35m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;126;126m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C\e[48;2;0;143;143m  \e[48;2;0;134;134m  \e[48;2;0;120;120m  \e[48;2;0;117;117m    \e[48;2;0;59;59m  \e[48;2;0;0;0m                          \e[48;2;0;27;27m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;132;132m  \e[48;2;0;119;119m  \e[48;2;0;117;117m  \e[48;2;0;83;83m  \e[48;2;0;0;0m                          \e[48;2;0;27;27m  \e[48;2;0;117;117m    \e[48;2;0;119;119m  \e[48;2;0;132;132m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m  \e[48;2;0;43;43m  \e[48;2;0;0;0m                        \e[48;2;0;27;27m  \e[48;2;0;117;117m  \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m                        \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[60C\e[48;2;0;135;135m    \e[48;2;0;134;134m  \e[48;2;0;127;127m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m            \e[48;2;0;119;119m  \e[48;2;0;122;122m  \e[48;2;0;127;127m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[64C                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_tresjog() {
    printf("\e[12E");
    printf("\e[64C\e[48;2;0;135;135m  \e[48;2;0;137;137m  \e[48;2;0;135;135m                    \e[48;2;0;137;137m  \e[48;2;0;135;135m  \e[E");
    printf("\e[60C\e[48;2;0;143;143m  \e[48;2;0;135;135m  \e[48;2;0;134;134m  \e[48;2;0;128;128m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m          \e[48;2;0;118;118m  \e[48;2;0;120;120m  \e[48;2;0;122;122m  \e[48;2;0;128;128m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;99;99m  \e[48;2;0;83;83m                \e[48;2;0;91;91m  \e[48;2;0;117;117m    \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m    \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;0;27;27m            \e[48;2;0;20;20m  \e[48;2;0;0;0m  \e[48;2;0;91;91m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;135;135m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;133;133m  \e[48;2;0;119;119m  \e[48;2;0;117;117m    \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m            \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;20;20m  \e[48;2;0;117;117m        \e[48;2;0;119;119m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C  \e[48;2;0;134;134m  \e[48;2;0;121;121m  \e[48;2;0;117;117m    \e[48;2;0;66;67m  \e[48;2;0;13;13m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;59;59m  \e[48;2;0;117;117m        \e[48;2;0;121;121m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;127;127m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m  \e[48;2;176;176;176m  \e[48;2;98;98;98m        \e[48;2;146;146;146m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;4;4m  \e[48;2;0;99;99m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m        \e[48;2;79;79;79m  \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;35;35m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[50C\e[48;2;0;135;135m  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;0;0;0m                  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;119;119m  \e[48;2;0;117;117m        \e[48;2;0;83;83m  \e[48;2;0;0;0m                \e[48;2;79;79;79m  \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m            \e[48;2;0;43;43m  \e[48;2;0;0;0m    \e[48;2;98;98;98m  \e[48;2;161;161;161m        \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m                \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m          \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m    \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m                \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m          \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m                \e[48;2;0;59;59m  \e[48;2;60;60;60m  \e[48;2;98;98;98m        \e[48;2;146;146;146m  \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;0;4;4m  \e[48;2;0;66;67m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;99;99m  \e[48;2;0;83;83m    \e[48;2;0;59;59m  \e[48;2;0;0;0m          \e[48;2;60;60;60m  \e[48;2;176;176;176m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m  \e[48;2;0;83;83m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;118;118m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;0;27;27m  \e[48;2;0;13;13m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;35;35m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;120;120m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m        \e[48;2;98;98;98m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;60;60;60m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;204;204;204m        \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;79;79;79m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;66;67m  \e[48;2;0;0;0m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m            \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m    \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;126;126m  \e[48;2;0;117;117m        \e[48;2;0;27;27m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m            \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C\e[48;2;0;143;143m  \e[48;2;0;134;134m  \e[48;2;0;120;120m  \e[48;2;0;117;117m      \e[48;2;0;99;99m  \e[48;2;0;4;4m  \e[48;2;0;0;0m                    \e[48;2;0;13;13m  \e[48;2;0;66;67m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;132;132m  \e[48;2;0;119;119m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;0;0;0m                  \e[48;2;0;4;4m  \e[48;2;0;50;50m  \e[48;2;0;117;117m      \e[48;2;0;119;119m  \e[48;2;0;132;132m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m      \e[48;2;0;27;27m  \e[48;2;0;0;0m                \e[48;2;0;27;27m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m                        \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[60C\e[48;2;0;135;135m    \e[48;2;0;134;134m  \e[48;2;0;127;127m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m            \e[48;2;0;119;119m  \e[48;2;0;122;122m  \e[48;2;0;127;127m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[64C                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_quatrojog() {
    printf("\e[12E");
    printf("\e[64C\e[48;2;0;135;135m  \e[48;2;0;137;137m  \e[48;2;0;135;135m                    \e[48;2;0;137;137m  \e[48;2;0;135;135m  \e[E");
    printf("\e[60C\e[48;2;0;143;143m  \e[48;2;0;135;135m  \e[48;2;0;134;134m  \e[48;2;0;128;128m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m          \e[48;2;0;118;118m  \e[48;2;0;120;120m  \e[48;2;0;122;122m  \e[48;2;0;128;128m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m        \e[48;2;0;99;99m  \e[48;2;0;83;83m        \e[48;2;0;91;91m  \e[48;2;0;117;117m    \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m            \e[48;2;0;59;59m  \e[48;2;0;4;4m  \e[48;2;0;27;27m    \e[48;2;0;20;20m  \e[48;2;0;0;0m  \e[48;2;0;108;108m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;135;135m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;133;133m  \e[48;2;0;119;119m  \e[48;2;0;117;117m            \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;98;98;98m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;59;59m  \e[48;2;0;117;117m        \e[48;2;0;119;119m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C  \e[48;2;0;134;134m  \e[48;2;0;121;121m  \e[48;2;0;117;117m            \e[48;2;0;66;67m  \e[48;2;0;13;13m  \e[48;2;161;161;161m  \e[48;2;255;255;255m      \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;121;121m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;127;127m  \e[48;2;0;117;117m            \e[48;2;0;83;83m  \e[48;2;0;27;27m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m      \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m            \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[50C\e[48;2;0;135;135m  \e[48;2;0;127;127m  \e[48;2;0;117;117m            \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m              \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m          \e[48;2;0;66;67m  \e[48;2;0;13;13m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m              \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;119;119m  \e[48;2;0;117;117m        \e[48;2;0;83;83m  \e[48;2;0;27;27m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m  \e[48;2;176;176;176m  \e[48;2;60;60;60m  \e[48;2;0;0;0m  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m              \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;27;27m  \e[48;2;204;204;204m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;98;98;98m  \e[48;2;0;0;0m    \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m                \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;0;0m      \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m                \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m        \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m    \e[48;2;0;4;4m  \e[48;2;0;117;117m              \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;204;204;204m        \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;204;204;204m  \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;0;66;67m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;118;118m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;131;131;131m  \e[48;2;204;204;204m            \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;204;204;204m  \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;120;120m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;0;0;0m              \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;99;99m  \e[48;2;0;4;4m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;127;127m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;27;27m          \e[48;2;0;13;13m  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;4;4m  \e[48;2;0;27;27m  \e[48;2;0;50;50m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m                    \e[48;2;0;59;59m  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;126;126m  \e[48;2;0;117;117m                    \e[48;2;0;59;59m  \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C\e[48;2;0;143;143m  \e[48;2;0;134;134m  \e[48;2;0;120;120m  \e[48;2;0;117;117m                  \e[48;2;0;59;59m  \e[48;2;0;0;0m        \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;120;120m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;132;132m  \e[48;2;0;119;119m  \e[48;2;0;117;117m                \e[48;2;0;99;99m  \e[48;2;0;0;0m        \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;119;119m  \e[48;2;0;132;132m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m                \e[48;2;0;59;59m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m                        \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[60C\e[48;2;0;135;135m    \e[48;2;0;134;134m  \e[48;2;0;127;127m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m            \e[48;2;0;119;119m  \e[48;2;0;122;122m  \e[48;2;0;127;127m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[64C                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cincojog() {
    printf("\e[12E");
    printf("\e[64C\e[48;2;0;135;135m  \e[48;2;0;137;137m  \e[48;2;0;135;135m                    \e[48;2;0;137;137m  \e[48;2;0;135;135m  \e[E");
    printf("\e[60C\e[48;2;0;143;143m  \e[48;2;0;135;135m  \e[48;2;0;134;134m  \e[48;2;0;128;128m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m          \e[48;2;0;118;118m  \e[48;2;0;120;120m  \e[48;2;0;122;122m  \e[48;2;0;128;128m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;107;108m  \e[48;2;0;83;83m                        \e[48;2;0;91;91m  \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;0;27;27m                    \e[48;2;0;20;20m  \e[48;2;0;0;0m  \e[48;2;0;99;99m  \e[48;2;0;117;117m  \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;135;135m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;133;133m  \e[48;2;0;119;119m  \e[48;2;0;117;117m  \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;43;43m  \e[48;2;0;117;117m    \e[48;2;0;119;119m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C  \e[48;2;0;134;134m  \e[48;2;0;121;121m  \e[48;2;0;117;117m    \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m      \e[48;2;0;121;121m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;127;127m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;176;176;176m  \e[48;2;98;98;98m                \e[48;2;79;79;79m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m                    \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[50C\e[48;2;0;135;135m  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m                    \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m              \e[48;2;0;4;4m  \e[48;2;0;59;59m    \e[48;2;0;66;67m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;119;119m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;204;204;204m            \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;0;74;74m  \e[48;2;0;117;117m              \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;98;98;98m  \e[48;2;204;204;204m  \e[48;2;255;255;255m              \e[48;2;230;230;230m  \e[48;2;131;131;131m  \e[48;2;0;4;4m  \e[48;2;0;108;108m  \e[48;2;0;117;117m              \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;131;131;131m  \e[48;2;204;204;204m            \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;0;20;20m  \e[48;2;0;35;35m  \e[48;2;0;117;117m              \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m            \e[48;2;0;13;13m  \e[48;2;0;0;0m              \e[48;2;98;98;98m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;74;74m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m            \e[48;2;0;83;83m  \e[48;2;0;0;0m              \e[48;2;36;36;36m  \e[48;2;146;146;146m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;99;99m  \e[48;2;0;83;83m  \e[48;2;0;20;20m  \e[48;2;0;0;0m              \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;118;118m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;0;27;27m  \e[48;2;0;13;13m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;120;120m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m        \e[48;2;98;98;98m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;204;204;204m        \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;79;79;79m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;66;67m  \e[48;2;0;0;0m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m            \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m    \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;126;126m  \e[48;2;0;117;117m        \e[48;2;0;27;27m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m            \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C\e[48;2;0;143;143m  \e[48;2;0;134;134m  \e[48;2;0;120;120m  \e[48;2;0;117;117m      \e[48;2;0;99;99m  \e[48;2;0;4;4m  \e[48;2;0;0;0m                    \e[48;2;0;13;13m  \e[48;2;0;66;67m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;132;132m  \e[48;2;0;119;119m  \e[48;2;0;117;117m      \e[48;2;0;66;67m  \e[48;2;0;0;0m                  \e[48;2;0;4;4m  \e[48;2;0;50;50m  \e[48;2;0;117;117m      \e[48;2;0;119;119m  \e[48;2;0;132;132m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m      \e[48;2;0;35;35m  \e[48;2;0;0;0m                \e[48;2;0;27;27m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m                        \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[60C\e[48;2;0;135;135m    \e[48;2;0;134;134m  \e[48;2;0;127;127m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m            \e[48;2;0;119;119m  \e[48;2;0;122;122m  \e[48;2;0;127;127m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[64C                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_seisjog() {
    printf("\e[12E");
    printf("\e[64C\e[48;2;0;135;135m  \e[48;2;0;137;137m  \e[48;2;0;135;135m                    \e[48;2;0;137;137m  \e[48;2;0;135;135m  \e[E");
    printf("\e[60C\e[48;2;0;143;143m  \e[48;2;0;135;135m  \e[48;2;0;134;134m  \e[48;2;0;128;128m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m          \e[48;2;0;118;118m  \e[48;2;0;120;120m  \e[48;2;0;122;122m  \e[48;2;0;128;128m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;99;99m  \e[48;2;0;83;83m          \e[48;2;0;91;91m  \e[48;2;0;117;117m    \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;0;27;27m      \e[48;2;0;20;20m  \e[48;2;0;0;0m  \e[48;2;0;108;108m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;135;135m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;133;133m  \e[48;2;0;119;119m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m      \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;59;59m  \e[48;2;0;117;117m        \e[48;2;0;119;119m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C  \e[48;2;0;134;134m  \e[48;2;0;121;121m  \e[48;2;0;117;117m          \e[48;2;0;66;67m  \e[48;2;0;13;13m  \e[48;2;161;161;161m  \e[48;2;255;255;255m        \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;121;121m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;127;127m  \e[48;2;0;117;117m          \e[48;2;0;83;83m  \e[48;2;0;27;27m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;98;98;98m    \e[48;2;79;79;79m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;60;60;60m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;161;161;161m  \e[48;2;0;0;0m        \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[50C\e[48;2;0;135;135m  \e[48;2;0;127;127m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m          \e[48;2;0;27;27m  \e[48;2;0;117;117m              \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m      \e[48;2;0;13;13m  \e[48;2;0;59;59m    \e[48;2;0;66;67m  \e[48;2;0;117;117m              \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;119;119m  \e[48;2;0;117;117m        \e[48;2;0;83;83m  \e[48;2;0;27;27m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;176;176;176m  \e[48;2;60;60;60m  \e[48;2;0;0;0m      \e[48;2;0;13;13m  \e[48;2;0;59;59m    \e[48;2;0;117;117m                \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;98;98;98m  \e[48;2;204;204;204m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;161;161;161m          \e[48;2;131;131;131m  \e[48;2;0;0;0m  \e[48;2;0;74;74m  \e[48;2;0;117;117m                \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                \e[48;2;217;217;217m  \e[48;2;0;20;20m  \e[48;2;0;13;13m  \e[48;2;0;108;108m  \e[48;2;0;117;117m              \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m                  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;50;50m  \e[48;2;0;117;117m              \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;176;176;176m  \e[48;2;98;98;98m        \e[48;2;146;146;146m  \e[48;2;255;255;255m  \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m  \e[48;2;0;83;83m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;117;117m          \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;98;98;98m  \e[48;2;0;0;0m        \e[48;2;60;60;60m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;35;35m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;118;118m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m            \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;120;120m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m  \e[48;2;161;161;161m  \e[48;2;0;0;0m            \e[48;2;98;98;98m  \e[48;2;255;255;255m  \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;119;119m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;136;136m  \e[48;2;0;122;122m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;161;161;161m  \e[48;2;255;255;255m    \e[48;2;161;161;161m  \e[48;2;0;0;0m        \e[48;2;98;98;98m  \e[48;2;255;255;255m    \e[48;2;204;204;204m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;122;122m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C  \e[48;2;0;127;127m  \e[48;2;0;117;117m        \e[48;2;0;59;59m  \e[48;2;0;13;13m  \e[48;2;176;176;176m  \e[48;2;255;255;255m  \e[48;2;230;230;230m  \e[48;2;204;204;204m        \e[48;2;217;217;217m  \e[48;2;255;255;255m  \e[48;2;217;217;217m  \e[48;2;79;79;79m  \e[48;2;0;0;0m  \e[48;2;0;27;27m  \e[48;2;0;117;117m          \e[48;2;0;127;127m  \e[48;2;0;135;135m  \e[E");
    printf("\e[50C\e[48;2;0;141;141m  \e[48;2;0;134;134m  \e[48;2;0;118;118m  \e[48;2;0;117;117m      \e[48;2;0;66;67m  \e[48;2;0;0;0m  \e[48;2;131;131;131m  \e[48;2;230;230;230m  \e[48;2;255;255;255m            \e[48;2;243;243;243m  \e[48;2;161;161;161m  \e[48;2;0;0;0m    \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;118;118m  \e[48;2;0;134;134m  \e[48;2;0;141;141m  \e[E");
    printf("\e[52C\e[48;2;0;136;136m  \e[48;2;0;126;126m  \e[48;2;0;117;117m        \e[48;2;0;27;27m  \e[48;2;0;0;0m  \e[48;2;161;161;161m  \e[48;2;255;255;255m            \e[48;2;204;204;204m  \e[48;2;0;0;0m      \e[48;2;0;27;27m  \e[48;2;0;117;117m        \e[48;2;0;126;126m  \e[48;2;0;136;136m  \e[E");
    printf("\e[52C\e[48;2;0;143;143m  \e[48;2;0;134;134m  \e[48;2;0;120;120m  \e[48;2;0;117;117m      \e[48;2;0;99;99m  \e[48;2;0;4;4m  \e[48;2;0;0;0m                    \e[48;2;0;13;13m  \e[48;2;0;66;67m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;134;134m  \e[48;2;0;143;143m  \e[E");
    printf("\e[54C\e[48;2;0;136;136m  \e[48;2;0;132;132m  \e[48;2;0;119;119m  \e[48;2;0;117;117m      \e[48;2;0;66;67m  \e[48;2;0;0;0m                  \e[48;2;0;4;4m  \e[48;2;0;50;50m  \e[48;2;0;117;117m      \e[48;2;0;119;119m  \e[48;2;0;132;132m  \e[48;2;0;137;137m  \e[E");
    printf("\e[56C\e[48;2;0;135;135m  \e[48;2;0;133;133m  \e[48;2;0;120;120m  \e[48;2;0;117;117m      \e[48;2;0;35;35m  \e[48;2;0;0;0m                \e[48;2;0;27;27m  \e[48;2;0;117;117m      \e[48;2;0;120;120m  \e[48;2;0;133;133m  \e[48;2;0;136;136m  \e[E");
    printf("\e[58C\e[48;2;0;137;137m  \e[48;2;0;134;134m  \e[48;2;0;126;126m  \e[48;2;0;118;118m  \e[48;2;0;117;117m                        \e[48;2;0;118;118m  \e[48;2;0;126;126m  \e[48;2;0;134;134m  \e[48;2;0;137;137m  \e[E");
    printf("\e[60C\e[48;2;0;135;135m    \e[48;2;0;134;134m  \e[48;2;0;127;127m  \e[48;2;0;122;122m  \e[48;2;0;119;119m  \e[48;2;0;117;117m            \e[48;2;0;119;119m  \e[48;2;0;122;122m  \e[48;2;0;127;127m  \e[48;2;0;134;134m  \e[48;2;0;135;135m    \e[E");
    printf("\e[64C                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_setasdentro() {
    printf("\e[22E");
    printf("\e[40C\e[48;2;0;35;28m  \e[48;2;207;217;216m  \e[68C  \e[48;2;0;35;28m  \e[E");
    printf("\e[36C  \e[48;2;207;217;216m  \e[48;2;255;255;255m    \e[68C    \e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[E");
    printf("\e[32C  \e[48;2;207;217;216m  \e[48;2;255;255;255m        \e[68C        \e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[E");
    printf("\e[30C  \e[48;2;207;217;216m  \e[48;2;255;255;255m          \e[68C          \e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[E");
    printf("\e[30C  \e[48;2;207;217;216m  \e[48;2;255;255;255m          \e[68C          \e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[E");
    printf("\e[32C  \e[48;2;207;217;216m  \e[48;2;255;255;255m        \e[68C        \e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[E");
    printf("\e[36C  \e[48;2;207;217;216m  \e[48;2;255;255;255m    \e[68C    \e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[E");
    printf("\e[40C  \e[48;2;207;217;216m  \e[68C  \e[48;2;0;35;28m  \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_setasfora() {
    printf("\e[22E");
    printf("\e[40C\e[48;2;207;217;216m  \e[48;2;0;35;28m  \e[68C  \e[48;2;207;217;216m  \e[E");
    printf("\e[36C  \e[48;2;255;255;255m    \e[48;2;0;35;28m  \e[68C  \e[48;2;255;255;255m    \e[48;2;207;217;216m  \e[E");
    printf("\e[32C  \e[48;2;255;255;255m        \e[48;2;0;35;28m  \e[68C  \e[48;2;255;255;255m        \e[48;2;207;217;216m  \e[E");
    printf("\e[30C  \e[48;2;255;255;255m          \e[48;2;0;35;28m  \e[68C  \e[48;2;255;255;255m          \e[48;2;207;217;216m  \e[E");
    printf("\e[30C  \e[48;2;255;255;255m          \e[48;2;0;35;28m  \e[68C  \e[48;2;255;255;255m          \e[48;2;207;217;216m  \e[E");
    printf("\e[32C  \e[48;2;255;255;255m        \e[48;2;0;35;28m  \e[68C  \e[48;2;255;255;255m        \e[48;2;207;217;216m  \e[E");
    printf("\e[36C  \e[48;2;255;255;255m    \e[48;2;0;35;28m  \e[68C  \e[48;2;255;255;255m    \e[48;2;207;217;216m  \e[E");
    printf("\e[40C  \e[48;2;0;35;28m  \e[68C  \e[48;2;207;217;216m  \e[E");
    printf("\e[0m");
    printf("\e[H");
}

/**
 * @brief Desenha um fundo em espiral com cor e tamanho definidos.
 * A cor é passada como um parâmetro para máxima flexibilidade.
 * * @param cor_rgb_string Uma string contendo os valores R, G e B, separados
 * por ponto e vírgula. Exemplo: "17;52;66".
 */
void desenhar_fundo_espiral_com_cor(const char* cor_rgb_string) {
    int tempo=0;
    // Usamos as dimensões fixas definidas
    int rows = TERMINAL_ALTURA;
    int cols = TERMINAL_LARGURA;

    // --- AQUI ESTÁ A SUA SUGESTÃO EM AÇÃO ---
    // Limpa a tela, move o cursor para o topo, e então CONSTRÓI a
    // sequência de cor usando o parâmetro recebido.
    printf("\e[H\e[48;2;%sm", cor_rgb_string);
    fflush(stdout); // Garante que a cor seja aplicada imediatamente

    // A lógica da espiral continua exatamente a mesma.
    // Ela apenas desenha "blocos" de espaço, que usarão a cor de fundo
    // que acabamos de definir.
    int topo = 1, base = rows;
    int esquerda = 1, direita = cols;
    int i;

    while (topo <= base && esquerda <= direita) {
        // 1. Pinta a linha do topo
        for (i = esquerda; i <= direita; ++i) {
            printf("\e[%d;%dH ", topo, i); // Move o cursor e imprime um espaço
            fflush(stdout);
            Sleep(tempo); // Ajuste o delay para a velocidade desejada
        }
        topo++;

        // 2. Pinta a coluna da direita
        for (i = topo; i <= base; ++i) {
            printf("\e[%d;%dH ", i, direita);
            fflush(stdout);
            Sleep(tempo);
        }
        direita--;

        // 3. Pinta a linha da base
        if (topo <= base) {
            for (i = direita; i >= esquerda; --i) {
                printf("\e[%d;%dH ", base, i);
                fflush(stdout);
                Sleep(tempo);
            }
            base--;
        }

        // 4. Pinta a coluna da esquerda
        if (esquerda <= direita) {
            for (i = base; i >= topo; --i) {
                printf("\e[%d;%dH ", i, esquerda);
                fflush(stdout);
                Sleep(tempo);
            }
            esquerda++;
        }
    }

    // Reseta toda a formatação e posiciona o cursor para o próximo comando
    printf("\e[0m\e[H");
    fflush(stdout);
}

void desenhar_cartaursocoroa() {
    printf("\e[23E");
    printf("\e[96C\e[48;2;70;49;26m      \e[48;2;255;189;0m  \e[48;2;70;49;26m  \e[48;2;255;189;0m    \e[48;2;70;49;26m  \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[96C    \e[48;2;121;66;53m  \e[48;2;255;235;33m  \e[48;2;255;189;0m        \e[48;2;255;235;33m  \e[48;2;121;66;53m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m  \e[48;2;255;145;0m    \e[48;2;255;58;43m    \e[48;2;255;145;0m    \e[48;2;121;66;53m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C      \e[48;2;121;66;53m  \e[48;2;22;22;22m  \e[48;2;121;66;53m    \e[48;2;22;22;22m  \e[48;2;121;66;53m  \e[48;2;70;49;26m      \e[E");
    printf("\e[96C    \e[48;2;121;66;53m    \e[48;2;0;0;0m  \e[48;2;121;66;53m    \e[48;2;0;0;0m  \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m    \e[48;2;135;75;61m  \e[48;2;0;0;0m    \e[48;2;135;75;61m  \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m    \e[48;2;135;75;61m        \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C\e[48;2;83;62;37m                        \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaursodesistido() {
    printf("\e[23E");
    printf("\e[96C\e[48;2;78;50;42m                        \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m      \e[48;2;46;46;46m    \e[48;2;82;82;82m      \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m  \e[48;2;201;201;201m  \e[48;2;82;82;82m  \e[48;2;46;46;46m    \e[48;2;82;82;82m  \e[48;2;201;201;201m  \e[48;2;82;82;82m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m                \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m    \e[48;2;82;82;82m  \e[48;2;22;22;22m  \e[48;2;82;82;82m    \e[48;2;22;22;22m  \e[48;2;82;82;82m  \e[48;2;46;46;46m    \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m    \e[48;2;0;0;0m  \e[48;2;82;82;82m    \e[48;2;0;0;0m  \e[48;2;82;82;82m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m                \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m    \e[48;2;92;92;92m  \e[48;2;0;0;0m    \e[48;2;92;92;92m  \e[48;2;82;82;82m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;82;82;82m    \e[48;2;92;92;92m        \e[48;2;82;82;82m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaursoausente() {
    printf("\e[23E");
    printf("\e[96C\e[48;2;46;46;46m                        \e[E");
    printf("\e[96C    \e[48;2;82;82;82m      \e[48;2;46;46;46m    \e[48;2;82;82;82m      \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;82;82;82m  \e[48;2;201;201;201m  \e[48;2;82;82;82m  \e[48;2;46;46;46m    \e[48;2;82;82;82m  \e[48;2;201;201;201m  \e[48;2;82;82;82m  \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;82;82;82m                \e[48;2;46;46;46m    \e[E");
    printf("\e[96C      \e[48;2;82;82;82m  \e[48;2;22;22;22m  \e[48;2;82;82;82m    \e[48;2;22;22;22m  \e[48;2;82;82;82m  \e[48;2;46;46;46m      \e[E");
    printf("\e[96C    \e[48;2;82;82;82m    \e[48;2;0;0;0m  \e[48;2;82;82;82m    \e[48;2;0;0;0m  \e[48;2;82;82;82m    \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;82;82;82m                \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;82;82;82m    \e[48;2;92;92;92m  \e[48;2;0;0;0m    \e[48;2;92;92;92m  \e[48;2;82;82;82m    \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;82;82;82m    \e[48;2;92;92;92m        \e[48;2;82;82;82m    \e[48;2;46;46;46m    \e[E");
    printf("\e[96C\e[48;2;58;58;58m                        \e[E");
    printf("\e[96C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;204;204;204m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;164;164;164m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaurso() {
    printf("\e[23E");
    printf("\e[96C\e[48;2;70;49;26m                        \e[E");
    printf("\e[96C    \e[48;2;121;66;53m      \e[48;2;70;49;26m    \e[48;2;121;66;53m      \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m  \e[48;2;255;147;147m  \e[48;2;121;66;53m  \e[48;2;70;49;26m    \e[48;2;121;66;53m  \e[48;2;255;147;147m  \e[48;2;121;66;53m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C      \e[48;2;121;66;53m  \e[48;2;22;22;22m  \e[48;2;121;66;53m    \e[48;2;22;22;22m  \e[48;2;121;66;53m  \e[48;2;70;49;26m      \e[E");
    printf("\e[96C    \e[48;2;121;66;53m    \e[48;2;0;0;0m  \e[48;2;121;66;53m    \e[48;2;0;0;0m  \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m    \e[48;2;135;75;61m  \e[48;2;0;0;0m    \e[48;2;135;75;61m  \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;121;66;53m    \e[48;2;135;75;61m        \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C\e[48;2;83;62;37m                        \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaratocoroa() {
    printf("\e[23E");
    printf("\e[66C\e[48;2;70;49;26m      \e[48;2;255;189;0m  \e[48;2;70;49;26m  \e[48;2;255;189;0m    \e[48;2;70;49;26m  \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[66C      \e[48;2;255;235;33m  \e[48;2;255;189;0m        \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[66C    \e[48;2;151;151;151m  \e[48;2;255;145;0m    \e[48;2;255;58;43m    \e[48;2;255;145;0m    \e[48;2;151;151;151m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m  \e[48;2;255;200;206m  \e[48;2;151;151;151m        \e[48;2;255;200;206m  \e[48;2;151;151;151m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m                \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m      \e[48;2;255;146;146m    \e[48;2;151;151;151m      \e[48;2;70;49;26m    \e[E");
    printf("\e[66C      \e[48;2;151;151;151m            \e[48;2;70;49;26m      \e[E");
    printf("\e[66C        \e[48;2;151;151;151m        \e[48;2;70;49;26m        \e[E");
    printf("\e[66C\e[48;2;83;62;37m                        \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaratodesistido() {
    printf("\e[23E");
    printf("\e[66C\e[48;2;78;50;42m                        \e[E");
    printf("\e[66C  \e[48;2;46;46;46m    \e[48;2;151;151;151m  \e[48;2;46;46;46m        \e[48;2;151;151;151m  \e[48;2;46;46;46m    \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;151;151;151m  \e[48;2;228;228;228m  \e[48;2;151;151;151m  \e[48;2;46;46;46m    \e[48;2;151;151;151m  \e[48;2;228;228;228m  \e[48;2;151;151;151m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;151;151;151m  \e[48;2;228;228;228m  \e[48;2;151;151;151m        \e[48;2;228;228;228m  \e[48;2;151;151;151m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;151;151;151m                \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;151;151;151m      \e[48;2;191;191;191m    \e[48;2;151;151;151m      \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m    \e[48;2;151;151;151m            \e[48;2;46;46;46m    \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m      \e[48;2;151;151;151m        \e[48;2;46;46;46m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaratoausente() {
    printf("\e[23E");
    printf("\e[66C\e[48;2;46;46;46m                        \e[E");
    printf("\e[66C      \e[48;2;151;151;151m  \e[48;2;46;46;46m        \e[48;2;151;151;151m  \e[48;2;46;46;46m      \e[E");
    printf("\e[66C    \e[48;2;151;151;151m  \e[48;2;228;228;228m  \e[48;2;151;151;151m  \e[48;2;46;46;46m    \e[48;2;151;151;151m  \e[48;2;228;228;228m  \e[48;2;151;151;151m  \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m  \e[48;2;228;228;228m  \e[48;2;151;151;151m        \e[48;2;228;228;228m  \e[48;2;151;151;151m  \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m                \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m      \e[48;2;191;191;191m    \e[48;2;151;151;151m      \e[48;2;46;46;46m    \e[E");
    printf("\e[66C      \e[48;2;151;151;151m            \e[48;2;46;46;46m      \e[E");
    printf("\e[66C        \e[48;2;151;151;151m        \e[48;2;46;46;46m        \e[E");
    printf("\e[66C\e[48;2;58;58;58m                        \e[E");
    printf("\e[66C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;204;204;204m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;164;164;164m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartarato() {
    printf("\e[23E");
    printf("\e[66C\e[48;2;70;49;26m                        \e[E");
    printf("\e[66C      \e[48;2;151;151;151m  \e[48;2;70;49;26m        \e[48;2;151;151;151m  \e[48;2;70;49;26m      \e[E");
    printf("\e[66C    \e[48;2;151;151;151m  \e[48;2;255;200;206m  \e[48;2;151;151;151m  \e[48;2;70;49;26m    \e[48;2;151;151;151m  \e[48;2;255;200;206m  \e[48;2;151;151;151m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m  \e[48;2;255;200;206m  \e[48;2;151;151;151m        \e[48;2;255;200;206m  \e[48;2;151;151;151m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m                \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;0;0;0m  \e[48;2;151;151;151m    \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;151;151;151m      \e[48;2;255;146;146m    \e[48;2;151;151;151m      \e[48;2;70;49;26m    \e[E");
    printf("\e[66C      \e[48;2;151;151;151m            \e[48;2;70;49;26m      \e[E");
    printf("\e[66C        \e[48;2;151;151;151m        \e[48;2;70;49;26m        \e[E");
    printf("\e[66C\e[48;2;83;62;37m                        \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaesquilocoroa() {
    printf("\e[22E");
    printf("\e[40C\e[48;2;255;189;0m  \e[2C    \e[2C\e[48;2;255;235;33m  \e[E");
    printf("\e[34C\e[48;2;70;49;26m      \e[48;2;255;235;33m  \e[48;2;255;189;0m        \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[34C    \e[48;2;83;42;35m  \e[48;2;255;145;0m    \e[48;2;255;58;43m    \e[48;2;255;145;0m    \e[48;2;83;42;35m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;202;207m  \e[48;2;83;42;35m  \e[48;2;121;66;53m        \e[48;2;83;42;35m  \e[48;2;255;202;207m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;207;111m    \e[48;2;121;66;53m        \e[48;2;255;207;111m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;255;202;112m  \e[48;2;121;66;53m    \e[48;2;255;207;111m  \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;255;207;111m  \e[48;2;155;101;88m    \e[48;2;255;207;111m  \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;202;112m  \e[48;2;255;207;111m  \e[48;2;121;66;53m  \e[48;2;0;0;0m    \e[48;2;121;66;53m  \e[48;2;255;202;112m  \e[48;2;255;207;111m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;121;66;53m    \e[48;2;155;101;88m  \e[48;2;255;255;255m    \e[48;2;155;101;88m  \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;121;66;53m  \e[48;2;155;101;88m            \e[48;2;121;66;53m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C\e[48;2;83;62;37m                        \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaesquilodesistido() {
    printf("\e[23E");
    printf("\e[34C\e[48;2;78;50;42m                        \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;55;55;55m    \e[48;2;46;46;46m        \e[48;2;55;55;55m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;228;228;228m  \e[48;2;55;55;55m  \e[48;2;82;82;82m        \e[48;2;55;55;55m  \e[48;2;228;228;228m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;183;183;183m    \e[48;2;82;82;82m        \e[48;2;183;183;183m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;183;183;183m  \e[48;2;82;82;82m    \e[48;2;183;183;183m  \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;183;183;183m  \e[48;2;116;116;116m    \e[48;2;183;183;183m  \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;183;183;183m    \e[48;2;82;82;82m  \e[48;2;0;0;0m    \e[48;2;82;82;82m  \e[48;2;183;183;183m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;82;82;82m    \e[48;2;116;116;116m  \e[48;2;255;255;255m    \e[48;2;116;116;116m  \e[48;2;82;82;82m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;82;82;82m  \e[48;2;116;116;116m            \e[48;2;82;82;82m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaesquiloausente() {
    printf("\e[23E");
    printf("\e[34C\e[48;2;46;46;46m                        \e[E");
    printf("\e[34C    \e[48;2;55;55;55m    \e[48;2;46;46;46m        \e[48;2;55;55;55m    \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;228;228;228m  \e[48;2;55;55;55m  \e[48;2;82;82;82m        \e[48;2;55;55;55m  \e[48;2;228;228;228m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;183;183;183m    \e[48;2;82;82;82m        \e[48;2;183;183;183m    \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;183;183;183m  \e[48;2;82;82;82m    \e[48;2;183;183;183m  \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;183;183;183m  \e[48;2;116;116;116m    \e[48;2;183;183;183m  \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;183;183;183m    \e[48;2;82;82;82m  \e[48;2;0;0;0m    \e[48;2;82;82;82m  \e[48;2;183;183;183m    \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;82;82;82m    \e[48;2;116;116;116m  \e[48;2;255;255;255m    \e[48;2;116;116;116m  \e[48;2;82;82;82m    \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;82;82;82m  \e[48;2;116;116;116m            \e[48;2;82;82;82m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C\e[48;2;58;58;58m                        \e[E");
    printf("\e[34C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;204;204;204m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;164;164;164m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartaesquilo() {
    printf("\e[23E");
    printf("\e[34C\e[48;2;70;49;26m                        \e[E");
    printf("\e[34C    \e[48;2;83;42;35m    \e[48;2;70;49;26m        \e[48;2;83;42;35m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;202;207m  \e[48;2;83;42;35m  \e[48;2;121;66;53m        \e[48;2;83;42;35m  \e[48;2;255;202;207m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;207;111m    \e[48;2;121;66;53m        \e[48;2;255;207;111m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;255;202;112m  \e[48;2;121;66;53m    \e[48;2;255;207;111m  \e[48;2;22;22;22m  \e[48;2;88;88;88m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;255;207;111m  \e[48;2;155;101;88m    \e[48;2;255;207;111m  \e[48;2;88;88;88m  \e[48;2;22;22;22m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;202;112m  \e[48;2;255;207;111m  \e[48;2;121;66;53m  \e[48;2;0;0;0m    \e[48;2;121;66;53m  \e[48;2;255;202;112m  \e[48;2;255;207;111m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;121;66;53m    \e[48;2;155;101;88m  \e[48;2;255;255;255m    \e[48;2;155;101;88m  \e[48;2;121;66;53m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;121;66;53m  \e[48;2;155;101;88m            \e[48;2;121;66;53m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C\e[48;2;83;62;37m                        \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartasapocoroa() {
    printf("\e[3E");
    printf("\e[102C\e[48;2;255;189;0m  \e[2C    \e[2C\e[48;2;255;235;33m  \e[E");
    printf("\e[102C  \e[48;2;255;189;0m        \e[48;2;255;235;33m  \e[E");
    printf("\e[96C\e[48;2;70;49;26m      \e[48;2;255;145;0m    \e[48;2;255;58;43m    \e[48;2;255;145;0m    \e[48;2;70;49;26m      \e[E");
    printf("\e[96C      \e[48;2;0;135;48m      \e[48;2;70;49;26m  \e[48;2;0;135;48m    \e[48;2;0;117;39m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C      \e[48;2;0;135;48m  \e[48;2;0;0;0m  \e[48;2;0;135;48m  \e[48;2;70;49;26m  \e[48;2;0;135;48m  \e[48;2;0;0;0m  \e[48;2;0;135;48m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m    \e[48;2;0;86;23m            \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m            \e[48;2;0;117;39m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;154;59m  \e[48;2;0;135;48m            \e[48;2;0;117;39m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;154;59m    \e[48;2;70;49;26m  \e[48;2;0;135;48m      \e[48;2;70;49;26m  \e[48;2;0;117;39m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C\e[48;2;83;62;37m                        \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartasapodesistido() {
    printf("\e[5E");
    printf("\e[96C\e[48;2;78;50;42m                        \e[E");
    printf("\e[96C  \e[48;2;46;46;46m    \e[48;2;90;90;90m      \e[48;2;46;46;46m  \e[48;2;90;90;90m    \e[48;2;76;76;76m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m    \e[48;2;90;90;90m  \e[48;2;0;0;0m  \e[48;2;90;90;90m  \e[48;2;46;46;46m  \e[48;2;90;90;90m  \e[48;2;0;0;0m  \e[48;2;90;90;90m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;90;90;90m                \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;90;90;90m    \e[48;2;52;52;52m            \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;90;90;90m                \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;90;90;90m            \e[48;2;76;76;76m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;104;104;104m  \e[48;2;90;90;90m            \e[48;2;76;76;76m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;46;46;46m  \e[48;2;104;104;104m    \e[48;2;46;46;46m  \e[48;2;90;90;90m      \e[48;2;46;46;46m  \e[48;2;76;76;76m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[96C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartasapoausente() {
    printf("\e[5E");
    printf("\e[96C\e[48;2;46;46;46m                        \e[E");
    printf("\e[96C      \e[48;2;90;90;90m      \e[48;2;46;46;46m  \e[48;2;90;90;90m    \e[48;2;76;76;76m  \e[48;2;46;46;46m    \e[E");
    printf("\e[96C      \e[48;2;90;90;90m  \e[48;2;0;0;0m  \e[48;2;90;90;90m  \e[48;2;46;46;46m  \e[48;2;90;90;90m  \e[48;2;0;0;0m  \e[48;2;90;90;90m  \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;90;90;90m                \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;90;90;90m    \e[48;2;52;52;52m            \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;90;90;90m                \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;90;90;90m            \e[48;2;76;76;76m    \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;104;104;104m  \e[48;2;90;90;90m            \e[48;2;76;76;76m  \e[48;2;46;46;46m    \e[E");
    printf("\e[96C    \e[48;2;104;104;104m    \e[48;2;46;46;46m  \e[48;2;90;90;90m      \e[48;2;46;46;46m  \e[48;2;76;76;76m  \e[48;2;46;46;46m    \e[E");
    printf("\e[96C\e[48;2;58;58;58m                        \e[E");
    printf("\e[96C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;204;204;204m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;164;164;164m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartasapo() {
    printf("\e[5E");
    printf("\e[96C\e[48;2;70;49;26m                        \e[E");
    printf("\e[96C      \e[48;2;0;135;48m      \e[48;2;70;49;26m  \e[48;2;0;135;48m    \e[48;2;0;117;39m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C      \e[48;2;0;135;48m  \e[48;2;0;0;0m  \e[48;2;0;135;48m  \e[48;2;70;49;26m  \e[48;2;0;135;48m  \e[48;2;0;0;0m  \e[48;2;0;135;48m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m    \e[48;2;0;86;23m            \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m                \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;135;48m            \e[48;2;0;117;39m    \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;154;59m  \e[48;2;0;135;48m            \e[48;2;0;117;39m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C    \e[48;2;0;154;59m    \e[48;2;70;49;26m  \e[48;2;0;135;48m      \e[48;2;70;49;26m  \e[48;2;0;117;39m  \e[48;2;70;49;26m    \e[E");
    printf("\e[96C\e[48;2;83;62;37m                        \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[96C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartacoelhocoroa() {
    printf("\e[4E");
    printf("\e[72C\e[48;2;255;189;0m  \e[2C    \e[2C\e[48;2;255;235;33m  \e[E");
    printf("\e[66C\e[48;2;70;49;26m      \e[48;2;255;235;33m  \e[48;2;255;189;0m        \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[66C    \e[48;2;0;0;0m  \e[48;2;255;145;0m    \e[48;2;255;58;43m    \e[48;2;255;145;0m    \e[48;2;70;49;26m      \e[E");
    printf("\e[66C    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;70;49;26m  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m  \e[48;2;0;0;0m  \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m  \e[48;2;0;0;0m  \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m        \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;182;206m  \e[48;2;255;255;255m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m      \e[48;2;255;107;106m  \e[48;2;255;255;255m    \e[48;2;255;182;206m    \e[48;2;70;49;26m    \e[E");
    printf("\e[66C\e[48;2;83;62;37m                        \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartacoelhodesistido() {
    printf("\e[5E");
    printf("\e[66C\e[48;2;78;50;42m                        \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;0;0;0m    \e[48;2;46;46;46m      \e[48;2;0;0;0m    \e[48;2;46;46;46m    \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m        \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;218;218;218m  \e[48;2;255;255;255m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;46;46;46m  \e[48;2;255;255;255m      \e[48;2;179;179;179m  \e[48;2;255;255;255m    \e[48;2;218;218;218m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[66C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartacoelhoausente() {
    printf("\e[5E");
    printf("\e[66C\e[48;2;46;46;46m                        \e[E");
    printf("\e[66C    \e[48;2;0;0;0m    \e[48;2;46;46;46m      \e[48;2;0;0;0m    \e[48;2;46;46;46m      \e[E");
    printf("\e[66C    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;201;201;201m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m        \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;218;218;218m  \e[48;2;255;255;255m  \e[48;2;46;46;46m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m      \e[48;2;179;179;179m  \e[48;2;255;255;255m    \e[48;2;218;218;218m    \e[48;2;46;46;46m    \e[E");
    printf("\e[66C\e[48;2;58;58;58m                        \e[E");
    printf("\e[66C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;204;204;204m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;164;164;164m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartacoelho() {
    printf("\e[5E");
    printf("\e[66C\e[48;2;70;49;26m                        \e[E");
    printf("\e[66C    \e[48;2;0;0;0m    \e[48;2;70;49;26m      \e[48;2;0;0;0m    \e[48;2;70;49;26m      \e[E");
    printf("\e[66C    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;70;49;26m  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m  \e[48;2;0;0;0m  \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m  \e[48;2;0;0;0m  \e[48;2;255;147;147m  \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m        \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m  \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;182;206m  \e[48;2;255;255;255m  \e[48;2;70;49;26m    \e[E");
    printf("\e[66C    \e[48;2;255;255;255m      \e[48;2;255;107;106m  \e[48;2;255;255;255m    \e[48;2;255;182;206m    \e[48;2;70;49;26m    \e[E");
    printf("\e[66C\e[48;2;83;62;37m                        \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[66C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartagatocoroa() {
    printf("\e[5E");
    printf("\e[34C\e[48;2;70;49;26m      \e[48;2;255;189;0m  \e[48;2;70;49;26m  \e[48;2;255;189;0m    \e[48;2;70;49;26m  \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[34C      \e[48;2;255;235;33m  \e[48;2;255;189;0m        \e[48;2;255;235;33m  \e[48;2;70;49;26m      \e[E");
    printf("\e[34C    \e[48;2;255;179;49m  \e[48;2;255;145;0m    \e[48;2;255;58;43m    \e[48;2;255;145;0m    \e[48;2;255;179;49m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;179;49m                \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;0;0;0m  \e[48;2;255;202;112m  \e[48;2;0;0;0m  \e[48;2;255;202;112m    \e[48;2;0;0;0m  \e[48;2;255;202;112m  \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;202;112m        \e[48;2;255;73;68m  \e[48;2;255;202;112m      \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;0;0;0m  \e[48;2;255;202;112m            \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C\e[48;2;83;62;37m                        \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartagatodesistido() {
    printf("\e[5E");
    printf("\e[34C\e[48;2;78;50;42m                        \e[E");
    printf("\e[34C  \e[48;2;46;46;46m    \e[48;2;153;153;153m  \e[48;2;46;46;46m        \e[48;2;153;153;153m  \e[48;2;46;46;46m    \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;153;153;153m  \e[48;2;183;183;183m  \e[48;2;153;153;153m  \e[48;2;46;46;46m    \e[48;2;153;153;153m  \e[48;2;183;183;183m  \e[48;2;153;153;153m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;153;153;153m                \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;183;183;183m  \e[48;2;0;0;0m  \e[48;2;183;183;183m    \e[48;2;0;0;0m  \e[48;2;183;183;183m  \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;183;183;183m        \e[48;2;160;160;160m  \e[48;2;183;183;183m      \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;46;46;46m  \e[48;2;0;0;0m  \e[48;2;183;183;183m            \e[48;2;0;0;0m  \e[48;2;46;46;46m  \e[48;2;78;50;42m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m  \e[48;2;61;36;29m    \e[48;2;182;56;21m  \e[48;2;61;36;29m      \e[48;2;78;50;42m  \e[E");
    printf("\e[34C  \e[48;2;61;36;29m      \e[48;2;182;56;21m      \e[48;2;61;36;29m        \e[48;2;78;50;42m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartagatoausente() {
    printf("\e[5E");
    printf("\e[34C\e[48;2;46;46;46m                        \e[E");
    printf("\e[34C      \e[48;2;153;153;153m  \e[48;2;46;46;46m        \e[48;2;153;153;153m  \e[48;2;46;46;46m      \e[E");
    printf("\e[34C    \e[48;2;153;153;153m  \e[48;2;183;183;183m  \e[48;2;153;153;153m  \e[48;2;46;46;46m    \e[48;2;153;153;153m  \e[48;2;183;183;183m  \e[48;2;153;153;153m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;153;153;153m                \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;0;0;0m  \e[48;2;153;153;153m    \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;0;0;0m  \e[48;2;183;183;183m  \e[48;2;0;0;0m  \e[48;2;183;183;183m    \e[48;2;0;0;0m  \e[48;2;183;183;183m  \e[48;2;0;0;0m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;183;183;183m        \e[48;2;160;160;160m  \e[48;2;183;183;183m      \e[48;2;46;46;46m    \e[E");
    printf("\e[34C    \e[48;2;0;0;0m  \e[48;2;183;183;183m            \e[48;2;0;0;0m  \e[48;2;46;46;46m    \e[E");
    printf("\e[34C\e[48;2;58;58;58m                        \e[E");
    printf("\e[34C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;204;204;204m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;164;164;164m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C  \e[48;2;158;158;158m                    \e[48;2;58;58;58m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_cartagato() {
    printf("\e[5E");
    printf("\e[34C\e[48;2;70;49;26m                        \e[E");
    printf("\e[34C      \e[48;2;255;179;49m  \e[48;2;70;49;26m        \e[48;2;255;179;49m  \e[48;2;70;49;26m      \e[E");
    printf("\e[34C    \e[48;2;255;179;49m  \e[48;2;255;202;112m  \e[48;2;255;179;49m  \e[48;2;70;49;26m    \e[48;2;255;179;49m  \e[48;2;255;202;112m  \e[48;2;255;179;49m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;179;49m                \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;0;0;0m  \e[48;2;255;179;49m    \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;0;0;0m  \e[48;2;255;202;112m  \e[48;2;0;0;0m  \e[48;2;255;202;112m    \e[48;2;0;0;0m  \e[48;2;255;202;112m  \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;255;202;112m        \e[48;2;255;73;68m  \e[48;2;255;202;112m      \e[48;2;70;49;26m    \e[E");
    printf("\e[34C    \e[48;2;0;0;0m  \e[48;2;255;202;112m            \e[48;2;0;0;0m  \e[48;2;70;49;26m    \e[E");
    printf("\e[34C\e[48;2;83;62;37m                        \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;239;208;174m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;255;187;73m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C  \e[48;2;204;164;120m                    \e[48;2;83;62;37m  \e[E");
    printf("\e[34C                        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimbase() {
    printf("\e[48;2;255;191;105m      \e[48;2;232;135;29m        \e[48;2;153;121;87m                                                                                                                                \e[48;2;232;135;29m        \e[48;2;255;191;105m      \e[E");
    printf("  \e[48;2;93;71;45m                                                                                                                                                        \e[48;2;255;191;105m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m                                                                                                                                                    \e[48;2;93;71;45m  \e[48;2;255;191;105m  \e[E");
    printf("\e[48;2;232;135;29m  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("\e[48;2;153;121;87m  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;255;189;0m  \e[48;2;232;135;29m  \e[48;2;72;45;14m                    \e[48;2;232;135;29m  \e[48;2;255;189;0m  \e[48;2;43;33;22m                                                                      \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;232;135;29m  \e[48;2;113;64;1m                        \e[48;2;232;135;29m  \e[48;2;43;33;22m                                                                      \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;43;33;22m                                                                      \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;43;33;22m                                                                      \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;75;55;32m                                      \e[48;2;232;135;29m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;134;93;48m                                      \e[48;2;75;55;32m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;134;93;48m                                      \e[48;2;75;55;32m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;134;93;48m                                      \e[48;2;75;55;32m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;153;121;87m  \e[E");
    printf("\e[48;2;232;135;29m  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;72;45;14m  \e[48;2;113;64;1m                        \e[48;2;72;45;14m  \e[48;2;134;93;48m                                      \e[48;2;75;55;32m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;232;135;29m  \e[48;2;113;64;1m                        \e[48;2;232;135;29m  \e[48;2;134;93;48m                                      \e[48;2;75;55;32m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                              \e[48;2;255;189;0m  \e[48;2;232;135;29m  \e[48;2;72;45;14m                    \e[48;2;232;135;29m  \e[48;2;255;189;0m  \e[48;2;75;55;32m                                      \e[48;2;232;135;29m  \e[48;2;43;33;22m                              \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("  \e[48;2;93;71;45m  \e[48;2;63;47;32m  \e[48;2;43;33;22m                                                                                                                                                \e[48;2;63;47;32m  \e[48;2;93;71;45m  \e[48;2;232;135;29m  \e[E");
    printf("\e[48;2;255;191;105m  \e[48;2;93;71;45m  \e[48;2;63;47;32m                                                                                                                                                    \e[48;2;93;71;45m  \e[48;2;255;191;105m  \e[E");
    printf("  \e[48;2;93;71;45m                                                                                                                                                        \e[48;2;255;191;105m  \e[E");
    printf("      \e[48;2;232;135;29m        \e[48;2;153;121;87m                                                                                                                                \e[48;2;232;135;29m        \e[48;2;255;191;105m      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimvitoria() {
    printf("\e[5E");
    printf("\e[18C\e[48;2;255;189;0m    \e[4C        \e[4C\e[48;2;255;235;33m    \e[14C\e[48;2;144;87;25m                                                                                      \e[E");
    printf("\e[18C\e[48;2;255;189;0m    \e[4C        \e[4C\e[48;2;255;235;33m    \e[12C\e[48;2;144;87;25m    \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m          \e[48;2;144;87;25m  \e[48;2;232;135;29m          \e[48;2;144;87;25m    \e[48;2;232;135;29m      \e[48;2;144;87;25m    \e[48;2;232;135;29m        \e[48;2;144;87;25m    \e[48;2;232;135;29m          \e[48;2;144;87;25m    \e[48;2;232;135;29m      \e[48;2;144;87;25m      \e[E");
    printf("\e[18C\e[48;2;255;235;33m    \e[48;2;255;189;0m                \e[48;2;255;235;33m    \e[10C\e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m          \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[E");
    printf("\e[18C\e[48;2;255;235;33m    \e[48;2;255;189;0m                \e[48;2;255;235;33m    \e[10C\e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m          \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[E");
    printf("\e[18C\e[48;2;255;145;0m        \e[48;2;255;58;43m        \e[48;2;255;145;0m        \e[10C\e[48;2;144;87;25m      \e[48;2;232;135;29m    \e[48;2;144;87;25m  \e[48;2;232;135;29m    \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m          \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m        \e[48;2;144;87;25m        \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m          \e[48;2;144;87;25m      \e[E");
    printf("\e[18C\e[48;2;255;145;0m        \e[48;2;255;58;43m        \e[48;2;255;145;0m        \e[10C\e[48;2;144;87;25m        \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m  \e[48;2;144;87;25m        \e[48;2;232;135;29m  \e[48;2;144;87;25m          \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[E");
    printf("\e[10C\e[48;2;255;189;0m  \e[48;2;232;135;29m  \e[48;2;163;93;16m                                \e[48;2;232;135;29m  \e[48;2;255;189;0m  \e[2C\e[48;2;144;87;25m        \e[48;2;232;135;29m      \e[48;2;144;87;25m        \e[48;2;232;135;29m  \e[48;2;144;87;25m          \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[E");
    printf("\e[10C\e[48;2;232;135;29m  \e[48;2;126;73;15m                                    \e[48;2;232;135;29m  \e[4C\e[48;2;144;87;25m        \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m          \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m        \e[48;2;232;135;29m      \e[48;2;144;87;25m    \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m  \e[48;2;232;135;29m          \e[48;2;144;87;25m  \e[48;2;232;135;29m  \e[48;2;144;87;25m      \e[48;2;232;135;29m  \e[48;2;144;87;25m    \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[6C\e[48;2;144;87;25m                                                                                      \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[E");
    printf("\e[10C  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[46C\e[48;2;181;120;14m  \e[48;2;116;56;0m  \e[48;2;181;120;14m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[42C\e[48;2;181;120;14m  \e[48;2;116;56;0m  \e[48;2;65;31;0m  \e[48;2;188;98;0m  \e[48;2;65;31;0m  \e[48;2;116;56;0m  \e[48;2;181;120;14m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[30C\e[48;2;246;154;0m  \e[10C\e[48;2;116;56;0m  \e[48;2;65;31;0m  \e[48;2;246;154;0m      \e[48;2;65;31;0m  \e[48;2;116;56;0m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[30C\e[48;2;246;154;0m  \e[8C\e[48;2;181;120;14m  \e[48;2;65;31;0m    \e[48;2;246;154;0m  \e[48;2;188;98;0m  \e[48;2;65;31;0m      \e[48;2;181;120;14m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[26C\e[48;2;246;154;0m          \e[4C\e[48;2;116;56;0m  \e[48;2;65;31;0m    \e[48;2;246;154;0m      \e[48;2;65;31;0m    \e[48;2;116;56;0m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[30C\e[48;2;246;154;0m  \e[8C\e[48;2;181;120;14m  \e[48;2;65;31;0m      \e[48;2;188;98;0m  \e[48;2;246;154;0m  \e[48;2;65;31;0m    \e[48;2;181;120;14m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[30C\e[48;2;246;154;0m  \e[10C\e[48;2;116;56;0m  \e[48;2;65;31;0m  \e[48;2;246;154;0m      \e[48;2;65;31;0m  \e[48;2;116;56;0m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[42C\e[48;2;181;120;14m  \e[48;2;116;56;0m  \e[48;2;65;31;0m  \e[48;2;188;98;0m  \e[48;2;65;31;0m  \e[48;2;116;56;0m  \e[48;2;181;120;14m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[46C\e[48;2;181;120;14m  \e[48;2;116;56;0m  \e[48;2;181;120;14m  \e[E");
    printf("\e[10C\e[48;2;163;93;16m  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[E");
    printf("\e[10C  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[E");
    printf("\e[10C  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[E");
    printf("\e[10C  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[E");
    printf("\e[10C  \e[48;2;126;73;15m  \e[48;2;204;147;86m                                \e[48;2;126;73;15m  \e[48;2;163;93;16m  \e[E");
    printf("\e[10C\e[48;2;232;135;29m  \e[48;2;126;73;15m                                    \e[48;2;232;135;29m  \e[E");
    printf("\e[10C\e[48;2;255;189;0m  \e[48;2;232;135;29m  \e[48;2;163;93;16m                                \e[48;2;232;135;29m  \e[48;2;255;189;0m  \e[E");
    printf("\e[E");
    printf("\e[16C\e[48;2;232;135;29m    \e[48;2;126;73;15m                    \e[48;2;232;135;29m    \e[E");
    printf("\e[16C  \e[48;2;126;73;15m                        \e[48;2;232;135;29m  \e[E");
    printf("\e[16C\e[48;2;126;73;15m                            \e[E");
    printf("\e[16C    \e[48;2;232;135;29m                    \e[48;2;126;73;15m    \e[E");
    printf("\e[16C                            \e[E");
    printf("\e[16C\e[48;2;232;135;29m  \e[48;2;126;73;15m      \e[48;2;188;110;26m            \e[48;2;126;73;15m      \e[48;2;232;135;29m  \e[E");
    printf("\e[16C    \e[48;2;126;73;15m                    \e[48;2;232;135;29m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimperda() {
    printf("\e[5E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[14C\e[48;2;48;52;101m                                                                                      \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[12C\e[48;2;48;52;101m          \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m          \e[48;2;48;52;101m  \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m          \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;48;52;101m            \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m            \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;48;52;101m            \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m            \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;48;52;101m            \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m            \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;48;52;101m            \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m            \e[E");
    printf("\e[10C\e[48;2;165;127;84m    \e[48;2;93;71;45m                                \e[48;2;165;127;84m    \e[2C\e[48;2;48;52;101m            \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m            \e[E");
    printf("\e[10C\e[48;2;165;127;84m  \e[48;2;105;78;47m                                    \e[48;2;165;127;84m  \e[4C\e[48;2;48;52;101m          \e[48;2;92;123;142m  \e[48;2;48;52;101m          \e[48;2;92;123;142m          \e[48;2;48;52;101m  \e[48;2;92;123;142m  \e[48;2;48;52;101m      \e[48;2;92;123;142m  \e[48;2;48;52;101m  \e[48;2;92;123;142m        \e[48;2;48;52;101m    \e[48;2;92;123;142m          \e[48;2;48;52;101m    \e[48;2;92;123;142m      \e[48;2;48;52;101m            \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[6C\e[48;2;48;52;101m                                                                                      \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[46C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[42C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;116;67;58m  \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[10C\e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;153;95;76m      \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[8C\e[48;2;122;85;74m  \e[48;2;40;22;20m    \e[48;2;153;95;76m  \e[48;2;116;67;58m  \e[48;2;40;22;20m      \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[26C\e[48;2;153;95;76m          \e[4C\e[48;2;71;40;36m  \e[48;2;40;22;20m    \e[48;2;153;95;76m      \e[48;2;40;22;20m    \e[48;2;71;40;36m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[8C\e[48;2;122;85;74m  \e[48;2;40;22;20m      \e[48;2;116;67;58m  \e[48;2;153;95;76m  \e[48;2;40;22;20m    \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[10C\e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;153;95;76m      \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[42C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;116;67;58m  \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[46C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C\e[48;2;165;127;84m  \e[48;2;105;78;47m                                    \e[48;2;165;127;84m  \e[E");
    printf("\e[10C    \e[48;2;93;71;45m                                \e[48;2;165;127;84m    \e[E");
    printf("\e[E");
    printf("\e[16C\e[48;2;63;47;31m    \e[48;2;105;78;47m                    \e[48;2;63;47;31m    \e[E");
    printf("\e[16C  \e[48;2;105;78;47m                        \e[48;2;63;47;31m  \e[E");
    printf("\e[16C\e[48;2;105;78;47m                            \e[E");
    printf("\e[16C    \e[48;2;165;127;84m                    \e[48;2;105;78;47m    \e[E");
    printf("\e[16C                            \e[E");
    printf("\e[16C\e[48;2;63;47;31m  \e[48;2;105;78;47m      \e[48;2;134;93;48m            \e[48;2;105;78;47m      \e[48;2;63;47;31m  \e[E");
    printf("\e[16C    \e[48;2;105;78;47m                    \e[48;2;63;47;31m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimdesistencia() {
    printf("\e[5E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[14C\e[48;2;110;48;48m                                                                                      \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[12C\e[48;2;110;48;48m    \e[48;2;163;97;97m        \e[48;2;110;48;48m    \e[48;2;163;97;97m          \e[48;2;110;48;48m    \e[48;2;163;97;97m        \e[48;2;110;48;48m  \e[48;2;163;97;97m          \e[48;2;110;48;48m  \e[48;2;163;97;97m          \e[48;2;110;48;48m  \e[48;2;163;97;97m          \e[48;2;110;48;48m  \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m    \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m  \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m              \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m  \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m              \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m  \e[48;2;163;97;97m        \e[48;2;110;48;48m      \e[48;2;163;97;97m      \e[48;2;110;48;48m        \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[E");
    printf("\e[18C\e[48;2;43;33;22m                        \e[10C\e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m  \e[48;2;163;97;97m  \e[48;2;110;48;48m                  \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[E");
    printf("\e[10C\e[48;2;165;127;84m    \e[48;2;93;71;45m                                \e[48;2;165;127;84m    \e[2C\e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m  \e[48;2;163;97;97m  \e[48;2;110;48;48m                  \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m          \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[E");
    printf("\e[10C\e[48;2;165;127;84m  \e[48;2;105;78;47m                                    \e[48;2;165;127;84m  \e[4C\e[48;2;110;48;48m    \e[48;2;163;97;97m        \e[48;2;110;48;48m    \e[48;2;163;97;97m          \e[48;2;110;48;48m  \e[48;2;163;97;97m        \e[48;2;110;48;48m    \e[48;2;163;97;97m          \e[48;2;110;48;48m      \e[48;2;163;97;97m  \e[48;2;110;48;48m      \e[48;2;163;97;97m          \e[48;2;110;48;48m    \e[48;2;163;97;97m      \e[48;2;110;48;48m      \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[6C\e[48;2;110;48;48m                                                                                      \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[46C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[42C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;116;67;58m  \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[10C\e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;153;95;76m      \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[8C\e[48;2;122;85;74m  \e[48;2;40;22;20m    \e[48;2;153;95;76m  \e[48;2;116;67;58m  \e[48;2;40;22;20m      \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[26C\e[48;2;153;95;76m          \e[4C\e[48;2;71;40;36m  \e[48;2;40;22;20m    \e[48;2;153;95;76m      \e[48;2;40;22;20m    \e[48;2;71;40;36m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[8C\e[48;2;122;85;74m  \e[48;2;40;22;20m      \e[48;2;116;67;58m  \e[48;2;153;95;76m  \e[48;2;40;22;20m    \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[30C\e[48;2;43;33;22m  \e[10C\e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;153;95;76m      \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[42C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;40;22;20m  \e[48;2;116;67;58m  \e[48;2;40;22;20m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[46C\e[48;2;122;85;74m  \e[48;2;71;40;36m  \e[48;2;122;85;74m  \e[E");
    printf("\e[10C\e[48;2;93;71;45m  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C  \e[48;2;105;78;47m                                    \e[48;2;93;71;45m  \e[E");
    printf("\e[10C\e[48;2;165;127;84m  \e[48;2;105;78;47m                                    \e[48;2;165;127;84m  \e[E");
    printf("\e[10C    \e[48;2;93;71;45m                                \e[48;2;165;127;84m    \e[E");
    printf("\e[E");
    printf("\e[16C\e[48;2;63;47;31m    \e[48;2;105;78;47m                    \e[48;2;63;47;31m    \e[E");
    printf("\e[16C  \e[48;2;105;78;47m                        \e[48;2;63;47;31m  \e[E");
    printf("\e[16C\e[48;2;105;78;47m                            \e[E");
    printf("\e[16C    \e[48;2;165;127;84m                    \e[48;2;105;78;47m    \e[E");
    printf("\e[16C                            \e[E");
    printf("\e[16C\e[48;2;63;47;31m  \e[48;2;105;78;47m      \e[48;2;134;93;48m            \e[48;2;105;78;47m      \e[48;2;63;47;31m  \e[E");
    printf("\e[16C    \e[48;2;105;78;47m                    \e[48;2;63;47;31m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimcombinacoes() {
    printf("\e[22E");
    printf("\e[134C\e[48;2;80;74;67m      \e[E");
    printf("\e[130C    \e[6C    \e[E");
    printf("\e[126C\e[48;2;232;135;29m    \e[48;2;80;74;67m              \e[48;2;232;135;29m    \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;232;135;29m  \e[E");
    printf("\e[126C\e[48;2;75;55;32m  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C  \e[48;2;134;93;48m                  \e[48;2;75;55;32m  \e[E");
    printf("\e[126C\e[48;2;232;135;29m  \e[48;2;134;93;48m                  \e[48;2;232;135;29m  \e[E");
    printf("\e[126C    \e[48;2;75;55;32m              \e[48;2;232;135;29m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimsetadentro() {
    printf("\e[38;2;43;33;22m");
    printf("\e[15E");
    printf("\e[116C\e[48;2;43;33;22m  \e[48;2;135;101;58m    \e[2C        \e[2C    \e[48;2;43;33;22m  \e[E");
    printf("\e[114C  \e[48;2;135;101;58m      \e[2C  SAIR  \e[2C      \e[48;2;43;33;22m  \e[E");
    printf("\e[116C  \e[48;2;135;101;58m    \e[2C        \e[2C    \e[48;2;43;33;22m  \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_fimsetafora() {
    printf("\e[38;2;43;33;22m");
    printf("\e[15E");
    printf("\e[116C\e[48;2;135;101;58m    \e[48;2;43;33;22m  \e[2C\e[48;2;135;101;58m        \e[2C\e[48;2;43;33;22m  \e[48;2;135;101;58m    \e[E");
    printf("\e[114C      \e[48;2;43;33;22m  \e[2C\e[48;2;135;101;58m  SAIR  \e[2C\e[48;2;43;33;22m  \e[48;2;135;101;58m      \e[E");
    printf("\e[116C    \e[48;2;43;33;22m  \e[2C\e[48;2;135;101;58m        \e[2C\e[48;2;43;33;22m  \e[48;2;135;101;58m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_round1() {
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                      \e[48;2;0;0;0m                                                                              \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                  \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m              \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                    \e[48;2;0;0;0m                                                                        \e[48;2;0;79;18m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                                  \e[48;2;0;0;0m                  \e[48;2;0;79;18m                                                                \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;0;79;18m                                                                    \e[48;2;0;0;0m                      \e[48;2;0;79;18m                                                              \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;0;79;18m                                                              \e[48;2;0;0;0m                          \e[48;2;0;79;18m                                                            \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;0;79;18m                                                        \e[48;2;0;0;0m                              \e[48;2;0;79;18m                                                          \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                    \e[48;2;0;0;0m                                  \e[48;2;0;79;18m                                                        \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;0;79;18m                                                  \e[48;2;0;0;0m                                      \e[48;2;0;79;18m                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_round2() {
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;255;151;0m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;255;151;0m                                      \e[48;2;0;0;0m                                                                              \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                  \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m              \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;255;151;0m                                            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                    \e[48;2;0;0;0m                                                                        \e[48;2;255;151;0m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;255;151;0m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;255;151;0m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                                  \e[48;2;0;0;0m                  \e[48;2;255;151;0m                                                                \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;255;151;0m                                                                    \e[48;2;0;0;0m                      \e[48;2;255;151;0m                                                              \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;255;151;0m                                                              \e[48;2;0;0;0m                          \e[48;2;255;151;0m                                                            \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;255;151;0m                                                        \e[48;2;0;0;0m                              \e[48;2;255;151;0m                                                          \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                    \e[48;2;0;0;0m                                  \e[48;2;255;151;0m                                                        \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;255;151;0m                                                  \e[48;2;0;0;0m                                      \e[48;2;255;151;0m                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_round3() {
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;253;76;0m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;253;76;0m                                      \e[48;2;0;0;0m                                                                              \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                  \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m              \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;253;76;0m                                            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                    \e[48;2;0;0;0m                                                                        \e[48;2;253;76;0m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;253;76;0m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;253;76;0m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                                  \e[48;2;0;0;0m                  \e[48;2;253;76;0m                                                                \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;253;76;0m                                                                    \e[48;2;0;0;0m                      \e[48;2;253;76;0m                                                              \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;253;76;0m                                                              \e[48;2;0;0;0m                          \e[48;2;253;76;0m                                                            \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;253;76;0m                                                        \e[48;2;0;0;0m                              \e[48;2;253;76;0m                                                          \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                    \e[48;2;0;0;0m                                  \e[48;2;253;76;0m                                                        \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;253;76;0m                                                  \e[48;2;0;0;0m                                      \e[48;2;253;76;0m                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_round4() {
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;148;17;53m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;148;17;53m                                      \e[48;2;0;0;0m                                                                              \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                  \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m              \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                  \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;148;17;53m                                            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                        \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[48;2;255;255;255m          \e[48;2;0;0;0m    \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                    \e[48;2;0;0;0m                                                                        \e[48;2;148;17;53m                                    \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;148;17;53m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;148;17;53m                                                                                                                                                        \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                                                                                                    \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                                                                                                              \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                                                                                                                \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                                  \e[48;2;0;0;0m                  \e[48;2;148;17;53m                                                                \e[E");
    printf("\e[48;2;255;255;255m    \e[48;2;148;17;53m                                                                    \e[48;2;0;0;0m                      \e[48;2;148;17;53m                                                              \e[E");
    printf("\e[48;2;255;255;255m        \e[48;2;148;17;53m                                                              \e[48;2;0;0;0m                          \e[48;2;148;17;53m                                                            \e[E");
    printf("\e[48;2;255;255;255m            \e[48;2;148;17;53m                                                        \e[48;2;0;0;0m                              \e[48;2;148;17;53m                                                          \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                    \e[48;2;0;0;0m                                  \e[48;2;148;17;53m                                                        \e[E");
    printf("\e[48;2;255;255;255m              \e[48;2;148;17;53m                                                  \e[48;2;0;0;0m                                      \e[48;2;148;17;53m                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

SpriteSheet* animacao_carregar_spritesheet(char caminho[]){

    SpriteSheet *sheet = sprite_sheet_load(caminho, 15, 15);
    if (!sheet) {
        printf("Falha ao carregar %s\n", caminho);
        return NULL;
    }
    return sheet;
}

void animacao_animar_round1(){
    SpriteSheet *round = animacao_carregar_spritesheet("anim/um.png");
    if (!round) printf("Não foi possível carregar um sprite");

    desenhar_round1();
    sprite_animate(round, 1, 80000, "0;79;18", 68, 23);
    sprite_sheet_free(round);
}

void animacao_animar_round2(){
    SpriteSheet *round = animacao_carregar_spritesheet("anim/dois.png");
    if (!round) printf("Não foi possível carregar um sprite");

    desenhar_round2();
    sprite_animate(round, 1, 80000, "255;151;0", 68, 23);
    sprite_sheet_free(round);
}

void animacao_animar_round3(){
    SpriteSheet *round = animacao_carregar_spritesheet("anim/tres.png");
    if (!round) printf("Não foi possível carregar um sprite");

    desenhar_round3();
    sprite_animate(round, 1, 80000, "253;76;0", 68, 23);
    sprite_sheet_free(round);
}

void animacao_animar_round4(){
    SpriteSheet *round = animacao_carregar_spritesheet("anim/quatro.png");
    if (!round) printf("Não foi possível carregar um sprite");

    desenhar_round4();
    sprite_animate(round, 1, 80000, "148;17;53", 68, 23);
    sprite_sheet_free(round);
}

void desenhar_misterio() {
    printf("\e[48;2;255;255;255m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[E");
    printf("  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[E");
    printf("    \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m    \e[E");
    printf("    \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m      \e[48;2;255;255;255m        \e[48;2;0;0;0m    \e[E");
    printf("      \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;0;0;0m      \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[48;2;19;19;19m                                                                                                                                                            \e[E");
    printf("                                                                  \e[48;2;123;123;123m    \e[48;2;19;19;19m    \e[48;2;123;123;123m        \e[48;2;19;19;19m    \e[48;2;150;150;150m    \e[48;2;19;19;19m                                                                  \e[E");
    printf("                                                                  \e[48;2;123;123;123m    \e[48;2;19;19;19m    \e[48;2;123;123;123m        \e[48;2;19;19;19m    \e[48;2;150;150;150m    \e[48;2;19;19;19m                                                                  \e[E");
    printf("                                                                  \e[48;2;150;150;150m    \e[48;2;123;123;123m                \e[48;2;150;150;150m    \e[48;2;19;19;19m                                                                  \e[E");
    printf("                                                                  \e[48;2;150;150;150m    \e[48;2;123;123;123m                \e[48;2;150;150;150m    \e[48;2;19;19;19m                                                                  \e[E");
    printf("                                                                  \e[48;2;118;119;118m        \e[48;2;141;141;141m        \e[48;2;118;119;118m        \e[48;2;19;19;19m                                                                  \e[E");
    printf("                                                                  \e[48;2;118;119;118m        \e[48;2;141;141;141m        \e[48;2;118;119;118m        \e[48;2;19;19;19m                                                                  \e[E");
    printf("                                                          \e[48;2;123;123;123m    \e[48;2;84;84;84m                                \e[48;2;123;123;123m    \e[48;2;19;19;19m                                                          \e[E");
    printf("                                                          \e[48;2;123;123;123m  \e[48;2;66;66;66m                                    \e[48;2;123;123;123m  \e[48;2;19;19;19m                                                          \e[E");
    printf("\e[48;2;29;29;29m                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m                                \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m                                \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;29;29;29m                                                          \e[E");
    printf("\e[48;2;35;35;35m                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m      \e[48;2;43;43;43m                    \e[48;2;140;140;140m      \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m  \e[48;2;43;43;43m                            \e[48;2;140;140;140m  \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m  \e[48;2;43;43;43m                            \e[48;2;140;140;140m  \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m  \e[48;2;43;43;43m                            \e[48;2;140;140;140m  \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m  \e[48;2;43;43;43m                            \e[48;2;140;140;140m  \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m  \e[48;2;43;43;43m                            \e[48;2;140;140;140m  \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;84;84;84m  \e[48;2;66;66;66m  \e[48;2;140;140;140m  \e[48;2;43;43;43m                            \e[48;2;140;140;140m  \e[48;2;66;66;66m  \e[48;2;84;84;84m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;123;123;123m  \e[48;2;66;66;66m                                    \e[48;2;123;123;123m  \e[48;2;35;35;35m                                                          \e[E");
    printf("                                                          \e[48;2;123;123;123m    \e[48;2;84;84;84m                                \e[48;2;123;123;123m    \e[48;2;35;35;35m                                                          \e[E");
    printf("\e[48;2;43;43;43m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_misteriobotao() {
    printf("\e[35E");
    printf("\e[56C\e[48;2;170;117;5m              \e[48;2;244;161;0m                              \e[E");
    printf("\e[54C\e[48;2;170;117;5m    \e[48;2;255;191;35m                                        \e[48;2;244;161;0m    \e[E");
    printf("\e[52C\e[48;2;170;117;5m    \e[48;2;255;191;35m                  \e[48;2;200;140;21m        \e[48;2;255;191;35m                  \e[48;2;244;161;0m    \e[E");
    printf("\e[52C\e[48;2;105;81;31m  \e[48;2;255;191;35m                    \e[48;2;200;140;21m  \e[48;2;255;191;35m                          \e[48;2;244;161;0m  \e[E");
    printf("\e[52C\e[48;2;105;81;31m  \e[48;2;255;191;35m                    \e[48;2;200;140;21m      \e[48;2;255;191;35m                      \e[48;2;244;161;0m  \e[E");
    printf("\e[52C\e[48;2;105;81;31m  \e[48;2;255;191;35m                    \e[48;2;200;140;21m  \e[48;2;255;191;35m                          \e[48;2;170;117;5m  \e[E");
    printf("\e[52C\e[48;2;105;81;31m    \e[48;2;255;191;35m                  \e[48;2;200;140;21m  \e[48;2;255;191;35m                        \e[48;2;170;117;5m    \e[E");
    printf("\e[54C\e[48;2;105;81;31m    \e[48;2;255;191;35m                                        \e[48;2;170;117;5m    \e[E");
    printf("\e[56C\e[48;2;105;81;31m                                          \e[48;2;170;117;5m  \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_misteriobotaoapertado() {
    printf("\e[35E");
    printf("\e[56C\e[48;2;244;161;0m                                            \e[E");
    printf("\e[54C    \e[48;2;170;117;5m                                        \e[48;2;244;161;0m    \e[E");
    printf("\e[52C    \e[48;2;170;117;5m                  \e[48;2;125;90;21m        \e[48;2;170;117;5m                  \e[48;2;244;161;0m    \e[E");
    printf("\e[52C  \e[48;2;170;117;5m                    \e[48;2;125;90;21m  \e[48;2;170;117;5m                          \e[48;2;244;161;0m  \e[E");
    printf("\e[52C  \e[48;2;170;117;5m                    \e[48;2;125;90;21m      \e[48;2;170;117;5m                      \e[48;2;244;161;0m  \e[E");
    printf("\e[52C  \e[48;2;170;117;5m                    \e[48;2;125;90;21m  \e[48;2;170;117;5m                          \e[48;2;244;161;0m  \e[E");
    printf("\e[52C    \e[48;2;170;117;5m                  \e[48;2;125;90;21m  \e[48;2;170;117;5m                        \e[48;2;244;161;0m    \e[E");
    printf("\e[54C    \e[48;2;170;117;5m                                        \e[48;2;244;161;0m    \e[E");
    printf("\e[56C                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratogrande() {
    printf("\e[13E");
    printf("\e[18C\e[48;2;151;151;151m    \e[16C    \e[E");
    printf("\e[18C    \e[16C    \e[E");
    printf("\e[14C    \e[48;2;255;200;206m    \e[48;2;151;151;151m    \e[8C    \e[48;2;255;200;206m    \e[48;2;151;151;151m    \e[E");
    printf("\e[14C    \e[48;2;255;200;206m    \e[48;2;151;151;151m    \e[8C    \e[48;2;255;200;206m    \e[48;2;151;151;151m    \e[E");
    printf("\e[14C    \e[48;2;255;200;206m    \e[48;2;151;151;151m                \e[48;2;255;200;206m    \e[48;2;151;151;151m    \e[E");
    printf("\e[14C    \e[48;2;255;200;206m    \e[48;2;151;151;151m                \e[48;2;255;200;206m    \e[48;2;151;151;151m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;151;151;151m        \e[48;2;0;0;0m    \e[48;2;151;151;151m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;151;151;151m        \e[48;2;0;0;0m    \e[48;2;151;151;151m        \e[E");
    printf("\e[14C            \e[48;2;255;146;146m        \e[48;2;151;151;151m            \e[E");
    printf("\e[14C            \e[48;2;255;146;146m        \e[48;2;151;151;151m            \e[E");
    printf("\e[18C                        \e[E");
    printf("\e[18C                        \e[E");
    printf("\e[22C                \e[E");
    printf("\e[22C                \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatogrande() {
    printf("\e[13E");
    printf("\e[18C\e[48;2;255;179;49m    \e[16C    \e[E");
    printf("\e[18C    \e[16C    \e[E");
    printf("\e[14C    \e[48;2;255;202;112m    \e[48;2;255;179;49m    \e[8C    \e[48;2;255;202;112m    \e[48;2;255;179;49m    \e[E");
    printf("\e[14C    \e[48;2;255;202;112m    \e[48;2;255;179;49m    \e[8C    \e[48;2;255;202;112m    \e[48;2;255;179;49m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[48;2;0;0;0m    \e[48;2;255;179;49m        \e[E");
    printf("\e[14C\e[48;2;0;0;0m    \e[48;2;255;202;112m    \e[48;2;0;0;0m    \e[48;2;255;202;112m        \e[48;2;0;0;0m    \e[48;2;255;202;112m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C    \e[48;2;255;202;112m    \e[48;2;0;0;0m    \e[48;2;255;202;112m        \e[48;2;0;0;0m    \e[48;2;255;202;112m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;202;112m                \e[48;2;255;73;68m    \e[48;2;255;202;112m            \e[E");
    printf("\e[14C                \e[48;2;255;73;68m    \e[48;2;255;202;112m            \e[E");
    printf("\e[14C\e[48;2;0;0;0m    \e[48;2;255;202;112m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C    \e[48;2;255;202;112m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhogrande() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;0;0;0m        \e[12C        \e[E");
    printf("\e[14C        \e[12C        \e[E");
    printf("\e[14C\e[48;2;255;255;255m        \e[48;2;0;0;0m    \e[4C    \e[48;2;255;255;255m        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;255;255m        \e[48;2;0;0;0m    \e[4C    \e[48;2;255;255;255m        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[4C    \e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[4C    \e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[4C    \e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[4C    \e[48;2;255;147;147m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[E");
    printf("\e[14C            \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[E");
    printf("\e[14C    \e[48;2;0;0;0m    \e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;255;255m        \e[E");
    printf("\e[14C    \e[48;2;0;0;0m    \e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;255;255m        \e[E");
    printf("\e[14C    \e[48;2;0;0;0m    \e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;182;206m    \e[48;2;255;255;255m    \e[E");
    printf("\e[14C    \e[48;2;0;0;0m    \e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;182;206m    \e[48;2;255;255;255m    \e[E");
    printf("\e[14C            \e[48;2;255;107;106m    \e[48;2;255;255;255m        \e[48;2;255;182;206m        \e[E");
    printf("\e[14C\e[48;2;255;255;255m            \e[48;2;255;107;106m    \e[48;2;255;255;255m        \e[48;2;255;182;206m        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapogrande() {
    printf("\e[13E");
    printf("\e[18C\e[48;2;0;135;48m            \e[4C        \e[48;2;0;117;39m    \e[E");
    printf("\e[18C\e[48;2;0;135;48m            \e[4C        \e[48;2;0;117;39m    \e[E");
    printf("\e[18C\e[48;2;0;135;48m    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[4C    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[E");
    printf("\e[18C    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[4C    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;0;86;23m                        \e[E");
    printf("\e[14C\e[48;2;0;135;48m        \e[48;2;0;86;23m                        \e[E");
    printf("\e[14C\e[48;2;0;135;48m                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                        \e[48;2;0;117;39m        \e[E");
    printf("\e[14C\e[48;2;0;135;48m                        \e[48;2;0;117;39m        \e[E");
    printf("\e[14C\e[48;2;0;154;59m    \e[48;2;0;135;48m                        \e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m    \e[48;2;0;135;48m                        \e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m        \e[4C\e[48;2;0;135;48m            \e[4C\e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m        \e[4C\e[48;2;0;135;48m            \e[4C\e[48;2;0;117;39m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursogrande() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;121;66;53m            \e[8C            \e[E");
    printf("\e[14C            \e[8C            \e[E");
    printf("\e[14C    \e[48;2;255;147;147m    \e[48;2;121;66;53m    \e[8C    \e[48;2;255;147;147m    \e[48;2;121;66;53m    \e[E");
    printf("\e[14C    \e[48;2;255;147;147m    \e[48;2;121;66;53m    \e[8C    \e[48;2;255;147;147m    \e[48;2;121;66;53m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[18C    \e[48;2;22;22;22m    \e[48;2;121;66;53m        \e[48;2;22;22;22m    \e[48;2;121;66;53m    \e[E");
    printf("\e[18C    \e[48;2;22;22;22m    \e[48;2;121;66;53m        \e[48;2;22;22;22m    \e[48;2;121;66;53m    \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;121;66;53m        \e[48;2;0;0;0m    \e[48;2;121;66;53m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;121;66;53m        \e[48;2;0;0;0m    \e[48;2;121;66;53m        \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;135;75;61m    \e[48;2;0;0;0m        \e[48;2;135;75;61m    \e[48;2;121;66;53m        \e[E");
    printf("\e[14C        \e[48;2;135;75;61m    \e[48;2;0;0;0m        \e[48;2;135;75;61m    \e[48;2;121;66;53m        \e[E");
    printf("\e[14C        \e[48;2;135;75;61m                \e[48;2;121;66;53m        \e[E");
    printf("\e[14C        \e[48;2;135;75;61m                \e[48;2;121;66;53m        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquilogrande() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;83;42;35m        \e[16C        \e[E");
    printf("\e[14C        \e[16C        \e[E");
    printf("\e[14C\e[48;2;255;202;207m    \e[48;2;83;42;35m    \e[48;2;121;66;53m                \e[48;2;83;42;35m    \e[48;2;255;202;207m    \e[E");
    printf("\e[14C    \e[48;2;83;42;35m    \e[48;2;121;66;53m                \e[48;2;83;42;35m    \e[48;2;255;202;207m    \e[E");
    printf("\e[14C\e[48;2;255;207;111m        \e[48;2;121;66;53m                \e[48;2;255;207;111m        \e[E");
    printf("\e[14C        \e[48;2;121;66;53m                \e[48;2;255;207;111m        \e[E");
    printf("\e[14C\e[48;2;22;22;22m    \e[48;2;88;88;88m    \e[48;2;255;202;112m    \e[48;2;121;66;53m        \e[48;2;255;207;111m    \e[48;2;22;22;22m    \e[48;2;88;88;88m    \e[E");
    printf("\e[14C\e[48;2;22;22;22m    \e[48;2;88;88;88m    \e[48;2;255;202;112m    \e[48;2;121;66;53m        \e[48;2;255;207;111m    \e[48;2;22;22;22m    \e[48;2;88;88;88m    \e[E");
    printf("\e[14C    \e[48;2;22;22;22m    \e[48;2;255;207;111m    \e[48;2;155;101;88m        \e[48;2;255;207;111m    \e[48;2;88;88;88m    \e[48;2;22;22;22m    \e[E");
    printf("\e[14C\e[48;2;88;88;88m    \e[48;2;22;22;22m    \e[48;2;255;207;111m    \e[48;2;155;101;88m        \e[48;2;255;207;111m    \e[48;2;88;88;88m    \e[48;2;22;22;22m    \e[E");
    printf("\e[14C\e[48;2;255;202;112m    \e[48;2;255;207;111m    \e[48;2;121;66;53m    \e[48;2;0;0;0m        \e[48;2;121;66;53m    \e[48;2;255;202;112m    \e[48;2;255;207;111m    \e[E");
    printf("\e[14C\e[48;2;255;202;112m    \e[48;2;255;207;111m    \e[48;2;121;66;53m    \e[48;2;0;0;0m        \e[48;2;121;66;53m    \e[48;2;255;202;112m    \e[48;2;255;207;111m    \e[E");
    printf("\e[14C\e[48;2;121;66;53m        \e[48;2;155;101;88m    \e[48;2;255;255;255m        \e[48;2;155;101;88m    \e[48;2;121;66;53m        \e[E");
    printf("\e[14C        \e[48;2;155;101;88m    \e[48;2;255;255;255m        \e[48;2;155;101;88m    \e[48;2;121;66;53m        \e[E");
    printf("\e[14C    \e[48;2;155;101;88m                        \e[48;2;121;66;53m    \e[E");
    printf("\e[14C    \e[48;2;155;101;88m                        \e[48;2;121;66;53m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhoperde() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;0;0;0m        \e[12C        \e[E");
    printf("\e[14C\e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[8C  \e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[8C  \e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[8C  \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[8C  \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[8C  \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[4C    \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C    \e[48;2;0;0;0m      \e[48;2;255;255;255m          \e[48;2;0;0;0m      \e[48;2;255;255;255m      \e[E");
    printf("\e[14C    \e[48;2;0;0;0m      \e[48;2;255;255;255m          \e[48;2;0;0;0m      \e[48;2;255;255;255m      \e[E");
    printf("\e[14C    \e[48;2;0;140;244m    \e[48;2;255;255;255m              \e[48;2;0;140;244m    \e[48;2;255;255;255m      \e[E");
    printf("\e[14C    \e[48;2;0;140;244m    \e[48;2;255;255;255m    \e[48;2;250;106;105m    \e[48;2;255;255;255m      \e[48;2;0;140;244m    \e[48;2;255;181;204m  \e[48;2;255;255;255m    \e[E");
    printf("\e[14C    \e[48;2;0;140;244m  \e[48;2;255;255;255m                  \e[48;2;0;140;244m  \e[48;2;255;181;204m      \e[E");
    printf("\e[14C\e[48;2;255;255;255m          \e[48;2;0;0;0m          \e[48;2;255;255;255m    \e[48;2;255;181;204m        \e[E");
    printf("\e[14C\e[48;2;255;255;255m          \e[48;2;0;0;0m  \e[48;2;255;255;255m      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_coelhoganha() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;0;0;0m        \e[12C        \e[E");
    printf("\e[14C\e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[8C  \e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[8C  \e[48;2;255;255;255m        \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[8C  \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[8C  \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[8C  \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m  \e[E");
    printf("\e[14C\e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[4C    \e[48;2;255;146;146m    \e[48;2;255;255;255m    \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;255;255m                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C    \e[48;2;0;0;0m    \e[48;2;255;255;255m            \e[48;2;0;0;0m    \e[48;2;255;255;255m        \e[E");
    printf("\e[14C    \e[48;2;0;0;0m      \e[48;2;255;255;255m          \e[48;2;0;0;0m      \e[48;2;255;255;255m      \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C            \e[48;2;250;106;105m    \e[48;2;255;255;255m        \e[48;2;255;181;204m    \e[48;2;255;255;255m    \e[E");
    printf("\e[14C      \e[48;2;0;0;0m  \e[48;2;255;255;255m            \e[48;2;0;0;0m  \e[48;2;255;255;255m  \e[48;2;255;181;204m        \e[E");
    printf("\e[14C\e[48;2;255;255;255m      \e[48;2;0;0;0m                \e[48;2;255;255;255m  \e[48;2;255;181;204m        \e[E");
    printf("\e[14C\e[48;2;255;255;255m            \e[48;2;237;0;0m          \e[48;2;255;255;255m          \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquiloganha() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;75;44;38m        \e[16C        \e[E");
    printf("\e[14C        \e[16C        \e[E");
    printf("\e[14C\e[48;2;255;200;206m    \e[48;2;75;44;38m    \e[48;2;107;68;56m                \e[48;2;75;44;38m    \e[48;2;255;200;206m    \e[E");
    printf("\e[14C    \e[48;2;75;44;38m    \e[48;2;107;68;56m                \e[48;2;75;44;38m    \e[48;2;255;200;206m    \e[E");
    printf("\e[14C\e[48;2;255;206;116m        \e[48;2;107;68;56m                \e[48;2;255;206;116m        \e[E");
    printf("\e[14C        \e[48;2;107;68;56m                \e[48;2;255;206;116m        \e[E");
    printf("\e[14C\e[48;2;255;145;0m  \e[48;2;255;233;236m    \e[48;2;255;189;0m  \e[48;2;255;201;116m    \e[48;2;107;68;56m        \e[48;2;255;206;116m    \e[48;2;255;145;0m  \e[48;2;255;233;236m    \e[48;2;255;189;0m  \e[E");
    printf("\e[14C\e[48;2;255;233;236m    \e[48;2;255;189;0m  \e[48;2;255;145;0m  \e[48;2;255;201;116m    \e[48;2;107;68;56m        \e[48;2;255;206;116m    \e[48;2;255;233;236m    \e[48;2;255;189;0m  \e[48;2;255;145;0m  \e[E");
    printf("\e[14C\e[48;2;255;233;236m  \e[48;2;255;189;0m  \e[48;2;255;145;0m  \e[48;2;255;235;33m  \e[48;2;255;206;116m    \e[48;2;140;101;90m        \e[48;2;255;206;116m    \e[48;2;255;233;236m  \e[48;2;255;189;0m  \e[48;2;255;145;0m  \e[48;2;255;235;33m  \e[E");
    printf("\e[14C\e[48;2;255;189;0m  \e[48;2;255;145;0m  \e[48;2;255;235;33m    \e[48;2;255;206;116m    \e[48;2;140;101;90m        \e[48;2;255;206;116m    \e[48;2;255;189;0m  \e[48;2;255;145;0m  \e[48;2;255;235;33m    \e[E");
    printf("\e[14C\e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[48;2;107;68;56m    \e[48;2;0;0;0m        \e[48;2;107;68;56m    \e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[E");
    printf("\e[14C\e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[48;2;107;68;56m    \e[48;2;0;0;0m        \e[48;2;107;68;56m    \e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[E");
    printf("\e[14C\e[48;2;107;68;56m        \e[48;2;140;101;90m    \e[48;2;255;255;255m        \e[48;2;140;101;90m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;140;101;90m    \e[48;2;255;255;255m        \e[48;2;140;101;90m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C    \e[48;2;140;101;90m        \e[48;2;237;0;0m        \e[48;2;140;101;90m        \e[48;2;107;68;56m    \e[E");
    printf("\e[14C    \e[48;2;140;101;90m        \e[48;2;237;0;0m        \e[48;2;140;101;90m        \e[48;2;107;68;56m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_esquiloperde() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;75;44;38m        \e[16C        \e[E");
    printf("\e[14C        \e[16C        \e[E");
    printf("\e[14C\e[48;2;255;200;206m    \e[48;2;75;44;38m    \e[48;2;107;68;56m                \e[48;2;75;44;38m    \e[48;2;255;200;206m    \e[E");
    printf("\e[14C    \e[48;2;75;44;38m    \e[48;2;107;68;56m                \e[48;2;75;44;38m    \e[48;2;255;200;206m    \e[E");
    printf("\e[14C\e[48;2;107;68;56m                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C\e[48;2;255;206;116m        \e[48;2;107;68;56m                \e[48;2;255;206;116m        \e[E");
    printf("\e[14C        \e[48;2;107;68;56m                \e[48;2;255;206;116m        \e[E");
    printf("\e[14C\e[48;2;0;0;0m        \e[48;2;255;206;116m    \e[48;2;140;101;90m        \e[48;2;255;206;116m    \e[48;2;0;0;0m        \e[E");
    printf("\e[14C\e[48;2;0;140;244m      \e[48;2;0;0;0m  \e[48;2;255;206;116m    \e[48;2;140;101;90m        \e[48;2;255;206;116m    \e[48;2;0;0;0m  \e[48;2;0;140;244m      \e[E");
    printf("\e[14C\e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[48;2;107;68;56m    \e[48;2;0;0;0m        \e[48;2;107;68;56m    \e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[E");
    printf("\e[14C\e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[48;2;107;68;56m    \e[48;2;0;0;0m        \e[48;2;107;68;56m    \e[48;2;255;201;116m    \e[48;2;255;206;116m    \e[E");
    printf("\e[14C\e[48;2;107;68;56m        \e[48;2;140;101;90m      \e[48;2;0;0;0m    \e[48;2;140;101;90m      \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m                \e[48;2;107;68;56m        \e[E");
    printf("\e[14C    \e[48;2;140;101;90m    \e[48;2;0;0;0m  \e[48;2;140;101;90m            \e[48;2;0;0;0m  \e[48;2;140;101;90m    \e[48;2;107;68;56m    \e[E");
    printf("\e[14C    \e[48;2;140;101;90m                        \e[48;2;107;68;56m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatoganha() {
    printf("\e[13E");
    printf("\e[18C\e[48;2;255;178;61m    \e[16C    \e[E");
    printf("\e[18C    \e[16C    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[8C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[8C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;178;61m        \e[48;2;0;0;0m    \e[48;2;255;178;61m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;178;61m        \e[48;2;0;0;0m    \e[48;2;255;178;61m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;255;178;61m        \e[48;2;0;0;0m    \e[48;2;255;178;61m        \e[E");
    printf("\e[14C      \e[48;2;0;0;0m        \e[48;2;255;178;61m    \e[48;2;0;0;0m        \e[48;2;255;178;61m      \e[E");
    printf("\e[14C\e[48;2;0;0;0m    \e[48;2;255;201;116m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;201;116m                \e[48;2;255;74;69m    \e[48;2;255;201;116m            \e[E");
    printf("\e[14C      \e[48;2;0;0;0m      \e[48;2;255;201;116m    \e[48;2;255;74;69m    \e[48;2;255;201;116m            \e[E");
    printf("\e[14C\e[48;2;0;0;0m    \e[48;2;255;201;116m    \e[48;2;0;0;0m  \e[48;2;255;201;116m                  \e[48;2;0;0;0m    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m    \e[48;2;0;0;0m            \e[48;2;255;201;116m        \e[48;2;0;0;0m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_gatoperde() {
    printf("\e[13E");
    printf("\e[18C\e[48;2;255;178;61m    \e[16C    \e[E");
    printf("\e[18C    \e[16C    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[8C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[8C    \e[48;2;255;201;116m    \e[48;2;255;178;61m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C      \e[48;2;0;0;0m        \e[48;2;255;178;61m    \e[48;2;0;0;0m        \e[48;2;255;178;61m      \e[E");
    printf("\e[14C      \e[48;2;0;0;0m        \e[48;2;255;178;61m    \e[48;2;0;0;0m        \e[48;2;255;178;61m      \e[E");
    printf("\e[14C      \e[48;2;0;0;0m      \e[48;2;255;178;61m      \e[48;2;0;0;0m      \e[48;2;255;178;61m        \e[E");
    printf("\e[14C\e[48;2;0;0;0m    \e[48;2;255;201;116m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C\e[48;2;255;201;116m                \e[48;2;255;74;69m    \e[48;2;255;201;116m            \e[E");
    printf("\e[14C                \e[48;2;255;74;69m    \e[48;2;255;201;116m            \e[E");
    printf("\e[14C\e[48;2;0;0;0m    \e[48;2;255;201;116m                        \e[48;2;0;0;0m    \e[E");
    printf("\e[14C    \e[48;2;255;201;116m    \e[48;2;0;0;0m            \e[48;2;255;201;116m        \e[48;2;0;0;0m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratoperde() {
    printf("\e[13E");
    printf("\e[16C\e[48;2;108;108;108m      \e[14C      \e[E");
    printf("\e[14C  \e[48;2;151;151;151m      \e[48;2;108;108;108m  \e[10C  \e[48;2;151;151;151m      \e[48;2;108;108;108m  \e[E");
    printf("\e[14C  \e[48;2;151;151;151m  \e[48;2;255;200;206m    \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[6C  \e[48;2;151;151;151m  \e[48;2;255;200;206m      \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[14C  \e[48;2;151;151;151m  \e[48;2;255;200;206m    \e[48;2;151;151;151m  \e[48;2;108;108;108m        \e[48;2;151;151;151m  \e[48;2;255;200;206m        \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[14C  \e[48;2;151;151;151m    \e[48;2;255;200;206m  \e[48;2;108;108;108m  \e[48;2;151;151;151m            \e[48;2;255;200;206m      \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[16C      \e[48;2;151;151;151m                    \e[48;2;108;108;108m  \e[E");
    printf("\e[20C\e[48;2;0;0;0m    \e[48;2;151;151;151m    \e[48;2;0;0;0m    \e[48;2;151;151;151m    \e[48;2;108;108;108m      \e[E");
    printf("\e[18C  \e[48;2;151;151;151m          \e[48;2;0;140;244m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[E");
    printf("\e[16C\e[48;2;255;146;146m  \e[48;2;151;151;151m            \e[48;2;0;140;244m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[E");
    printf("\e[18C              \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[E");
    printf("\e[24C  \e[48;2;151;151;151m  \e[48;2;237;0;0m    \e[48;2;108;108;108m  \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[6C\e[48;2;255;146;146m  \e[E");
    printf("\e[24C\e[48;2;108;108;108m  \e[48;2;151;151;151m          \e[48;2;108;108;108m  \e[4C\e[48;2;255;146;146m  \e[E");
    printf("\e[22C  \e[48;2;108;108;108m  \e[48;2;151;151;151m      \e[48;2;255;146;146m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[4C\e[48;2;255;146;146m  \e[E");
    printf("\e[22C  \e[48;2;108;108;108m  \e[48;2;151;151;151m      \e[48;2;255;146;146m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[4C\e[48;2;255;146;146m  \e[E");
    printf("\e[24C\e[48;2;108;108;108m  \e[48;2;151;151;151m        \e[48;2;108;108;108m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[2C\e[48;2;255;146;146m  \e[E");
    printf("\e[24C\e[48;2;108;108;108m                  \e[48;2;255;146;146m  \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ratoganha() {
    printf("\e[13E");
    printf("\e[16C\e[48;2;108;108;108m      \e[14C      \e[E");
    printf("\e[14C  \e[48;2;151;151;151m      \e[48;2;108;108;108m  \e[10C  \e[48;2;151;151;151m      \e[48;2;108;108;108m  \e[E");
    printf("\e[14C  \e[48;2;151;151;151m  \e[48;2;255;200;206m    \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[6C  \e[48;2;151;151;151m  \e[48;2;255;200;206m      \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[14C  \e[48;2;151;151;151m  \e[48;2;255;200;206m    \e[48;2;151;151;151m  \e[48;2;108;108;108m        \e[48;2;151;151;151m  \e[48;2;255;200;206m        \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[14C  \e[48;2;151;151;151m    \e[48;2;255;200;206m  \e[48;2;108;108;108m  \e[48;2;151;151;151m            \e[48;2;255;200;206m      \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[16C    \e[48;2;0;0;0m    \e[48;2;151;151;151m    \e[48;2;0;0;0m    \e[48;2;151;151;151m          \e[48;2;108;108;108m  \e[E");
    printf("\e[20C\e[48;2;0;0;0m  \e[48;2;151;151;151m      \e[48;2;0;0;0m  \e[48;2;151;151;151m      \e[48;2;108;108;108m      \e[E");
    printf("\e[18C  \e[48;2;151;151;151m                \e[48;2;108;108;108m  \e[E");
    printf("\e[16C\e[48;2;255;146;146m  \e[48;2;151;151;151m              \e[48;2;108;108;108m  \e[48;2;151;151;151m  \e[48;2;108;108;108m  \e[E");
    printf("\e[18C              \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[E");
    printf("\e[24C  \e[48;2;151;151;151m  \e[48;2;255;255;255m    \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[6C\e[48;2;255;146;146m  \e[E");
    printf("\e[24C\e[48;2;108;108;108m  \e[48;2;151;151;151m          \e[48;2;108;108;108m  \e[4C\e[48;2;255;146;146m  \e[E");
    printf("\e[22C  \e[48;2;108;108;108m  \e[48;2;151;151;151m      \e[48;2;255;146;146m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[4C\e[48;2;255;146;146m  \e[E");
    printf("\e[22C  \e[48;2;108;108;108m  \e[48;2;151;151;151m      \e[48;2;255;146;146m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[4C\e[48;2;255;146;146m  \e[E");
    printf("\e[24C\e[48;2;108;108;108m  \e[48;2;151;151;151m        \e[48;2;108;108;108m  \e[48;2;151;151;151m    \e[48;2;108;108;108m  \e[2C\e[48;2;255;146;146m  \e[E");
    printf("\e[24C\e[48;2;108;108;108m                  \e[48;2;255;146;146m  \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapoperde() {
    printf("\e[13E");
    printf("\e[20C\e[48;2;0;0;0m  \e[4C  \e[8C  \e[4C  \e[E");
    printf("\e[18C\e[48;2;0;135;48m    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[4C    \e[48;2;0;0;0m    \e[48;2;0;117;39m    \e[E");
    printf("\e[18C\e[48;2;0;135;48m            \e[4C        \e[48;2;0;117;39m    \e[E");
    printf("\e[18C\e[48;2;0;135;48m            \e[4C            \e[E");
    printf("\e[18C    \e[48;2;0;0;0m      \e[48;2;0;135;48m  \e[4C    \e[48;2;0;0;0m      \e[48;2;0;135;48m  \e[E");
    printf("\e[14C          \e[48;2;0;140;244m    \e[48;2;0;135;48m            \e[48;2;0;140;244m    \e[48;2;0;135;48m  \e[E");
    printf("\e[14C        \e[48;2;0;86;23m  \e[48;2;0;140;244m    \e[48;2;0;135;48m            \e[48;2;0;140;244m    \e[48;2;0;135;48m  \e[E");
    printf("\e[14C        \e[48;2;0;86;23m                        \e[E");
    printf("\e[14C\e[48;2;0;135;48m                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                        \e[48;2;0;117;39m        \e[E");
    printf("\e[14C\e[48;2;0;135;48m                        \e[48;2;0;117;39m        \e[E");
    printf("\e[14C\e[48;2;0;154;59m    \e[48;2;0;135;48m                        \e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m    \e[48;2;0;135;48m                        \e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m        \e[4C\e[48;2;0;135;48m            \e[4C\e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m        \e[4C\e[48;2;0;135;48m            \e[4C\e[48;2;0;117;39m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_sapoganha() {
    printf("\e[13E");
    printf("\e[20C\e[48;2;0;0;0m  \e[4C  \e[10C    \e[E");
    printf("\e[18C\e[48;2;0;135;48m    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[4C  \e[48;2;0;0;0m  \e[48;2;0;135;48m    \e[48;2;0;0;0m  \e[48;2;0;117;39m  \e[E");
    printf("\e[18C\e[48;2;0;135;48m            \e[4C        \e[48;2;0;117;39m    \e[E");
    printf("\e[18C\e[48;2;0;135;48m    \e[48;2;0;0;0m      \e[48;2;0;135;48m  \e[4C    \e[48;2;0;0;0m      \e[48;2;0;135;48m  \e[E");
    printf("\e[18C    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[4C    \e[48;2;0;0;0m    \e[48;2;0;135;48m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;0;86;23m  \e[48;2;0;135;48m                      \e[E");
    printf("\e[14C        \e[48;2;0;86;23m                        \e[E");
    printf("\e[14C\e[48;2;0;135;48m                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                        \e[48;2;0;117;39m        \e[E");
    printf("\e[14C\e[48;2;0;135;48m                        \e[48;2;0;117;39m        \e[E");
    printf("\e[14C\e[48;2;0;154;59m    \e[48;2;0;135;48m                        \e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m    \e[48;2;0;135;48m                        \e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m        \e[4C\e[48;2;0;135;48m            \e[4C\e[48;2;0;117;39m    \e[E");
    printf("\e[14C\e[48;2;0;154;59m        \e[4C\e[48;2;0;135;48m            \e[4C\e[48;2;0;117;39m    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursoganha() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;107;68;56m            \e[8C            \e[E");
    printf("\e[14C            \e[8C            \e[E");
    printf("\e[14C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[8C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[E");
    printf("\e[14C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[8C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[E");
    printf("\e[14C                    \e[48;2;0;0;0m      \e[48;2;107;68;56m      \e[E");
    printf("\e[14C      \e[48;2;0;0;0m        \e[48;2;107;68;56m    \e[48;2;0;0;0m  \e[48;2;107;68;56m      \e[48;2;0;0;0m  \e[48;2;107;68;56m    \e[E");
    printf("\e[18C                        \e[E");
    printf("\e[18C    \e[48;2;0;0;0m      \e[48;2;107;68;56m      \e[48;2;0;0;0m      \e[48;2;107;68;56m  \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;107;68;56m        \e[48;2;0;0;0m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;107;68;56m        \e[48;2;0;0;0m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C            \e[48;2;0;0;0m        \e[48;2;107;68;56m            \e[E");
    printf("\e[14C        \e[48;2;120;76;63m    \e[48;2;0;0;0m        \e[48;2;120;76;63m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;120;76;63m      \e[48;2;0;0;0m    \e[48;2;120;76;63m    \e[48;2;0;0;0m  \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;120;76;63m  \e[48;2;0;0;0m              \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;120;76;63m                \e[48;2;107;68;56m        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_ursoperde() {
    printf("\e[13E");
    printf("\e[14C\e[48;2;107;68;56m            \e[8C            \e[E");
    printf("\e[14C            \e[8C            \e[E");
    printf("\e[14C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[8C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[E");
    printf("\e[14C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[8C    \e[48;2;255;146;146m    \e[48;2;107;68;56m    \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C        \e[48;2;0;0;0m      \e[48;2;107;68;56m      \e[48;2;0;0;0m      \e[48;2;107;68;56m      \e[E");
    printf("\e[18C                        \e[E");
    printf("\e[18C    \e[48;2;0;0;0m      \e[48;2;107;68;56m      \e[48;2;0;0;0m      \e[48;2;107;68;56m  \e[E");
    printf("\e[14C        \e[48;2;0;0;0m    \e[48;2;107;68;56m        \e[48;2;0;0;0m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C                                \e[E");
    printf("\e[14C            \e[48;2;0;0;0m        \e[48;2;107;68;56m            \e[E");
    printf("\e[14C        \e[48;2;120;76;63m    \e[48;2;0;0;0m        \e[48;2;120;76;63m    \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;120;76;63m      \e[48;2;0;0;0m    \e[48;2;120;76;63m      \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;0;0;0m                \e[48;2;107;68;56m        \e[E");
    printf("\e[14C        \e[48;2;120;76;63m          \e[48;2;237;0;0m      \e[48;2;107;68;56m        \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_animaisgrande (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatogrande();
        break;

        case 1:
        desenhar_coelhogrande();
        break;

        case 2:
        desenhar_sapogrande();
        break;

        case 3:
        desenhar_esquilogrande();
        break;

        case 4:
        desenhar_ratogrande();
        break;

        case 5:
        desenhar_ursogrande();
        break;
    }
}

void desenhar_animaisgrandeganha (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatoganha();
        break;

        case 1:
        desenhar_coelhoganha();
        break;

        case 2:
        desenhar_sapoganha();
        break;

        case 3:
        desenhar_esquiloganha();
        break;

        case 4:
        desenhar_ratoganha();
        break;

        case 5:
        desenhar_ursoganha();
        break;
    }
}

void desenhar_animaisgrandeperde (int ID) {
    switch (ID) {
        case 0:
        desenhar_gatoperde();
        break;

        case 1:
        desenhar_coelhoperde();
        break;

        case 2:
        desenhar_sapoperde();
        break;

        case 3:
        desenhar_esquiloperde();
        break;

        case 4:
        desenhar_ratoperde();
        break;

        case 5:
        desenhar_ursoperde();
        break;
    }
}

void desenhar_fundotipojogo() {
    printf("\e[48;2;0;0;0m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[48;2;19;19;19m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[48;2;29;29;29m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[48;2;35;35;35m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[48;2;43;43;43m                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("                                                                                                                                                            \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_novojogoaceso() {
    printf("\e[15E");
    printf("\e[28C\e[48;2;117;69;29m                                                                                                    \e[E");
    printf("\e[26C    \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m      \e[48;2;117;69;29m    \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m      \e[48;2;117;69;29m                \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m      \e[48;2;117;69;29m      \e[48;2;199;109;31m      \e[48;2;117;69;29m      \e[48;2;199;109;31m      \e[48;2;117;69;29m    \e[E");
    printf("\e[24C      \e[48;2;199;109;31m    \e[48;2;117;69;29m    \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m              \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m          \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[E");
    printf("\e[24C      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m              \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m    \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[E");
    printf("\e[24C      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m    \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m  \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[E");
    printf("\e[26C    \e[48;2;199;109;31m  \e[48;2;117;69;29m      \e[48;2;199;109;31m  \e[48;2;117;69;29m    \e[48;2;199;109;31m      \e[48;2;117;69;29m        \e[48;2;199;109;31m  \e[48;2;117;69;29m        \e[48;2;199;109;31m      \e[48;2;117;69;29m          \e[48;2;199;109;31m      \e[48;2;117;69;29m      \e[48;2;199;109;31m      \e[48;2;117;69;29m      \e[48;2;199;109;31m      \e[48;2;117;69;29m      \e[48;2;199;109;31m      \e[48;2;117;69;29m    \e[E");
    printf("\e[28C                                                                                                    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_novojogoapagado() {
    printf("\e[15E");
    printf("\e[28C\e[48;2;68;68;68m                                                                                                    \e[E");
    printf("\e[26C    \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m      \e[48;2;68;68;68m    \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m      \e[48;2;68;68;68m                \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m      \e[48;2;68;68;68m      \e[48;2;107;107;107m      \e[48;2;68;68;68m      \e[48;2;107;107;107m      \e[48;2;68;68;68m    \e[E");
    printf("\e[24C      \e[48;2;107;107;107m    \e[48;2;68;68;68m    \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m              \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m          \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[E");
    printf("\e[24C      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m              \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m    \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[E");
    printf("\e[24C      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m    \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m  \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[E");
    printf("\e[26C    \e[48;2;107;107;107m  \e[48;2;68;68;68m      \e[48;2;107;107;107m  \e[48;2;68;68;68m    \e[48;2;107;107;107m      \e[48;2;68;68;68m        \e[48;2;107;107;107m  \e[48;2;68;68;68m        \e[48;2;107;107;107m      \e[48;2;68;68;68m          \e[48;2;107;107;107m      \e[48;2;68;68;68m      \e[48;2;107;107;107m      \e[48;2;68;68;68m      \e[48;2;107;107;107m      \e[48;2;68;68;68m      \e[48;2;107;107;107m      \e[48;2;68;68;68m    \e[E");
    printf("\e[28C                                                                                                    \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_continuaraceso() {
    printf("\e[24E");
    printf("\e[44C\e[48;2;98;68;6m                                                                      \e[E");
    printf("\e[42C    \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m    \e[48;2;98;68;6m      \e[E");
    printf("\e[42C    \e[48;2;194;139;28m  \e[48;2;98;68;6m      \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m    \e[48;2;194;139;28m  \e[48;2;98;68;6m    \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m    \e[48;2;98;68;6m      \e[E");
    printf("\e[42C    \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m    \e[48;2;194;139;28m  \e[48;2;98;68;6m    \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m      \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m  \e[48;2;194;139;28m  \e[48;2;98;68;6m    \e[E");
    printf("\e[44C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

void desenhar_continuarapagado() {
    printf("\e[24E");
    printf("\e[44C\e[48;2;51;51;51m                                                                      \e[E");
    printf("\e[42C    \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m    \e[48;2;51;51;51m      \e[E");
    printf("\e[42C    \e[48;2;107;107;107m  \e[48;2;51;51;51m      \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m    \e[48;2;107;107;107m  \e[48;2;51;51;51m    \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m    \e[48;2;51;51;51m      \e[E");
    printf("\e[42C    \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m    \e[48;2;107;107;107m  \e[48;2;51;51;51m    \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m      \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m  \e[48;2;107;107;107m  \e[48;2;51;51;51m    \e[E");
    printf("\e[44C                                                                      \e[E");
    printf("\e[0m");
    printf("\e[H");
}

#endif