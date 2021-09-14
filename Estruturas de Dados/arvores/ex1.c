#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

typedef struct arv TArv;

struct arv {
    char info;
    TArv* esq;
    TArv* dir;
};

TArv* inicializa(void) {
    return NULL;
}

TArv* cria(char c, TArv* sae, TArv* sad) {
    TArv* p = (TArv *)malloc(sizeof(TArv));
    p->info = c;
    p->esq = sae;
    p->dir = sad;
    return p;
}

int vazia(TArv* a) {
    return a == NULL;
}

void imprime(TArv* a) {
    if (!vazia(a)) {
        printf("%c ", a->info);
        imprime(a->esq);
        imprime(a->dir);
    }
}

TArv* libera(TArv* a) {
    if(!vazia(a)) {
        libera(a->esq);
        libera(a->dir);
        free(a);
    }
    return NULL;
}

int busca(TArv* a, char c) {
    if (vazia(a)) {
        return 0;
    } else {
        return a->info == c || 
            busca(a->esq, c) ||
            busca(a->dir, c);
    }
}

int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    char letra = 'e';
    /* sub-árvore com 'd' */
    // TArv* d= cria('d',inicializa(),inicializa());
    /* sub-árvore com 'b' */
    // TArv* b= cria('b',inicializa(),d);
    /* sub-árvore com 'e' */
    // TArv* e= cria('e',inicializa(),inicializa());
    /* sub-árvore com 'f' */
    // TArv* f= cria('f',inicializa(),inicializa());
    /* sub-árvore com 'c' */
    // TArv* c= cria('c', e, f);
    /* árvore com raiz 'a'*/
    // TArv* a = cria('a',b,c);
    // ou
    TArv* a = cria('a', 
                    cria('b', 
                        inicializa(), 
                        cria('d', inicializa(), inicializa())
                        ),
                    cria('c',
                        cria('e', inicializa(), inicializa()),
                        cria('f', inicializa(), inicializa()))
                    );
    imprime(a);
    if(busca(a, letra)){
        printf("\nLetra %c encontrada!", letra);
    } else {
        printf("\nLetra %c não encontrada!", letra);
    }
    system("pause");

    a->esq->esq = cria('x',
                        cria('y', inicializa(), inicializa()),
                        cria('z', inicializa(), inicializa())
                        );
    imprime(a);
    system("pause");

    a->dir->esq = libera(a->dir->esq);
    imprime(a);
    if(busca(a, letra)){
        printf("\nLetra %c encontrada!", letra);
    } else {
        printf("\nLetra %c não encontrada!", letra);
    }

    libera(a);
    
    return 0;
}
