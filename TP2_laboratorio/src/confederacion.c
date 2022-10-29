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
/// @brief
///
/// @param arrayConfederation
/// @param lenArrayConfederation
void initializeArrayConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int i;
	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (i = 0; i < lenArrayConfederation; i++)
		{

			arrayConfederation[i].isEmpty = FREE;

		}
	}

}
/// @brief
///
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @return
int getFreeIndexArrayConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int i;
	int returngetFreeIndexArrayConfederation = ERROR;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (i = 0; i < lenArrayConfederation; i++)
		{
			if (arrayConfederation[i].isEmpty == FREE)
			{
				returngetFreeIndexArrayConfederation = i;
				break;
			}
		}
	}
	return returngetFreeIndexArrayConfederation;
}
/// @brief
///
/// @param arrayConfederation
/// @param idConfederation
/// @param lenArrayConfederation
/// @return
int findByIdArrayConfederation(sConfederation arrayConfederation[], int idConfederation, int lenArrayConfederation)
{
	int returnfindByIdArrayConfederation = ERROR;
	int i;

	if (arrayConfederation != NULL && idConfederation > 0 && lenArrayConfederation > 0)
	{

		for (i = 0; i < lenArrayConfederation; i++)
		{

			if (arrayConfederation[i].idConfederation == idConfederation && arrayConfederation[i].isEmpty == OCCUPIED)
			{
				returnfindByIdArrayConfederation = i;

				break;

			}
		}
	}

	return returnfindByIdArrayConfederation;
}
/// @brief
///
/// @param pConfederation
/// @param pIdConfederation
/// @return
int loadDataConfederation(sConfederation *pConfederation, int *pIdConfederation)
{

	sConfederation auxConfederation;
	int returnloadDataConfederation;

	if (utn_getAlphabeticDescription(auxConfederation.confederationName, "Ingrese nombre de confederacion.\n", "Dato invalido. Reintente.\n", 3, 50) == -1

	|| utn_getAlphabeticDescription(auxConfederation.region, "Ingrese region de confederacion.\n", "Dato invalido. Reintente", 3, 50) == -1

	|| utn_getNumber(&auxConfederation.creationYear, "Ingrese el anio de creacion de confederacion (1900-2022).\n", "Dato invalido. Reintente.\n", 1900, 2022, 3) == -1)
	{

		auxConfederation.idConfederation = *pIdConfederation;
		auxConfederation.isEmpty = OCCUPIED;
		(*pIdConfederation)++;
		*pConfederation = auxConfederation;
		returnloadDataConfederation = OK;
	}
	else
	{
		returnloadDataConfederation = ERROR;
	}

	return returnloadDataConfederation;
}
/// @brief
///
/// @param arrayConfederation
/// @param pIdConfederation
/// @param lenArrayConfederation
/// @return
int registerConfederation(sConfederation arrayConfederation[], int *pIdConfederation, int lenArrayConfederation)
{

	int returnregisterConfederation = ERROR;

	int index;

	sConfederation auxConfederation;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		index = getFreeIndexArrayConfederation(arrayConfederation, lenArrayConfederation);

		if (index != -1)
		{

			returnregisterConfederation = loadDataConfederation(&auxConfederation, pIdConfederation);

			if (returnregisterConfederation == OK)
			{
				arrayConfederation[index] = auxConfederation;

				returnregisterConfederation = OK;

			}
			else if (returnregisterConfederation == ERROR)
			{
				returnregisterConfederation = -2;

			}

		}
		else if (index == -1)
		{
			returnregisterConfederation = ERROR;
		}
	}

	return returnregisterConfederation;
}
/// @brief
///
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @return
int downConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{
	int returndownConfederation = ERROR;
	char buffer[3];
	int idConfederationAux;
	int index;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		do
		{
			utn_getNumber(&idConfederationAux, "Ingrese el ID de confederacion a dar de baja.\n", "Dato invalido. Reintente.\n", 1, 1000, 3);

		} while (findByIdArrayConfederation(arrayConfederation, idConfederationAux, lenArrayConfederation) == ERROR);

		index = findByIdArrayConfederation(arrayConfederation, idConfederationAux, lenArrayConfederation);

		utn_getDescriptionExit(buffer, "\t\t\t\t\t\t\tSu confederacion se dara de baja. Presione si para continuar. Presione no para cancelar baja de confederacion.\n", "\t\t\t\t\t\t\tError. Solo si o no.\n", 3);
		if (stricmp(buffer, "si") == 0)
		{

			arrayConfederation[index].isEmpty = DOWN;
			returndownConfederation = OK;
		}
		else
		{

			returndownConfederation = ERROR;
		}

	}

	return returndownConfederation;
}
/// @brief
///
/// @param pConfederation
/// @return
int modifyOneConfederation(sConfederation *pConfederation)
{

	int returnmodifyOneConfederation;
	int auxOptionModify;
	sConfederation auxModifyOneConfederation;

	do
	{

		if (pConfederation != NULL)
		{
			showModifyConfederationMenu();
			if (utn_getNumber(&auxOptionModify, "\t\t\t\t\t\t\tINGRESE OPCION", "Ingrese opcion valida\n", 1, 4, 3) == 0)
			{

				switch (auxOptionModify)
				{

				case 1:
					if (utn_getAlphabeticDescription(auxModifyOneConfederation.confederationName, "Ingrese nombre.\n", "Dato invalido. Reintente.\n", 3, 50) == 0)
					{
						strcpy(pConfederation->confederationName, auxModifyOneConfederation.confederationName);

						returnmodifyOneConfederation = OK;

					}
					else
					{
						returnmodifyOneConfederation = ERROR;

					}
					break;
				case 2:
					if (utn_getAlphabeticDescription(auxModifyOneConfederation.region, "Ingrese region.\n", "Dato invalido. Reintente.\n", 3, 50) == 0)
					{
						strcpy(pConfederation->region, auxModifyOneConfederation.region);

						returnmodifyOneConfederation = OK;

					}
					else
					{
						returnmodifyOneConfederation = ERROR;

					}
					break;
				case 3:
					if (utn_getNumber(&auxModifyOneConfederation.creationYear, "Ingrese su numero de camiseta. Solo entre 1 y 99.\n", "Dato invalido. Reintente", 1, 99, 3) == 0)
					{

						pConfederation->creationYear = auxModifyOneConfederation.creationYear;
						returnmodifyOneConfederation = OK;
					}
					else
					{
						returnmodifyOneConfederation = ERROR;

					}
					break;
				}
			}
			else
			{

				returnmodifyOneConfederation = ERROR;
				break;

			}
		}
		else
		{
			returnmodifyOneConfederation = ERROR;
		}
	} while (auxOptionModify != 7 && returnmodifyOneConfederation != ERROR);

	return returnmodifyOneConfederation;
}
/// @brief
///
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @return
int modifyConfederations(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnmodifyPlayers = ERROR;
	int idPlayer;
	int index;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		do
		{
			utn_getNumber(&idPlayer, "Ingrese el ID de confederacion a modificar.\n", "Dato invalido. Reintente.\n", 1, 1000, 3);

		} while (findByIdArrayConfederation(arrayConfederation, idPlayer, lenArrayConfederation) == ERROR);

		index = findByIdArrayConfederation(arrayConfederation, idPlayer, lenArrayConfederation);

		if (modifyOneConfederation(&arrayConfederation[index]) == OK)
		{

			returnmodifyPlayers = OK;

		}
		else
		{
			returnmodifyPlayers = -2;
		}

	}

	return returnmodifyPlayers;
}

/// @brief
///
/// @param OneConfederation
void listOneConfederation(sConfederation OneConfederation)
{

	printf("\t\t\t\t\t\t|%d|  %-20s|  %-25s| %-10d| \n", OneConfederation.idConfederation, OneConfederation.confederationName, OneConfederation.region, OneConfederation.creationYear);

}
/// @brief
///
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @return
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

