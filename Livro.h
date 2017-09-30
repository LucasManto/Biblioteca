#ifndef LIVRO_H
#define LIVRO_H

#include "FilaAluno.h"

typedef struct {
    char *titulo;
    char *autor;
    int isbn;
    char *editora;
    int quantidade;
    FilaAluno fila;
} Livro;

typedef struct noLivro {
	Livro info;
	struct noLivro *prox;
} NoLivro;

Livro *CriaLivro(char *titulo, char *autor, int *isbn, char *editora, int *quantidade, int *erro);

#endif
