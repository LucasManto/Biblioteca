#include "Livro.h"

Livro *CriaLivro(char *titulo, char *autor, int *isbn, char *editora, int *quantidade, int *erro){
    Livro *l = (Livro*) malloc(sizeof(Livro));
    if(l == NULL) {
    	*erro = 0;
	}
	else {
		*erro = 1;
	    l->titulo = (char *) malloc(50*sizeof(char));
	    l->isbn = *isbn;
		l->autor = (char *) malloc(50*sizeof(char));
		l->editora = (char *) malloc(50*sizeof(char));
	    l->quantidade = *quantidade;
	    Cria(&l->fila);
	    
	    strcpy(l->titulo, titulo);
	    strcpy(l->autor, autor);
	    strcpy(l->editora, editora);
	}

    return l;
}
