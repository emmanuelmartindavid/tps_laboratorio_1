/*
 * confederacion.c
 *
 *  Created on: 14 oct. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "validaciones.h"

/// @brief getIdtype		   Funcion para obtener el ID de tipo de vehiculo elegido por usuario.
///
/// @param arrayType		   ARRAY de tipos de vehiculo harcodeado.
/// @return					   Retorno ID de tipo de vehiculo elegido por usuario a traves de auxiliar sType.
int getIdConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int ConfederationId;
	int i;
	sConfederation auxConfederationId;
	listConfederation(arrayConfederation, lenArrayConfederation);

	if (arrayConfederation != NULL)
	{
		if (utn_getNumber(&ConfederationId, "Ingrese Confederacion(100 al 105).\n", "Dato invalido. Reintente.\n", 100, 105, 3) == -1)
		{
			auxConfederationId.idConfederation = ERROR;

		}
		else
		{
			for (i = 0; i < lenArrayConfederation; i++)
			{

				if (arrayConfederation[i].idConfederation == ConfederationId)
				{

					auxConfederationId.idConfederation = ConfederationId;

				}
			}

		}

	}

	return auxConfederationId.idConfederation;
}

void listOneConfederation(sConfederation OneConfederation)
{

	printf("\t\t\t\t\t\t|%d|  %-20s|  %-25s| %-10d| \n", OneConfederation.idConfederation, OneConfederation.confederationName, OneConfederation.region, OneConfederation.creationYear);

}

int listConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int i = 0;
	int ammount = 0;
	int rtn = ERROR;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		printf("\t\t\t\t\t\t====================================================================\n");
		printf("\t\t\t\t\t\t|ID |           NOMBRE      |REGION                |ANIO DE CREACION|\n");
		printf("\t\t\t\t\t\t---------------------------------------------------------------------\n");

		for (i = 0; i < lenArrayConfederation; i++)
		{

			listOneConfederation(arrayConfederation[i]);

			ammount++;

		}
		if (ammount > 0)
		{
			rtn = OK;

			printf("\t\t\t\t\t\t===================================================================\n");
		}

	}

	return rtn;
}

/// @brief getDescriptionType  Funcion para obtener la descripcion de tipo de vehiculo, segun ID tipo elegido por usuario.
///
/// @param arrayType           ARRAY de tipos de vehiculo harcodeado.
/// @param lenType			   Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @param idType			   ID tipo de vehiculo elegido por usuario a comparar.
/// @param pDescription		   Puntero a cadena de texto, con descripcion de tipo de vehiculo, dependiendo del ID de tipo de vehiculo elegido por usuario.
/// @return					   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.

int getConfederationDescription(sConfederation arrayConfederation[], int lenArrayConfederation, int idConfederation, char *pCofederationDescription)
{
	int rtn = ERROR;
	int i;

	if (arrayConfederation != NULL && lenArrayConfederation > 0 && idConfederation > 0 && pCofederationDescription != NULL)
	{

		for (i = 0; i < lenArrayConfederation; i++)
		{

			if (arrayConfederation[i].idConfederation == idConfederation)
			{

				strncpy(pCofederationDescription, arrayConfederation[i].confederationName, 50);
				rtn = OK;

				break;

			}
		}
	}

	return rtn;
}
/// @brief hardCode			   Funcion de harcodeo de ID tipo de vehiculo, descripcion tipo de vehiculo.
///
/// @param arrayType		   ARRAY de tipos de vehiculo a harcodear.
int hardCodeConfederations(sConfederation arrayConfederation[], int lenArrayConfederation, int ammount, int *pNextId)
{

	int rtn = ERROR;

	sConfederation aux[6] =
	{

	{ 0, "CONMEBOL", "SUDAMERICA", 1916, 1 },
	{ 0, "UEFA", "EUROPA", 1954, 1 },
	{ 0, "AFC", "ASIA", 1954, 1 },
	{ 0, "CAF", "AFRICA", 1957, 1 },
	{ 0, "CONCACAF", "NORTE CENTRO AMERICA", 1961, 1 },
	{ 0, "OFC", "OCEANIA", 1966, 1 }

	};

	if (arrayConfederation != NULL && pNextId != NULL && lenArrayConfederation > 0 && lenArrayConfederation <= 6 && ammount <= lenArrayConfederation)
	{
		for (int i = 0; i < ammount; i++)
		{
			arrayConfederation[i] = aux[i];
			arrayConfederation[i].idConfederation = *pNextId;
			(*pNextId)++;
		}
		rtn = OK;
	}
	return rtn;

}
