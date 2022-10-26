/*
 * jugador.c
 *
 *  Created on: 13 oct. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "validaciones.h"

void initializeArrayPlayer(sPlayer arrayPlayer[], int lenArrayPlayer)
{

	int i;
	if (arrayPlayer != NULL && lenArrayPlayer > 0)
	{
		for (i = 0; i < lenArrayPlayer; i++)
		{

			arrayPlayer[i].isEmpty = FREE;

		}
	}

}
/// @brief getFreeIndex			Funcion obtiene posicion de ARRAY de vehiculos libre a dar de alta.
///
/// @param arrayVehicle			Array de vehiculos a dar de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorna la posicion del ARRAY de vehiculos libre a dar de alta.
int getFreeIndexArrayPlayer(sPlayer arrayPlayer[], int lenArrayPlayer)
{

	int i;
	int returngetFreeIndexArrayPlayer = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0)
	{
		for (i = 0; i < lenArrayPlayer; i++)
		{
			if (arrayPlayer[i].isEmpty == FREE)
			{
				returngetFreeIndexArrayPlayer = i;
				break;
			}
		}
	}
	return returngetFreeIndexArrayPlayer;
}
/// @brief findById				Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayVehicle			Array de vehiculos.
/// @param idVehicle			ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorna la posicion del ARRAY buescado a traves del ID ingresado por usuario.
int findByIdArrayPlayer(sPlayer arrayPlayer[], int idPlayer, int lenArrayPlayer)
{
	int returnfindByIdArrayPlayer = ERROR;
	int i;

	if (arrayPlayer != NULL && idPlayer > 0 && lenArrayPlayer > 0)
	{

		for (i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].idPlayer == idPlayer && arrayPlayer[i].isEmpty == OCCUPIED)
			{
				returnfindByIdArrayPlayer = i;

				break;

			}
		}
	}

	return returnfindByIdArrayPlayer;
}
/// @brief listOneVehicle		Funcion para listar un vehiculo.
///
/// @param vehicle				Un vehiculo de estructura sVehicle, dado de alta.
/// @param arrayType			ARRAY de tipos de vehiculos harcodeado.
/// @param lenType				Tamanio de ARRAY de tipo harcodeado.
int listOnePlayer(sPlayer player, sConfederation arrayConfederation[], int lenArrayConfederation)
{
	int returnlistOnePlayer = ERROR;
	char confederationDescription[50];

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		getConfederationDescription(arrayConfederation, lenArrayConfederation, player.confederationId, confederationDescription);

		printf("\t\t\t\t\t\t|%4d|  %-20s|  %-20s| %-15hd|  %-15.2f| %-15s| %-16hd|\n", player.idPlayer, player.name, player.position, player.shirtNumber, player.salary, confederationDescription, player.hiringYears);
		returnlistOnePlayer = OK;
	}

	return returnlistOnePlayer;
}
/// @brief listVehicles			Funcion lista ARRAY de vehiculos dados de alta.
///
/// @param arrayVehicle			ARRAY de vehiculos dado de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculos harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int i = 0;
	int ammount = 0;
	int returnlistPlayers = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		printf("\t\t\t\t\t\t========================================================================================================================\n");
		printf("\t\t\t\t\t\t| ID |         NOMBRE      |POSICION             |N° DE CAMISETA  |      SUELDO    |CONFEDERACION  |ANIOS DE CONTRATO|\n");
		printf("\t\t\t\t\t\t------------------------------------------------------------------------------------------------------------------------\n");

		for (i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].isEmpty == OCCUPIED)
			{

				listOnePlayer(arrayPlayer[i], arrayConfederation, lenArrayConfederation);

				ammount++;

			}

		}
		if (ammount > 0)
		{
			returnlistPlayers = OK;

			printf("\t\t\t\t\t\t========================================================================================================================\n");
		}

	}

	return returnlistPlayers;
}
/// @brief getId Funcion STATIC para autoincrementar ID de cada vehiculo.
///
/// @return Retorno ID autoincrementada para cada vehiculo dado de alta.
static int getId(void)
{

	static int getIdIncremental = 1;

	return getIdIncremental++;
}
/// @brief loadData				Funcion de tipo sVehicle(estructura de vehiculo) para realiza la carga de datos de vehiculo.
///
/// @return						Retorno auxiliar de sVehicle(estructura de vehiculo) con los datos cargados por el usuario.
sPlayer loadDataPlayer(void)
{

	sPlayer auxPlayer;
	int auxShirt;
	int auxHiringYears;
	char playerPosition[50];

	if (utn_getAlphabeticDescription(auxPlayer.name, "Ingrese su nombre y apellido.\n", "Dato invalido. Reintente.\n", 3, 50) == -1 || getPositionPlayer(playerPosition) == -1

	|| utn_getNumberFloat(&auxPlayer.salary, "Ingrese su salario. desde ($10000)", "Dato invalido. Reintente.\n", 10000, 9999999, 3) == -1 || utn_getNumber(&auxShirt, "Ingrese su numero de camiseta. Solo entre 1 y 99.\n", "Dato invalido. Reintente", 1, 99, 3) == -1

	|| utn_getNumber(&auxHiringYears, "Ingrese los anios de contrato. Desde 1 a 10 maximo.", "Dato invalido. Reintente.\n", 1, 10, 3) == -1)
	{

		auxPlayer.isEmpty = ERROR;

	}
	else
	{
		strcpy(auxPlayer.position, playerPosition);
		auxPlayer.shirtNumber = auxShirt;
		auxPlayer.hiringYears = auxHiringYears;

		auxPlayer.isEmpty = FREE;
	}

	return auxPlayer;
}

/// @brief registerVehicle		Funcion para dar de alta un vehiculo.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerPlayer(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnregisterPlayer = ERROR;

	int index;

	sPlayer auxPlayers;

	if (arrayPlayer != NULL && arrayPlayer > 0 && arrayConfederation != NULL)
	{

		index = getFreeIndexArrayPlayer(arrayPlayer, lenArrayPlayer);

		if (index != -1)
		{

			auxPlayers = loadDataPlayer();

			if (auxPlayers.isEmpty == FREE)
			{

				auxPlayers.idPlayer = getId();

				auxPlayers.confederationId = getIdConfederation(arrayConfederation, lenArrayConfederation);
				if (auxPlayers.confederationId == ERROR)
				{

					returnregisterPlayer = -2;

				}
				else
				{

					auxPlayers.isEmpty = OCCUPIED;

					arrayPlayer[index] = auxPlayers;

					returnregisterPlayer = OK;
				}

			}
			else if (auxPlayers.isEmpty == ERROR)
			{
				returnregisterPlayer = -2;

			}

		}
		else if (index == -1)
		{
			returnregisterPlayer = ERROR;
		}
	}

	return returnregisterPlayer;
}

/// @brief downVehicle			Funcion para dar de baja un vehiculo dado de alta, atraves de ID.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int downPlayer(sPlayer arrayPlayer[], int lenArrayPlayer)
{
	int returndownPlayer = ERROR;
	char buffer[3];
	int idPlayerAux;
	int index;
	int returnIdAux;

	if (arrayPlayer != NULL && lenArrayPlayer > 0)
	{

		do
		{
			returnIdAux = utn_getNumber(&idPlayerAux, "Ingrese el ID del jugador a dar de baja.\n", "Dato invalido. Reintente.\n", 1, 3000, 3);

		} while (findByIdArrayPlayer(arrayPlayer, idPlayerAux, lenArrayPlayer) == ERROR && returnIdAux == 0);

		if (returnIdAux == -1)
		{
			returndownPlayer = -2;
		}
		else
		{
			index = findByIdArrayPlayer(arrayPlayer, idPlayerAux, lenArrayPlayer);

			utn_getDescriptionExit(buffer, "\t\t\t\t\t\t\tSu jugador se dara de baja. Presione si para continuar. Presione no para cancelar baja de jugador.\n", "\t\t\t\t\t\t\tError. Solo si o no.\n", 3);
			if (stricmp(buffer, "si") == 0)
			{

				arrayPlayer[index].isEmpty = DOWN;
				returndownPlayer = OK;
			}
			else
			{

				returndownPlayer = ERROR;
			}
		}
	}

	return returndownPlayer;
}
/// @brief modifyOneVehicle	    Funcion de tipo sVehicle(estructura de vehiculo) para realiza la carga de datos de vehiculo a modificar.
///
/// @param vehicle				Un vehiculo de estructura sVehicle dado de alta a ser modificado.
/// @return						Retorno auxiliar de sVehicle(estructura de vehiculo) con los datos modificados por el usuario.
sPlayer modifyOnePlayer(sPlayer player, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	sPlayer auxModifyOnePlayer = player;
	int auxOptionModify;
	int auxModifyShirt;
	int auxModifyHiringYears;
	char playerPosition[50];

	do
	{

		if (arrayConfederation != NULL && lenArrayConfederation > 0)
		{
			showModifyPlayerMenu();
			if (utn_getNumber(&auxOptionModify, "\t\t\t\t\t\t\tINGRESE OPCION", "Ingrese opcion valida\n", 1, 7, 3) == 0)
			{

				switch (auxOptionModify)
				{

				case 1:
					if (utn_getAlphabeticDescription(auxModifyOnePlayer.name, "Ingrese su nombre y apellido.\n", "Dato invalido. Reintente.\n", 3, 50) == 0)
					{

						auxModifyOnePlayer.isEmpty = OCCUPIED;
					}
					else
					{

						auxModifyOnePlayer.isEmpty = ERROR;
					}
					break;
				case 2:
					if (getPositionPlayer(playerPosition) == ERROR)
					{

						auxModifyOnePlayer.isEmpty = ERROR;
					}
					else
					{

						strcpy(auxModifyOnePlayer.position, playerPosition);
						auxModifyOnePlayer.isEmpty = OCCUPIED;

					}
					break;
				case 3:
					if (utn_getNumber(&auxModifyShirt, "Ingrese su numero de camiseta. Solo entre 1 y 99.\n", "Dato invalido. Reintente", 1, 99, 3) == 0)
					{

						auxModifyOnePlayer.shirtNumber = auxModifyShirt;
						auxModifyOnePlayer.isEmpty = OCCUPIED;
					}
					else
					{
						auxModifyOnePlayer.isEmpty = ERROR;

					}
					break;
				case 4:
					auxModifyOnePlayer.confederationId = getIdConfederation(arrayConfederation, lenArrayConfederation);
					if (auxModifyOnePlayer.confederationId == ERROR)
					{

						auxModifyOnePlayer.isEmpty = ERROR;

					}
					else
					{
						auxModifyOnePlayer.isEmpty = OCCUPIED;
					}
					break;
				case 5:
					if (utn_getNumberFloat(&auxModifyOnePlayer.salary, "Ingrese su salario. desde ($10000)", "Dato invalido. Reintente.\n", 10000, 9999999, 3) == 0)
					{

						auxModifyOnePlayer.isEmpty = OCCUPIED;
					}
					else
					{
						auxModifyOnePlayer.isEmpty = ERROR;

					}
					break;
				case 6:
					if (utn_getNumber(&auxModifyHiringYears, "Ingrese los anios de contrato. Desde 1 a 10 maximo.", "Dato invalido. Reintente.\n", 1, 10, 3) == 0)
					{
						auxModifyOnePlayer.hiringYears = auxModifyHiringYears;
						auxModifyOnePlayer.isEmpty = OCCUPIED;
					}
					else
					{
						auxModifyOnePlayer.isEmpty = ERROR;

					}
					break;
				}
			}
			else
			{

				auxModifyOnePlayer.isEmpty = ERROR;
				break;

			}
		}
		else
		{
			auxModifyOnePlayer.isEmpty = ERROR;
		}
	} while (auxOptionModify != 7 && auxModifyOnePlayer.isEmpty != ERROR);

	return auxModifyOnePlayer;
}
/// @brief modifyVehicles		Funcion para dar de modificar vehiculos dado de alta, atraves de ID.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnmodifyPlayers = ERROR;
	int idPlayer;
	int index;
	int returnIdAux;
	sPlayer auxPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		do
		{
			returnIdAux = utn_getNumber(&idPlayer, "Ingrese el ID del jugador a dar de baja.\n", "Dato invalido. Reintente.\n", 1, 3000, 3);

		} while (findByIdArrayPlayer(arrayPlayer, idPlayer, lenArrayPlayer) == ERROR && returnIdAux == 0);
		if (returnIdAux == -1)
		{
			returnmodifyPlayers = -2;
		}
		else
		{
			index = findByIdArrayPlayer(arrayPlayer, idPlayer, lenArrayPlayer);

			auxPlayer = modifyOnePlayer(arrayPlayer[index], arrayConfederation, lenArrayConfederation);
		}
		if (auxPlayer.isEmpty == OCCUPIED)
		{
			arrayPlayer[index] = auxPlayer;
			returnmodifyPlayers = OK;

		}
		else if (auxPlayer.isEmpty == ERROR)
		{
			returnmodifyPlayers = -2;
		}

	}

	return returnmodifyPlayers;
}

int sortPerIdPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int rtn = ERROR;

	sPlayer auxSortPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (int i = 0; i < lenArrayPlayer - 1; i++)
		{
			for (int j = i + 1; j < lenArrayPlayer; j++)
			{

				if (arrayPlayer[i].isEmpty == OCCUPIED)
				{

					if (arrayPlayer[i].idPlayer > arrayPlayer[j].idPlayer)
					{

						auxSortPlayer = arrayPlayer[i];
						arrayPlayer[i] = arrayPlayer[j];
						arrayPlayer[j] = auxSortPlayer;
					}
					rtn = OK;
				}
			}
		}

	}

	return rtn;
}

int getPositionPlayer(char *pPosition)
{

	int rtn;
	int option;

	if (pPosition != NULL)
	{
		if (utn_getNumber(&option, "Ingrese su posicion.\n"
				"1. ARQUERO\n"
				"2. DEFENSOR\n"
				"3. MEDIOCAMPISTA\n"
				"4. DELANTERO\n", "Dato invalido. Reintente.\n", 1, 4, 3) == 0)
		{

			switch (option)
			{
			case 1:
				strcpy(pPosition, "Arquero");
				break;
			case 2:
				strcpy(pPosition, "Defensor");
				break;
			case 3:
				strcpy(pPosition, "Mediocampista");
				break;
			case 4:
				strcpy(pPosition, "Delantero");
				break;

				rtn = OK;
			}

		}
		else
		{

			rtn = ERROR;
		}
	}

	return rtn;
}

int hardCodePlayers(sPlayer arrayPlayer[], int len, int ammount, int *pNextId)
{

	int rtn = ERROR;

	sPlayer aux[27] =
	{

	{ 0, "Ronaldo Nazario", "Delantero", 9, 100, 23000, 10, 1 },
	{ 0, "Lionel Messi", "Delantero", 10, 100, 999000, 7, 1 },
	{ 0, "Cristiano Ronaldo", "Delantero", 7, 101, 999000, 2, 1 },
	{ 0, "Estefania Banini", "Mediocampista", 10, 102, 400000, 4, 1 },
	{ 0, "Megan Rapinoe", "Mediocampista", 15, 102, 450000, 3, 1 },
	{ 0, "Mariana Larroquette", "Delantera", 19, 102, 300000, 3, 1 },
	{ 0, "Diego Maradona", "Delantero", 10, 101, 999999, 2, 1 },
	{ 0, "Johan Cruyff", "Mediocampista", 14, 101, 600000, 2, 1 },
	{ 0, "Zinedine Zidane", "Mediocampista", 10, 101, 700000, 3, 1 },
	{ 0, "Alex Morgan", "Defensora", 10, 101, 400000, 4, 1 },
	{ 0, "Alfredo Di Stefano", "Mediocampista", 9, 101, 500000, 2, 1 },
	{ 0, "Dalila Ippolito", "Mediocampista", 8, 101, 350000, 3, 1 },
	{ 0, "Julieta Cruz", "Defensora", 4, 105, 450000, 3, 1 },
	{ 0, "Virgil van Dijk", "Defensor", 4, 104, 700000, 3, 1 },
	{ 0, "Cristian Romero", "Defensor", 13, 104, 500000, 2, 1 },
	{ 0, "Agustina Barroso", "Mediocampista", 2, 103, 550000, 3, 1 },
	{ 0, "Virginia Gomez", "Mediocampista", 13, 105, 200000, 2, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 101, 400000, 4, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 103, 400000, 4, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 102, 400000, 4, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 102, 400000, 4, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 105, 400000, 4, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 105, 400000, 4, 1 },
	{ 0, "Estefanía Banini", "Mediocampista", 10, 105, 400000, 4, 1 }

	};
	if (arrayPlayer != NULL && pNextId != NULL && len > 0 && len <= 3000 && ammount <= len)
	{
		for (int i = 0; i < ammount; i++)
		{
			arrayPlayer[i] = aux[i];
			arrayPlayer[i].idPlayer = *pNextId;
			(*pNextId)++;
		}
		rtn = OK;
	}
	return rtn;

}
