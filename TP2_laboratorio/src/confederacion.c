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
/// @brief initializeArrayConfederation     Funcion inicializa en 0 el array de confederaciones.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
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
/// @brief getFreeIndexArrayConfederation		Funcion obtiene posicion de ARRAY de confederaciones libre a dar de alta.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return									 Retorna la posicion del ARRAY de jugadores libre a dar de alta.
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
/// @brief findByIdArrayConfederation				 Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayConfederation				         ARRAY de confederaciones.
/// @param idConfederation							ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return								 Retorna la posicion del ARRAY buscado a traves del ID ingresado por usuario.
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
/// @brief loadDataConfederation		Carga datos de confederacion a dar de alta.
///
/// @param pConfederation			Puntero a una confederacion de struct.
/// @param pIdConfederation			Puntero a entero autoincremental a traves de contador.
/// @return							  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int loadDataConfederation(sConfederation *pConfederation, int *pIdConfederation)
{

	sConfederation auxConfederation;
	int returnloadDataConfederation;
	if (pConfederation != NULL && pIdConfederation != NULL)
	{
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
	}
	return returnloadDataConfederation;
}
/// @brief registerConfederation			Da de alta una confederacion.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param pIdConfederation						Puntero a entero autoincremental a traves de contador.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return								  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerConfederation(sConfederation arrayConfederation[], int *pIdConfederation, int lenArrayConfederation)
{

	int returnregisterConfederation = ERROR;

	int index;

	sConfederation auxConfederation;

	if (arrayConfederation != NULL && pIdConfederation != NULL && lenArrayConfederation > 0)
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
/// @brief downConfederation					Da de baja confederacion.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int downConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{
	int returndownConfederation = ERROR;
	char buffer[3];
	int idConfederationAux;
	int index;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		listConfederation(arrayConfederation, lenArrayConfederation);
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
/// @brief modifyOneConfederation			Modifica un jugador.
///
/// @param pConfederation				Puntero a una confederacion de struct.
/// @return						  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
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
	} while (auxOptionModify != 4 && returnmodifyOneConfederation != ERROR);

	return returnmodifyOneConfederation;
}
/// @brief modifyConfederations					 Funcion para dar de modificar confederaciones dado de alta, atraves de ID.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return							  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyConfederations(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnmodifyPlayers = ERROR;
	int idPlayer;
	int index;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		listConfederation(arrayConfederation, lenArrayConfederation);
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
/// @brief listOneConfederation				Lista una confedracion.
///
/// @param OneConfederation			 Una confederacion de estructura sConfederation, dado de alta.
void listOneConfederation(sConfederation OneConfederation)
{

	printf("\t\t\t\t\t\t|%d|  %-20s|  %-25s| %-10d| \n", OneConfederation.idConfederation, OneConfederation.confederationName, OneConfederation.region, OneConfederation.creationYear);

}
/// @brief listConfederation			Lista confederaciones
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
void listConfederation(sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int i = 0;
	int ammount = 0;

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		printf("\t\t\t\t\t\t====================================================================\n");
		printf("\t\t\t\t\t\t|ID |           NOMBRE      |REGION                |ANIO DE CREACION|\n");
		printf("\t\t\t\t\t\t---------------------------------------------------------------------\n");

		for (i = 0; i < lenArrayConfederation; i++)
		{

			if (arrayConfederation[i].isEmpty == OCCUPIED)
			{

				listOneConfederation(arrayConfederation[i]);

				ammount++;

			}

		}
		if (ammount > 0)
		{

			printf("\t\t\t\t\t\t===================================================================\n");
		}

	}
}
/// @brief getConfederationDescription 				 Funcion para obtener la descripcion de tipo de vehiculo, segun ID tipo elegido por usuario.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @param idConfederation			  			 ID de confederacion elegido por usuario a comparar.
/// @param pCofederationDescription		  		 Puntero a cadena de texto, con nombre de confederacion.
/// @return					  				 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
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
/// @brief hardCodeConfederations			 Funcion para harcodear confederaciones.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @param ammount								Entero, cantidad.
/// @param pNextId					 Puntero a entero autoincremental a traves de contador.
/// @return							   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
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

