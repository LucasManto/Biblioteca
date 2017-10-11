/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef pilha
#define pilha

#include <stdlib.h>

// Definicao do tipo elemento como char
typedef char elem;

// Definicao do no utilizado na pilha dinamica
typedef struct bloco
{
	elem info[100];
	struct bloco *prox;
} no;

// Definicao da estrutura da pilha dinamica
typedef struct pilha
{
	no *topo;
} Pilha;

// Cria uma pilha P
void Create(Pilha *P);
//Insere o elemento X na pilha P. erro = 0 se n�o houver erro, erro =  1 se algum erro acontecer
void Push(Pilha *P, elem *X, int *erro);
//Remove o elemento X da pilha P. erro =  0 se n�o houver erro, erro = 1 se algum erro acontecer
void Pop(Pilha *P, elem *X, int *erro);
//Retorna 1 se a pilha estiver vazia, 0 se a pilha tiver conteudo
int IsEmpty(Pilha *P);

#endif
