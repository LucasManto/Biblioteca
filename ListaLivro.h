//#include "Livro.h"

typedef struct {
        NoLivro *inicio, *fim;
} ListaLivro;

void cria_l(ListaLivro *L);
void inserir_l(ListaLivro *L, Livro *X, int *erro);
void finaliza_l(ListaLivro *L);
int tamanho_rec_l(NoLivro *p);
int tamanho_rec_lista_l(ListaLivro *L);
int tamanho_l(ListaLivro *L);
int esta_na_lista_l(ListaLivro *L, Livro *X);
int esta_na_lista_rec_l(NoLivro *p, Livro *X);
void eliminar_l(ListaLivro *L, NoLivro *x, int *erro);
void eliminar_rec_l(ListaLivro *L, NoLivro* anterior, NoLivro* atual, Livro *X, int *erro);
NoLivro *busca_na_lista_l(ListaLivro *L, int *isbn);
