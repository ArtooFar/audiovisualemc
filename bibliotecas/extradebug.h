//Biblioteca Própria //
#ifndef EXTRADEBUG_H
#define EXTRADEBUG_H

void debug_mostrarBaralhos(tp_carta *baralhoReferencia, opc opcoes, tp_pilhaSEcarta *baralhoJogo) {
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[5EBaralho Embaralhado P:\n");
    baralho_printarP(baralhoJogo);
    printf("\e[5E");
    programa_pausar();
    limparTela();
    printf("-> Opção de Debug ligada, mostrando Baralhos:\n");
    printf("\e[2EBaralho Embaralhado G:\n");
    baralho_printarG(baralhoJogo);
    printf("\e[10E");
    programa_pausar();
    limparTela();
}

void debug_jogador_inicializacao(tp_jogador *jogador) {

    for(int i=0;i<15;i++){
        jogador->comparadorValor[i].quant=0;
        jogador->comparadorValor[i].naipeMaisAlto=-1;
        jogador->comparadorValor[i].naipeMaisAltoReserva=-1;
        jogador->comparadorValor[i].valorMaisAlto=-1;
        jogador->comparadorValor[i].valorMaisAltoReserva=-1;
    }

    for(int i=0;i<4;i++){
        jogador->comparadorNaipe[i].quant=0;
        jogador->comparadorNaipe[i].naipeMaisAlto=-1;
        jogador->comparadorNaipe[i].naipeMaisAltoReserva=-1;
        jogador->comparadorNaipe[i].valorMaisAlto=-1;
        jogador->comparadorNaipe[i].valorMaisAltoReserva=-1;
    }

    jogador->combinacoes.par.quant=0;
    jogador->combinacoes.par.naipeMaisAlto=-1;
    jogador->combinacoes.par.valorMaisAlto=-1;
    jogador->combinacoes.par.naipeMaisAltoReserva=-1;
    jogador->combinacoes.par.valorMaisAltoReserva=-1;

    jogador->combinacoes.trinca.quant=0;
    jogador->combinacoes.trinca.naipeMaisAlto=-1;
    jogador->combinacoes.trinca.valorMaisAlto=-1;
    jogador->combinacoes.trinca.naipeMaisAltoReserva=-1;
    jogador->combinacoes.trinca.valorMaisAltoReserva=-1;

    jogador->combinacoes.straight.quant=0;
    jogador->combinacoes.straight.naipeMaisAlto=-1;
    jogador->combinacoes.straight.valorMaisAlto=-1;
    jogador->combinacoes.straight.naipeMaisAltoReserva=-1;
    jogador->combinacoes.straight.valorMaisAltoReserva=-1;

    jogador->combinacoes.flush.quant=0;
    jogador->combinacoes.flush.naipeMaisAlto=-1;
    jogador->combinacoes.flush.valorMaisAlto=-1;
    jogador->combinacoes.flush.naipeMaisAltoReserva=-1;
    jogador->combinacoes.flush.valorMaisAltoReserva=-1;

    jogador->combinacoes.fullHouse.quant=0;
    jogador->combinacoes.fullHouse.naipeMaisAlto=-1;
    jogador->combinacoes.fullHouse.valorMaisAlto=-1;
    jogador->combinacoes.fullHouse.naipeMaisAltoReserva=-1;
    jogador->combinacoes.fullHouse.valorMaisAltoReserva=-1;

    jogador->combinacoes.quadra.quant=0;
    jogador->combinacoes.quadra.naipeMaisAlto=-1;
    jogador->combinacoes.quadra.valorMaisAlto=-1;
    jogador->combinacoes.quadra.naipeMaisAltoReserva=-1;
    jogador->combinacoes.quadra.valorMaisAltoReserva=-1;

    jogador->combinacoes.straightFlush.quant=0;
    jogador->combinacoes.straightFlush.naipeMaisAlto=-1;
    jogador->combinacoes.straightFlush.valorMaisAlto=-1;
    jogador->combinacoes.straightFlush.naipeMaisAltoReserva=-1;
    jogador->combinacoes.straightFlush.valorMaisAltoReserva=-1;

    jogador->combinacoes.royalFlush.quant=0;
    jogador->combinacoes.royalFlush.naipeMaisAlto=-1;
    jogador->combinacoes.royalFlush.valorMaisAlto=-1;
    jogador->combinacoes.royalFlush.naipeMaisAltoReserva=-1;
    jogador->combinacoes.royalFlush.valorMaisAltoReserva=-1;
}

void debug_jogador_escolherNomes(tp_jogador jogador[],int quant){
    int cont=0;
    char nomes[6][20]={"Felix","Marzia","Cinna","Ludwig","Jaiden","Pedro"};

    for(int i=0;i<quant;i++){
        switch(cont){
            case 0:
            strcpy(jogador[i].cor,"38;2;38;198;218");
            break;

            case 1:
            strcpy(jogador[i].cor,"38;2;255;23;68");
            break;

            case 2:
            strcpy(jogador[i].cor,"38;2;205;220;57");
            break;

            case 3:
            strcpy(jogador[i].cor,"38;2;255;152;0");
            break;

            case 4:
            strcpy(jogador[i].cor,"38;2;213;0;249");
            break;

            case 5:
            strcpy(jogador[i].cor,"38;2;255;209;128");
            break;
        }


        jogador[i].ID=i;
        jogador[i].aposta=0;
        jogador[i].desistir=0;
        jogador[i].allIn=0;

        jogador[i].maiorInfo.naipe=-1;
        jogador[i].maiorInfo.valor=-1;
        
        debug_jogador_inicializacao(&jogador[i]);

        strcpy(jogador[i].nome,nomes[i]);
        cont++;
    }
    limparTela();
    printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("                          TODOS OS JOGADORES CADASTRADOS                           \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i=0; i<quant;i++) {
        printf("\e[%sm",jogador[i].cor);
        printf("  Jogador [%d]: %s\n",i+1,jogador[i].nome);
        printf("\e[39m");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}



void debug_jogador_escolherNomes_discreto(tp_jogador jogador[],int quant){
    int cont=0;
    char nomes[6][20]={"Felix","Marzia","Cinna","Ludwig","Jaiden","Pedro"};

    for(int i=0;i<quant;i++){
        switch(cont){
            case 0:
            strcpy(jogador[i].cor,"38;2;38;198;218");
            break;

            case 1:
            strcpy(jogador[i].cor,"38;2;255;23;68");
            break;

            case 2:
            strcpy(jogador[i].cor,"38;2;205;220;57");
            break;

            case 3:
            strcpy(jogador[i].cor,"38;2;255;152;0");
            break;

            case 4:
            strcpy(jogador[i].cor,"38;2;213;0;249");
            break;

            case 5:
            strcpy(jogador[i].cor,"38;2;255;209;128");
            break;
        }


        jogador[i].ID=i;
        jogador[i].dinheiro=1000;
        jogador[i].aposta=0;
        jogador[i].desistir=0;

        jogador[i].maiorInfo.naipe=-1;
        jogador[i].maiorInfo.valor=-1;
        
        debug_jogador_inicializacao(&jogador[i]);

        strcpy(jogador[i].nome,nomes[i]);
        cont++;
    }
}

void debug_mostrarMaos (tp_pilhaSEcarta *baralhoJogo,tp_jogador jogador[],int quant) {
    printf("Maos dos jogadores:\n");
    for (int i=0;i<quant;i++){
        printf("Jogador %d: ",i);
        carta_printarP(&jogador[i].mao->info);
        carta_printarP(&jogador[i].mao->prox->info);
        printf("\n\n\n\n");
    }
    programa_pausar();
    limparTela();

    printf("Mão da mesa:\n");

    int cont=0;
    tp_pilhaSEcarta *pilha_aux;
    tp_pilhaSEcarta_item carta;
    pilha_aux=pilhaSEcarta_inicializar();
    
    while (cont<5) {
        pilhaSEcarta_pop(baralhoJogo,&carta);
        carta_printarP(&carta);
        fflush(stdout);
        pilhaSEcarta_push(pilha_aux, carta);
        cont++;  
    }
   
    while (!pilhaSEcarta_verificar_vazia(pilha_aux)) {
        pilhaSEcarta_pop(pilha_aux,&carta);
        pilhaSEcarta_push(baralhoJogo, carta);           
    }

    pilha_aux = pilhaSEcarta_destruir(pilha_aux);

    printf("\n\n\n\n");
    programa_pausar();
    limparTela();
}

#endif