/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "PilhaMensagemEstatica.h"

void Create(Pilha *p)
{
	p->topo = -1;
	return;
}

void Empty(Pilha *p)
{
	p->topo = -1;
	return;
}

int IsEmpty(Pilha *P)
{
	if (P->topo == -1)
		return 1;
	else
		return 0;
}

int IsFull(Pilha *P)
{
	if (P->topo == TamPilha - 1)
		return 1;
	else
		return 0;
}

int Push(Pilha *P, char *X)
{

	if (!IsFull(P))
	{
		P->topo++;
		strcpy(P->itens[P->topo], X);
		return 0;
	}
	else
		return 1;
}

int Pop(Pilha *P, char *X)
{
	if (!IsEmpty(P))
	{
		strcpy(X, P->itens[P->topo]);
		P->topo--;
		return 0;
	}
	else
		return 1;
}
