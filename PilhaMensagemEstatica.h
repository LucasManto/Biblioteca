/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#ifndef pilha_estatica_mensagem
#define pilha_estatica_mensagem

#define TamPilha 10

typedef struct
{
	int topo;
	char itens[TamPilha][100];
} Pilha;

// Cria uma pilha P
void Create(Pilha *);
// Esvazia uma pilha P
void Empty(Pilha *);
//Insere o elemento X na pilha P. Retorna 0 se n�o houver erro, Retorna 1 se algum erro acontecer
int Push(Pilha *, char *);
//Remove o elemento X da pilha P. Retorna 0 se n�o houver erro, Retorna 1 se algum erro acontecer
int Pop(Pilha *, char *);
//Retorna 1 se a pilha estiver vazia, 0 se a pilha tiver conteudo
int IsEmpty(Pilha *P);
//Retorna 1 se a pilha estiver cheia, 0 se a pilha tiver conteudo ou vazia
int IsFull(Pilha *P);

#endif
