#include <stdio.h>

int potencia(int base, int exp) {
	int resultado = 1;
	while (exp > 0) {
		resultado = resultado * base;
		exp = exp - 1;
	}
	return resultado;
}

int es_par(int n) {

	if (n % 2 == 0) {
		return 1;
	} else {
		return 0;
	}
}

int main(void) {

	int base = 0;
	int exp = 0;
	int resultado;

	do {
		printf("Ingrese una base: ");
		scanf("%d", &base);
		printf("Ingrese un exponente: ");
		scanf("%d", &exp);

	} while (base == 0 || exp < 0);

	resultado = potencia(base, exp);

	printf("%d^%d = %d\n", base, exp, resultado);

	if (es_par(resultado)) {
		printf("El numero es par\n");
	} else {
		printf("El numero es impar\n");
	}

	return 0;
}

