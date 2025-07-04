//Biblioteca Própria //
#ifndef CARTAS_H
#define CARTAS_H
#include <stdio.h>
#include <string.h>


typedef struct {
    int ID;
    int naipe; // ♥(0)[copas], ♦(1)[ouros], ♠(2)[espadas], ♣(3)[paus]
    int valor_i; //2,3,4,5,6,7,8,9,10,11,12,13,14
    char valor_c[4]; //A,2,3,4,5,6,7,8,9,J,Q,K
}tp_carta;

#include "listasecarta.h"
#include "pilhasecarta.h"
#include "jogador.h"

int carta_setarvalor(tp_carta *carta, int valor) {
    // Seta o valor da carta atual do baralho para "valor".
    // ele guarda o valor de 2 formas diferentes, uma em caractere (A,2 a 10, J, Q e K) e outra em int (1 a 13)
    switch (valor) {
        case 1:
        strcpy(carta->valor_c, "A");
        carta->valor_i = 14;
        break;

        case 2:
        strcpy(carta->valor_c, "2");
        carta->valor_i = valor;
        break;

        case 3:
        strcpy(carta->valor_c, "3");
        carta->valor_i = valor;
        break;

        case 4:
        strcpy(carta->valor_c, "4");
        carta->valor_i = valor;
        break;

        case 5:
        strcpy(carta->valor_c, "5");
        carta->valor_i = valor;
        break;

        case 6:
        strcpy(carta->valor_c, "6");
        carta->valor_i = valor;
        break;

        case 7:
        strcpy(carta->valor_c, "7");
        carta->valor_i = valor;
        break;

        case 8:
        strcpy(carta->valor_c, "8");
        carta->valor_i = valor;
        break;

        case 9:
        strcpy(carta->valor_c, "9");
        carta->valor_i = valor;
        break;

        case 10:
        strcpy(carta->valor_c, "10");
        carta->valor_i = valor;
        break;

        case 11:
        strcpy(carta->valor_c, "J");
        carta->valor_i = valor;
        break;

        case 12:
        carta->valor_i = valor;
        strcpy(carta->valor_c, "Q");
        break;

        case 13:
        strcpy(carta->valor_c, "K");
        carta->valor_i = valor;
        break;

        default:
        return 0;
    }
    return 1;
}

void baralhoReferencia_inicializar(tp_carta *baralhoReferencia) {
    // Monta o baralho de forma organizada
    // Baralho precisa ser um vetor de struct tp_carta de tamanho 52
    for(int i=0;i<52;i++){
        baralhoReferencia[i].ID = (i+1);
        baralhoReferencia[i].naipe = (i/13);
        carta_setarvalor(&baralhoReferencia[i], ((i%13)+1));
    }
}

