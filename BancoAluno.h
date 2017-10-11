/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef banco_aluno_h
#define banco_aluno_h

#define TAM 100
#include "AlunoEstatico.h"

// Estrutura que define o Banco de Memoria que armazena alunos
typedef struct
{
	int ini, fim, primeiro_vazio;
	NoAlunoEstatico itens[TAM];
} ListaAluno;

// Criacao do banco
void cria_a(ListaAluno *);
// Retorna a primeira posicao vazia do banco
void getnode(ListaAluno *, int *);
// Adiciona um espaco vazio no banco
void freenode(ListaAluno *, int *);
// Verifica se o banco esta vazio
int EstaVazio(ListaAluno *);
// Verifica se o banco esta cheio
int EstaCheio(ListaAluno *);
// Elimina aluno buscado pelo nUsp
void eliminar_a(ListaAluno *, int *, int *);
// Insere aluno no banco
void inserir_a(ListaAluno *, Aluno *, int *);
// Busca aluno pelo nUsp e copia os valores para x
void buscar_a(ListaAluno *B, Aluno *x, int *nUsp, int *erro);
// Retorna a posicao do aluno buscado pelo nUsp
int retorna_a(ListaAluno *L, int *nUsp);

#endif
