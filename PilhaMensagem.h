#ifndef pilha
#define pilha

#include <stdlib.h>

typedef char elem;

typedef struct bloco{
	elem info[100];
	struct bloco *prox;
} no;

typedef struct pilha {
	no* topo;
} Pilha;

void Create(Pilha *P);
void Push(Pilha *P, elem *X, int *erro);
void Pop(Pilha *P, elem *X, int *erro);
int IsEmpty(Pilha *P);

#endif
