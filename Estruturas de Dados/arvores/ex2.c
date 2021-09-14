#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* Constantes */
#define TAM_ARV 8

typedef struct arv TArv;

struct arv {
    int info;
    int altura;
    TArv* esq;
    TArv* dir;
};

void imprime(TArv* a) {
    if (a != NULL) {
        printf("%d ", a->info);
        imprime(a->esq);
        imprime(a->dir);
    }
}

TArv* libera(TArv* a) {
    if(a != NULL) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

TArv* busca(TArv* r, int v) {
    if (r == NULL) return NULL;
    else if (v < r->info) return busca(r->esq, v);
    else if (v > r->info) return busca(r->dir, v);
    else return r;
}

TArv* insere(TArv* a, int v) {
    if (a == NULL) {
        a = (TArv*)malloc(sizeof(TArv));
        a->info = v;
        a->esq = a->dir = NULL;
        printf("%d inserido\n", v);
        a->bal = avl_height ( a->dir ) - avl_height ( a->esq );
    }
    else if (v < a->info) {
        printf("\n\tCaminhando para a esq. => ");
        if (a->esq != NULL)
            printf("%d(%d); ", a->esq->info, a->esq->bal);
        a->esq = insere(a->esq, v);
        a->bal = avl_height ( a->dir ) - avl_height ( a->esq );
    } else {
        printf("\n\tCaminhando para a dir. => ");
        if (a->dir != NULL)
            printf("%d(%d); ", a->dir->info, a->dir->bal);
        a->dir = insere(a->dir, v);
        a->bal = avl_height ( a->dir ) - avl_height ( a->esq );
    }
    return a;
}

TArv* retira (TArv* r, int v) {
    if (r == NULL) return NULL;
    else if (r->info > v)
        r->esq = retira(r->esq, v);
    else if (r->info < v)
        r->dir = retira(r->dir, v);
    else { /* achou o elemento */
        /* elemento sem filhos */
        if (r->esq == NULL && r->dir == NULL) {
            free(r);
            r = NULL;
        }
        /* só tem filho à direita */
        else if (r->esq == NULL) {
            TArv* t = r;
            r = r->dir;
            free(t);
        }
        /* só tem filho à esquerda */
        else if (r->dir == NULL) {
            TArv* t = r;
            r = r->esq;
            free(t);
        }
        /* tem os dois filhos */
        else {
            TArv* pai = r;
            TArv* f = r->esq;
            while (f->dir != NULL) {
                pai = f;
                f = f->dir;
            }
            r->info = f->info;
            f->info = v;
            r->esq = retira(r->esq, v);
        }

        return r;
    }
}

int avl_height ( TArv * r) {
   
    int esq, dir;
   
    if ( r == NULL ) return -1;
   
    esq = avl_height ( r->esq );
    dir = avl_height ( r->dir );
   
    if ( esq > dir )
        return esq + 1;
    else
        return dir + 1;
}

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "");
    system("cls");

    /* Declarações locais */    
    int i, ra[TAM_ARV] = {1,9,1,4,3,1,5,5};    
    TArv* t = NULL;

    for (i = 0; i < TAM_ARV; i++) {
        printf("Inserindo: %d\n", ra[i]);
        if (t != NULL) {
            printf("Raiz => %d(%d); ", t->info, t->bal);
        }
        t = insere(t, ra[i]);
    }

    imprime(t);

    libera(t);

    return 0;
}
