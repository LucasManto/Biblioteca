/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#include "BancoAluno.h"

void cria_a(ListaAluno *B)
{
	int i;
	for (i = 0; i < TAM - 1; i++)
		B->itens[i].prox = i + 1;

	B->itens[TAM - 1].prox = -1;
	B->primeiro_vazio = 0;
	B->ini = -1;
	B->fim = -1;
}

void getnode(ListaAluno *B, int *pos)
{
	if (B->primeiro_vazio != -1)
	{
		*pos = B->primeiro_vazio;
		B->primeiro_vazio = B->itens[B->primeiro_vazio].prox;
		B->itens[*pos].prox = -1;
	}
	else
		*pos = -1;
}

void freenode(ListaAluno *B, int *pos)
{
	B->itens[*pos].prox = B->primeiro_vazio;
	B->primeiro_vazio = *pos;
}

int EstaVazio(ListaAluno *B)
{
	if (B->ini == -1)
		return (1);
	else
		return (0);
}

int EstaCheio(ListaAluno *B)
{
	if (B->primeiro_vazio == -1)
		return (1);
	else
		return (0);
}

void eliminar_a(ListaAluno *B, int *nUsp, int *erro)
{
	int pos, ant = -1, ant2 = -1;
	if (EstaVazio(B))
		*erro = 1;
	else
	{
		*erro = 0;

		pos = B->ini;
		while (pos != -1 && B->itens[pos].info.nUsp != *nUsp)
		{
			ant2 = ant;
			ant = pos;
			pos = B->itens[pos].prox;
		}

		if (pos == -1)
		{
			*erro = 1;
		}
		else
		{
			*erro = 0;

			if (pos == B->ini)
			{
				B->ini = B->itens[pos].prox;
				if (B->ini == -1)
					B->fim = -1;
			}
			else if (pos == B->fim)
			{
				B->fim = B->itens[ant2].prox;
				B->itens[ant].prox = -1;
			}
			else
			{
				B->itens[ant].prox = B->itens[pos].prox;
			}

			freenode(B, &pos);
		}
	}
}

void inserir_a(ListaAluno *B, Aluno *x, int *erro)
{
	int pos;
	if (EstaCheio(B))
		*erro = 1;
	else
	{
		*erro = 0;
		getnode(B, &pos);
		B->itens[pos].info = *x;
		B->itens[pos].prox = -1;
		if (B->fim != -1)
			B->itens[B->fim].prox = pos;
		B->fim = pos;
		if (B->ini == -1)
			B->ini = pos;
	}
}

void buscar_a(ListaAluno *B, Aluno *x, int *nUsp, int *erro)
{
	int pos;
	if (EstaVazio(B))
		*erro = 1;
	else
	{
		*erro = 0;

		pos = B->ini;
		while (pos != -1 && B->itens[pos].info.nUsp != *nUsp)
		{
			pos = B->itens[pos].prox;
		}

		if (pos == -1)
		{
			*erro = 1;
		}
		else
		{
			*erro = 0;
			*x = B->itens[pos].info;
		}
	}
}

int retorna_a(ListaAluno *L, int *nUsp)
{
	int pos = L->ini;

	while (pos != -1 && L->itens[pos].info.nUsp != *nUsp)
	{
		pos = L->itens[pos].prox;
	}

	return pos;
}
