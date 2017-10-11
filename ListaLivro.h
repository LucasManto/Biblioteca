/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef lista_livro_h
#define lista_livro_h

#include <stdlib.h>
#include "Livro.h"

// Estrutura que define a Lista que armazena livros
typedef struct
{
	NoLivro *inicio, *fim;
} ListaLivro;

// Criacao da lista
void cria_l(ListaLivro *L);
// Insere o livro na lista
void inserir_l(ListaLivro *L, Livro *X, int *erro);
// Esvazia a lista
void finaliza_l(ListaLivro *L);
// Retorna o tamanho da lista
int tamanho_l(ListaLivro *L);
// Verifica se o livro esta na lista
int esta_na_lista_l(ListaLivro *L, int *nUsp);
// Elimina o livro buscado pelo isbn
void eliminar_l(ListaLivro *L, int *isbn, int *erro);
// Busca livro pelo isbn e copia os valores para a
void buscar_l(ListaLivro *L, Livro *a, int *isbn, int *erro);
// Retorna um ponteiro para o livro buscado pelo isbn
Livro *retorna_l(ListaLivro *L, int *isbn);

#endif
