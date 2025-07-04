//Biblioteca Própria //
#ifndef COMBINACOES_H
#define COMBINACOES_H

#include "listadecarta.h"

int vetor_inteiro_busca_maiorValor(const int vet[], int ini, int fim) {
    int maior  = vet[ini];
    int indice = ini;

    for (int i = ini + 1; i <= fim; i++) {
        if (vet[i] > maior) {
            maior  = vet[i];
            indice = i;
        } else if (vet[i] == maior) {
            indice = i;
        }
    }
    return indice;
}


int vetor_inteiro_maiorValor(int vet[],int ini,int fim) {
    int maior=0;

    for(int i=ini;i<=fim;i++){
        if (vet[i]>=maior) maior=vet[i];
    }

    return maior;
}

int combinacoes_criar_vetorDeCartas(tp_carta cartas[],int *ncartas, tp_listasecarta *mao_jogador,tp_jogador *jogador, tp_listasecarta *mao_mesa){
    
    int cartas_da_mesa = listaSEcarta_verificar_tamanho(mao_mesa);
    *ncartas = (cartas_da_mesa + 2);
    
    int numcartas = *ncartas;

    int cont = 0;
    tp_listasecarta *atu = mao_jogador;

    while (cont < 2) {
        cartas[cont]=atu->info;
        if (jogador->maiorInfo.naipe < cartas[cont].naipe) jogador->maiorInfo.naipe=cartas[cont].naipe;

        atu = atu->prox;
        cont++;
    }

    atu = mao_mesa;
    while (cont < numcartas) {
        cartas[cont]=atu->info;
        atu = atu->prox;
        cont++;
    }

}

//Tentativa de Combinação de 1 par
int combinacoes_verificar_valores (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador,tp_combinacaoInfo comparadorValor[]) {

    tp_carta cartas[7];
    int numcartas;
    combinacoes_criar_vetorDeCartas(cartas,&numcartas,mao_jogador,jogador,mao_mesa);
   
    
    for(int i=0;i<numcartas;i++) {
        jogador->comparadorValor[cartas[i].valor_i].quant+=1;
        
        if (jogador->comparadorValor[cartas[i].valor_i].naipeMaisAlto < cartas[i].naipe) {
            jogador->comparadorValor[cartas[i].valor_i].naipeMaisAltoReserva = jogador->comparadorValor[cartas[i].valor_i].naipeMaisAlto;
            jogador->comparadorValor[cartas[i].valor_i].naipeMaisAlto=cartas[i].naipe;
        }
    }

    int pares=0;
    int trincas=0;
    int quadras=0;

    for(int i=0;i<15;i++) {
        if (jogador->comparadorValor[i].quant == 2) pares++;
        if (jogador->comparadorValor[i].quant == 3) trincas++;
        if (jogador->comparadorValor[i].quant == 4) quadras++;
    }

    for (int i=0;i<15;i++){
        if (jogador->comparadorValor[i].quant==2) {

            jogador->combinacoes.par.quant = pares;
            if (jogador->combinacoes.par.valorMaisAlto < i) {
                jogador->combinacoes.par.valorMaisAltoReserva = jogador->combinacoes.par.valorMaisAlto;
                jogador->combinacoes.par.valorMaisAlto = i;
            }

            if (jogador->combinacoes.par.naipeMaisAlto < comparadorValor[i].naipeMaisAlto) {
                jogador->combinacoes.par.naipeMaisAltoReserva = jogador->combinacoes.par.naipeMaisAlto;
                jogador->combinacoes.par.naipeMaisAlto = comparadorValor[i].naipeMaisAlto;
            }
        }

        else if (jogador->comparadorValor[i].quant==3) {

            jogador->combinacoes.trinca.quant = trincas;

            if (jogador->combinacoes.trinca.valorMaisAlto < i) {
                jogador->combinacoes.trinca.valorMaisAltoReserva = jogador->combinacoes.trinca.valorMaisAlto;
                jogador->combinacoes.trinca.valorMaisAlto = i;
            }

            if (jogador->combinacoes.trinca.naipeMaisAlto < comparadorValor[i].naipeMaisAlto) {
                jogador->combinacoes.trinca.naipeMaisAltoReserva = jogador->combinacoes.trinca.naipeMaisAlto;
                jogador->combinacoes.trinca.naipeMaisAlto = comparadorValor[i].naipeMaisAlto;
            }
        }

        else if (jogador->comparadorValor[i].quant==4) {

            jogador->combinacoes.quadra.quant = quadras;

            if (jogador->combinacoes.quadra.valorMaisAlto < i) {
                jogador->combinacoes.quadra.valorMaisAltoReserva = jogador->combinacoes.quadra.valorMaisAlto;
                jogador->combinacoes.quadra.valorMaisAlto = i;
            }

            if (jogador->combinacoes.quadra.naipeMaisAlto < comparadorValor[i].naipeMaisAlto) {
                jogador->combinacoes.quadra.naipeMaisAltoReserva = jogador->combinacoes.quadra.naipeMaisAlto;
                jogador->combinacoes.quadra.naipeMaisAlto = comparadorValor[i].naipeMaisAlto;
            }
        }
    }

    if (pares > 0 && trincas == 1) {
        jogador->combinacoes.fullHouse.quant=1;
        jogador->combinacoes.fullHouse.naipeMaisAlto = ((jogador->combinacoes.par.naipeMaisAlto * 2) + (jogador->combinacoes.trinca.naipeMaisAlto * 3));
        jogador->combinacoes.fullHouse.valorMaisAlto = ((jogador->combinacoes.par.valorMaisAlto * 2) + (jogador->combinacoes.trinca.valorMaisAlto * 3));
    }
}

