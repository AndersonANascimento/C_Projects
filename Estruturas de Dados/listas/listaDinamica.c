#include <stdio.h>
#include <stdlib.h>

typedef struct no {
    int dado;
    struct no* prox;
} no;

typedef struct lista {
    no* ini;
} lista;

lista *l;