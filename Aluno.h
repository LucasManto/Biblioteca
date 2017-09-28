//#include "PilhaMensagem.h"

typedef struct {
    char *nome;
    int nUsp;
    char *telefone;
    char *email;
    Pilha mensagens;
} Aluno;

typedef struct noAluno {
	Aluno info;
	struct noAluno *prox;
} NoAluno;

Aluno *CriaAluno(char *nome, int nUsp, char *telefone, char *email, int *erro);
