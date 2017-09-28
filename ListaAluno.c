//#include "ListaAluno.h"
//#include <stdlib.h>

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
	
	p->info = *X;
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

int tamanho_rec_a(NoAluno *p){
	
	if(p==NULL)
		return 0;
		else return(1+tamanho_rec_a(p->prox));
	
}

int tamanho_rec_lista_a(ListaAluno *L){
	return tamanho_rec_a(L->inicio);
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

void eliminar_a(ListaAluno *L, NoAluno *X, int *erro) {
	NoAluno *p = L->inicio, *ant = NULL;
	
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

//void eliminar_rec_a(Lista *L, NoAluno* anterior, NoAluno* atual, Aluno *X, int *erro){
//	
//	if(atual == NULL)
//		*erro = 1;
//	else if(atual->info == *X){
//		if(atual == L->inicio){
//			L->inicio = L->inicio->prox;
//			if(L->inicio == NULL)
//				L->fim = NULL;
//		} else if(atual == L->fim){
//			L->fim = anterior;
//			L->fim->prox = NULL;		
//		} else anterior->prox = atual->prox;
//		free(atual);
//		*erro = 0;
//	}else eliminar_rec_a(L, atual, atual->prox, X, erro);
//	
//}

int esta_na_lista_a(ListaAluno *L, Aluno *X){
	
	NoAluno *p;
	p=L->inicio;
	
	while((p != NULL) && (&p->info != X)){
		p=p->prox;
	}
	
	if(p==NULL)
		return 0;
		else return 1;
	
}

//int esta_na_lista_rec_a(NoAluno *p, Aluno *X){
//	
//	if(p == NULL)
//		return 0;
//		else if (p->info==*X)
//			return 1;
//			else 
//				return esta_na_lista_rec(p->prox,X);
//		
//}

NoAluno *busca_na_lista_a(ListaAluno *alunos, int *nUsp) {
	NoAluno *a = alunos->inicio;
	
	while((a != NULL) && (a->info.nUsp != *nUsp)) {
		a = a->prox;
	}
	
	return a;
}
