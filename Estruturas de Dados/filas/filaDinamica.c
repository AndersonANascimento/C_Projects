#include <stdio.h>
#include <stdlib.h>

typedef struct NO {
    int dado;
    struct NO* prox;
} NO;

typedef struct FILA {
    NO* ini;
    NO* fim;
} FILA;

FILA *f;

void enfileirar(int valor) {
    NO* ptr = (NO *)malloc(sizeof(NO));
    ptr->dado = valor; // rand()%100;
    ptr->prox = NULL;
    if (f->ini == NULL) {
        f->ini = ptr;
    } else {
        f->fim->prox = ptr;
    }    
    f->fim = ptr;
    printf("NO %d inserido\n", f->fim->dado);
}

int desenfileirar() {
    NO* ptr = f->ini;
    int valor;
    if (ptr != NULL) {
        f->ini = ptr->prox;
        ptr->prox = NULL;
        valor = ptr->dado;
        free(ptr);
        return valor;
    }    
}

int main(int argc, char const *argv[]) {
    f = (FILA *) malloc(sizeof(FILA));
	f->ini = f->fim = NULL;
    
    enfileirar(1);
    enfileirar(9);
    enfileirar(1);
    enfileirar(4);
    enfileirar(3);
    enfileirar(1);
    enfileirar(5);
    enfileirar(5);

    while (f->ini != NULL) {
        printf("\nDesenfilera %d", desenfileirar());
    }

    free(f);
    return 0;
}
