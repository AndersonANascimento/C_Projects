
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    /* a) Crie uma vari�vel inteira e dois ponteiros do tipo inteiro. */
    int tam, i;
    int *v1, *v2;
    /* b) Pergunte ao usu�rio o tamanho do vetor din�mico e leia esse valor na vari�vel inteira. */
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    /* c) Aloque dinamicamente os dois vetores usando a fun��o malloc. */
    v1 = (int *) malloc(sizeof(int) * tam);
    v2 = (int *) malloc(sizeof(int) * tam * 2);
    /* d) Fa�a um la�o de repeti��o para preencher o primeiro vetor com pot�ncias de 2. */
    for (i = 0; i < tam; i++) {
        v1[i] = pow(2, i);
        printf("Posi��o %d: %d\n", i, v1[i]);
    }
    /* e) Fa�a um segundo la�o de repeti��o para preencher o outro vetor com pot�ncias de 3. */
    for (i = 0; i < (tam * 2); i++) {
        v2[i] = pow(3, i);
        printf("Posi��o %d: %d\n", i, v2[i]);
    }
    /* f) N�o se esque�a de usar a biblioteca math.h para poder usar o c�lculo de pot�ncia (pow). */
    system("pause");
    return 0;
}
