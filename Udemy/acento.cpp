#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL,""); // Permite usar acentos
	printf("Olá Mundo!");
	exit(0);
}
