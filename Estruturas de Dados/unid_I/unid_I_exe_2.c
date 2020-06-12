#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
/* a) Crie uma estrutura que tenha dois atributos: cor (cadeia de caracteres) e id
(inteiro). */
struct semaforo {
    char cor[10];
    int id;
};
/* b) Crie três variáveis com o tipo definido no item a. */
/* d) Inicialize as estruturas da seguinte forma:
    ? cor vermelha, id 1.
    ? cor amarela, id 2.
    ? cor verde, id 3. */
struct semaforo s1 = {"Vermelho", 1};
struct semaforo s2 = {"Amarelo", 2};
struct semaforo s3 = {"Verde", 3};
/* c) Crie um ponteiro do mesmo tipo. */
struct semaforo *ptr;

int main(int argc, char const *argv[])
{
    /* e) Inicialize o ponteiro apontando para a primeira variável criada. */
    ptr = &s1;
    /* f) Por meio de operações aritméticas com ponteiros, percorra a memória e imprima o valor de cada uma das variáveis criadas nesse programa. */
    printf("%d - %s\n", (*ptr).id, (*ptr).cor);
    ptr = ptr + 1;
    printf("%d - %s\n", (*ptr).id, (*ptr).cor);
    ptr = ptr + 1;
    printf("%d - %s\n", (*ptr).id, (*ptr).cor);

    system("pause");
    return(0);
}