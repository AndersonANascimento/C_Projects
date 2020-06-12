#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    /* a) Defina um ponteiro do tipo inteiro */
    int *ptr;
    /* b) Faça alocação dinâmica para o ponteiro recém-criado */
    ptr = (int *) malloc(sizeof(int));
    /* c) Preencha a memória com o valor 42 */
    *ptr = 42;
    /* d) Imprima o endereço do ponteiro na memória e o valor contido nele */
    printf("Endereço: %p \nValor: %d\n\n", ptr, *ptr);

    system("pause");
    return 0;
}
