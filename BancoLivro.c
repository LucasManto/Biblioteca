/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#include "BancoLivro.h"

void cria_l(ListaLivro *B)
{
	int i;
	for (i = 0; i < TAM_L - 1; i++)
		B->itens[i].prox = i + 1;
	B->itens[TAM_L - 1].prox = -1;
	B->primeiro_vazio = 0;
	B->ini = -1;
	B->fim = -1;
	cria_f(&B->fila);
}

void getnode_l(ListaLivro *B, int *pos)
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

void freenode_l(ListaLivro *B, int *pos)
{
	B->itens[*pos].prox = B->primeiro_vazio;
	B->primeiro_vazio = *pos;
}

int EstaVazio_l(ListaLivro *B)
{
	if (B->ini == -1)
		return (1);
	else
		return (0);
}

int EstaCheio_l(ListaLivro *B)
{
	if (B->primeiro_vazio == -1)
		return (1);
	else
		return (0);
}

void eliminar_l(ListaLivro *B, int *Isbn, int *erro)
{
	int pos, ant = -1, ant2 = -1;
	if (EstaVazio_l(B))
		*erro = 1;
	else
	{
		*erro = 0;

		pos = B->ini;
		while (pos != -1 && B->itens[pos].info.Isbn != *Isbn)
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

			freenode_l(B, &pos);
		}
	}
}

void inserir_l(ListaLivro *B, Livro *x, int *erro)
{
	int pos;
	if (EstaCheio_l(B))
		*erro = 1;
	else
	{
		*erro = 0;
		getnode_l(B, &pos);
		B->itens[pos].info = *x;
		B->itens[pos].prox = -1;
		if (B->fim != -1)
			B->itens[B->fim].prox = pos;
		B->fim = pos;
		if (B->ini == -1)
			B->ini = pos;
	}
}

void buscar_l(ListaLivro *B, Livro *x, int *Isbn, int *erro)
{
	int pos;
	if (EstaVazio_l(B))
		*erro = 1;
	else
	{
		*erro = 0;

		pos = B->ini;
		while (pos != -1 && B->itens[pos].info.Isbn != *Isbn)
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

int retorna_l(ListaLivro *L, int *Isbn)
{
	int pos = L->ini;

	while (pos != -1 && L->itens[pos].info.Isbn != *Isbn)
	{
		pos = L->itens[pos].prox;
	}

	return pos;
}
