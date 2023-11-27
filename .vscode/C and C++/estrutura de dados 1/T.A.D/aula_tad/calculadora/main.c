#include "definicoes.h"
#include <stdio.h>
#include <stdlib.h>

int main()
{
	float a = 90, b = 234;
	printf("Soma: %.2f", somar(a, b));
	printf("Subtrair: %.2f", subtrair(a, b));
	printf("Soma: %.2f", multiplicar(a, b));
	printf("Soma: %.2f", dividir(a, b));
	
	return 0;
}