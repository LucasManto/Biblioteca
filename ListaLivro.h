#ifndef lista_livro_h
#define lista_livro_h

#include <stdlib.h>
#include "Livro.h"

typedef struct {
    NoLivro *inicio, *fim;
} ListaLivro;

void cria_l(ListaLivro *L);
void inserir_l(ListaLivro *L, Livro *X, int *erro);
void finaliza_l(ListaLivro *L);
int tamanho_l(ListaLivro *L);
int esta_na_lista_l(ListaLivro *L, int *nUsp);
void eliminar_l(ListaLivro *L, int *isbn, int *erro);
void buscar_l(ListaLivro *L, Livro *a, int *isbn, int *erro);
Livro *retorna_l(ListaLivro *L, int *isbn);

#endif
