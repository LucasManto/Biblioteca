#ifndef PILHA_MENSAGEM_H
#define PILHA_MENSAGEM_H

#include <stdlib.h>
#include <string.h>

typedef struct noMensagem {
	char *info;
	struct noMensagem *prox;
} NoMensagem;

struct pilha {
	NoMensagem *topo;
};

typedef struct pilha Pilha;

void Create(Pilha *P);
void Push(Pilha *P, char *X, int *erro);
void Pop(Pilha *P, char *X, int *erro);
int IsEmpty(Pilha *P);

#endif
