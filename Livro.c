//#include "Livro.h"
//#include <stdlib.h>

Livro *CriaLivro(char *titulo, char *autor, int *isbn, char *editora, int *quantidade, int *erro){
    Livro *l = (Livro*) malloc(sizeof(Livro));
    if(l == NULL) {
    	*erro = 0;
	}
	else {
		*erro = 1;
	    l->titulo = titulo;
	    l->autor = autor;
	    l->isbn = *isbn;
	    l->editora = editora;
	    l->quantidade = *quantidade;
//	    Cria(&l->fila);
	}

    return l;
}
