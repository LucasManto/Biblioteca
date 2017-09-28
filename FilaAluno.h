//#include "Aluno.h"

struct fila {
	NoAluno *inicio, *fim;
};

typedef struct fila FilaAluno;

void Cria(FilaAluno *F);
void Entra(FilaAluno *F, Aluno *X, int *erro);
void Sai(FilaAluno *F, Aluno *X, int *erro);
int EstaVazia(FilaAluno *F);
int EstaCheia(FilaAluno *F);
