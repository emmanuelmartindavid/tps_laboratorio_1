/*
 * validaciones.c
 *
 *  Created on: 14 oct. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#define LEN 4096

/// @brief get String      Funcion para pedir dato por consola, a traves de cadena de caracteres.
///
/// @param pString         Puntero de cadena de caracteres.
/// @param len	           Limite de cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getString(char *pString, int len)
{
	int retorno = -1;
	char bufferString[LEN];

	if (pString != NULL && pString > 0)
	{
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL)
		{
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] == '\n')
			{
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] = '\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= LEN)
			{
				strcpy(pString, bufferString);
				retorno = 0;
			}
		}
	}
	return retorno;
}

/// @brief  getAlfaNumeric  Funcion verifica la cadena de caracteres ingresada, devolviendola asi por puntero cadena si es correcta.
///
/// @param pResult   	    Puntero a cadena de caracteres.
/// @param len				Largo de cadena maximo.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getalphabetic(char *pString, int len)
{
	int ret = -1;
	char option[len];
	if (pString != NULL)
	{
		if (getString(option, sizeof(option)) == 0 && isAlphabetic(option, sizeof(option)) == 0)
		{
			if (strnlen(option, sizeof(option)) <= len)
			{
				strcpy(pString, option);

				ret = 0;

			}

		}

	}
	return ret;
}
/// @brief  islfaNumeric  	Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de una cadena caracteres alfanumerica.
///
/// @param pResult   	    Puntero de cadena de caracteres.
/// @param len				Largo de cadena maximo.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isAlphabetic(char *pString, int len)
{

	int ret = 0;
	int lenght;
	if (pString != NULL)
	{
		lenght = strlen(pString);
		for (int i = 0; i < lenght; i++)
		{
			if ((pString[i] < 97 || pString[i] > 122) && (pString[i] < 65 || pString[i] > 90) && (pString[i] != ' '))
			{
				ret = -1;
				break;
			}
		}

	}
	return ret;
}
/// @brief utn_getAlfaNumeric    Función para pedir una descripcion alfanumerica por consola.
///
/// @param pResult          Puntero a direccion de la cadena de  caracteres ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para usuario.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.

int utn_getAlphabeticDescription(char *pResult, char *message, char *ErrorMessage, int retry, int len)
{
	int ret;
	char bufferString[len];
	while (retry > 0)
	{
		printf(message);
		if (getalphabetic(bufferString, sizeof(bufferString)) == 0 && strnlen(bufferString, sizeof(bufferString)) < len)
		{

			ret = 0;
			break;
		}
		fflush(stdin);
		retry--;
		printf(ErrorMessage);
	}
	if (retry == 0)
	{
		ret = -1;
	}
	else
	{
		ret = 0;
		strcpy(pResult, bufferString);

	}
	return ret;
}
/// @brief getInt           Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero entero.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOI.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getInt(int *pResult)
{
	int ret = -1;
	char option[LEN];

	if (pResult != NULL && getString(option, sizeof(option)) == 0 && isInt(option, sizeof(option)) == 0)
	{
		*pResult = atoi(option);

		//(short)*pResult = atoi(option);

		ret = 0;
	}

	return ret;
}

/// @brief isInt        Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero entero.
///
/// @param pString          Puntero de cadena de caracteres a verificar en funcion.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isInt(char *pString, int len)
{
	int i = 0;
	int ret = 0;
	if (pString != NULL && len > 0)
	{
		while (i < len && pString[i] != '\0')
		{
			if (pString[i] < '0' || pString[i] > '9')
			{
				ret = -1;
				break;
			}
			i++;
		}
	}
	return ret;
}

/// @brief utn_getNumber    Función para pedir un número entero por consola.
///
/// @param pResult          Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		    Valor mínimo valido.
/// @param maximus          Valor máximo valido.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.

int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus, int maximus, int retry)
{
	int ret;
	int num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL)
	{
		while (retry > 0)
		{
			printf(message);
			if (getInt(&num) == 0)
			{
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
			*pResult = num;
		}
	}
	return ret;

}

/// @brief getFloat		    Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero flotante.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOF.
/// @return				    Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getFloat(float *pResult)
{
	int ret = -1;
	char option[LEN];
	if (pResult != NULL)
	{
		if (getString(option, sizeof(option)) == 0 && isFloat(option) == 0)
		{
			*pResult = atof(option);
			ret = 0;
		}
	}
	return ret;
}
/// @brief isFloat          Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero flotante.
///
/// @param pString          Puntero a cadena de caracteres.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isFloat(char *pString)
{
	int i = 0;
	int ret = 0;
	int pointCounter = 0;

	if (pString != NULL && strlen(pString) > 0)
	{
		for (i = 0; pString[i] != '\0'; i++)
		{
			if (pString[i] < '0' || pString[i] > '9')
			{
				if (pString[i] == '.' && pointCounter == 0)
				{
					pointCounter++;
				}
				else
				{
					ret = -1;
					break;
				}
			}
		}
	}
	return ret;
}
/// @brief utn_getNumberFloat   Función para pedir un número flotante  por consola
///
/// @param pResult        	    Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message              Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage         Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus 	            Valor mínimo valido.
/// @param maximus              Valor máximo valido.
/// @return                     Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage, float minimus, float maximus, int retry)
{
	int ret;
	float num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL)
	{
		while (retry > 0)
		{
			printf(message);
			if (getFloat(&num) == 0)
			{
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
			*pResult = num;
		}
	}
	return ret;
}
/// @brief
///
/// @param pResult
/// @param message
/// @param ErrorMessage
/// @param retry
/// @return
int utn_getDescriptionExit(char *pResult, char *message, char *ErrorMessage, int retry)
{
	int ret;
	char bufferString[3];
	while (retry > 0)
	{
		printf(message);
		if (getalphabetic(bufferString, sizeof(bufferString)) == 0 && (strnlen(bufferString, sizeof(bufferString)) < 3 && (stricmp(bufferString, "si") == 0 || stricmp(bufferString, "no") == 0)))
		{

			ret = 0;
			break;
		}
		fflush(stdin);
		retry--;
		printf(ErrorMessage);
	}
	if (retry == 0)
	{
		ret = -1;
	}
	else
	{
		ret = 0;
		strcpy(pResult, bufferString);

	}
	return ret;
}
/// @brief getshort           Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero short.
///
/// @param pResult          Puntero numero entero de la conversion realizada con ATOI.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getshort(short *pResult)
{
	int ret = -1;
	char option[LEN];

	if (pResult != NULL && getString(option, sizeof(option)) == 0 && isInt(option, sizeof(option)) == 0)
	{

		*pResult = atoi(option);

		ret = 0;
	}

	return ret;
}
/// @brief utn_getNumberShort    Función para pedir un número entero por consola.
///
/// @param pResult          Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		    Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage     Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		    Valor mínimo valido.
/// @param maximus          Valor máximo valido.
/// @return                 Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberShort(short *pResult, char *message, char *errorMessage, int minimus, int maximus, int retry)
{
	int ret;
	short num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL)
	{
		while (retry > 0)
		{
			printf(message);
			if (getshort(&num) == 0)
			{
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0)
		{
			ret = -1;
		}
		else
		{
			ret = 0;
			*pResult = num;
		}
	}
	return ret;

}
