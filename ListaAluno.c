#include "ListaAluno.h"

void cria_a(ListaAluno *L){
	L->inicio = NULL;
	L->fim = NULL;
}

void inserir_a(ListaAluno *L, Aluno *X, int *erro){
	
	NoAluno *p;
	
	p = (NoAluno*)malloc(sizeof(NoAluno));
	if(p==NULL){
		*erro = 1;
		return;
	} else *erro = 0;
	
	p->info = X;
	p->prox = NULL;
	
	if(L->inicio == NULL)
		L->inicio = p;
		else L->fim->prox = p;
		
	L->fim = p;
	
}

void finaliza_a(ListaAluno *L){

	NoAluno *p;
	
	p=L->inicio;	
	
	while(p!=NULL){
		L->inicio = L->inicio->prox;
		free(p);
		p=L->inicio;
	}
	
	L->fim = p;
}

int tamanho_a(ListaAluno *L){
	
	NoAluno *p;
	int count = 0;
	
	p=L->inicio;
	
	while(p!=NULL){
		count++;
		p=p->prox;		
	}
	
	return count;
}

int esta_na_lista_a(ListaAluno *L, int *nUsp){
	
	NoAluno *p;
	p=L->inicio;
	
	while((p != NULL)&&(p->info->nUsp != *nUsp)){
		p=p->prox;
	}
	
	if(p==NULL)
		return 0;
		else return 1;
	
}

void eliminar_a(ListaAluno *L, int *nUsp, int *erro) {
	NoAluno *p, *ant = NULL;
	p = L->inicio;
	
	while(p != NULL && p->info->nUsp != *nUsp) {
		ant = p;
		p = p->prox;
	}
	
	if(p == NULL) {
		*erro = 1;
	}
	else {
		*erro = 0;
		if(p == L->inicio){
			L->inicio = L->inicio->prox;
			if(L->inicio == NULL)
				L->fim = NULL;
		} else if(p == L->fim){
			L->fim = ant;
			L->fim->prox = NULL;		
		} else ant->prox = p->prox;
		free(p);
	}
}

void buscar_a(ListaAluno *L, Aluno *a, int *nUsp, int *erro) {
	NoAluno *p;
	p=L->inicio;
	
	while((p != NULL)&&(p->info->nUsp != *nUsp)){
		p=p->prox;
	}
	
	if(p == NULL) {
		*erro = 1;
	}
	else {
		*erro = 0;
		*a = *p->info;
	}
}

Aluno *retorna_a(ListaAluno *L, int *nUsp) {
	NoAluno *p;
	p = L->inicio;
	
	while((p != NULL)&&(p->info->nUsp != *nUsp)){
		p=p->prox;
	}
	
	return p->info;
}
