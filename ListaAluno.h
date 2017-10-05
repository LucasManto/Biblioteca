#ifndef lista_aluno_h
#define lista_aluno_h

#include <stdlib.h>
#include "Aluno.h"

typedef struct {
    NoAluno *inicio, *fim;
} ListaAluno;

void cria_a(ListaAluno *L);
void inserir_a(ListaAluno *L, Aluno *X, int *erro);
void finaliza_a(ListaAluno *L);
int tamanho_a(ListaAluno *L);
int esta_na_lista_a(ListaAluno *L, int *nUsp);
void eliminar_a(ListaAluno *L, int *nUsp, int *erro);
void buscar_a(ListaAluno *L, Aluno *a, int *nUsp, int *erro);
Aluno *retorna_a(ListaAluno *L, int *nUsp);

#endif
