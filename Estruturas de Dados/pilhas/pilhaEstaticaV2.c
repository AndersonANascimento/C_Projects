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
#define TAM_PILHA 3

/* Estrutura da Pilha */
struct tp_pilha {
    int dados[TAM_PILHA];
    int base;
    int topo;
};
/* Globais */
struct tp_pilha pilha;
/* Protótipos */
void push(int valor);
int pop();
void print_pilha();
void menu();

/* Função Principal */
int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    int elem, op = 1;
    pilha.base = pilha.topo = 0;
    
    while (op != 0) {
        elem = -1;
        system("clear");
        print_pilha();
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            printf("\nDigite o valor a ser empilhado: ");
            scanf("%d", &elem);
            push(elem);
            break;
        case 2:
            // printf("pop => %d", pop());
            elem = pop();
            if (elem != -1) {
                printf("O %d foi desempilhado!\n", elem);
                system(PAUSE);
            }
            break;
        default:
            break;
        }
    }
    return 0;
}

void push(int valor) {
    if (pilha.topo == TAM_PILHA) {
        printf("Pilha cheia.\n");
        system(PAUSE);
    } else {
        pilha.dados[pilha.topo] = valor;
        pilha.topo++;
    }
}

int pop() {
    int valor = -1;
    if (pilha.topo == pilha.base) {
        printf("Pilha vazia.\n");
        system(PAUSE);
    } else {
        pilha.topo--;
        valor = pilha.dados[pilha.topo];
    }
    return valor;
}

void print_pilha() {
    int i;
    for (i = pilha.topo - 1; i >= pilha.base; i--)
        printf("%d\n", pilha.dados[i]);    
}

void menu() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}