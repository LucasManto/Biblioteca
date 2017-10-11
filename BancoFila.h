/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef banco_fila
#define banco_fila

#define TAMFILA 1000
#include "AlunoEstatico.h"

// Estrutura que define o Banco de Memoria que armazena alunos para a fila de espera
typedef struct
{
	int ini, fim, primeiro_vazio;
	NoAlunoEstatico itens[TAMFILA];
} BancoFila;

// Criacao do banco
void cria_f(BancoFila *);
// Retorna a primeira posicao vazia do banco
void getnode_f(BancoFila *, int *);
// Adiciona um espaco vazio no banco
void freenode_f(BancoFila *, int *);
// Verifica se o banco esta vazio
int EstaVazio_f(BancoFila *);
// Verifica se o banco esta cheio
int EstaCheio_f(BancoFila *);
// Elimina aluno buscado pelo nUsp
void retirar_f(BancoFila *, Aluno *, int *, int *, int *, int *);
// Insere aluno no banco
void inserir_f(BancoFila *, Aluno *, int *, int *, int *, int *);

#endif
