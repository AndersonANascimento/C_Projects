
#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <math.h>

int main(int argc, char const *argv[]) {
    setlocale(LC_ALL, "Portuguese");
    /* a) Crie uma variável inteira e dois ponteiros do tipo inteiro. */
    int tam, i;
    int *v1, *v2;
    /* b) Pergunte ao usuário o tamanho do vetor dinâmico e leia esse valor na variável inteira. */
    printf("Informe o tamanho do vetor: ");
    scanf("%d", &tam);
    /* c) Aloque dinamicamente os dois vetores usando a função malloc. */
    v1 = (int *) malloc(sizeof(int) * tam);
    v2 = (int *) malloc(sizeof(int) * tam * 2);
    /* d) Faça um laço de repetição para preencher o primeiro vetor com potências de 2. */
    for (i = 0; i < tam; i++) {
        v1[i] = pow(2, i);
        printf("Posição %d: %d\n", i, v1[i]);
    }
    /* e) Faça um segundo laço de repetição para preencher o outro vetor com potências de 3. */
    for (i = 0; i < (tam * 2); i++) {
        v2[i] = pow(3, i);
        printf("Posição %d: %d\n", i, v2[i]);
    }
    /* f) Não se esqueça de usar a biblioteca math.h para poder usar o cálculo de potência (pow). */
    system("pause");
    return 0;
}
