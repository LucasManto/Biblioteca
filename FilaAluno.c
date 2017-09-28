//#include "FilaAluno.h"
//#include <stdlib.h>

void Cria(FilaAluno *F){
	F->inicio = NULL;
	F->fim = NULL;
}

void Entra(FilaAluno *F, Aluno *X, int *erro){
	
	NoAluno *p;
	
	p = (NoAluno*)malloc(sizeof(NoAluno));
	if(p==NULL)
		*erro = 1;
		else {
			*erro = 0;
			p->info = *X;
			p->prox = NULL;
			if(F->inicio == NULL)
				F->inicio = p;
				else F->fim->prox = p;
			F->fim = p;	
		}
}

void Sai(FilaAluno *F, Aluno *X, int *erro){
	
	NoAluno *p;
	
	if(EstaVazia(F))
		*erro = 1;
		else {
			*erro = 0;
			*X = F->inicio->info;
			p = F->inicio;
			F->inicio = F->inicio->prox;
			if(F->inicio == NULL)
				F->fim=NULL;
			free(p);
		}	
}

int EstaVazia(FilaAluno *F){
	if(F->inicio == NULL)
		return 1;
		else return 0;
}

int EstaCheia(FilaAluno *F){
	
	NoAluno *p;
	
	p=(NoAluno*)malloc(sizeof(NoAluno));
	
	if(p==NULL)
		return 1;
		else {
			free(p);
			return 0;
		}
}




