/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Constantes */
#ifdef WIN32
#define PAUSE "pause"
#else
#define PAUSE "read -p \'Pressione enter para continuar...\' continue"
#endif
#define TAM_FILA 3

/* Estrutura da Fila */
struct tp_fila {
    int dados[TAM_FILA];
    int ini;
    int fim;
};

/* Globais */
struct tp_fila fila;

/* Protótipos */
void queue(int valor);
int dequeue();
void print_queue();
void menu();

/* Função Principal */
int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    int elem, op = 1;
    fila.ini = fila.fim = 0;

    while (op != 0) {
        elem = -1;
        system("clear");
        print_queue();
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("\nDigite o valor a ser inserido: ");
            scanf("%d", &elem);
            queue(elem);
            break;
        case 2:
            elem = dequeue();
            if (elem != -1) {
                printf("O %d foi retirado da fila!\n", elem);
                system(PAUSE);
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

void queue(int valor) {
    if (fila.fim == TAM_FILA) {
        printf("Fila cheia.\n");
        system(PAUSE);
    } else {
        fila.dados[fila.fim] = valor;
        fila.fim++;
    }
}

int dequeue() {
    int i, valor = -1;
    if (fila.ini == fila.fim) {
        printf("Fila vazia.\n");
        system(PAUSE);
    } else {
        valor = fila.dados[fila.ini];
        for (i = fila.ini; i < TAM_FILA; i++) {
            fila.dados[i] = fila.dados[i+1];            
        }
        fila.dados[fila.fim] = 0;
        fila.fim--;
    }
    return valor;
}

void print_queue() {
    int i;
    printf("[");
    for (i = fila.ini; i < fila.fim; i++)
        printf("%d ", fila.dados[i]);    
    printf("]");
}

void menu() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Enfileira\n");
    printf("2 - Desenfileira\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}