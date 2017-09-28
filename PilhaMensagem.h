typedef char elem;

typedef struct noMensagem {
	elem *info;
	struct noMensagem *prox;
} NoMensagem;

struct pilha {
	NoMensagem *topo;
};

typedef struct pilha Pilha;

void Create(Pilha *P);
void Push(Pilha *P, elem *X, int *erro);
void Pop(Pilha *P, elem *X, int *erro);
int IsEmpty(Pilha *P);