void carta_printarP(tp_carta *carta) {
    // Printa a carta dada
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
 
        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m    \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D    \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[31m\e[1m%s\e[22m\e[39m   \e[1B\e[5D  \e[31m\e[1m%s\e[22m\e[39m  \e[1B\e[5D   \e[31m\e[1m%s\e[22m\e[39m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m    \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D    \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("     \e[1B\e[5D\e[107;30m\e[1m%s\e[22m   \e[1B\e[5D  \e[1m%s\e[22m  \e[1B\e[5D   \e[1m%s\e[22m\e[49;39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        }
    printf("\e[3A\e[1C");
}

void carta_printarP_verso() {
    // Printa a carta dada
    printf("     \e[1B\e[5D\e[41;37m\e[1mx\e[22mxxxx\e[1B\e[5Dxx\e[1mx\e[22mxx\e[1B\e[5Dxxxx\e[1mx\e[22m\e[49;39m");
    printf("\e[3A\e[1C");
}

void carta_printarG_verso() {
    // Printa a carta dada
    printf("         \e[1B\e[9D\e[41;37mXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[1B\e[9DXXXXXXXXX\e[49m\e[39m");
    printf("\e[7A\e[1C");
}

void carta_printarG(tp_carta *carta) {
    // Printa a carta dada
    char  simbolo_naipe[4][8] = {"\u2665", "\u2666", "\u2660", "\u2663"};  // ♥, ♦, ♠, ♣;
 
        if(carta->naipe == 0 || carta->naipe == 1) {
            //Para as cartas de naipe vermelho
            if(carta->valor_i != 10) printf("         \e[1B\e[9D\e[107m\e[91m         \e[1B\e[9D  %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s  \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("         \e[1B\e[9D\e[107m\e[91m         \e[1B\e[9D %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
    
        } else {
            //Para as cartas de naipe preto
            if(carta->valor_i != 10) printf("         \e[1B\e[9D\e[107m\e[30m         \e[1B\e[9D  %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s  \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
            else printf("         \e[1B\e[9D\e[107m\e[30m         \e[1B\e[9D %s      \e[1B\e[9D         \e[1B\e[9D    %s    \e[1B\e[9D         \e[1B\e[9D      %s \e[1B\e[9D         \e[49m\e[39m",carta->valor_c,simbolo_naipe[carta->naipe],carta->valor_c);
        }

    printf("\e[7A\e[1C");
}

void baralho_printarP (tp_pilhaSEcarta *baralhoJogo) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralhoJogo usando cartas pequenas
    //Precisa receber uma pilhaSEcarta 
    int cont=0;
    tp_pilhaSEcarta *pilha_aux;
    tp_pilhaSEcarta_item carta;
    //cria e inicializa uma pilha auxiliar
    pilha_aux=pilhaSEcarta_inicializar();
    
    while (!pilhaSEcarta_verificar_vazia(baralhoJogo))
          {
           pilhaSEcarta_pop(baralhoJogo,&carta);
           carta_printarP(&carta);
           fflush(stdout);
           pilhaSEcarta_push(pilha_aux, carta);
           if (cont==12||cont==25||cont==38||cont==51) printf("\e[5E");
           cont++;           
           }
   
   while (!pilhaSEcarta_verificar_vazia(pilha_aux))
          {
           pilhaSEcarta_pop(pilha_aux,&carta);
           pilhaSEcarta_push(baralhoJogo, carta);           
           }
    pilha_aux = pilhaSEcarta_destruir(pilha_aux);

}

void baralho_printarG (tp_pilhaSEcarta *baralhoJogo) {
    //Provavelmente inútil para o funcionamente do jogo
    //Printa todo o baralhoJogo usando cartas grandes
    //Precisa receber uma pilhaSEcarta 

    int cont=0;
    tp_pilhaSEcarta *pilha_aux;
    tp_pilhaSEcarta_item carta;
    //cria e inicializa uma pilha auxiliar
    pilha_aux=pilhaSEcarta_inicializar();
    
    while (!pilhaSEcarta_verificar_vazia(baralhoJogo))
          {
           pilhaSEcarta_pop(baralhoJogo,&carta);
           carta_printarG(&carta);
           fflush(stdout);
           pilhaSEcarta_push(pilha_aux, carta);
           if (cont==12||cont==25||cont==38||cont==51) printf("\e[8E");
           cont++;  
           }
   
   while (!pilhaSEcarta_verificar_vazia(pilha_aux))
          {
           pilhaSEcarta_pop(pilha_aux,&carta);
           pilhaSEcarta_push(baralhoJogo, carta);           
           }
    pilha_aux = pilhaSEcarta_destruir(pilha_aux);

}


int baralho_embaralhar(tp_carta baralhoReferencia[],tp_pilhaSEcarta *baralhoJogo){
    int aleat;
    tp_carta aux;
    for(int i=0;i<52;i++){
        aleat=aleatorio(i, 51);
        aux = baralhoReferencia[i];
        baralhoReferencia[i] = baralhoReferencia[aleat];
        baralhoReferencia[aleat] = aux;
    }
    for (int i=0;i<52;i++){
        pilhaSEcarta_push(baralhoJogo,baralhoReferencia[i]);
    }
}

int baralho_distribuirCartas_jogadores(tp_pilhaSEcarta *baralhoJogo, tp_jogador jogador[], int quant){
    tp_pilhaSEcarta_item e;
    for(int i = 0; i < quant; i++){
        if (!pilhaSEcarta_pop(baralhoJogo, &e)) return 0;
        listaSEcarta_inserir_inicio(&jogador[i].mao, e);

        jogador[i].maiorInfo.valor=e.valor_i;
        jogador[i].maiorInfo.valorReserva=e.valor_i;

        if (!pilhaSEcarta_pop(baralhoJogo, &e)) return 0;

        if (e.valor_i>jogador[i].maiorInfo.valor) jogador[i].maiorInfo.valor=e.valor_i;
        else jogador[i].maiorInfo.valorReserva=e.valor_i;

        listaSEcarta_inserir_inicio(&jogador[i].mao, e);

    }
    return 1;
}

int baralho_distribuirCartas_mesa(tp_pilhaSEcarta *baralhoJogo, tp_listasecarta **mao_mesa){
    tp_pilhaSEcarta_item e;
    pilhaSEcarta_pop(baralhoJogo, &e);
    listaSEcarta_inserir_inicio(mao_mesa, e);


}








#endif