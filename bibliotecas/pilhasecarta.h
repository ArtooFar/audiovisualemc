//Biblioteca Própria //
#ifndef PILHASECARTA_H
#define PILHASECARTA_H

#include <stdio.h>
#include <stdlib.h>

typedef tp_carta tp_pilhaSEcarta_item; 

typedef struct tp_pilhaSEcarta_no_aux {   
  tp_pilhaSEcarta_item info;   
  struct tp_pilhaSEcarta_no_aux *prox;   
} tp_pilhaSEcarta_no; 


typedef struct {   
  tp_pilhaSEcarta_no *topo;   
} tp_pilhaSEcarta;


tp_pilhaSEcarta *pilhaSEcarta_inicializar (){
   tp_pilhaSEcarta *pilha=(tp_pilhaSEcarta*) malloc(sizeof(tp_pilhaSEcarta));   
   pilha->topo = NULL;   
   return pilha;
}  

int pilhaSEcarta_verificar_vazia (tp_pilhaSEcarta *pilha){   
 if (pilha->topo == NULL) return 1;
 return 0;
}

tp_pilhaSEcarta_no *pilhaSEcarta_aloca() {
	tp_pilhaSEcarta_no* pt;
	pt=(tp_pilhaSEcarta_no*) malloc(sizeof(tp_pilhaSEcarta_no));
	return pt;
}

int pilhaSEcarta_push (tp_pilhaSEcarta *pilha, tp_pilhaSEcarta_item e){   
  tp_pilhaSEcarta_no *novo;   
  novo=pilhaSEcarta_aloca();
  if (!novo) return 0;
  novo->info = e;  
  if (pilhaSEcarta_verificar_vazia(pilha) ) { //Se for o primeiro elemento da lista
     novo->prox = NULL;   
     }  
  else {
     novo->prox = pilha->topo;   
     }  
  pilha->topo = novo; 
  return 1;   
}        


int pilhaSEcarta_pop (tp_pilhaSEcarta *pilha, tp_pilhaSEcarta_item *e){   
  tp_pilhaSEcarta_no *aux;
  if (pilhaSEcarta_verificar_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  aux=pilha->topo;
  pilha->topo=pilha->topo->prox;
  free(aux);
  aux=NULL;
  return 1;   
}      

int pilhaSEcarta_topo (tp_pilhaSEcarta *pilha, tp_pilhaSEcarta_item *e){   
  if (pilhaSEcarta_verificar_vazia(pilha)) return 0;
  *e=pilha->topo->info;
  return 1;   
}        

tp_pilhaSEcarta *pilhaSEcarta_destruir(tp_pilhaSEcarta *pilha) {    
	 tp_pilhaSEcarta_no *atu=pilha->topo, *aux;
     tp_pilhaSEcarta_item e;
	 while (atu != NULL)
	       {
			aux = atu->prox;
            pilhaSEcarta_pop(pilha, &e);  
			atu= aux; 
            }
	pilha->topo = NULL;
	free(pilha);
	return NULL;
}


#endif
