#ifndef biblioteca_dinamica_h
#define biblioteca_dinamica_h

#include "ListaAluno.h"
#include "ListaLivro.h"

int CadastrarAluno(ListaAluno *L, int *nUsp, char *nome, char *email, char *telefone);
int RemoverAluno(ListaAluno *L, int *nUsp);
int BuscarAluno(ListaAluno *L, Aluno *a, int *nUsp);

int CadastrarLivro(ListaLivro *L, int *isbn, char *titulo, char *autor, char *editora, int *quantidade);
int RemoverLivro(ListaLivro *L, int *isbn);
int BuscarLivro(ListaLivro *L, Livro *l, int *isbn);

int RetirarLivro(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn);
int DevolverLivro(ListaLivro *L, int *isbn);
void ColocarNaFila(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn);
void TirarDaFila(ListaLivro *L, int *isbn);
int VerMensagens(ListaAluno *L, int *nUsp);

void RemoverDaFila(ListaLivro *L, int *nUsp);

#endif
