#include "input.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

/**
 * \brief Solicita un número al usuario y devuelve el resultado
 * \param mensaje Es el mensaje a ser mostrado
 * \param eMensaje Es el mensaje de error a ser mostrado
 * \param min es el minimo
 * \param max es el maximo
 * \return El número ingresado por el usuario
 *
 */
int getInt(char mensaje[], char eMensaje[], int min, int max) {
	int auxiliar;

	printf("%s", mensaje);
	scanf("%d", &auxiliar);
	while (auxiliar < min || auxiliar > max) {
		printf("%s", eMensaje);
		scanf("%d", &auxiliar);
	}

	return auxiliar;
}

/** \brief Solicita un numero flotante al usuario
 *
 * \param mensaje recibe un mensaje para mostrar
 * \param eMensaje recibe un mensaje de error para mostrar
 * \param minLimit limite mas bajo para el numero
 * \param maxlimit limite mas alto para el numero
 * \return retorna el numero flotante ingresado
 */
float getFloat(char mensaje[], char eMensaje[], float minLimit, float maxLimit)

{
	float aux;

	printf("%s", mensaje);
	scanf("%f", &aux);

	while (aux < minLimit || aux > maxLimit) {
		printf("%s", eMensaje);
		scanf("%f", &aux);
	}

	return aux;

}
/** \brief Solicita un char al usuario
 *
 * \param input array donde se cargara el char
 * \param message recibe un mensaje para mostrar
 * \param eMessage recibe un mensaje de error para mostrar
 * \param lowLimit limite mas bajo para el char
 * \param hilimit limite mas alto para el char
 * \return retorna [0] en caso de que se ingrese bien o [-1] en caso de que se ingrese mal
 *
 */
int getChar(char *input, char message[], char eMessage[], char lowLimit,
		char hiLimit) {
	int respuesta = -1;
	char aux;
	int scanfOk;
	puts(message);
	scanfOk = scanf("%c", &aux);
	aux = tolower(aux);

	if (scanfOk) {
		if (aux < lowLimit || aux > hiLimit) {
			puts(eMessage);
		} else {
			aux = toupper(aux);
			*input = aux;
			respuesta = 0;

		}
	}
	return respuesta;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return void
 */
void getString(char cadena[], char mensaje[], char eMensaje[], int minLimit,
		int maxLimit) {
	int x;
	char aux[400];

	printf("%s", mensaje);
	fflush(stdin);
	scanf("%[^\n]", aux);
	x = strlen(aux);

	while (x < minLimit || x > maxLimit) {
		printf("%s", eMensaje);
		fflush(stdin);
		scanf("%[^\n]", aux);
		x = strlen(aux);
	}

	strcpy(cadena, aux);
}

/**
 * \brief Verifica si el valor recibido contiene solo letras
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo ' ' y letras y 0 si no lo es
 *
 */
int esSoloLetras(char str[]) {
	int i = 0;
	int retorno;
	retorno = 1;
	while (str[i] != '\0') {
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z')
				&& (str[i] < 'A' || str[i] > 'Z')) {
			retorno = 0;
			i++;
		}

	}
	return retorno;
}

/**
 * \brief Solicita un texto al usuario y lo devuelve
 * \param mensaje Es el mensaje a ser mostrado
 * \param input Array donde se cargará el texto ingresado
 * \return 1 si el texto contiene solo letras
 */
int getStringLetras(char mensaje[], char input[]) {
	char aux[256];
	int retorno;
	retorno = 0;
	getString(aux, mensaje, mensaje, 1, 256);
	if (esSoloLetras(aux)) {
		strcpy(input, aux);
		retorno = 1;
	}
	return retorno;
}

/**
 * \brief Verifica si el valor recibido contiene solo letras y números
 * \param str Array con la cadena a ser analizada
 * \return 1 si contiene solo espacio o letras y números, y 0 si no lo es
 *
 */
int esAlfaNumerico(char str[]) {
	int i = 0;
	int retorno;
	retorno = 1;
	while (str[i] != '\0') {
		if ((str[i] != ' ') && (str[i] < 'a' || str[i] > 'z')
				&& (str[i] < 'A' || str[i] > 'Z')
				&& (str[i] < '0' || str[i] > '9')) {
			retorno = 0;
			i++;
		}

	}
	return retorno;
}

float sacarPromedio(int resultado, int acumulador) {
	float total;

	total = resultado / acumulador;

	return total;
}


