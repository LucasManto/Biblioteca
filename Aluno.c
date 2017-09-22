#include "Aluno.h"

Aluno *CriaAluno(char *nome, int nUsp, int *telefone, char *email, int *erro) {
    Aluno *a = (Aluno *) malloc(sizeof(Aluno));
    if(a == NULL) {
    	*erro = 0;
	}
	else {
		*erro = 1;
	    a->nome = nome;
	    a->nUsp = nUsp;
	    a->telefone = telefone;
	    a->email = email;
	    Create(&a->mensagens);
	}
	
    return a;
}
