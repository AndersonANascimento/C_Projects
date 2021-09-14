/** 
 * Disciplina...: [ESTRUTURA DE DADOS I] 
 * Professor....: Me. Pietro M de Oliveira 
 * Objetivo.....: Árvore AVL(MAPA)
 * Vers?o.......: Beta - Teste
 * Autor(a).....: Anderson Abreu do Nascimento
 * RA...........: 1914315-5
 * Data atual...: 02/07/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Constantes */
#define TAM_AVL 8

/* Estrutura */
typedef struct NO {
    char dado;
    NO* esquerda;
    NO* direita;
    NO* pai;
} NO;

typedef struct TREE {
    NO* raiz;
} TREE;

TREE *t;

void arvore_insere(int valor) {
    printf("Inserindo...\n");
    NO* ptr = (NO *) malloc(sizeof(NO));
    ptr->dado = valor;
    ptr->pai = ptr->esquerda = ptr->direita = NULL;
    if (t->raiz == NULL) {
        t->raiz = ptr;
    } else if (valor < t->raiz->dado)   {
        /* code */
    }
    
}

/* Função principal */
int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    /* Declarações locais */
    int i, ra[TAM_AVL] = {1,9,1,4,3,1,5,5};

    t = (TREE *) malloc(sizeof(TREE));
    t->raiz = NULL;

    /* Empilhando os digitos do RA - 19143155 atrav?s da fun??o push, passando a pilha1 por refer?ncia */
    for (i = 0; i < TAM_AVL; i++) {
        printf("Insere: %d\n", ra[i]);
        arvore_insere(ra[i]);
    }
}