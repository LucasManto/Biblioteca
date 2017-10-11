/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef banco_livro_h
#define banco_livro_h

#define TAM_L 1000
#include "LivroEstatico.h"
#include "BancoFila.h"

// Estrutura que define o Banco de Memoria que armazena livros
typedef struct
{
        int ini, fim, primeiro_vazio;
        NoLivroEstatico itens[TAM_L];
        BancoFila fila;
} ListaLivro;

// Criacao do banco
void cria_l(ListaLivro *);
// Retorna a primeira posicao vazia do banco
void getnode_l(ListaLivro *, int *);
// Adiciona um espaco vazio no banco
void freenode_l(ListaLivro *, int *);
// Verifica se o banco esta vazio
int EstaVazio_l(ListaLivro *);
// Verifica se o banco esta cheio
int EstaCheio_l(ListaLivro *);
// Elimina livro buscado pelo isbn
void eliminar_l(ListaLivro *, int *, int *);
// Insere livro no banco
void inserir_l(ListaLivro *, Livro *, int *);
// Busca livro pelo isbn e copia os valores para x
void buscar_l(ListaLivro *B, Livro *x, int *Isbn, int *erro);
// Retorna a posicao do livro buscado pelo isbn
int retorna_l(ListaLivro *L, int *Isbn);

#endif
