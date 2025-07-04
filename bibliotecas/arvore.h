#ifndef ARVORE_COMBINACOES_IMPLEMENTADA
#define ARVORE_COMBINACOES_IMPLEMENTADA

#include <stdio.h>
#include <stdlib.h>

// ===============================
// Estruturas
// ===============================

typedef struct NoArvoreComb {
    int rodada;               // Ex: 1=Pré-flop, 2=Flop, 3=Turn, 4=River
    int totalCombinacoes;     // Número de tipos de combinações diferentes
    struct NoArvoreComb *prox;
} NoArvoreComb;

typedef NoArvoreComb* ArvoreComb;

typedef struct {
    int par;
    int trinca;
    int straight;
    int flush;
    int fullHouse;
    int quadra;
    int straightFlush;
    int royalFlush;
} EstatisticasComb;

// ===============================
// Funções da árvore
// ===============================

ArvoreComb arv_comb_inicializar(void) {
    return NULL;
}

ArvoreComb arv_comb_inserir(ArvoreComb raiz, int rodada, int totalComb) {
    NoArvoreComb *novo = malloc(sizeof(NoArvoreComb));
    if (!novo) return raiz;

    novo->rodada = rodada;
    novo->totalCombinacoes = totalComb;
    novo->prox = NULL;

    if (!raiz) return novo;

    NoArvoreComb *atu = raiz;
    while (atu->prox) atu = atu->prox;
    atu->prox = novo;

    return raiz;
}

void arv_comb_imprimir(ArvoreComb raiz) {
    for (NoArvoreComb *n = raiz; n; n = n->prox)
        printf("Rodada %d: %d combinação(ões)\n", n->rodada, n->totalCombinacoes);
}

void arv_comb_destruir(ArvoreComb raiz) {
    while (raiz) {
        NoArvoreComb *tmp = raiz->prox;
        free(raiz);
        raiz = tmp;
    }
}

void arv_comb_salvar_em_arquivo(ArvoreComb raiz, const char *arquivo) {
    if (!arquivo) return;
    FILE *f = fopen(arquivo, "w");
    if (!f) return;

    fprintf(f, "--- CONTADOR DE COMBINAÇÕES ---\n\n");
    for (NoArvoreComb *n = raiz; n; n = n->prox)
        fprintf(f, "Rodada %d: %d combinação(ões)\n", n->rodada, n->totalCombinacoes);

    fclose(f);
}

// ===============================
// Funções de estatística
// ===============================

void iniciar_estatisticas(EstatisticasComb *est) {
    if (est) *est = (EstatisticasComb){0};
}

void atualizar_estatisticas(EstatisticasComb *est, const tp_combinacoes *comb) {
    if (!est || !comb) return;
    est->par           += comb->par.quant;
    est->trinca        += comb->trinca.quant;
    est->straight      += comb->straight.quant;
    est->flush         += comb->flush.quant;
    est->fullHouse     += comb->fullHouse.quant;
    est->quadra        += comb->quadra.quant;
    est->straightFlush += comb->straightFlush.quant;
    est->royalFlush    += comb->royalFlush.quant;
}

void salvar_estatisticas(const EstatisticasComb *est, const char *arquivo) {
    if (!est || !arquivo) return;
    FILE *f = fopen(arquivo, "w");
    if (!f) return;

    fprintf(f, "Par: %d\n", est->par);
    fprintf(f, "Trinca: %d\n", est->trinca);
    fprintf(f, "Straight: %d\n", est->straight);
    fprintf(f, "Flush: %d\n", est->flush);
    fprintf(f, "FullHouse: %d\n", est->fullHouse);
    fprintf(f, "Quadra: %d\n", est->quadra);
    fprintf(f, "StraightFlush: %d\n", est->straightFlush);
    fprintf(f, "RoyalFlush: %d\n", est->royalFlush);

    fclose(f);
}

// ===============================
// Função unificada (opcional)
// ===============================

ArvoreComb registrar_combinacoes(tp_jogador *j, ArvoreComb raiz, int rodada, EstatisticasComb *est) {
    if (!j) return raiz;

    int total =
        (j->combinacoes.par.quant           > 0) +
        (j->combinacoes.trinca.quant        > 0) +
        (j->combinacoes.straight.quant      > 0) +
        (j->combinacoes.flush.quant         > 0) +
        (j->combinacoes.fullHouse.quant     > 0) +
        (j->combinacoes.quadra.quant        > 0) +
        (j->combinacoes.straightFlush.quant > 0) +
        (j->combinacoes.royalFlush.quant    > 0);

    if (est) atualizar_estatisticas(est, &j->combinacoes);

    return arv_comb_inserir(raiz, rodada, total);
}

#endif
