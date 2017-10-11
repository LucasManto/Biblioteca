/*
	Alunos: 
		Felipe Veloso		nºUsp: 10349529
		Lucas Mantovani		nºUsp: 10258942

*/

#ifndef biblioteca_dinamica_h
#define biblioteca_dinamica_h

#include "BancoAluno.h"
#include "BancoLivro.h"

// Funcao que realiza o cadastro do aluno na lista.
// Inclui a criacao de um novo aluno e da sua pilha de mensagens.
// E a inclusao do mesmo na fila de alunos
int CadastrarAluno(ListaAluno *L, int *nUsp, char *nome, char *email, char *telefone);
// Remove o aluno buscado pelo nUsp da lista de alunos
int RemoverAluno(ListaAluno *L, int *nUsp);
// Realiza a busca de um aluno
// O aluno é procurado pelo nUsp e suas informacoes sao copiadas para um tipo Aluno
int BuscarAluno(ListaAluno *L, Aluno *a, int *nUsp);

// Funcao que realiza o cadastro do livro na lista.
// Inclui a criacao de um novo livro e da sua fila de espera
// E a inclusao do mesmo na lista de livros
int CadastrarLivro(ListaLivro *L, int *isbn, char *titulo, char *autor, char *editora, int *quantidade);
// Remove o livro buscado pelo isbn da lista de livros
int RemoverLivro(ListaLivro *L, int *isbn);
// Realiza a busca de um aluno
// O livro é procurado pelo isbn e suas informacoes sao copiadas para um tipo Livro
int BuscarLivro(ListaLivro *L, Livro *l, int *isbn);

// Retira o livro buscado pelo isbn
// Caso nao seja possivel retirar o livro, o aluno que tentou retirar é colocado na fila de espera
int RetirarLivro(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn);
// Devolve o livro
// Retira o aluno da fila de espera e envia uma mensagem informando que o livro esta disponivel
int DevolverLivro(ListaLivro *L, int *isbn, ListaAluno *A);
// Coloca o aluno na fila de espera do livro de isbn passado como argumento
void ColocarNaFila(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn);
// Retira o aluno na fila de espera do livro de isbn passado como argumento
void TirarDaFila(ListaLivro *L, int *isbn, ListaAluno *A);
// Imprime todas as mensagens do aluno de nUsp passado como argumento
int VerMensagens(ListaAluno *L, int *nUsp);

// Remove o aluno buscado pelo nUsp da fila
// Por se tratar de uma fila, não pode ser percorrida
// Os elementos são retirados e se não for o aluno procurado, são reinseridos
void RemoverDaFila(ListaLivro *L, int *nUsp);

#endif
