#include "ListaComoPilha.h"

void Create(Pilha *P){
	P->topo = NULL;	
}

void Push(Pilha *P, elem *X, int *erro){
	
	No *pont;
	
	pont = (No*)malloc(sizeof(No));
	
	if(pont==NULL)
		*erro = 1;
		else {
			*erro = 0;
			pont->info = *X;
			pont->prox = P->topo;
			P->topo = pont;			
		}
}

void Pop(Pilha *P, elem *X, int *erro){
	
	No *pont;
	
	if(IsEmpty(P))
		*erro = 1;
		else {
			*erro = 0;
			*X = P->topo->info;
			pont = P->topo;
			P->topo = P->topo->prox;
			free(pont);
		}
}
	
int IsEmpty(Pilha *P){
	if(P->topo == NULL)
		return 1;
		else return 0;
}


