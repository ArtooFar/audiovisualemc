//Biblioteca Própria //
#ifndef LISTASECARTA_H
#define LISTASECARTA_H
#include <stdlib.h>
#include <stdio.h>

//Para usar essa biblioteca de lista, na main deve ser criada uma lista assim:
// tp_listasecarta *lista
//Logo depois, inicialize assim:
// lista = listaSEcarta_inicializar();


//Alterar o tipo de tp_listasecarta_item altera em toda a biblioteca
// ATENÇÃO -> precisa trocar no printf de impressão

typedef tp_carta tp_listasecarta_item;

typedef struct tp_listasecarta_no { // tp_no = Apelido da struct (tipo sinonimo)
    tp_listasecarta_item info;
    struct tp_listasecarta_no *prox;
} tp_listasecarta;


tp_listasecarta* listaSEcarta_inicializar() {
    // Inicializa a lista (retorna NULL)
    // Exemplo: lista = listaSEcarta_inicializar();
    return NULL;
}


int listaSEcarta_verificar_vazia(tp_listasecarta *lista) {
  // Verifica se a lista está vazia
  // Parâmetros a serem passados na main: conteúdo do ponteiro que aponta o início da lista (Ponteiro Primário)
  // Exemplo: if (listaSEcarta_verificar_vazia(lista)) {...}
    if (lista == NULL) return 1;
    return 0;
}


tp_listasecarta* listaSEcarta_alocar() {
    // Aloca dinamicamente um novo nó
    // Exemplo: novo_no = listaSEcarta_alocar();
    // Retorna NULL se não conseguir alocar um espaço de memória, 
    // Caso consiga, retorna o endereço de memória desse espaço alocado
    tp_listasecarta *novo_no;
    novo_no = (tp_listasecarta*) malloc(sizeof(tp_listasecarta));
    return novo_no;
}

int listaSEcarta_inserir_inicio(tp_listasecarta **l, tp_listasecarta_item e) {
    // Insere um item no início da lista
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início da lista e o item a ser inserido
    // Exemplo: listaSEcarta_inserir_inicio(&lista, 10);
    tp_listasecarta *novo_no = listaSEcarta_alocar();
    if (novo_no == NULL) return 0;

    novo_no->info = e;
    novo_no->prox = *l;
    *l = novo_no;
    return 1;
}


int listaSEcarta_inserir_fim(tp_listasecarta **l, tp_listasecarta_item e) {
    // Insere um item no fim da lista
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início da lista e o item a ser inserido
    // Exemplo: listaSEcarta_inserir_fim(&lista, 10);
    tp_listasecarta *novo_no = listaSEcarta_alocar();
    if (novo_no == NULL) return 0;

    novo_no->info = e;
    novo_no->prox = NULL;

    if (listaSEcarta_verificar_vazia(*l)) {
        *l = novo_no;
    } else {
        tp_listasecarta *atu = *l;
        while (atu->prox != NULL) atu = atu->prox;
        atu->prox = novo_no;
    }
    return 1;
}

int listaSEcarta_inserir_numericamenteOrdenado_crescente(tp_listasecarta **l, tp_listasecarta_item e) {
    // Insere um item respeitando a ordem numérica crescente
    // IMPORTANTE -> caso decida por utilizar esse metodo de inserção, não utilize nenhum outro, isso pode quebrar a ordem crescente.
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início da lista e o item a ser inserido
    // Exemplo: listaSE_inserir_numericamenteOrdenado(&lista, 10);
    tp_listasecarta *novo_no = listaSEcarta_alocar();
    if (novo_no == NULL) return 0;

    novo_no->info = e;
    novo_no->prox = NULL;

    // 1) Lista vazia ou deve ficar na cabeça
    if (listaSEcarta_verificar_vazia(*l) || (e.valor_i) < ((*l)->info).valor_i) {
        novo_no->prox = *l;
        *l = novo_no;
        return 1;
    }

    // 2) Procura o ponto de inserção, olhando para o próximo
    tp_listasecarta *atu = *l;
    while (atu->prox != NULL && (atu->prox->info).valor_i < e.valor_i) {
        atu = atu->prox;
    }

    // 3) Agora 'atu' é o nó **antes** do ponto de inserção
    novo_no->prox = atu->prox;
    atu->prox = novo_no;
    return 1;
}

