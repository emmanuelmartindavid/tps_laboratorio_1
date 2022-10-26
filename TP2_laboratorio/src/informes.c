/*
 * informes.c
 *
 *  Created on: 20 oct. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "informes.h"
#include "validaciones.h"

int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int rtn = ERROR;
	char confederationDescription[50];
	char confederationDescription2[50];

	sPlayer auxSortPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (int i = 0; i < lenArrayPlayer - 1; i++)
		{
			for (int j = i + 1; j < lenArrayPlayer; j++)
			{

				if (arrayPlayer[i].isEmpty == OCCUPIED && getConfederationDescription(arrayConfederation, lenArrayConfederation, arrayPlayer[i].confederationId, confederationDescription) == OK
						&& getConfederationDescription(arrayConfederation, lenArrayConfederation, arrayPlayer[j].confederationId, confederationDescription2) == OK)
				{

					if ((stricmp(confederationDescription, confederationDescription2)) > 0 || (stricmp(confederationDescription, confederationDescription2) == 0 && (stricmp(arrayPlayer[i].name, arrayPlayer[j].name)) > 0))
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

int listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int rtn = ERROR;
	int ammount = 0;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (int j = 0; j < lenArrayConfederation; j++)
		{

			printf("\n\t\t\t\t\t\t\t\t\t\t\t\tCONFEDERACION: %s\n", arrayConfederation[j].confederationName);
			printf("\t\t\t\t\t\t========================================================================================================================\n");
			printf("\t\t\t\t\t\t|ID|         NOMBRE       |POSICION              |N° DE CAMISETA  |      SUELDO     |CONFEDERACION   |ANIOS DE CONTRATO|\n");
			printf("\t\t\t\t\t\t------------------------------------------------------------------------------------------------------------------------\n");
			for (int i = 0; i < lenArrayPlayer; i++)
			{

				if (arrayPlayer[i].isEmpty == OCCUPIED)
				{

					if (arrayPlayer[i].confederationId == arrayConfederation[j].idConfederation && listOnePlayer(arrayPlayer[i], arrayConfederation, lenArrayConfederation) == OK)
					{

						ammount++;
					}

				}

			}
			if (ammount > 0)
			{

				rtn = OK;
				printf("\t\t\t\t\t\t========================================================================================================================\n");
			}

		}

	}

	return rtn;
}

int countPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayer)
{

	int returnCountPlayers = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pCounterPlayer != NULL)
	{

		*pCounterPlayer = 0;
		for (int i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].isEmpty == OCCUPIED)
			{

				(*pCounterPlayer)++;

				returnCountPlayers = OK;

			}
		}

	}

	return returnCountPlayers;
}

int accumulateTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAccumulatorSalary)
{

	int returnaccumulateTotalSalary = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pAccumulatorSalary != NULL)
	{

		*pAccumulatorSalary = 0;
		for (int i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].isEmpty == OCCUPIED)
			{

				*pAccumulatorSalary += arrayPlayer[i].salary;

				returnaccumulateTotalSalary = OK;

			}

		}

	}

	return returnaccumulateTotalSalary;
}

int calculateAverageTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAverageTotalSalary)
{

	int returncalculateAverageTotalSalary = ERROR;
	int counterPlayer;
	float accumulatorSalary;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pAverageTotalSalary != NULL && countPlayers(arrayPlayer, lenArrayPlayer, &counterPlayer) == OK && accumulateTotalSalary(arrayPlayer, lenArrayPlayer, &accumulatorSalary) == OK)
	{

		for (int i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].isEmpty == OCCUPIED && counterPlayer > 0)
			{

				*pAverageTotalSalary = (float) accumulatorSalary / counterPlayer;

				returncalculateAverageTotalSalary = OK;

			}
		}

	}

	return returncalculateAverageTotalSalary;
}

int countPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayerAboveAverageSalary)
{

	float averageTotalSalary;

	int returncountPlayerAboveAverageSalary = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pCounterPlayerAboveAverageSalary != NULL && calculateAverageTotalSalary(arrayPlayer, lenArrayPlayer, &averageTotalSalary) == OK)
	{

		*pCounterPlayerAboveAverageSalary = 0;
		for (int i = 0; i < lenArrayPlayer; i++)
		{

			if (arrayPlayer[i].isEmpty == OCCUPIED && averageTotalSalary >= 0)
			{

				if (arrayPlayer[i].salary > averageTotalSalary)
				{

					(*pCounterPlayerAboveAverageSalary)++;

					returncountPlayerAboveAverageSalary = OK;
				}

			}
		}
	}

	return returncountPlayerAboveAverageSalary;
}

int accumulateHiringYearsByConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[])
{

	int returnaccumulateHiringYears = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{

		for (int i = 0; i < lenArrayConfederation; i++)
		{
			arrayAccumulatorHiringYears[i] = 0;
			for (int j = 0; j < lenArrayPlayer; j++)
			{
				if (arrayPlayer[j].isEmpty == OCCUPIED && arrayPlayer[j].confederationId == arrayConfederation[i].idConfederation)
				{

					arrayAccumulatorHiringYears[i] += arrayPlayer[j].hiringYears;

					returnaccumulateHiringYears = OK;
				}
			}

		}
	}
	return returnaccumulateHiringYears;
}

int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int *pMaximusHiringYears, int arrayAccumulatorHiringYears[])
{

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		*pMaximusHiringYears = 0;
		accumulateHiringYearsByConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorHiringYears);
		for (int i = 0; i < lenArrayConfederation; i++)
		{

			if (i == 0 || arrayAccumulatorHiringYears[i] > *pMaximusHiringYears)
			{

				*pMaximusHiringYears = arrayAccumulatorHiringYears[i];

			}

		}

	}
	return 0;
}

int accumulatePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[])
{

	int accumulatePlayersPerConfederation = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && arrayAccumulatorPlayerPerConfederation != NULL)
	{

		for (int i = 0; i < lenArrayConfederation; i++)
		{
			arrayAccumulatorPlayerPerConfederation[i] = 0;
			for (int j = 0; j < lenArrayPlayer; j++)
			{
				if (arrayPlayer[j].isEmpty == OCCUPIED && arrayPlayer[j].confederationId == arrayConfederation[i].idConfederation)
				{

					arrayAccumulatorPlayerPerConfederation[i]++;

					accumulatePlayersPerConfederation = OK;
				}
			}
		}
	}
	return accumulatePlayersPerConfederation;
}

int calculatePorcentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, float porcentagePlayersPerConfederation[], int arrayAccumulatorPlayerPerConfederation[])
{

	int counterPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && porcentagePlayersPerConfederation != NULL && arrayAccumulatorPlayerPerConfederation != NULL)
	{

		if (accumulatePlayersPerConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorPlayerPerConfederation) == OK && countPlayers(arrayPlayer, lenArrayPlayer, &counterPlayer) == OK)
		{

			for (int i = 0; i < lenArrayConfederation; i++)
			{
				porcentagePlayersPerConfederation[i] = 0;

				porcentagePlayersPerConfederation[i] = (float) arrayAccumulatorPlayerPerConfederation[i] / counterPlayer * 100;
			}

		}

	}

	return 0;
}

int calculateMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[], int *pMaximusPlayersPerConfederation)
{

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && arrayAccumulatorPlayerPerConfederation != NULL)
	{

		if (accumulatePlayersPerConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorPlayerPerConfederation) == OK)
		{

			for (int i = 0; i < lenArrayConfederation; i++)
			{

				if (i == 0 || arrayAccumulatorPlayerPerConfederation[i] > *pMaximusPlayersPerConfederation)
				{

					*pMaximusPlayersPerConfederation = arrayAccumulatorPlayerPerConfederation[i];
				}

			}

		}

	}

	return 0;
}

int showMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[])
{
	int maximusPlayersPerConfederation;
	calculateMaximusPlayersPerRegion(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorPlayerPerConfederation, &maximusPlayersPerConfederation);

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && arrayAccumulatorPlayerPerConfederation != NULL)
	{

		for (int i = 0; i < lenArrayConfederation; i++)
		{

			if (arrayAccumulatorPlayerPerConfederation[i] == maximusPlayersPerConfederation)
			{

				listOneConfederation(arrayConfederation[i]);
				for(int j=0;j<lenArrayPlayer;j++){


					if(arrayPlayer[j].isEmpty==OCCUPIED && arrayPlayer[j].confederationId ==arrayConfederation[i].idConfederation){


						listOnePlayer(arrayPlayer[j], arrayConfederation, lenArrayConfederation);
					}



				}


			}

		}

	}

	return 0;
}