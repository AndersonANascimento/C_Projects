/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>

/* Constantes */
#ifdef WIN32
#define PAUSE "pause"
#define CLS "cls"
#else
#define PAUSE "read -p \'Pressione enter para continuar...\' continue"
#define CLS "clear"
#endif
#define TAMANHO 3

/* Estrutura Livro */
typedef struct TLivro {
    int codigo;
    char nome[50];
    char autor[50];
} TLivro;

/* Estrutura da Pilha */
typedef struct TPilha {
    TLivro dados[TAMANHO];
    int base;
    int topo;
} TPilha;

/* Globais */
TPilha pilha;

/* Protótipos */
void push();
TLivro pop();
void print_pilha();
void menu();

char *mygets(char *buf, size_t size) {
    if (buf != NULL && size > 0) {
        if (fgets(buf, size, stdin)) {
            buf[strcspn(buf, "\n")] = '\0';
            return buf;
        }
        *buf = '\0';  /* clear buffer at end of file */
    }
    return NULL;
}
/* Função Principal */
int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    TLivro elem;
    int cod = 1, op = 1;
    pilha.base = pilha.topo = 0;
    
    while (op != 0) {
        system(CLS);
        print_pilha();
        menu();
        scanf("%d", &op);
        switch (op) {
        case 1:
            push();
            break;
        case 2:
            // printf("pop => %d", pop());
            elem = pop();
            // printf("O %d foi desempilhado!\n", elem);
            // system(PAUSE);
            break;
        default:
            break;
        }
    }
    system(CLS);
    return 0;
}

void push() {
	TLivro elem;
    if (pilha.topo == TAMANHO) {
        printf("Pilha cheia.\n");
        system(PAUSE);
    } else {
        printf("\nCódigo: ");
        scanf("%d", &elem.codigo);
		getchar();
		
        printf("Nome..: ");
        mygets(elem.nome, sizeof(elem.nome));

        printf("Autor.: ");
        mygets(elem.autor, sizeof(elem.autor));
        
        pilha.dados[pilha.topo] = elem;
        pilha.topo++;
    }
}

TLivro pop() {
    TLivro livro;
    if (pilha.topo == pilha.base) {
        printf("Pilha vazia.\n");
        system(PAUSE);
    } else {
        pilha.topo--;
        livro = pilha.dados[pilha.topo];
    }
    return livro;
}

void print_pilha() {
    int i;
    char s[50] = "--------------------------------------------------";
    printf(">> Pilha de livros <<\n");
    printf("%-3s\t%-50s\t%-50s\n", "Cod", "Nome", "Autor");
    printf("---\t%s\t%s\n", s, s);
    for (i = pilha.topo - 1; i >= pilha.base; i--) {
        printf("%3d\t%-50s\t%-50s\n", pilha.dados[i].codigo, pilha.dados[i].nome, pilha.dados[i].autor);
    }
}

void menu() {
    printf("\nEscolha uma opção:\n");
    printf("1 - Empilhar\n");
    printf("2 - Desempilhar\n");
    printf("0 - Sair\n");
    printf("Opção: ");
}
