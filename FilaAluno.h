#ifndef fila_aluno_h
#define fila_aluno_h

#include <stdlib.h>
#include "Aluno.h"

typedef struct fila {
	NoAluno* inicio, *fim;
	int total;
} FilaAluno;

void Cria(FilaAluno *F);
void Entra(FilaAluno *F, Aluno *X, int *erro);
void Sai(FilaAluno *F, Aluno **X, int *erro);
int EstaVazia(FilaAluno *F);

#endif
