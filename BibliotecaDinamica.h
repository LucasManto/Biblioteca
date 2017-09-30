#ifndef BIBLIOTECA_DINAMICA_H
#define BIBLIOTECA_DINAMICA_H

#include "ListaAluno.h"
#include "ListaLivro.h"

int CadastrarAluno(ListaAluno *alunos, char *nome, int nUsp, char *telefone, char *email);
NoAluno *BuscaAluno(ListaAluno *alunos, int *nUsp);
int RemoverAluno(ListaAluno *alunos, NoAluno *a);

int CadastrarLivro(ListaLivro *livros, char *titulo, int isbn, char *autor, char *editora, int quantidade);
NoLivro *BuscaLivro(ListaLivro *livros, int *isbn);
int RemoverLivro(ListaLivro *livros, NoLivro *l);

int ColocaNaFila(NoLivro *l, NoAluno *a);
int RemoveDaFila(NoLivro *l, NoAluno *a);

#endif
