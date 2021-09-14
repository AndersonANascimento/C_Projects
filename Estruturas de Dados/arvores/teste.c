#include <stdio.h>
#include <stdlib.h>

typedef struct NO {    
    int dado;       // dadormação contida no nó
    int bal;     // Fator de balanceamento do nó
     
    struct NO *pai; // Aponta para o nó ancestral
    struct NO *esq; // Aponta para o filho da esquerda 
    struct NO *dir; // Aponta para o filho da direita
     
} NO;

typedef struct NO* ArvAVL;

ArvAVL* raiz;

/* Funções para manipulação da árvore */

// Retorna a altura de uma sub-árvore
int avl_altura (struct NO* no ) {
    if ( no == NULL ) 
        return -1;
    else
        return no->altura;
}

int fatorBalanceamento(struct NO* no) {
    return labs(alt_NO(no->esq) - alt_NO(no->dir));
}

int maior(int x, int y) {
    if (x>y)
        return x;
    else
        return y;
}
/*  -- Rotações de sub-árvore --
 *
 *  A árvore AVL necessita, além das rotinas 
 *  básicas, algumas rotinas auxiliares para 
 *  mantê-la balanceada. São elas: rotação 
 *  simples para a esquerda, rotação simples 
 *   para a direita.
 */

/* Rotação simples para a direita */
NO *rotacao_direita ( NO *p ) 
{
    NO *q;
    
    q = p->esq;
    //----------------> Realiza a rotação
    p->esq = q->dir;
    if ( q->dir != NULL )
        q->dir->pai = p;
    q->dir = p;
    q->pai = p->pai;
    if ( p->pai != NULL )
        if ( p->pai->esq == p )
            p->pai->esq = q;
        else
            p->pai->dir = q;
    p->pai = q;
    //----------------> Rebalanceia
    q->bal = avl_altura ( q->dir ) - avl_altura ( q->esq );
    p->bal = avl_altura ( p->dir ) - avl_altura ( p->esq );    
    
    return q;
}
    
/* Rotação simples para a esquerda */
NO *rotacao_esquerda ( NO *p ) 
{    
    NO *q;
   
    q = p->dir;
    //----------------> Realiza a rotação
    p->dir = q->esq;
    if ( q->esq != NULL )
        q->esq->pai = p;
    q->esq = p;
    q->pai = p->pai;
    if ( p->pai != NULL )
        if ( p->pai->esq == p )
            p->pai->esq = q;
        else
            p->pai->dir = q;
    p->pai = q;
    //----------------> Rebalanceia
    q->bal = avl_altura ( q->dir ) - avl_altura ( q->esq );
    p->bal = avl_altura ( p->dir ) - avl_altura ( p->esq );
    
    return q;
}

/* Inserção na árvore AVL */
int avl_insert ( AVL_Tree **tree, NO *pai, NO **node, void *dado ) 
{    
    NO *novo;
    int aux;
    
    if ( *tree == NULL ) return -1;
    if ( *node == NULL ) 
    // Se for o local correto para a inserção
    {
        novo = ( NO * ) malloc ( sizeof ( NO ));
        if ( novo == NULL ) return -1;
        novo->dado  = dado;
        novo->bal   = 0;
        novo->pai   = pai;
        novo->esq   = NULL;
        novo->dir   = NULL;
        
        *node = novo;
        (*tree)->num_nodes++;
        return 1;
    }
    
    /* 
     *  Procura o local apropriado. Na volta da pilha do processador, o 
     *  algoritmo vai atualizando o fator de balanceamento de cada nó. 
     *  São feitas rotações, se necessárias, para que a árvore se rebalanceie.
     */
     
    if ( (*tree)->compara_dado( dado, (*node)->dado ) == +1 ) {
    
        aux = avl_insert ( tree, *node, &((*node)->dir), dado );
        if ( aux != 1 ) return 0;
        
        if ( ++((*node)->bal) == 2 ) {
            if ( (*node)->dir->bal == 1 ) {
                *node = rotacao_esquerda ( *node );
                return 0;
            }
            (*node)->dir = rotacao_direita ( (*node)->dir );
            *node = rotacao_esquerda ( *node );
            
            return 0;
        }
        
        return ( (*node)->bal == 0 )? 0: 1;  
    }
    
    if ( (*tree)->compara_dado( dado, (*node)->dado ) == -1 ) {
        
        aux = avl_insert ( tree, *node, &((*node)->esq), dado );
        if ( aux != 1 ) return 0;
        
        if ( --((*node)->bal) == -2 ) {
            if ( (*node)->esq->bal == -1 ) {
                *node = rotacao_direita ( *node );
                return 0;
            }
            (*node)->esq = rotacao_esquerda ( (*node)->esq );
            *node = rotacao_direita ( *node );
            
            return 0;
        }
        
        return ( (*node)->bal == 0 )? 0: 1;        
    }
    
    return 0;
}

