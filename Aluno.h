#include <stdlib.h>
#include "PilhaMensagem.h"

typedef struct {
    char *nome;
    int nUsp;
    int *telefone;
    char *email;
    Pilha mensagens;
} Aluno;

typedef struct noAluno {
	Aluno info;
	struct noAluno *prox;
} NoAluno;

Aluno *CriaAluno(char *nome, int nUsp, int *telefone, char *email, int *erro);
