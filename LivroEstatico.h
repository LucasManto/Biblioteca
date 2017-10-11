/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef livro_h
#define livro_h

// Estrutura para armazenamento dos dados do livro da vers�o est�tica
typedef struct
{
	int Isbn, quantidade;
	char titulo[100], autor[100], editora[100];
	int inicio_fila, fim_fila;
	int tam_fila;
} Livro;

// Criacao do no utilizado nas estruturas est�ticas
typedef struct noLivroEstatico
{
	Livro info;
	int prox;
} NoLivroEstatico;

#endif