/* Remove um elemento da árvore */
int avl_remove ( AVL_Tree **tree, NO **node, void *dado ) 
{    
    int ret;
    
    if ( *node == NULL || *tree == NULL ) return -1;
    
    if ( (*tree)->compara_dado( dado, (*node)->dado ) == +1 ) 
    // Vai para a S.A. da esquerda
    {
        ret = avl_remove ( tree, &((*node)->dir), dado );
        if ( ret != 1 ) return 0;
        
        if ( --((*node)->bal) == -2 ) {
            if ( (*node)->esq->bal == -1 ) {
                *node = rotacao_direita ( *node );
                return 0;
            }
            (*node)->esq = rotacao_esquerda ( (*node)->esq );
            *node = rotacao_direita ( *node );
            return 0;
        }
        return ( (*node)->bal == 0 )? 1: 0;
    }
    if ( (*tree)->compara_dado( dado, (*node)->dado ) == -1 ) 
    // Vai para a S.A. da direita
    {
        ret = avl_remove ( tree, &((*node)->esq), dado );
        if ( ret != 1 ) return 0;
        
        if ( ++((*node)->bal) == +2 ) {
            if ( (*node)->dir->bal == 1 ) {
                *node = rotacao_esquerda ( *node );
                return 0;
            }
            (*node)->dir = rotacao_direita ( (*node)->dir );
            *node = rotacao_esquerda ( *node );
            return 0;
        }
        return ( (*node)->bal == 0 )? 1: 0;
    }
    
    if ( (*tree)->compara_dado( dado, (*node)->dado ) == 0 ) 
    // Encontrou o elemento a ser removido
    {
        NO *aux, *temp;
        void *i;
        
        if ( (*node)->esq == NULL ) {
            
            if ( (*node)->dir == NULL )
            // Se não contiver filho algum
            {
                free ( *node );
                *node = NULL;
                (*tree)->num_nodes--;                
                return 1;
            }
            
            // Se contiver o filho da direita
            aux = *node;
            temp = (*node)->dir;
            temp->pai = (*node)->pai;
            if ( (*node)->pai != NULL )
                if ( (*node)->pai->esq == *node )
                    (*node)->pai->esq = temp;
                else
                    (*node)->pai->dir = temp;
            *node = temp;
            free ( aux );
            (*tree)->num_nodes--;            
            return 1;
        }
        
        if ( (*node)->dir == NULL )
        // Se contiver apenas o filho da esquerda
        {
            aux = *node;
            temp = (*node)->esq;
            temp->pai = (*node)->pai;
            if ( (*node)->pai != NULL )
                if ( (*node)->pai->esq == *node )
                    (*node)->pai->esq = temp;
                else
                    (*node)->pai->dir = temp;
            *node = temp;
            free ( aux );
            (*tree)->num_nodes--;            
            return 1;        
        }
        
        // Se contiver os dois filhos
        aux = (*node)->esq;
        while ( aux->dir != NULL )
            aux = aux->dir;
        i = aux->dado;
        avl_remove ( tree, node, aux->dado );
        (*node)->dado = i;
        
        return 1;
    }
}

/* Percursos da árvore */

// Percorre a árvore em pré-ordem
void avl_walk_pre ( AVL_Tree *tree, NO *node ) 
{    
    if ( node == NULL ) return;
    
    tree->imprime_dado( node->dado );
    if ( node->esq != NULL && node->dir != NULL ) printf ( ", " );
    
    avl_walk_pre ( tree, node->esq );
    avl_walk_pre ( tree, node->dir );
}

// Percorre a árvore em pós-ordem
void avl_walk_pos ( AVL_Tree *tree, NO *node ) 
{    
    if ( node == NULL ) return;
    
    avl_walk_pre ( tree, node->esq );
    avl_walk_pre ( tree, node->dir );
    
    tree->imprime_dado( node->dado );
    if ( node->esq != NULL && node->dir != NULL ) printf ( ", " );
}

// Percorre a árvore em ordem simétrica
void avl_walk_sim ( AVL_Tree *tree, NO *node ) 
{    
    if ( node == NULL ) return;
    
    avl_walk_pre ( tree, node->esq );
    
    tree->imprime_dado( node->dado );
    if ( node->esq != NULL && node->dir != NULL ) printf ( ", " );
    
    avl_walk_pre ( tree, node->dir );
}

// Percorre a árvore por nível ( Busca Lateral )
void avl_walk_lev ( AVL_Tree *tree ) 
{
   NO *queue[tree->num_nodes];
   NO *aux;
   int tail = -1, i;
   if ( tree->root == NULL ) return;
   
   queue[++tail] = tree->root;
   while ( tail > -1 ) {
      aux = queue[0];
      for ( i = 0; i < tail; i++ )
         queue[i] = queue[i+1];
      tail--;
      
      tree->imprime_dado( aux->dado );
      printf ( " " );
      
      if ( aux->esq != NULL )
         queue[++tail] = aux->esq;
      if ( aux->dir != NULL )
         queue[++tail] = aux->dir;
   }
}

void avl_print ( AVL_Tree *tree, NO *node, int level ) 
{    
    int i;
    
    if ( tree == NULL || node == NULL ) return;
    for ( i = 0; i < level; i++ )
        printf ( "   " );

    printf ( "> [" );
    tree->imprime_dado( node->dado );
    printf ( "][%i]\n", node->bal );
    
    avl_print ( tree, node->esq, level + 1 );
    avl_print ( tree, node->dir, level + 1 );
}

/* Busca por um elemento */
NO *avl_search ( AVL_Tree *tree, NO *node, void *dado ) 
{
    if ( tree == NULL || node == NULL ) return NULL;
    
    if ( tree->compara_dado( dado, node->dado ) == 0 ) return node;
    if ( tree->compara_dado( dado, node->dado )  > 0 )
        return avl_search ( tree, node->dir, dado );
    else
        return avl_search ( tree, node->esq, dado );
}

int main(int argc, char const *argv[])
{
    AVL_Tree *tree;
    tree = (AVL_Tree *) malloc(sizeof(AVL_Tree));

    avl_init(tree, 0, NULL);

    NO *no = (NO *)malloc(sizeof(NO));
    no->dado = 1; 
    avl_insert(tree, NULL, no, );
    return 0;
}
