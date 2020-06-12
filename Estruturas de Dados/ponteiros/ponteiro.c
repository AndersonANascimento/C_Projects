#include <stdio.h>
#include <stdlib.h>
#include <locale.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
int *p, x;

int main(int argc, char *argv[]) {
	setlocale(LC_ALL, "Portuguese");
		
	p = (int *)malloc(sizeof(int));
	
	if (p == NULL) {
		printf("Erro!\n");
	} else {
		*p = 10;
		printf("p: %p\n", p);
		printf("*p: %d\n", *p);
		free(p);
	}
	return 0;
}
