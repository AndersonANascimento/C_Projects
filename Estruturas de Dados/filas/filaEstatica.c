#include <stdio.h>
#include <stdlib.h>

#define TAM_FILA 8

struct tp_fila {
    int dados[TAM_FILA];
    int ini;
    int fim;
};

struct tp_fila fila;

void dequeue(int valor) {
    if (fila.fim == TAM_FILA) {
        printf("Fila cheia.\n");
        system("pause");
    } else {
        fila.dados[fila.fim] = valor;
        fila.fim++;
    }
}

int queue() {
    int valor, i;
    if (fila.ini == fila.fim) {
        printf("Fila vazia.\n");
        system("pause");
    } else {
        valor = fila.dados[fila.ini];
        for (i = fila.ini; i < TAM_FILA; i++) {
            fila.dados[i] = fila.dados[i+1];            
        }
        fila.dados[fila.fim] = 0;
        fila.fim--;
        return valor;
    }
}

void print_queue() {
    int i;
    for (i = fila.ini; i < fila.fim; i++)
        printf("%d ", fila.dados[i]);    
}

int main(int argc, char const *argv[]) {
    fila.ini = 0;
    fila.fim = 0;

    dequeue(1);
    dequeue(9);
    dequeue(1);
    dequeue(4);
    dequeue(3);
    dequeue(1);
    dequeue(5);
    dequeue(5);

    print_queue();

    while (fila.fim > 0)
    {
        printf("\nDesenfileira %d", queue());
    }
    
    print_queue();
    return 0;
}
