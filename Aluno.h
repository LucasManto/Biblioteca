/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef aluno_h
#define aluno_h

#include "PilhaMensagem.h"

// Estrutura para armazenamento dos dados do aluno da vers�o dinamica
typedef struct
{
	int nUsp;
	char nome[100], email[100], telefone[100];
	Pilha mensagens;
} Aluno;

// Definicao do no utilizado nas estruturas dinamicas
typedef struct noAluno
{
	Aluno *info;
	struct noAluno *prox;
} NoAluno;

#endif
