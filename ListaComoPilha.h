#include <stdlib.h>
#include "No.h"

struct pilha {
	No *topo;
};

typedef struct pilha Pilha;

void Create(Pilha *P);
void Push(Pilha *P, elem *X, int *erro);
void Pop(Pilha *P, elem *X, int *erro);
int IsEmpty(Pilha *P);


