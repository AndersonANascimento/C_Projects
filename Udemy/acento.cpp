#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

int main () {
	setlocale(LC_ALL,""); // Permite usar acentos
	printf("Ol� Mundo!");
	exit(0);
}
