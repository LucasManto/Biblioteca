/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#include "BibliotecaEstatica.h"
#include <stdio.h>
#include <string.h>

int CadastrarAluno(ListaAluno *L, int *nUsp, char *nome, char *email, char *telefone)
{
	int erro;

	Aluno a;
	a.nUsp = *nUsp;
	strcpy(a.nome, nome);
	strcpy(a.email, email);
	strcpy(a.telefone, telefone);
	Create(&a.mensagens);

	inserir_a(L, &a, &erro);

	return erro;
}

int RemoverAluno(ListaAluno *L, int *nUsp)
{
	int erro;

	eliminar_a(L, nUsp, &erro);

	return erro;
}

int BuscarAluno(ListaAluno *L, Aluno *a, int *nUsp)
{
	int erro;

	buscar_a(L, a, nUsp, &erro);

	return erro;
}

int CadastrarLivro(ListaLivro *L, int *Isbn, char *titulo, char *autor, char *editora, int *quantidade)
{
	int erro;

	Livro l;
	l.Isbn = *Isbn;
	l.Isbn = *Isbn;
	strcpy(l.titulo, titulo);
	strcpy(l.autor, autor);
	strcpy(l.editora, editora);
	l.quantidade = *quantidade;
	l.inicio_fila = -1;
	l.fim_fila = -1;
	l.tam_fila = 0;

	inserir_l(L, &l, &erro);

	return erro;
}

int RemoverLivro(ListaLivro *L, int *Isbn)
{
	int erro;

	eliminar_l(L, Isbn, &erro);

	return erro;
}

int BuscarLivro(ListaLivro *L, Livro *l, int *Isbn)
{
	int erro;

	buscar_l(L, l, Isbn, &erro);

	return erro;
}

int RetirarLivro(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn)
{
	int erro;

	int pos_l;

	pos_l = retorna_l(L, isbn);

	if (L->itens[pos_l].info.quantidade > 0)
	{
		erro = 1;
		L->itens[pos_l].info.quantidade--;
	}
	else
	{
		erro = 0;
		ColocarNaFila(A, nUsp, L, isbn);
	}

	return erro;
}

int DevolverLivro(ListaLivro *L, int *isbn, ListaAluno *A)
{
	int pos_l;

	pos_l = retorna_l(L, isbn);

	L->itens[pos_l].info.quantidade++;
	TirarDaFila(L, isbn, A);
}

void ColocarNaFila(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn)
{
	int erro;

	int pos_a, pos_l;

	pos_a = retorna_a(A, nUsp);
	pos_l = retorna_l(L, isbn);

	inserir_f(&L->fila, &A->itens[pos_a].info, &L->itens[pos_l].info.inicio_fila, &L->itens[pos_l].info.fim_fila, &L->itens[pos_l].info.tam_fila, &erro);
}

void TirarDaFila(ListaLivro *L, int *isbn, ListaAluno *A)
{
	int erro;
	char m[100];

	Aluno a;
	int pos_l, pos_a;

	pos_l = retorna_l(L, isbn);
	retirar_f(&L->fila, &a, &L->itens[pos_l].info.inicio_fila, &L->itens[pos_l].info.fim_fila, &L->itens[pos_l].info.tam_fila, &erro);

	pos_a = retorna_a(A, &a.nUsp);

	if (erro == 0)
	{
		sprintf(m, "Livro ISBN: %d disponivel.", L->itens[pos_l].info.Isbn);
		Push(&A->itens[pos_a].info.mensagens, m);
	}
}

int VerMensagens(ListaAluno *L, int *nUsp)
{
	char m[100];
	int erro = 0;
	int pos;

	pos = retorna_a(L, nUsp);

	while (!IsEmpty(&L->itens[pos].info.mensagens))
	{
		Pop(&L->itens[pos].info.mensagens, m);
		printf("%s\n", m);
		erro = 1;
	}

	return erro;
}

void RemoverDaFila(ListaLivro *L, int *nUsp)
{
	int erro;
	int pos_a, pos_l;
	int cont = 0;
	Aluno a;

	pos_l = L->ini;

	while (pos_l != -1)
	{
		while (cont < L->itens[pos_l].info.tam_fila)
		{
			retirar_f(&L->fila, &a, &L->itens[pos_l].info.inicio_fila, &L->itens[pos_l].info.fim_fila, &L->itens[pos_l].info.tam_fila, &erro);
			if (a.nUsp != *nUsp)
			{
				inserir_f(&L->fila, &a, &L->itens[pos_l].info.inicio_fila, &L->itens[pos_l].info.fim_fila, &L->itens[pos_l].info.tam_fila, &erro);
			}
			cont++;
		}
		pos_l = L->itens[pos_l].prox;
	}
}
