/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef livro_h
#define livro_h

#include "FilaAluno.h"

// Estrutura para armazenamento dos dados do livro da vers�o dinamica
typedef struct
{
	int isbn, quantidade;
	char titulo[100], autor[100], editora[100];
	FilaAluno fila;
} Livro;

// Definicao do no utilizado nas estruturas dinamicas
typedef struct noLivro
{
	Livro *info;
	struct noLivro *prox;
} NoLivro;

#endif