int combinacoes_verificar_naipes (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador,tp_combinacaoInfo comparadorValor[]) {

    tp_carta cartas[7];
    int numcartas;
    combinacoes_criar_vetorDeCartas(cartas,&numcartas,mao_jogador,jogador,mao_mesa);
   
    
    for(int i=0;i<numcartas;i++) {
        
        jogador->comparadorNaipe[cartas[i].naipe].quant+=1;
        
        if (jogador->comparadorNaipe[cartas[i].naipe].valorMaisAlto < cartas[i].valor_i) {
            jogador->comparadorNaipe[cartas[i].naipe].valorMaisAltoReserva = jogador->comparadorNaipe[cartas[i].naipe].valorMaisAlto;
            jogador->comparadorNaipe[cartas[i].naipe].valorMaisAlto=cartas[i].valor_i;
        }
    }
    

    int flush=0;


    for(int i=0;i<4;i++) {
        if (jogador->comparadorNaipe[i].quant >= 5) flush++;
    }

    for (int i=0;i<4;i++){
        if (jogador->comparadorNaipe[i].quant>=5) {

            jogador->combinacoes.flush.quant = flush;

            if (jogador->combinacoes.flush.naipeMaisAlto < i) {
                jogador->combinacoes.flush.naipeMaisAltoReserva = jogador->combinacoes.flush.naipeMaisAlto;
                jogador->combinacoes.flush.naipeMaisAlto = i;
            } 

            if (jogador->combinacoes.flush.naipeMaisAlto < jogador->comparadorNaipe[i].naipeMaisAlto) {
                jogador->combinacoes.flush.naipeMaisAltoReserva = jogador->combinacoes.flush.naipeMaisAlto;
                jogador->combinacoes.flush.naipeMaisAlto = jogador->comparadorNaipe[i].naipeMaisAlto;
            }
        }
    }
}

int combinacoes_ordenarMao(tp_carta cartas[],tp_listadecarta *maoOrdenada,int numcartas){
    for(int i=0;i<numcartas;i++) {
        listaDEcarta_inserir_ordenado(maoOrdenada,cartas[i]);
    }
}

int combinacoes_criar_vetorDeSequencia(tp_listadecarta *maoOrdenada,int contSequencia[],int numcartas) {
    tp_listadecarta_no *atual = maoOrdenada->ini;
    int ultimovalor=-1;

    for (int i=0;i<numcartas;i++) {
        if (atual->info.valor_i==(ultimovalor+1)) contSequencia[i]=contSequencia[i-1]+1;
        else if (atual->info.valor_i==ultimovalor) contSequencia[i]=contSequencia[i-1];
        else contSequencia[i]=0;
        ultimovalor=atual->info.valor_i;
        atual=atual->prox;
    }

}

int combinacoes_sequencias_retirar_fim(tp_listadecarta *maoOrdenada,int numcartas,int PosMaiorSequencia){
    tp_listadecarta_no *atual = maoOrdenada->fim;
        
    int PosAVoltar = (numcartas-1) - PosMaiorSequencia;
    for(int i=0;i<PosAVoltar;i++){
        maoOrdenada->fim=atual->ant;
        free(atual);
        maoOrdenada->fim->prox=NULL;
        atual = maoOrdenada->fim;
    }
}

int combinacoes_sequencias_retirar_inicio(tp_listadecarta *maoOrdenada,int maiorSequencia){
    tp_listadecarta_no *atual = maoOrdenada->fim;
    int valorMax = atual->info.valor_i;
    int valorMin = valorMax - maiorSequencia;

    atual = maoOrdenada->ini;
    while (atual->info.valor_i!=valorMin) {
        maoOrdenada->ini=atual->prox;
        free(atual);
        maoOrdenada->ini->ant=NULL;
        atual = maoOrdenada->ini;
    }
}

