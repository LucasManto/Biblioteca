#include "BibliotecaDinamica.h"

int CadastrarAluno(ListaAluno *alunos, char *nome, int nUsp, int *telefone, char *email) {
    int erro;
    
    Aluno *a = CriaAluno(nome, nUsp, telefone, email, &erro);
    if(erro == 0) return erro;
    
    inserir_a(alunos, a, &erro);
    
    return erro;
}

NoAluno *BuscaAluno(ListaAluno *alunos, int *nUsp) {
	return busca_na_lista_a(alunos, nUsp);
}

int RemoverAluno(ListaAluno *alunos, Aluno *a) {
	int erro;
    
    eliminar_a(alunos, a, &erro);
    
    return erro;
    
//    eliminar_rec(alunos, NULL, alunos->inicio, e, &erro);
}

char *LeString() {
    char *str = NULL;
    char aux;
    int i = 0;

    fflush(stdin);

    aux = getchar();
    while (aux != '\n') {
        str = (char *) realloc(str, (i + 1) *sizeof(char));
        str[i] = aux;
        i++;
        aux = getchar();
    }
    str[i] = '\0';

    return str;
}

int *LeTelefone() {
    int *str = NULL;
    char aux;
    int i = 0;

    fflush(stdin);

    aux = getchar();
    while (aux != '\n') {
        str = (int *) realloc(str, (i + 1) *sizeof(int));
        str[i] = atoi(&aux);
        i++;
        aux = getchar();
    }

    return str;
}
