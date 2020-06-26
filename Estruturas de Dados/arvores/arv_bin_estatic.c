/** 
 * Disciplina...: [ESTRUTURA DE DADOS I] 
 * Professor....: Me. Pietro M de Oliveira 
 * Objetivo.....: Manipulação de árvore binária em vetor;
 * Versão.......: Beta - Teste
 * Autor(a).....: Anderson Abreu do Nascimento
 * RA...........: 1914315-5
 * Data atual...: 16/06/2020
 */
/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* Constantes */
#define TAM 7
#define E 0
#define D 1
#define R -1

/* Estrutura */
typedef struct NO {
    char dado;
    int esquerda;
    int direita;
    int pai;
} NO;

/* Globais */
NO arvore[TAM];
int lado, indice = 0;
int opt = -1;
char pai, no;

/* Prototipação */
void arvore_insere(int pai, char dado, int lado);
int arvore_procura(char dado);
void menu_mostrar();
void setNo(int pai, char dado);

/* Função Principal */
int main(int argc, char const *argv[]) {
    int temp;
    do {
        menu_mostrar();
        scanf("%d", &opt);
        fflush(stdin);

        switch (opt) {
        case 1:
            printf("\nDigite o valor do PAI: ");
            pai = getchar(); //scanf("%c", &pai);
            fflush(stdin);

            printf("\nDigite o valor do NO: ");
            no = getchar(); //scanf("%c", &no);
            fflush(stdin);
            
            printf("\nDigite o lado da subarvore (E=%d/D=%d/R=%d): ", E,D,R);
            scanf("%d", &lado);
            fflush(stdin);
            
            temp = arvore_procura(pai);
            arvore_insere(temp, no, lado);
            break;
        case 2:
            printf("\nDigite o valor do NO: ");
            scanf("%c", &no);
            temp = arvore_procura(no);
            printf("\nNO %c\nFilho Esquerda: %c\nFilho Direita: %c\n\n", arvore[temp].dado, arvore[arvore[temp].esquerda].dado,arvore[arvore[temp].direita].dado);
            system("pause");
            break;

        }
    } while (opt != 0);
    system("pause");
    return 0;
}

void setNo(int pai, char dado) {
    arvore[indice].dado = dado;
    arvore[indice].pai = pai;
    arvore[indice].esquerda = -1;
    arvore[indice].direita = -1;
    indice++;
}

/* Inserir nó */
void arvore_insere(int pai, char dado, int lado) {
    switch (lado) {
    case E:
        arvore[pai].esquerda = indice;
        setNo(pai, dado);
        break;
    case D:
        arvore[pai].direita = indice;
        setNo(pai, dado);
        break;
    case R:
        setNo(-1, dado);
        break;    
    }
}

/* Procura nó */
int arvore_procura(char dado) {
    int i;
    if (indice != 0)
        for (i = 0; i < indice; i++) {
            if (arvore[i].dado == dado) 
                return i;
        }
    else 
        return 0;
}

/* Tela de Menu */
void menu_mostrar() {
    int i;
    system("cls");
    for (i = 0; i < indice; i++)
        printf("| %c ", arvore[i].dado);
    
    printf("\n1 - Inserir um NO na arvore");
    printf("\n2 - Pesquisar um NO na arvore");
    printf("\n0 - Sair...\n");
    printf("\nOpt: ");
}
