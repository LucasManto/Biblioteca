#include "ListaLivro.h"

void cria_l(ListaLivro *L){
	L->inicio = NULL;
	L->fim = NULL;
}

void inserir_l(ListaLivro *L, Livro *X, int *erro){
	
	NoLivro *p;
	
	p = (NoLivro*)malloc(sizeof(NoLivro));
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

void finaliza_l(ListaLivro *L){

	NoLivro *p;
	
	p=L->inicio;	
	
	while(p!=NULL){
		L->inicio = L->inicio->prox;
		free(p);
		p=L->inicio;
	}
	
	L->fim = p;
}

int tamanho_l(ListaLivro *L){
	
	NoLivro *p;
	int count = 0;
	
	p=L->inicio;
	
	while(p!=NULL){
		count++;
		p=p->prox;		
	}
	
	return count;
}

int esta_na_lista_l(ListaLivro *L, int *isbn){
	
	NoLivro *p;
	p=L->inicio;
	
	while((p != NULL)&&(p->info->isbn != *isbn)){
		p=p->prox;
	}
	
	if(p==NULL)
		return 0;
		else return 1;
	
}

void eliminar_l(ListaLivro *L, int *isbn, int *erro) {
	NoLivro *p, *ant = NULL;
	p = L->inicio;
	
	while(p != NULL && p->info->isbn != *isbn) {
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

void buscar_l(ListaLivro *L, Livro *a, int *isbn, int *erro) {
	NoLivro *p;
	p=L->inicio;
	
	while((p != NULL)&&(p->info->isbn != *isbn)){
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

Livro *retorna_l(ListaLivro *L, int *isbn) {
	NoLivro *p;
	p = L->inicio;
	
	while((p != NULL)&&(p->info->isbn != *isbn)){
		p=p->prox;
	}
	
	return p->info;
}
