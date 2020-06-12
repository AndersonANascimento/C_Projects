#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO* prox;
} NO;

typedef struct PILHA {
    NO* topo;
} PILHA;

PILHA *p;

void empilhar(int valor) {
    printf("Empilhando...\n");
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = valor; // rand()%100;
    ptr->prox = p->topo;
    p->topo = ptr;
    printf("NO topo %d\n", p->topo->dado);
}

int desempilhar() {
    NO* ptr = p->topo;
    int valor;
    if (ptr != NULL) {
        p->topo = ptr->prox;
        ptr->prox = NULL;
        valor = ptr->dado;
        free(ptr);
        return valor;
    }    
}

int main(int argc, char const *argv[]) {
	p = (PILHA *) malloc(sizeof(PILHA));
	p->topo = NULL;
    
    empilhar(1);
    empilhar(9);
    empilhar(1);
    empilhar(4);
    empilhar(3);
    empilhar(1);
    empilhar(5);
    empilhar(5);

    while (p->topo != NULL) {
        printf("\nDesempilha %d", desempilhar());
    }

    free(p);
    return 0;
}
