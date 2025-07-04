#ifndef HISTORICO_H
#define HISTORICO_H

#include <stdio.h>
#include <string.h>

char nomeArquivoHistorico[100] = "saves/ultimaPartida_jogadas.txt";

// Inicia o histórico: cria ou limpa o arquivo
int historico_iniciar() {
    FILE *arq = fopen(nomeArquivoHistorico, "w");
    if (!arq) return 0;
    fprintf(arq, "===== REGISTRO DE JOGADAS =====\n\n");
    fclose(arq);
    return 1;
}

// Registra uma jogada no arquivo
int historico_registrar(tp_jogador *jogador, char *mensagem) {
    FILE *arq = fopen(nomeArquivoHistorico, "a");
    if (!arq) printf("teste");
    fprintf(arq, "[%s] %s\n", jogador->nome, mensagem);
    fflush(arq); // força escrita
    fclose(arq);
    return 1;
}

// Escreve cabeçalho de rodada
int historico_inicio_rodada(int numeroRodada) {
    FILE *arq = fopen(nomeArquivoHistorico, "a");
    if (!arq) return 0;
    fprintf(arq, "\n--- INÍCIO DA RODADA %d ---\n", numeroRodada);
    fflush(arq); // força escrita
    fclose(arq);
    return 1;
}

#endif
