#ifndef aluno_h
#define aluno_h

#include "PilhaMensagem.h"

typedef struct {
	int nUsp;
	char nome[100], email[100], telefone[100];
	Pilha mensagens;
} Aluno;

typedef struct noAluno {
        Aluno *info;
        struct noAluno *prox;
} NoAluno;

#endif
