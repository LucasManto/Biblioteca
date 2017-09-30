#include "Aluno.h"

Aluno *CriaAluno(char *nome, int nUsp, char *telefone, char *email, int *erro) {
    Aluno *a = (Aluno *) malloc(sizeof(Aluno));
    if(a == NULL) {
    	*erro = 0;
	}
	else {
		*erro = 1;
		a->nome = (char *) malloc(50*sizeof(char));
	    a->nUsp = nUsp;
		a->telefone = (char *) malloc(50*sizeof(char));
		a->email = (char *) malloc(50*sizeof(char));
	    Create(&a->mensagens);
	    
	    strcpy(a->nome, nome);
	    strcpy(a->telefone, telefone);
	    strcpy(a->email, email);
	}
	
    return a;
}
