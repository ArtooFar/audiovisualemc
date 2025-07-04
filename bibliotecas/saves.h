#ifndef SAVES_H
#define SAVES_H

int arq_lerSavesInt (int *variavel, char scan[], char formato[]){
// Função para obter valores para uma variável cujos valores estão dentro deu um opcoes.txt
// Parametros: end.de memória da variável cujo valor será obtido / string a ser comparada com a linha escaneada / formatação da string q a variável tá inserida
// EXEMPLO DE USO: arq_lerOpcoes(&modoJogo,"Modo_de_Jogo =","Modo de Jogo = %d");
    FILE *arq = fopen("saves/ultimaPartida_save.txt", "r");
    if (!arq) return 0;

    char linha[200];
    int  veri = 0;

    while (fgets(linha, sizeof linha, arq)) {
        if (str_iniciaCom(linha, scan)) {
            if (sscanf(linha, formato, variavel) == 1) veri = 1;
            break;
        }
    }

    fclose(arq);
    
    return veri;
}

int arq_lerSavesFloat (float *variavel, char scan[], char formato[]){
// Função para obter valores para uma variável cujos valores estão dentro deu um opcoes.txt
// Parametros: end.de memória da variável cujo valor será obtido / string a ser comparada com a linha escaneada / formatação da string q a variável tá inserida
// EXEMPLO DE USO: arq_lerOpcoes(&modoJogo,"Modo_de_Jogo =","Modo de Jogo = %d");
    FILE *arq = fopen("saves/ultimaPartida_save.txt", "r");
    if (!arq) return 0;

    char linha[200];
    int  veri = 0;

    while (fgets(linha, sizeof linha, arq)) {
        if (str_iniciaCom(linha, scan)) {
            if (sscanf(linha, formato, variavel) == 1) veri = 1;
            break;
        }
    }

    fclose(arq);
    
    return veri;
}

int arq_lerSavesString (char variavel[], char scan[], char formato[]) {

// EXEMPLO DE USO:
//   char nome[100];
//   arq_lerSavesString(nome, "Jogador[0].nome =", "Jogador[%*d].nome = (%[^)])");

    FILE *arq;
    char linha[256];

    arq = fopen("saves/ultimaPartida_save.txt", "r");
    if (!arq) return 0;

    while (fgets(linha, sizeof(linha), arq) != NULL) {
        if (str_iniciaCom(linha, scan)) {
            if (sscanf(linha, formato, variavel) == 1) {
                fclose(arq);
                return 1;
            }
        }
    }
    fclose(arq);
    return 0;
}

int saves_salvar_partida(tp_jogador jogadores[],tp_pote *pote,char arqnome[],int pokervencedor){
    
    FILE *arq = fopen(arqnome,"w");
    if (!arq) return 0;

    fprintf(arq,"QuantidadeJogadores = %d\n",pote->quantidadeJogadores);
    fprintf(arq,"JogadorVencedorID: %d\n",pokervencedor);
    for(int i=0;i<pote->quantidadeJogadores;i++){
        fprintf(arq,"Jogador[%d].nome = %s\n",i,jogadores[i].nome);
        fprintf(arq,"Jogador[%d].dinheiro = %.2f\n",i,jogadores[i].dinheiro);
    }

    fclose(arq);
    return 1;
}

void saves_configurar_jogador(tp_jogador jogador[],int quant){
    int cont=0;

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
        
        jogador_inicializacao(&jogador[i]);
        cont++;
    }
}

int saves_carregar_partida(tp_jogador jogadores[],tp_pote *pote){

    if (!arq_lerSavesInt(&(pote->quantidadeJogadores),"QuantidadeJogadores = ","QuantidadeJogadores = %d")) return 0;


    char par1[100],par11[100],par2[100],par22[100];

    for(int i=0;i<pote->quantidadeJogadores;i++) {
        sprintf(par1,"Jogador[%d].nome = ",i);
        sprintf(par11, "Jogador[%d].nome = %%[^\n]", i);
        sprintf(par2,"Jogador[%d].dinheiro = ",i);
        sprintf(par22,"Jogador[%d].dinheiro = %%f",i);

        if (!arq_lerSavesString(jogadores[i].nome,par1,par11)) return 0;
        if (!arq_lerSavesFloat(&(jogadores[i].dinheiro),par2,par22)) return 0;
    }
    saves_configurar_jogador(jogadores,pote->quantidadeJogadores);
    return 1;
}

void saves_imprimir (tp_jogador jogadores[], tp_pote *pote){
    limparTela();
    printf("-==-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    printf("                          TODOS OS JOGADORES CADASTRADOS                           \n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
    for (int i=0; i<pote->quantidadeJogadores;i++) {
        printf("\e[%sm",jogadores[i].cor);
        printf("  Jogador [%d]: [%s] [R$ %.2f]\n",i+1,jogadores[i].nome,jogadores[i].dinheiro);
        printf("\e[39m");
    }
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=\n");
}





#endif