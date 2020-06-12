/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Estruturas */
typedef struct NO {
    int dado;
    NO* prox;
} NO;

typedef struct pilha {
    NO* topo;
} PILHA;

typedef struct fila {
    NO* inicio;
    NO* fim;
} FILA;

/* Globais */
FILA* f;
PILHA* p;

void empilha(int dado, PILHA *p) {
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = dado;
    ptr->prox = p->topo;
    p->topo = ptr;
}

int desempilha(PILHA *p) {
    NO* ptr = p->topo;
    int dado = -1;
    if (ptr != NULL) {
        dado = ptr->dado;
        p->topo = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
    }
    return dado;
}

void enfileira() {
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = rand()%100;
    ptr->prox = NULL;
    if (f->inicio == NULL)
        f->inicio = ptr;
    else
        f->fim->prox = ptr;
    f->fim = ptr;
}

int desenfileira() {
    NO* ptr = f->inicio;
    int dado = -1;
    if (ptr != NULL) {
        dado = ptr->dado;
        f->inicio = ptr->prox;
        ptr->prox = NULL;
        free(ptr);
    }
    return dado;
}

/* Função Principal */
int main(int argc, char const *argv[]) {
    /* Alocando estruturas em memoria */
    f = (FILA *) malloc(sizeof(FILA));
    p = (PILHA *) malloc(sizeof(PILHA));
    
    /* Inicialização dos ponteiros */
    p->topo = NULL;
    f->inicio = NULL;
    f->fim = NULL;

    empilha(rand()%100, p);
    printf("desempilha %d\n", desempilha(p));

    enfileira();
    desenfileira();
    return 0;
}
