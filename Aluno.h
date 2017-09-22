#include <stdlib.h>

typedef struct {
    char *nome;
    int nUsp;
    int *telefone;
    char *email;
    // Pilha mensagens;
} Aluno;

Aluno *CriaAluno(char *nome, int nUsp, int *telefone, char *email, int *erro);
