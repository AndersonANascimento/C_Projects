/** 
 * Disciplina...: [ESTRUTURA DE DADOS II] 
 * Professor....: Me. Pietro M de Oliveira 
 * Objetivo.....: Árvore AVL(MAPA)
 * Autor(a).....: Anderson Abreu do Nascimento
 * RA...........: 1914315-5
 * Data atual...: 02/07/2020
 */
#include <stdio.h>
#include <stdlib.h>
#include <String.h>
#include <locale.h>

/* Constantes */
#define TAM_ARV 8

/* Definição de estruras */
struct NO {
    int info;
    int altura;
    struct NO* esq;
    struct NO* dir;
};

typedef struct NO* ArvAVL;

/* Variáveis globais */
ArvAVL* raiz;

ArvAVL* cria_ArvAVL() {
    ArvAVL* raiz = (ArvAVL*) malloc(sizeof(ArvAVL));
    if (raiz != NULL)
        *raiz = NULL;
    return raiz;
}

void libera_NO(struct NO* no) {
    if (no == NULL)
        return;
    libera_NO(no->esq);
    libera_NO(no->dir);
    printf("libera_NO: %d\n", no->info);
    free(no);
    no = NULL;
}

void libera_ArvAVL(ArvAVL* raiz) {
    if (raiz == NULL)
        return ;
    libera_NO(*raiz);
}

int altura_NO(struct NO* no) {
    if (no == NULL) 
        return -1;
    else 
        return no->altura;
}

int fatorBalanceamento_NO(struct NO* no) {
    return labs(altura_NO(no->esq) - altura_NO(no->dir));
}

int maior(int x, int y) {
    if (x > y)
        return x;
    else
        return y;    
}

void RotacaoSimplesEsquerda(ArvAVL *raiz) {
    struct NO *no;
    no = (*raiz)->esq;
    (*raiz)->esq = no->dir;
    no->dir = *raiz;
    (*raiz)->altura = maior(altura_NO((*raiz)->esq), altura_NO((*raiz)->dir)) + 1;
    no->altura = maior(altura_NO(no->esq), (*raiz)->altura) + 1;
    *raiz = no;
}

void RotacaoSimplesDireita(ArvAVL* raiz) {
    struct NO *no;
    no = (*raiz)->dir;
    (*raiz)->dir = no->esq;
    no->esq = *raiz;
    (*raiz)->altura = maior(altura_NO((*raiz)->esq), 
                            altura_NO((*raiz)->dir))
                            + 1;
    no->altura = maior(altura_NO(no->dir), (*raiz)->altura) + 1;
    *raiz = no;
}

void RotacaoDuplaEsqDir(ArvAVL *raiz) {
    RotacaoSimplesDireita(&(*raiz)->esq);
    RotacaoSimplesEsquerda(raiz);
}

void RotacaoDuplaDirEsq(ArvAVL *raiz) {
    RotacaoSimplesEsquerda(&(*raiz)->dir);
    RotacaoSimplesDireita(raiz);
}

int insere_ArvAVL(ArvAVL *raiz, int valor) {
    int res;
    if (*raiz == NULL) {
        struct NO *novo;
        novo = (struct NO*) malloc (sizeof(struct NO));
        if (novo == NULL)
            return 0;

        novo->info = valor;
        novo->altura = 0;
        novo->esq = novo->dir = NULL;
        *raiz = novo;
        return 1;            
    }
    struct NO *atual = *raiz;
    // printf("valor: %d atual->info: %d\n", valor, atual->info);
    if (valor < atual->info) {
        res = insere_ArvAVL(&(atual->esq), valor);
        if (res == 1) {
            // printf("\tCaminhando a esq: %d\n", (*raiz)->esq->info);
            // printf("\tfatorBalanceamento_NO(atual): %d\n", fatorBalanceamento_NO(atual));
            if (fatorBalanceamento_NO(atual) >= 2) {
                if (valor < (*raiz)->esq->info) {
                    printf("\tRotacaoSimplesEsquerda\n");
                    RotacaoSimplesEsquerda(raiz);
                } else {
                    printf("\tRotacaoDuplaEsqDir\n");
                    RotacaoDuplaEsqDir(raiz);
                }
            }
        }
    }
    else {
        if (valor >= atual->info) {
            res = insere_ArvAVL(&(atual->dir), valor);
            if (res == 1) {
                // printf("\tCaminhando a dir: %d\n", (*raiz)->dir->info);
                // printf("\tfatorBalanceamento_NO(atual): %d\n", fatorBalanceamento_NO(atual));
                if (fatorBalanceamento_NO(atual) >= 2) {
                    if (valor > (*raiz)->dir->info) {
                        printf("\tRotacaoSimplesDireita\n");
                        RotacaoSimplesDireita(raiz);
                    } else {
                        printf("\tRotacaoDuplaDirEsq\n");
                        RotacaoDuplaDirEsq(raiz);
                    }
                }
            }
        }
    }
    atual->altura = maior(altura_NO(atual->esq), altura_NO(atual->dir)) + 1;
    return res;
}

/* Função para impressão da árvore AVL */
void imprime(struct NO* no) {
    if (no != NULL) {
        printf("%d ", no->info);
        imprime(no->esq);
        imprime(no->dir);
    }
}

/* Função principal */
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    system("cls");

    /* Declarações locais */    
    int i, res, ra[TAM_ARV] = {1,9,1,4,3,1,5,5};
    
    /* Criando a Árvore AVL em memoria */
    printf(">> Criando Árvore AVL em memoria\n");
    raiz = cria_ArvAVL();

    /* Loop de inserção dos nós com cada digito do RA */
    for (i = 0; i < TAM_ARV; i++) {
        printf("Inserindo: %d\n", ra[i]);
        res = insere_ArvAVL(raiz, ra[i]);
        if (res > 0)
            printf("Inserido com sucesso!\n");
        res = 0;
        // imprime(*raiz); // Para impressão da árvora a cada inserção
        // printf("\n");
    }

    printf("\n>> Impressão da Árvore AVL em Pré-Ordem: ");
    imprime(*raiz);

    printf("\n\n>> Liberando a Árvore AVL da Memoria...\n");
    libera_ArvAVL(raiz);
    
    return 0;
}