int combinacoes_sequencias_verificar_straightFlush(tp_jogador *jogador, tp_listadecarta *maoOrdenada,int numcartas) {
    
    for(int i=0;i<4;i++){
        jogador->comparadorNaipe[i].quant=0;
    }

    tp_listadecarta_no *atual = maoOrdenada->ini;
    while(atual!=NULL) {
        jogador->comparadorNaipe[atual->info.naipe].quant+=1;
        atual=atual->prox;
    }

    for(int i=0;i<4;i++) {
        if (jogador->comparadorNaipe[i].quant >= 5) {
            atual = maoOrdenada->ini;
            while(atual!=NULL) {
                if (atual->info.naipe == i) {
                    jogador->combinacoes.straightFlush.valorMaisAlto=atual->info.valor_i;
                }
                atual=atual->prox;
            }
            jogador->combinacoes.straightFlush.quant=1;
            jogador->combinacoes.straightFlush.naipeMaisAlto=i;
        }
    }
}

int combinacoes_verificar_sequencias (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador) {

    tp_carta cartas[7];
    int numcartas;
    combinacoes_criar_vetorDeCartas(cartas,&numcartas,mao_jogador,jogador,mao_mesa);

    tp_listadecarta *maoOrdenada;
    maoOrdenada = listaDEcarta_inicializar();
    combinacoes_ordenarMao(cartas,maoOrdenada,numcartas);

    int contSequencia[8]={0,0,0,0,0,0,0,0};  
    combinacoes_criar_vetorDeSequencia(maoOrdenada,contSequencia,numcartas);

    int maiorSequencia = vetor_inteiro_maiorValor(contSequencia,0,6);
    int PosMaiorSequencia = vetor_inteiro_busca_maiorValor(contSequencia,0,6);

    combinacoes_sequencias_retirar_fim(maoOrdenada,numcartas,PosMaiorSequencia);
    combinacoes_sequencias_retirar_inicio(maoOrdenada,maiorSequencia);

    if (maiorSequencia>=4) {
        jogador->combinacoes.straight.quant=1;
        jogador->combinacoes.straight.valorMaisAlto = maoOrdenada->fim->info.valor_i;
    }

    combinacoes_sequencias_verificar_straightFlush(jogador, maoOrdenada, numcartas);
}

int vec(tp_carta vet[],int tam, int ID){
//vetor_verificar_existenciaCarta
    for(int i=0;i<tam;i++){
        if (vet[i].ID==ID) return 1;
    }
    return 0;
}

int combinacoes_verificar_royalFlush (tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador) {
    tp_carta cartas[7];
    int numcartas;
    combinacoes_criar_vetorDeCartas(cartas,&numcartas,mao_jogador,jogador,mao_mesa);
   
    if (vec(cartas,numcartas, 10) && vec(cartas,numcartas, 11) && vec(cartas,numcartas, 12) && vec(cartas,numcartas, 13) && vec(cartas,numcartas, 1)) {
        jogador->combinacoes.royalFlush.quant=1;
        jogador->combinacoes.royalFlush.naipeMaisAlto=0;
    }
    else if (vec(cartas,numcartas, 23) && vec(cartas,numcartas, 24) && vec(cartas,numcartas, 25) && vec(cartas,numcartas, 26) && vec(cartas,numcartas, 14)) {
        jogador->combinacoes.royalFlush.quant=1;
        jogador->combinacoes.royalFlush.naipeMaisAlto=1;
    }
    else if (vec(cartas,numcartas, 36) && vec(cartas,numcartas, 37) && vec(cartas,numcartas, 38) && vec(cartas,numcartas, 39) && vec(cartas,numcartas, 27)) {
        jogador->combinacoes.royalFlush.quant=1;
        jogador->combinacoes.royalFlush.naipeMaisAlto=2;
    }
    else if (vec(cartas,numcartas, 49) && vec(cartas,numcartas, 50) && vec(cartas,numcartas, 51) && vec(cartas,numcartas, 52) && vec(cartas,numcartas, 40)) {
        jogador->combinacoes.royalFlush.quant=1;
        jogador->combinacoes.royalFlush.naipeMaisAlto=3;
    }
}

int combinacao_imprimir_maocombinada(tp_jogador *jogador, tp_listasecarta *mao_mesa, tp_listasecarta *mao_jogador){
    
    tp_carta cartas[7];
    int numcartas;
    combinacoes_criar_vetorDeCartas(cartas,&numcartas,mao_jogador,jogador,mao_mesa);

    tp_listadecarta *maoOrdenada;
    maoOrdenada = listaDEcarta_inicializar();
    combinacoes_ordenarMao(cartas,maoOrdenada,numcartas);

    tp_listadecarta_no *atual = maoOrdenada->ini;
    while (atual!= NULL) {
        carta_printarP(&(atual->info));
        atual=atual->prox;
    }

    printf("\n\n\n\n");
}

#endif