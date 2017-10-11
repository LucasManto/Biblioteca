/*
	Alunos: 
		Felipe Veloso		n�Usp: 10349529
		Lucas Mantovani		n�Usp: 10258942

*/

#include "BancoFila.h"

void cria_f(BancoFila *B)
{
    int i;
    for (i = 0; i < TAMFILA - 1; i++)
        B->itens[i].prox = i + 1;
    B->itens[TAMFILA - 1].prox = -1;
    B->primeiro_vazio = 0;
}

void getnode_f(BancoFila *B, int *pos)
{
    if (B->primeiro_vazio != -1)
    {
        *pos = B->primeiro_vazio;
        B->primeiro_vazio = B->itens[B->primeiro_vazio].prox;
        B->itens[*pos].prox = -1;
    }
    else
        *pos = -1;
}

void freenode_f(BancoFila *B, int *pos)
{
    B->itens[*pos].prox = B->primeiro_vazio;
    B->primeiro_vazio = *pos;
}

int EstaVazio_f(BancoFila *B)
{
    if (B->ini == -1)
        return (1);
    else
        return (0);
}

int EstaCheio_f(BancoFila *B)
{
    if (B->primeiro_vazio == -1)
        return (1);
    else
        return (0);
}

void retirar_f(BancoFila *B, Aluno *x, int *ini, int *fim, int *tam, int *erro)
{
    int pos;
    if (EstaVazio_f(B) || *tam == 0)
        *erro = 1;
    else
    {
        *erro = 0;
        *x = B->itens[*ini].info;
        pos = *ini;
        *ini = B->itens[*ini].prox;
        if (*ini == -1)
            *fim = -1;
        freenode_f(B, &pos);

        *tam = *tam - 1;
    }
}

void inserir_f(BancoFila *B, Aluno *x, int *ini, int *fim, int *tam, int *erro)
{
    int pos;
    if (EstaCheio_f(B) || *tam == 30)
        *erro = 1;
    else
    {
        *erro = 0;
        getnode_f(B, &pos);
        B->itens[pos].info = *x;
        B->itens[pos].prox = -1;
        if (*fim != -1)
            B->itens[*fim].prox = pos;
        *fim = pos;
        if (*ini == -1)
            *ini = pos;

        *tam = *tam + 1;
    }
}
