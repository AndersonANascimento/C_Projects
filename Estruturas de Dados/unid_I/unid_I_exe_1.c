#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    /* a) Defina um ponteiro do tipo inteiro */
    int *ptr;
    /* b) Fa�a aloca��o din�mica para o ponteiro rec�m-criado */
    ptr = (int *) malloc(sizeof(int));
    /* c) Preencha a mem�ria com o valor 42 */
    *ptr = 42;
    /* d) Imprima o endere�o do ponteiro na mem�ria e o valor contido nele */
    printf("Endere�o: %p \nValor: %d\n\n", ptr, *ptr);

    system("pause");
    return 0;
}
