#include <stdio.h>
#define MAX_SENSORES 8

typedef enum { NORMAL, ALERTA, FALLO } EstadoSensor;


typedef struct {
	int id;
	float valor;
	EstadoSensor estado;
} Lectura;

Lectura lecturas[MAX_SENSORES];


EstadoSensor clasificar(float valor) {

	if (valor > 80 || valor < 20) {
		return FALLO;
	}

	if (valor < 40 && valor >= 20) {
		return ALERTA;
	}

	if (valor <= 80 && valor > 60) {
		return ALERTA;
	}

	if (valor >= 40 && valor <= 60) {
		return NORMAL;
	}
	return 0;
}



int contar_estado(Lectura s[], int n, EstadoSensor e) {

	int contador = 0;

	for (int i = 0; i < n; i++) {
		if (s[i].estado == e) {
			contador++;
		}
	}

	return contador;
}


int lectura_extrema(Lectura s[], int n) {

	float valor_alejado = 0;
	float diferencia = 0;
	int indice = 0;

	for (int i = 0; i < n; i++) {
		diferencia = s[i].valor-50;
		if (diferencia < 0) {
			diferencia = -diferencia;
		}

		if (diferencia > valor_alejado) {
			valor_alejado = diferencia;
			indice = i;
		}
	}

	return indice;
}



int main(void) {

	/* Su implementacion */
	for (int i = 0; i < MAX_SENSORES; i++) {
		printf("Ingrese numero de identificacion (id): ");
		scanf("%d", &lecturas[i].id);

		printf("Ingrese su valor: ");
		scanf("%f", &lecturas[i].valor);

		lecturas[i].estado = clasificar(lecturas[i].valor);
	}

	printf("\n%-7s | %-7s | %-7s \n", "ID", "Valor", "Estado");

	const char* print_estado[] = {"NORMAL", "ALERTA", "FALLO"};

	for (int j = 0; j < MAX_SENSORES; j++) {

		printf("%-7d | %-7.2f | %-7s \n", lecturas[j].id, lecturas[j].valor, print_estado[lecturas[j].estado]);
	}


	printf("\nConteo de estados:\n");

	for (int k = 0; k < 3; k++) {

		EstadoSensor estado_actual = (EstadoSensor)k;

		int resultado = contar_estado(lecturas, MAX_SENSORES, estado_actual);

		printf("%s: %d\n", print_estado[estado_actual], resultado);
	}

	int indice_extremo = lectura_extrema(lecturas, MAX_SENSORES);

	printf("\nIdentificador con valor mas alejado del centro del rango normal:\n");
	printf("ID: %d, Valor: %.2f \n", lecturas[indice_extremo].id, lecturas[indice_extremo].valor);

	return 0;
}


