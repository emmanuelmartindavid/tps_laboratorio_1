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
/// @brief initializeArrayPlayer  		 Funcion inicializa en 0 el array de jugadores.
///
/// @param arrayPlayer					 Array de jugadores a dar de alta.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
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
/// @brief getFreeIndexArrayPlayer		 Funcion obtiene posicion de ARRAY de jugadores libre a dar de alta.
///
/// @param arrayPlayer					 Array de jugadores a dar de alta.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @return							     Retorna la posicion del ARRAY de jugadores libre a dar de alta.
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
/// @brief findByIdArrayPlayer			 Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayPlayer					 Array de jugadores.
/// @param idVehicle			   	 	 ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @return								 Retorna la posicion del ARRAY buscado a traves del ID ingresado por usuario.
int findByIdArrayPlayer(sPlayer arrayPlayer[], int idPlayer, int lenArrayPlayer)
{
	int returnfindByIdArrayPlayer = ERROR;
	int i;

	if (arrayPlayer != NULL  && lenArrayPlayer > 0)
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
/// @brief listOnePlayer			   	 Funcion para listar un jugador dado de alta.
///
/// @param player				         Un jugadores de estructura sPlayer, dado de alta.
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
int listOnePlayer(sPlayer player, sConfederation arrayConfederation[], int lenArrayConfederation)
{
	int returnlistOnePlayer = ERROR;
	char confederationDescription[50];

	if (arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		getConfederationDescription(arrayConfederation, lenArrayConfederation, player.confederationId, confederationDescription);

		printf("\t\t\t\t\t\t| %-8d| %-25s| %-18s| %-15hu| $%-14.2f| %-25s| %-15hu |\n", player.idPlayer, player.name, player.position, player.shirtNumber, player.salary, confederationDescription, player.hiringYears);
		returnlistOnePlayer = OK;

	}

	return returnlistOnePlayer;
}
/// @brief listPlayeres			         Funcion lista ARRAY de jugadores dados de alta.
///
/// @param arrayPlayer			         ARRAY de jugadores dado de alta.
/// @param lenArrayPlayer					         Tamanio de ARRAY de jugadores.
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation			Tamanio de ARRAY de confederaciones.
/// @return						         Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int i = 0;
	int ammount = 0;
	int returnlistPlayers = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		printf("\t\t\t\t\t\t=========================================================================================================================================\n");
		printf("\t\t\t\t\t\t| ID      |         NOMBRE           |      POSICION     | N. DE CAMISETA |      SUELDO    |    CONFEDERACION         |ANIOS DE CONTRATO|\n");
		printf("\t\t\t\t\t\t=========================================================================================================================================\n");

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

			printf("\t\t\t\t\t\t=========================================================================================================================================\n");
		}

	}

	return returnlistPlayers;
}
/// @brief loadDataPlayer					Carga datos de jugador a dar de alta.
///
/// @param pPlayer								Puntero a un jugador de struct.
/// @param pIdPlayer							Puntero a entero.
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				 Tamanio de ARRAY de confederaciones.
/// @return								  	Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int loadDataPlayer(sPlayer *pPlayer, int *pIdPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	sPlayer auxPlayer;
	int returnloadDataPlayer;

	int auxIdConfederation;
	char playerPosition[50];
	if (pPlayer != NULL && pIdPlayer != NULL && arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		if (utn_getAlphabeticDescription(auxPlayer.name, "Ingrese su nombre y apellido.\n", "Dato invalido. Reintente.\n", 3, 50) == 0 && getPositionPlayer(playerPosition) == OK
						&& utn_getNumberFloat(&auxPlayer.salary, "Ingrese su salario. desde ($10000 hasta $9999999)", "Dato invalido. Reintente.\n", 10000, 9999999, 3) == 0 && utn_getNumberShort(&auxPlayer.shirtNumber, "Ingrese su numero de camiseta. Solo entre 1 y 99.\n", "Dato invalido. Reintente", 1, 99, 3) == 0
						&& utn_getNumberShort(&auxPlayer.hiringYears, "Ingrese los anios de contrato. Desde 1 a 10 maximo.", "Dato invalido. Reintente.\n", 1, 10, 3) == 0)
		{
			listConfederation(arrayConfederation, lenArrayConfederation);

			do
			{
				utn_getNumber(&auxIdConfederation, "Ingrese ID de su confederacion.", "Dato invalido. Reintente.\n", 100, 10000, 3);

			} while (findByIdArrayConfederation(arrayConfederation, auxIdConfederation, lenArrayConfederation) == ERROR);

			auxPlayer.confederationId = auxIdConfederation;
			auxPlayer.idPlayer = *pIdPlayer;
			strcpy(auxPlayer.position, playerPosition);
			auxPlayer.isEmpty = OCCUPIED;
			(*pIdPlayer)++;
			*pPlayer = auxPlayer;
			returnloadDataPlayer = OK;

		}
		else
		{

			returnloadDataPlayer = ERROR;

		}
	}

	return returnloadDataPlayer;
}
/// @brief registerPlayer				 Da de alta un jugador.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param pIdPlayer					 Puntero a entero.
/// @param arrayConfederation			 ARRAY de confederaciones.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerPlayer(sPlayer arrayPlayer[], int lenArrayPlayer, int *pIdPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnregisterPlayer = ERROR;

	int index;

	sPlayer auxPlayers;

	if (arrayPlayer != NULL && arrayPlayer > 0 && pIdPlayer != NULL && arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		index = getFreeIndexArrayPlayer(arrayPlayer, lenArrayPlayer);

		if (index != -1)
		{

			if (loadDataPlayer(&auxPlayers, pIdPlayer, arrayConfederation, lenArrayConfederation) == OK)
			{

				arrayPlayer[index] = auxPlayers;
				returnregisterPlayer = OK;

			}
			else
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

	if (arrayPlayer != NULL && lenArrayPlayer > 0)
	{

		do
		{
			utn_getNumber(&idPlayerAux, "Ingrese el ID del jugador a dar de baja.\n", "Dato invalido. Reintente.\n", 1, 3000, 3);

		} while (findByIdArrayPlayer(arrayPlayer, idPlayerAux, lenArrayPlayer) == ERROR);

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

	return returndownPlayer;
}
/// @brief modifyOnePlayer				Modifica un jugador.
///
/// @param pPlayer						Puntero a un jugador de struct.
/// @param arrayConfederation			 ARRAY de confederaciones.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyOnePlayer(sPlayer *pPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnmodifyOnePlayer;
	sPlayer auxModifyOnePlayer;
	int auxOptionModify;
	char playerPosition[50];

	do
	{

		if (pPlayer != NULL && arrayConfederation != NULL && lenArrayConfederation > 0)
		{
			showModifyPlayerMenu();
			if (utn_getNumber(&auxOptionModify, "\t\t\t\t\t\t\tINGRESE OPCION.\n", "Ingrese opcion valida\n", 1, 7, 3) == 0)
			{

				switch (auxOptionModify)
				{

				case 1:
					if (utn_getAlphabeticDescription(auxModifyOnePlayer.name, "Ingrese su nombre y apellido.\n", "Dato invalido. Reintente.\n", 3, 50) == 0)
					{
						strcpy(pPlayer->name, auxModifyOnePlayer.name);

						returnmodifyOnePlayer = OK;

					}
					else
					{
						returnmodifyOnePlayer = ERROR;

					}
					break;
				case 2:
					if (getPositionPlayer(playerPosition) == OK)
					{
						strcpy(auxModifyOnePlayer.position, playerPosition);
						strcpy(pPlayer->position, auxModifyOnePlayer.position);
						returnmodifyOnePlayer = OK;
					}
					else
					{

						returnmodifyOnePlayer = ERROR;

					}
					break;
				case 3:
					if (utn_getNumberShort(&auxModifyOnePlayer.shirtNumber, "Ingrese su numero de camiseta. Solo entre 1 y 99.\n", "Dato invalido. Reintente", 1, 99, 3) == 0)
					{

						pPlayer->shirtNumber = auxModifyOnePlayer.shirtNumber;
						returnmodifyOnePlayer = OK;
					}
					else
					{
						returnmodifyOnePlayer = ERROR;

					}
					break;
				case 4:
					listConfederation(arrayConfederation, lenArrayConfederation);

					do
					{
						utn_getNumber(&auxModifyOnePlayer.confederationId, "Ingrese ID de su confederacion.", "Dato invalido. Reintente.\n", 100, 10000, 3);

					} while (findByIdArrayConfederation(arrayConfederation, auxModifyOnePlayer.confederationId, lenArrayConfederation) == ERROR);

					pPlayer->confederationId = auxModifyOnePlayer.confederationId;

					returnmodifyOnePlayer = OK;

					break;
				case 5:
					if (utn_getNumberFloat(&auxModifyOnePlayer.salary, "Ingrese su salario. desde ($10000)", "Dato invalido. Reintente.\n", 10000, 9999999, 3) == 0)
					{
						pPlayer->salary = auxModifyOnePlayer.salary;
						returnmodifyOnePlayer = OK;
					}
					else
					{
						returnmodifyOnePlayer = ERROR;

					}
					break;
				case 6:
					if (utn_getNumberShort(&auxModifyOnePlayer.hiringYears, "Ingrese los anios de contrato. Desde 1 a 10 maximo.", "Dato invalido. Reintente.\n", 1, 10, 3) == 0)
					{
						pPlayer->hiringYears = auxModifyOnePlayer.hiringYears;
						returnmodifyOnePlayer = OK;
					}
					else
					{
						returnmodifyOnePlayer = ERROR;

					}
					break;
				}
			}
			else
			{

				returnmodifyOnePlayer = ERROR;
				break;

			}
		}
		else
		{
			returnmodifyOnePlayer = ERROR;
		}
	} while (auxOptionModify != 7 && returnmodifyOnePlayer != ERROR);

	return returnmodifyOnePlayer;
}
/// @brief modifyPlayers		Funcion para dar de modificar vehiculos dado de alta, atraves de ID.
///
/// @param arrayPlayer			ARRAY de vehiculos.
/// @param lenArrayPlayer					Tamanio de ARRAY de vehiculos.
/// @param arrayConfederation			ARRAY de tipos de vehiculo harcodeado.
/// @param lenArrayConfederation				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnmodifyPlayers = ERROR;
	int idPlayer;
	int index;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		do
		{
			utn_getNumber(&idPlayer, "Ingrese el ID del jugador a modificar.\n", "Dato invalido. Reintente.\n", 1, 3000, 3);

		} while (findByIdArrayPlayer(arrayPlayer, idPlayer, lenArrayPlayer) == ERROR);

		index = findByIdArrayPlayer(arrayPlayer, idPlayer, lenArrayPlayer);

		if (modifyOnePlayer(&arrayPlayer[index], arrayConfederation, lenArrayConfederation) == OK)
		{

			returnmodifyPlayers = OK;

		}
		else
		{
			returnmodifyPlayers = ERROR;
		}

	}

	return returnmodifyPlayers;
}
/// @brief sortPerIdPlayers				Ordena jugadores por ID.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param arrayConfederation			 ARRAY de confederaciones harcodeado.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones harcodeado.
/// @return								Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
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
/// @brief getPositionPlayer			Obtiene la posicion de jugador elegida por usuario.
///
/// @param pPosition					puntero a cadena char.
/// @return								Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
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
				rtn = OK;
				break;
			case 2:
				strcpy(pPosition, "Defensor");
				rtn = OK;
				break;
			case 3:
				strcpy(pPosition, "Mediocampista");
				rtn = OK;
				break;
			case 4:
				strcpy(pPosition, "Delantero");
				rtn = OK;
				break;

			}

		}
		else
		{

			rtn = ERROR;
		}
	}

	return rtn;
}
/// @brief validateRegisterOrDownPlayer	 Valida a traves de flag la entrada a las opciones de menu dependiendo si hay jugadores dados de alta.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param pFlag						 Puntero a entero.
void validateRegisterOrDownPlayer(sPlayer arrayPlayer[], int lenArrayPlayer, int *pFlag)
{

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pFlag != NULL)
	{
		*pFlag = FREE;
		for (int i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].isEmpty == OCCUPIED)
			{

				*pFlag = OK;
				break;

			}
			else
			{

				*pFlag = FREE;

			}

		}
	}

}
/// @brief hardCodePlayers				 Funcion para harcodear jugadores de prueba de programa.
///
/// @param arrayPlayer			         ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param pNextId						 Puntero a entero autoincremental a traves de contador.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodePlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int ammount, int *pNextId)
{

	int rtn = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pNextId != NULL)
	{
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
		{ 0, "Robert Lewandowski", "Delantero", 10, 101, 400000, 4, 1 },
		{ 0, "Vivianne Miedema", "Mediocampista", 10, 105, 400000, 4, 1 },
		{ 0, "Jan Oblak", "Arquero", 10, 102, 400000, 4, 1 },
		{ 0, "Kevin De Bruyne", "Mediocampista", 10, 102, 400000, 4, 1 },
		{ 0, "Kylian Mbappe", "Delantero", 7, 101, 400000, 4, 1 },
		{ 0, "Neymar Jr", "Delantero", 10, 101, 400000, 4, 1 },
		{ 0, "Alexia Putellas", "Mediocampista", 10, 101, 400000, 4, 1 }

		};
		if (arrayPlayer != NULL && pNextId != NULL && lenArrayPlayer > 0 && lenArrayPlayer <= 3000 && ammount <= lenArrayPlayer)
		{
			for (int i = 0; i < ammount; i++)
			{
				arrayPlayer[i] = aux[i];
				arrayPlayer[i].idPlayer = *pNextId;
				(*pNextId)++;
			}
			rtn = OK;
		}
	}
	return rtn;

}

