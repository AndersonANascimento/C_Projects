#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    int tam, i;
    int *vetor;

    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);

    vetor = (int *) malloc(sizeof(int) * tam);
    for (i = 0; i < tam; i++) {
        vetor[i] = pow(2, i);
        printf("Posição %d: %d\n", i, vetor[i]);
    }
    system("pause");
    return 0;
}
