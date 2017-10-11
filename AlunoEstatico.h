/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef aluno_h
#define aluno_h

#include "PilhaMensagemEstatica.h"

// Estrutura para armazenamento dos dados do aluno da vers�o est�tica
typedef struct
{
	int nUsp;
	char nome[100], email[100], telefone[15];
	Pilha mensagens;
} Aluno;

// Definicao do no utilizado nas estruturas est�ticas
typedef struct noAlunoEstatico
{
	Aluno info;
	int prox;
} NoAlunoEstatico;

#endif
