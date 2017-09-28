//#include "BibliotecaDinamica.h"

int CadastrarAluno(ListaAluno *alunos, char *nome, int nUsp, char *telefone, char *email) {
    int erro;
    
    Aluno *a = CriaAluno(nome, nUsp, telefone, email, &erro);
    if(erro == 0) return erro;
    
    inserir_a(alunos, a, &erro);
    
    return erro;
}

NoAluno *BuscaAluno(ListaAluno *alunos, int *nUsp) {
	return busca_na_lista_a(alunos, nUsp);
}

int RemoverAluno(ListaAluno *alunos, NoAluno *a) {
	int erro;
    
    eliminar_a(alunos, a, &erro);
    
    return erro;
}

int CadastrarLivro(ListaLivro *livros, char *titulo, int isbn, char *autor, char *editora, int quantidade) {
    int erro;
    
    Livro *l = CriaLivro(titulo, autor, &isbn, editora, &quantidade, &erro);
    if(erro == 0) return erro;
    
    inserir_l(livros, l, &erro);
    
    return erro;
}

NoLivro *BuscaLivro(ListaLivro *livros, int *isbn) {
	return busca_na_lista_l(livros, isbn);
}

int RemoverLivro(ListaLivro *livros, NoLivro *l) {
	int erro;
    
    eliminar_l(livros, l, &erro);
    
    return erro;
}

int ColocaNaFila(NoLivro *l, NoAluno *a) {
	int erro;
	
	Entra(&l->info.fila, &a->info, &erro);
	
	return erro;
}
