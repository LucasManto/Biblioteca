//#include "ListaLivro.h"
//#include <stdlib.h>

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

	p->info = *X;
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

int tamanho_rec_l(NoLivro *p){

	if(p==NULL)
		return 0;
		else return(1+tamanho_rec_l(p->prox));

}

int tamanho_rec_lista_l(ListaLivro *L){
	return tamanho_rec_l(L->inicio);
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

void eliminar_l(ListaLivro *L, NoLivro *X, int *erro) {
	NoLivro *p = L->inicio, *ant = NULL;

	while((p != X) && (p != NULL)) {
		ant = p;
		p = p->prox;
	}

	if(p == NULL) *erro = 0;
	else {
		*erro = 1;
		if(p == L->inicio) {
			L->inicio = L->inicio->prox;
			if(L->inicio == NULL) L->fim = NULL;
		}
		else if(p == L->fim) {
			L->fim = ant;
			L->fim->prox = NULL;
		}
		else {
			ant->prox = p->prox;
		}
		free(p);
	}
}

int esta_na_lista_l(ListaLivro *L, Livro *X){

	NoLivro *p;
	p=L->inicio;

	while((p != NULL) && (&p->info != X)){
		p=p->prox;
	}

	if(p==NULL)
		return 0;
		else return 1;

}


NoLivro *busca_na_lista_l(ListaLivro *livro, int *isbn) {
	NoLivro *l = livro->inicio;

	while((l != NULL) && (l->info.isbn != *isbn)) {
		l = l->prox;
	}

	return l;
}
