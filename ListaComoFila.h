#include <stdlib.h>
#include "No.h"

struct fila {
	No *inicio, *fim;
};

typedef struct fila Fila;

void Cria(Fila *F);
void Entra(Fila *F, elem *X, int *erro);
void Sai(Fila *F, elem *X, int *erro);
int EstaVazia(Fila *F);
int EstaCheia(Fila *F);
