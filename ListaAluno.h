/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef lista_aluno_h
#define lista_aluno_h

#include <stdlib.h>
#include "Aluno.h"

// Estrutura que define a Lista que armazena alunos
typedef struct
{
	NoAluno *inicio, *fim;
} ListaAluno;

// Criacao da lista
void cria_a(ListaAluno *L);
// Insere o aluno a na lista
void inserir_a(ListaAluno *L, Aluno *X, int *erro);
// Esvazia a lista
void finaliza_a(ListaAluno *L);
// Retorna o tamanho da lista
int tamanho_a(ListaAluno *L);
// Verifica se o aluno esta na lista
int esta_na_lista_a(ListaAluno *L, int *nUsp);
// Elimina o aluno buscado pelo nUsp
void eliminar_a(ListaAluno *L, int *nUsp, int *erro);
// Busca aluno pelo nUsp e copia os valores para a
void buscar_a(ListaAluno *L, Aluno *a, int *nUsp, int *erro);
// Retorna um ponteiro para o aluno buscado pelo nUsp
Aluno *retorna_a(ListaAluno *L, int *nUsp);

#endif
