#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Jugador.h"
#include "Seleccion.h"

/** \brief Parsea los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 */
int parserPlayerFromText(FILE *pFile, LinkedList *pArrayListJugador)
{
	int returnparserPlayerFromText = ERROR;
	char auxId[2000];
	char auxFullName[2000];
	char auxAge[2000];
	char auxPosition[2000];
	char auxNationality[2000];
	char auxIdNationalTeam[2000];
	sPlayer *pPlayer;
	int returnFscanf;

	if (pFile != NULL && pArrayListJugador != NULL)
	{

		fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", auxId, auxFullName, auxAge, auxPosition, auxNationality, auxIdNationalTeam); //LECTURA FANTASMA
		do
		{
			returnFscanf = fscanf(pFile, "%[^,],%[^,],%[^,],%[^,],%[^,],%[^\n]", auxId, auxFullName, auxAge, auxPosition, auxNationality, auxIdNationalTeam);
			if (returnFscanf == 6)
			{

				pPlayer = newPlayerParameters(auxId, auxFullName, auxAge, auxPosition, auxNationality, auxIdNationalTeam);

				if (pPlayer != NULL && ll_add(pArrayListJugador, pPlayer))
				{


					//ACA LLAMO A LA FUNCION QUE ASIGNA MI PUNTERO EMPLEADO, AL ARRAY DE PUNTEROS EMPLEADOS.
				}
				returnparserPlayerFromText = SUCCESS;
			}
			else
			{

				returnparserPlayerFromText = ERROR;
				break; //si no leyo 4 variables break. se rompe
			}

		} while (!feof(pFile));
	}

	return returnparserPlayerFromText;
}

/** \brief Parsea los datos de los jugadores desde el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int parser_JugadorFromBinary(FILE *pFile, LinkedList *pArrayListJugador)
{
	return 1;
}

/** \brief Parsea los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int parser_SeleccionFromText(FILE *pFile, LinkedList *pArrayListSeleccion)
{
	return 1;
}

