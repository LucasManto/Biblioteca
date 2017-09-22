#include <stdio.h>
#include <stdlib.h>
#include "ListaAluno.h"

int CadastrarAluno(ListaAluno *alunos, char *nome, int nUsp, int *telefone, char *email);
NoAluno *BuscaAluno(ListaAluno *alunos, int *nUsp);
int RemoverAluno(ListaAluno *alunos, NoAluno *a);
char *LeString();
int *LeTelefone();
