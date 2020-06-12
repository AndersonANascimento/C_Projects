/** 
 * Disciplina...: [ESTRUTURA DE DADOS I] 
 * Professor....: Me. Pietro M de Oliveira 
 * Objetivo.....: Manipula��o de pilhas est�ticas(MAPA)
 * Vers�o.......: Beta - Teste
 * Autor(a).....: Anderson Abreu do Nascimento
 * RA...........: 1914315-5
 * Data atual...: 08/05/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Constantes */
#define TAM_PILHA 8
/* Defini��o de estrura do tipo pilha */
typedef struct tp_pilha {
    int dados[TAM_PILHA];
    int base;
    int topo;
} tp_pilha;
/* Vari�veis globais */
tp_pilha pilha1;
tp_pilha pilha2;
/* Fun��o de empilhamento */
void push(int valor, tp_pilha *p) {
    if (p->topo == TAM_PILHA) {
        printf("Pilha cheia.\n");
        system("pause");
    } else {
        p->dados[p->topo] = valor;
        p->topo++;
    }
}
/* Fun��o de desempilhamento */
int pop(tp_pilha *p) {
    int valor;
    if (p->topo == p->base) {
        printf("Pilha vazia.\n");
        system("pause");
    } else {
        p->topo--;
        valor = p->dados[p->topo];
        return valor;
    }
}
/* Fun��o para impress�o da pilha a partir de sua base */
void print_pilha(tp_pilha *p) {
    int i;
    for (i = p->base; i < p->topo; i++)
        printf("%d ", p->dados[i]);
    printf("\n");
}
/* Fun��o principal */
int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    /* Declara��es locais */
    int i, ra[TAM_PILHA] = {1,9,1,4,3,1,5,5};

    /* Inicializa��o da pilha */
    pilha1.base = pilha1.topo = 0;

    /* Empilhando os digitos do RA - 19143155 atrav�s da fun��o push, passando a pilha1 por refer�ncia */
    for (i = 0; i < TAM_PILHA; i++) {
        printf("Empilha: %d\n", ra[i]);
        push(ra[i], &pilha1);
    }

    printf("Pilha1: ");
    /* Chamada de fun��o de impress�o passando por refer�ncia a pilha1 */
    print_pilha(&pilha1);

    printf("Desempilhando de Pilha1 e empilhando em Pilha2.\n");
    /* Loop para varrer pilha1 enquanto tiver elementos */
    while (pilha1.topo > pilha1.base) {
        /* Empilha na pilha2 o elemento desempilhado da pilha1 */
        push(pop(&pilha1), &pilha2);
    }   

    printf("Pilha2: ");   
    /* Chamada de fun��o de impress�o passando por refer�ncia a pilha2 */
    print_pilha(&pilha2);

    return 0;
}
