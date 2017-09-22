#include <stdlib.h>
#include "Aluno.h"

struct fila {
	NoAluno *inicio, *fim;
};

typedef struct fila Fila;

void Cria(Fila *F);
void Entra(Fila *F, Aluno *X, int *erro);
void Sai(Fila *F, Aluno *X, int *erro);
int EstaVazia(Fila *F);
int EstaCheia(Fila *F);
