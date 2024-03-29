#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_validaciones.h"


/// @brief get String      Funcion para pedir dato por consola, a traves de cadena de caracteres.
///
/// @param pString         Puntero de cadena de caracteres.
/// @param len	           Limite de cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getString(char *pString, int len) {
	int ret = -1;
	char bufferString[4096];

	if (pString != NULL && pString > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= len) {
				strncpy(pString, bufferString, len);
				ret = 0;
			}
		}
	}
	return ret;
}

/// @brief  getInt         Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero entero.
///
/// @param pResult         Puntero numero entero de la conversion realizada con ATOI.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getInt(int *pResult) {
	int ret = -1;
	char option[4096];
	if (pResult != NULL) {
		if (getString(option, sizeof(option)) == 0 && isNumeric(option) == 0) {
			*pResult = atoi(option);
			ret = 0;
		}

	}
	return ret;
}

/// @brief isNumeric       Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero entero.
///
/// @param pString         Puntero de cadena de caracteres a verificar en funcion.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isNumeric(char *pString) {
	int i = 0;
	int ret = 0;
	if (pString != NULL && strlen(pString) > 0) {
		while (pString[i] != '\0') {
			if (pString[i] < '0' || pString[i] > '9') {
				ret = -1;
				break;
			}
			i++;
		}
	}
	return ret;
}

/// @brief utn_getNumber   Función para pedir un número entero por consola.
///
/// @param pResult         Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		   Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage    Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		   Valor mínimo valido.
/// @param maximus         Valor máximo valido.
/// @param retry           Cantidad de intentos, en caso de ingresar un dato invalido.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus, int retry) {
	int ret;
	int num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL) {
		while (retry > 0) {
			printf(message);
			if (getInt(&num) == 0) {
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0) {
			ret = -1;
		} else {
			ret = 0;
			*pResult = num;
		}
	}
	return ret;

}

/// @brief getFloat		   Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero flotante.
///
/// @param pResult         Puntero numero entero de la conversion realizada con ATOF.
/// @return				   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getFloat(float *pResult) {
	int ret = -1;
	char option[4096];
	if (pResult != NULL) {
		if (getString(option, sizeof(option)) == 0 && isFloat(option) == 0) {
			*pResult = atof(option);
			ret = 0;
		}
	}
	return ret;
}

/// @brief isFloat         Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero flotante.
///
/// @param pString         Puntero a cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isFloat(char *pString) {
	int i = 0;
	int ret = 0;
	int pointCounter = 0;

	if (pString != NULL && strlen(pString) > 0) {
		for (i = 0; pString[i] != '\0'; i++) {
			if (pString[i] < '0' || pString[i] > '9') {
				if (pString[i] == '.' && pointCounter == 0) {
					pointCounter++;
				} else {
					ret = -1;
					break;
				}
			}
		}
	}
	return ret;
}
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus, int retry) {
	int ret;
	float num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL) {
		while (retry > 0) {
			printf(message);
			if (getFloat(&num) == 0) {
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0) {
			ret = -1;
		} else {
			ret = 0;
			*pResult = num;
		}
	}
	return ret;
}