/*int listaSEcarta_remover(tp_listasecarta **lista, tp_listasecarta_item e) {
    // Remove a primeira ocorrência de um item na lista
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início da lista e o item a ser removido
    // Exemplo: listaSEcarta_remover(&lista, 10);
    tp_listasecarta *ant = NULL, *atu = *lista;
    while ((atu != NULL) && (atu->info != e)) {
        ant = atu;
        atu = atu->prox;
    }
    if (atu == NULL) return 0;

    if (ant == NULL) *lista = atu->prox;
    else ant->prox = atu->prox;

    free(atu);
    return 1;
}*/

void listaSEcarta_destruir(tp_listasecarta **l){
    // Destrói uma lista e libera a memória alocada
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início da lista
    // Exemplo: listaSEcarta_destruir(&lista);
	tp_listasecarta *atu;
	atu=*l;
	while (atu!=NULL){
		*l=atu->prox;
		free(atu);
		atu=*l;
	}
	*l=NULL;
}


int listaSEcarta_verificar_tamanho(tp_listasecarta *lista) {
    // Retorna a quantidade de elementos na lista
    // Parâmetros a serem passados na main: endereço de memória do início da lista
    // Exemplo: tam = listaSEcarta_verificar_tamanho(lista);
    int cont = 0;
    tp_listasecarta *atu = lista;
    while (atu != NULL) {
        cont++;
        atu = atu->prox;
    }
    return cont;
}



/*tp_listasecarta *listaSEcarta_buscar(tp_listasecarta *lista, tp_listasecarta_item e) {
    // Busca um valor na lista e retorna o endereço de memória do nó que o contém
    // Parâmetros a serem passados na main: endereço de memória do início lista e o valor a ser buscado
    // Exemplo: encontrado = listaSEcarta_buscar(lista, 5);
    tp_listasecarta *atu = lista;
    while ((atu != NULL) && (atu->info != e)) {
        atu = atu->prox;
    }
    return atu;
}*/

int listaSEcarta_especiais_criarLoop_entreListas(tp_listasecarta **l1, tp_listasecarta **l2) {
    // Cria um loop entre o final de duas listas, ligando o fim da l1 ao início da l2 e vice-versa
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início de duas listas
    // Exemplo: listaSEcarta_especiais_criarLoop_entreListas(&lista1, &lista2);
    tp_listasecarta *ultimol1 = *l1, *ultimol2 = *l2;

    if (!listaSEcarta_verificar_vazia(*l1)) {
        while (ultimol1->prox != NULL) {
            ultimol1 = ultimol1->prox;
        }
    }

    if (!listaSEcarta_verificar_vazia(*l2)) {
        while (ultimol2->prox != NULL) {
            ultimol2 = ultimol2->prox;
        }
    }

    ultimol1->prox = *l2;
    ultimol2->prox = *l1;
    
    l1=l2;

    return 1;
}

int listaSEcarta_especiais_criarLoop(tp_listasecarta **l) {
    // Faz uma listaSecarta se tornar cíclica
    // Parâmetros a serem passados na main: endereço de memória do ponteiro que aponta para o início de uma lista
    // Exemplo: listaSEcarta_especiais_criarLoop(&lista);
    tp_listasecarta *ultimol = *l;

    if (!listaSEcarta_verificar_vazia(*l)) {
        while (ultimol->prox != NULL) {
            ultimol = ultimol->prox;
        }
    }

    ultimol->prox = *l;
    return 1;
}

#endif
