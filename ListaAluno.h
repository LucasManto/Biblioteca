#ifndef LISTA_ALUNO_H
#define LISTA_ALUNO_H

#include "Aluno.h"
#include <stdlib.h>

typedef struct {
        NoAluno *inicio, *fim;
} ListaAluno;

void cria_a(ListaAluno *L);
void inserir_a(ListaAluno *L, Aluno *X, int *erro);
void finaliza_a(ListaAluno *L);
int tamanho_rec_a(NoAluno *p);
int tamanho_rec_lista_a(ListaAluno *L);
int tamanho_a(ListaAluno *L);
int esta_na_lista_a(ListaAluno *L, Aluno *X);
int esta_na_lista_rec_a(NoAluno *p, Aluno *X);
void eliminar_a(ListaAluno *L, NoAluno *x, int *erro);
void eliminar_rec_a(ListaAluno *L, NoAluno* anterior, NoAluno* atual, Aluno *X, int *erro);
NoAluno *busca_na_lista_a(ListaAluno *L, int *nUsp);

#endif
