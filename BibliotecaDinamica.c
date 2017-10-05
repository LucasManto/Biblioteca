#include "BibliotecaDinamica.h"
#include <stdio.h>
#include <string.h>

int CadastrarAluno(ListaAluno *L, int *nUsp, char *nome, char *email, char *telefone) {
	int erro;
	
	Aluno *a = (Aluno *) malloc(sizeof(Aluno));
	a->nUsp = *nUsp;
	strcpy(a->nome, nome);
	strcpy(a->email, email);
	strcpy(a->telefone, telefone);
	Create(&a->mensagens);
	
	inserir_a(L, a, &erro);
	
	return erro;
}

int RemoverAluno(ListaAluno *L, int *nUsp) {
	int erro;
	
	eliminar_a(L, nUsp, &erro);
	
	return erro;
}

int BuscarAluno(ListaAluno *L, Aluno *a, int *nUsp) {
	int erro;
	
	buscar_a(L, a, nUsp, &erro);
	
	return erro;
}

int CadastrarLivro(ListaLivro *L, int *isbn, char *titulo, char *autor, char *editora, int *quantidade) {
	int erro;
	
	Livro *l = (Livro *) malloc(sizeof(Livro));
	l->isbn = *isbn;
	strcpy(l->titulo, titulo);
	strcpy(l->autor, autor);
	strcpy(l->editora, editora);
	l->quantidade = *quantidade;
	Cria(&l->fila);
	
	inserir_l(L, l, &erro);
	
	return erro;
}

int RemoverLivro(ListaLivro *L, int *isbn) {
	int erro;
	
	eliminar_l(L, isbn, &erro);
	
	return erro;
}

int BuscarLivro(ListaLivro *L, Livro *l, int *isbn) {
	int erro;
	
	buscar_l(L, l, isbn, &erro);
	
	return erro;
}

int RetirarLivro(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn) {
	int erro;
	
	Livro *l;
	
	l = retorna_l(L, isbn);
	
	if(l->quantidade > 0) {
		erro = 1;
		l->quantidade--;
	}
	else {
		erro = 0;
		ColocarNaFila(A, nUsp, L, isbn);
	}
	
	return erro;
}

int DevolverLivro(ListaLivro *L, int *isbn) {
	Livro *l;
	
	l = retorna_l(L, isbn);
	
	l->quantidade++;
	TirarDaFila(L, isbn);
}

void ColocarNaFila(ListaAluno *A, int *nUsp, ListaLivro *L, int *isbn) {
	int erro;
	
	Aluno *a;
	Livro *l;
	
	a = retorna_a(A, nUsp);	
	l = retorna_l(L, isbn);
	
	Entra(&l->fila, a, &erro);
}

void TirarDaFila(ListaLivro *L, int *isbn) {
	int erro;
	char m[100];
	
	Aluno *a = NULL;
	Livro *l;
	
	l = retorna_l(L, isbn);
	
	Sai(&l->fila, &a, &erro);
	
	if(erro == 0) {
		sprintf(m, "Livro ISBN: %d disponivel.", l->isbn);
		Push(&a->mensagens, m, &erro);
	}
}

int VerMensagens(ListaAluno *L, int *nUsp) {
	char m[100];
	int erro = 0, erroM;
	
	Aluno *a;
	
	a = retorna_a(L, nUsp);
	
	while(!IsEmpty(&a->mensagens)) {
		Pop(&a->mensagens, m, &erroM);
		printf("%s\n", m);
		erro = 1;
	}
	
	return erro;
}

void RemoverDaFila(ListaLivro *L, int *nUsp) {
	int erro;
	
	NoLivro *p = L->inicio;
	NoAluno *a;
	int cont = 0;
	Aluno *aluno;
	
	while(p != NULL) {
		while(cont < p->info->fila.total) {
			Sai(&p->info->fila, &aluno, &erro);
			if(aluno->nUsp != *nUsp) {
				Entra(&p->info->fila, aluno, &erro);
			}
			cont++;
		}
		p = p->prox;
	}
}
