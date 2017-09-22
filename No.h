#include "Aluno.h"

// typedef Aluno elem;
typedef union {
    Aluno a;
    // Livro l;
} elem;

typedef struct no {
    elem info;
    struct no *prox;
} No;