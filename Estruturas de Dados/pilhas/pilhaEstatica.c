#include <stdio.h>
#include <stdlib.h>

#define TAM_PILHA 8

struct tp_pilha {
    int dados[TAM_PILHA];
    int base;
    int topo;
};

struct tp_pilha pilha;

void push(int valor) {
    if (pilha.topo == TAM_PILHA) {
        printf("Pilha cheia.\n");
        system("pause");
    } else {
        pilha.dados[pilha.topo] = valor;
        pilha.topo++;
    }
}

int pop() {
    int valor;
    if (pilha.topo == pilha.base) {
        printf("Pilha vazia.\n");
        system("pause");
    } else {
        pilha.topo--;
        valor = pilha.dados[pilha.topo];
        return valor;
    }
}

void print_pilha() {
    int i;
    for (i = pilha.topo - 1; i >= pilha.base; i--)
        printf("%d\n", pilha.dados[i]);    
}

int main(int argc, char const *argv[]) {
    pilha.base = pilha.topo = 0;
    push(1);
    push(9);
    push(1);
    push(4);
    push(3);
    push(1);
    push(5);
    push(5);

    print_pilha();

    while (pilha.topo > pilha.base) {
        printf("\nDesempilha %d", pop());
    }
    
    print_pilha();
    return 0;
}
