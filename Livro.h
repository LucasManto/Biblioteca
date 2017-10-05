#ifndef livro_h
#define livro_h

#include "FilaAluno.h"

typedef struct {
	int isbn, quantidade;
	char titulo[100], autor[100], editora[100];
	FilaAluno fila;
} Livro;

typedef struct noLivro {
        Livro *info;
        struct noLivro *prox;
} NoLivro;

#endif
