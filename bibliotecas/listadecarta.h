//Biblioteca Própria //
#ifndef LISTADE_H
#define LISTADECARTA_

#include <stdio.h>
#include <stdlib.h>

typedef tp_carta tp_listadecarta_item;

typedef struct tp_listadecarta_no_aux {
    struct tp_listadecarta_no_aux *ant;
    tp_listadecarta_item info;
    struct tp_listadecarta_no_aux *prox;
} tp_listadecarta_no;

typedef struct {
    tp_listadecarta_no *ini;
    tp_listadecarta_no *fim;
} tp_listadecarta;

tp_listadecarta *listaDEcarta_inicializar(){
    tp_listadecarta *lista=(tp_listadecarta*) malloc(sizeof(tp_listadecarta));
    lista->ini = NULL;
    lista->fim = NULL;
    
    return lista;
}

int listaDEcarta_verificar_vazia(tp_listadecarta *lista) {
    if ((lista->ini == NULL)) return 1;
    return 0;
}

tp_listadecarta_no *listaDEcarta_alocar() {
    tp_listadecarta_no* pt;
    pt=(tp_listadecarta_no*) malloc(sizeof(tp_listadecarta_no));
    return pt;
}

int listaDEcarta_inserir_fim (tp_listadecarta *lista,tp_listadecarta_item e) {
    tp_listadecarta_no *novo;
    novo=listaDEcarta_alocar();
    if (!novo) return 0;
    novo->info=e;

    if (listaDEcarta_verificar_vazia(lista)) {
        novo->prox=NULL;
        novo->ant = NULL;
        lista->ini = lista->fim = novo;
    }
    else {
        novo->prox=NULL;
        novo->ant=lista->fim;
        lista->fim->prox=novo;
        lista->fim=novo;
    }

    return 1;
}

int listaDEcarta_inserir_ordenado(tp_listadecarta *lista, tp_listadecarta_item e) {
    tp_listadecarta_no *novo = listaDEcarta_alocar();
    if (novo == NULL) {
        return 0;
    }

    novo->info = e;
    novo->ant  = NULL;
    novo->prox = NULL;

    if (listaDEcarta_verificar_vazia(lista)) {
        lista->ini = novo;
        lista->fim = novo;
        return 1;
    }

    tp_listadecarta_no *atu = lista->ini;
    while (atu != NULL && atu->info.valor_i < e.valor_i) {
        atu = atu->prox;
    }

    if (atu == lista->ini) {
        novo->prox      = lista->ini;
        lista->ini->ant = novo;
        lista->ini      = novo;
        return 1;
    }

    if (atu == NULL) {
        novo->ant        = lista->fim;
        lista->fim->prox = novo;
        lista->fim       = novo;
        return 1;
    }

    tp_listadecarta_no *ant = atu->ant;
    ant->prox     = novo;
    novo->ant     = ant;
    novo->prox    = atu;
    atu->ant      = novo;
    return 1;
}

int listaDEcarta_remover (tp_listadecarta *lista,tp_listadecarta_item e){
    tp_listadecarta_no *atu;
    atu = lista->ini;
    while ((atu!=NULL) && (atu->info.ID != e.ID)) {
        atu=atu->prox;
    }
    if (atu==NULL) return 0;
    if (lista->ini==lista->fim) {
        lista->ini = lista->fim=NULL;
    }
    else {
        if (lista->ini==atu) {
            lista->ini=atu->prox;
            atu->prox->ant=NULL;
        }
        else {
            if (lista->fim == atu) {
                lista->fim=atu->ant;
                atu->ant->prox=NULL;
            }
            else {
                atu->prox->ant = atu->ant;
                atu->ant->prox=atu->prox;
            }
        }
    }
    free(atu);
    return 1;
}

/*
tp_listadecarta_no* busca_listade (tp_listadecarta *lista,tp_listadecarta_item e) {
    tp_listadecarta_no *atu;
    atu = lista->ini;
    while ((atu!=NULL) && (atu->info!=e)) {
            atu=atu->prox;
    }
    return atu;
}
*/

tp_listadecarta* listaDEcarta_destruir (tp_listadecarta *lista) {
    tp_listadecarta_no *atu;
    atu=lista->ini;
    while (atu!=NULL) {
        lista->ini=atu->prox;
        free(atu);
        atu=lista->ini;
    }
    free(lista);
    return NULL;
}




#endif