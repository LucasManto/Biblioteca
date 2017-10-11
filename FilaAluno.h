/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef fila_aluno_h
#define fila_aluno_h

#include <stdlib.h>
#include "Aluno.h"

// Definicao da estrutura da fila de alunos
typedef struct fila
{
	NoAluno *inicio, *fim;
	int total;
} FilaAluno;

// Criacao da fila
void Cria(FilaAluno *F);
// Adiciona um aluno � fila
void Entra(FilaAluno *F, Aluno *X, int *erro);
// Retira um aluno da fila
void Sai(FilaAluno *F, Aluno **X, int *erro);
// Verifica se a fila esta vazia
int EstaVazia(FilaAluno *F);

#endif
