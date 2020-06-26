/* Bibliotecas */
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <locale.h>

/* Constantes */
#define TAM 12

/* Globais */
int lista[TAM];
int ordenado[TAM];
int opt = -1;
int qtd;

/* Prototipação */
void menu_mostrar(void);
void lista_mostrar(void);
void lista_gerar(void);
void lista_ler(void);
void lista_limpar(void);
void lista_mostrar_ordenado(void);
int bubbleSort(int v[]);
int selectionSort(int v[], int tam);
int insertionSort(int v[], int tam);
int shellSort(int v[], int tam);
void troca(int *a, int *b);

/* Função Principal */
int main(int argc, char const *argv[])
{
    setlocale(LC_ALL, "");
    srand(time(NULL));
    do
    {
        system("cls");
        lista_mostrar();
        lista_mostrar_ordenado();
        menu_mostrar();
        scanf("%d", &opt);
        switch (opt)
        {
        case 1:
            lista_gerar();
            break;
        case 2:
            lista_ler();
            break;
        case 3:
            lista_limpar();
            qtd = bubbleSort(ordenado);
            break;
        case 4:
            lista_limpar();
            qtd = selectionSort(ordenado, TAM);
            break;
        case 5:
            lista_limpar();
            qtd = insertionSort(ordenado, TAM);
            break;
        case 6:
            lista_limpar();
            qtd = shellSort(ordenado, TAM);
            break;
        default:
            break;
        }
    } while (opt != 0);
    system("pause");
    system("cls");
    return 0;
}

/* Mostra o conteúdo da lista */
void lista_mostrar(void)
{
    int i;
    printf("[ ");
    for (i = 0; i < TAM; i++)
        printf("%d ", lista[i]);
    printf("]\n\n");
}

/* Mostrar o menu */
void menu_mostrar(void)
{
    printf("> > M E N U < <\n\n");
    printf("1 - Gerar lista aleatoriamente\n");
    printf("2 - Criar lista manualmente\n");
    printf("3 - Aplicar bubbleSort\n");
    printf("4 - Aplicar selectionSort\n");
    printf("5 - Aplicar insertionSort\n");
    printf("6 - Aplicar shellSort\n");
    printf("0 - Sair...\n\n");
    printf("Opção: ");
}

/* Gera uma lista aleatória */
void lista_gerar(void)
{
    int i;
    for (i = 0; i < TAM; i++)
        lista[i] = rand()%80 + 1;
}

/* Permite que o usuário entre com os valores da lista */
void lista_ler(void)
{
    int i;
    for (i = 0; i < TAM; i++)
    {
        system("cls");
        lista_mostrar();
        printf("Digite o valor para a posição %d: ", i);
        scanf("%d", &lista[i]);
    }
}

/* Preparar a lista para a ordenação */
void lista_limpar(void)
{
    int i;
    for (i = 0; i < TAM; i++)
        ordenado[i] = lista[i];
}

/* Mostra o conteúdo da lista ordenada */
void lista_mostrar_ordenado(void)
{
    int i;
    printf("[ ");
    for (i = 0; i < TAM; i++)
        printf("%d ", ordenado[i]);
    printf("] Tempo = %d iterações\n\n", qtd);
}

/* Método bubbleSort */
int bubbleSort(int v[])
{
    int qtd = 0, i, j, tmp;
    for (i = 0; i < TAM - 1; i++)
        for (j = i + 1; j < TAM; j++)
        {
            if (v[i] > v[j])
                troca(&v[i], &v[j]);
            qtd++;
        }
    return qtd;    
}

/* Método selectionSort */
int selectionSort(int v[], int tam)
{
    int i, j, min, qtd = 0;
    for (i = 0; i < tam - 1; i++)
    {
        min = i;
        for (j = i + 1; j < tam; j++)
        {
            if (v[j] < v[min])
                min = j;
            qtd++;
        }
        if (i != min)
            troca(&v[i], &v[min]);
    }
    return qtd;
}

/* Método insertionSort */
int insertionSort(int v[], int tam)
{
    int i, j, qtd = 0;
    for (i = 1; i < tam; i++)
    {
        j = i;
        while ((v[j] < v[j - 1]) && (j != 0))
        {
            troca(&v[j], &v[j - 1]);
            j--;
            qtd++;
        }
    }
    return qtd;    
}

/* Método shellSort */
int shellSort(int v[], int tam)
{
    int i, j, valor, qtd = 0;
    int gap = 1;
    do
    {
        gap = 3 * gap + 1;
    } while (gap < tam);
    do
    {
        gap /= 3;
        for (i = gap; i < tam; i++)
        {
            valor = v[i];
            j = i - gap;
            while (j >= 0 && valor < v[j])
            {
                v[j + gap] = v[j];
                j -= gap;
                qtd++;
            }
            v[j + gap] = valor;
        }
    } while (gap > 1);
    return qtd;
}

/* Função de troca de valores */
void troca(int *a, int *b)
{
    int tmp;
    tmp = *a;
    *a = *b;
    *b = tmp;
}
