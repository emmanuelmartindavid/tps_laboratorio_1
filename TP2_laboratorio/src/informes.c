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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @return
int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{

	int returnsortPerConfederationAndPlayerName = ERROR;
	char confederationDescription[50];
	char confederationDescription2[50];

	sPlayer auxSortPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (int i = 0; i < lenArrayPlayer - 1; i++)
		{
			for (int j = i + 1; j < lenArrayPlayer; j++)
			{

				if (arrayPlayer[i].isEmpty == OCCUPIED
					&& getConfederationDescription(arrayConfederation, lenArrayConfederation, arrayPlayer[i].confederationId, confederationDescription) == OK
					&& getConfederationDescription(arrayConfederation, lenArrayConfederation, arrayPlayer[j].confederationId, confederationDescription2) == OK)
				{

					if ((stricmp(confederationDescription, confederationDescription2)) > 0 || (stricmp(confederationDescription, confederationDescription2) == 0 && (stricmp(arrayPlayer[i].name, arrayPlayer[j].name)) > 0))
					{

						auxSortPlayer = arrayPlayer[i];
						arrayPlayer[i] = arrayPlayer[j];
						arrayPlayer[j] = auxSortPlayer;
					}
					returnsortPerConfederationAndPlayerName = OK;
				}
			}
		}

	}

	return returnsortPerConfederationAndPlayerName;
}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
void listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation)
{


	int ammount = 0;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		for (int j = 0; j < lenArrayConfederation; j++)
		{

			printf("\n\t\t\t\t\t\t\t\t\t\t\t\tCONFEDERACION: %s\n", arrayConfederation[j].confederationName);
			printf("\t\t\t\t\t\t=========================================================================================================================================\n");
			printf("\t\t\t\t\t\t| ID      |         NOMBRE           |POSICION          |N° DE CAMISETA  |         SUELDO       |CONFEDERACION        |ANIOS DE CONTRATO|\n");
			printf("\t\t\t\t\t\t=========================================================================================================================================\n");
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

				printf("\t\t\t\t\t\t=========================================================================================================================================\n");
			}

		}

	}

}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pCounterPlayer
/// @return
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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pAccumulatorSalary
/// @return
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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pAverageTotalSalary
/// @return
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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pCounterPlayerAboveAverageSalary
/// @return
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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorHiringYears
/// @return
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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param pMaximusHiringYears
/// @param arrayAccumulatorHiringYears
/// @return
int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int *pMaximusHiringYears, int arrayAccumulatorHiringYears[])
{
	int returnCalculateMaximusHiringYearsConfederation = ERROR;
	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0)
	{
		*pMaximusHiringYears = 0;
		accumulateHiringYearsByConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorHiringYears);
		for (int i = 0; i < lenArrayConfederation; i++)
		{

			if (i == 0 || arrayAccumulatorHiringYears[i] > *pMaximusHiringYears)
			{

				*pMaximusHiringYears = arrayAccumulatorHiringYears[i];
				returnCalculateMaximusHiringYearsConfederation = OK;
			}

		}

	}
	return returnCalculateMaximusHiringYearsConfederation;
}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorHiringYears
/// @return
int showMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[])
{
	int returnShowMaximusHiringYearsConfederation=ERROR;
	int maximusHiringYears;
	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && arrayAccumulatorHiringYears != NULL)
	{
		calculateMaximusHiringYearsConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, &maximusHiringYears, arrayAccumulatorHiringYears);

		for (int i = 0; i < lenArrayConfederation; i++)
		{

			if (arrayAccumulatorHiringYears[i] == maximusHiringYears)
			{

				printf("\n\t\t\t\t\t\tLA CONFEDERACION CON MAS ANIOS DE CONTRATO ES %s."
								"\n\t\t\t\t\t\tCUENTA CON %d ANIOS  CONTRATO TOTAL.\n", arrayConfederation[i].confederationName, maximusHiringYears);
				returnShowMaximusHiringYearsConfederation=OK;

			}

		}

	}

	return returnShowMaximusHiringYearsConfederation;
}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
/// @return
int accumulatePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[])
{

	int returnAccumulatePlayersPerConfederation = ERROR;

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

					returnAccumulatePlayersPerConfederation = OK;
				}
			}
		}
	}
	return returnAccumulatePlayersPerConfederation;
}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param porcentagePlayersPerConfederation
/// @param arrayAccumulatorPlayerPerConfederation
/// @return
int calculatePercentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, float porcentagePlayersPerConfederation[], int arrayAccumulatorPlayerPerConfederation[])
{

	int returncalculatePercentagePlayersPerConfederation=ERROR;
	int counterPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && porcentagePlayersPerConfederation != NULL && arrayAccumulatorPlayerPerConfederation != NULL)
	{

		if (accumulatePlayersPerConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorPlayerPerConfederation) == OK && countPlayers(arrayPlayer, lenArrayPlayer, &counterPlayer) == OK)
		{

			for (int i = 0; i < lenArrayConfederation; i++)
			{
				porcentagePlayersPerConfederation[i] = 0;
				if (counterPlayer > 0)
				{

					porcentagePlayersPerConfederation[i] = (float) arrayAccumulatorPlayerPerConfederation[i] / counterPlayer * 100;
					returncalculatePercentagePlayersPerConfederation=OK;
				}
			}

		}

	}

	return returncalculatePercentagePlayersPerConfederation;
}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
void showPercentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[])
{

	float percentagePerConfederation[lenArrayConfederation];

	calculatePercentagePlayersPerConfederation(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, percentagePerConfederation, arrayAccumulatorPlayerPerConfederation);
	for (int i = 0; i < lenArrayConfederation; i++)
	{

		printf("\n\t\t\t\t\t\tLA CONFEDERACION %s."
						"\n\t\t\t\t\t\tCUENTA CON UN %% %.2f DE JUGADORES\n", arrayConfederation[i].confederationName, percentagePerConfederation[i]);

	}

}
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
/// @param pMaximusPlayersPerConfederation
/// @return
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
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
void showMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[])
{
	int maximusPlayersPerConfederation;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL && lenArrayConfederation > 0 && arrayAccumulatorPlayerPerConfederation != NULL)
	{
		calculateMaximusPlayersPerRegion(arrayPlayer, lenArrayPlayer, arrayConfederation, lenArrayConfederation, arrayAccumulatorPlayerPerConfederation, &maximusPlayersPerConfederation);

		printf("\t\t\t\t\t\t=========================================================================================================================================\n");

		for (int i = 0; i < lenArrayConfederation; i++)
		{

			if (arrayAccumulatorPlayerPerConfederation[i] == maximusPlayersPerConfederation)
			{
				printf("\t\t\t\t\t\tLA CONFEDERACION %s DE REGION %s CUENTA CON MAYOR CANTIDAD DE JUGADORES\n\n", arrayConfederation[i].confederationName, arrayConfederation[i].region);
				printf("\t\t\t\t\t\t=========================================================================================================================================\n");
				printf("\t\t\t\t\t\t| ID      |         NOMBRE           |POSICION          |N° DE CAMISETA  |         SUELDO       |CONFEDERACION        |ANIOS DE CONTRATO|\n");
				printf("\t\t\t\t\t\t=========================================================================================================================================\n");

				for (int j = 0; j < lenArrayPlayer; j++)
				{

					if (arrayPlayer[j].isEmpty == OCCUPIED && arrayPlayer[j].confederationId == arrayConfederation[i].idConfederation)
					{

						listOnePlayer(arrayPlayer[j], arrayConfederation, lenArrayConfederation);
					}

				}

			}

		}
		printf("\t\t\t\t\t\t=========================================================================================================================================\n");

	}


}
