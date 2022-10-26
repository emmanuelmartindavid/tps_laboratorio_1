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

int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer,
		sConfederation arrayConfederation[], int lenArrayConfederation) {

	int rtn = ERROR;
	char confederationDescription[50];
	char confederationDescription2[50];

	sPlayer auxSortPlayer;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL
			&& lenArrayConfederation > 0) {
		for (int i = 0; i < lenArrayPlayer - 1; i++) {
			for (int j = i + 1; j < lenArrayPlayer; j++) {

				if (arrayPlayer[i].isEmpty == OCCUPIED
						&& getConfederationDescription(arrayConfederation,
								lenArrayConfederation,
								arrayPlayer[i].confederationId,
								confederationDescription) == OK
						&& getConfederationDescription(arrayConfederation,
								lenArrayConfederation,
								arrayPlayer[j].confederationId,
								confederationDescription2) == OK) {

					if ((stricmp(confederationDescription,
							confederationDescription2)) > 0
							|| (stricmp(confederationDescription,
									confederationDescription2) == 0
									&& (stricmp(arrayPlayer[i].name,
											arrayPlayer[j].name)) > 0)) {

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

int listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer,
		sConfederation arrayConfederation[], int lenArrayConfederation) {

	int rtn = ERROR;
	int ammount = 0;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && arrayConfederation != NULL
			&& lenArrayConfederation > 0) {
		for (int j = 0; j < lenArrayConfederation; j++) {

			printf("\n\t\t\t\t\t\t\t\t\t\t\t\tCONFEDERACION: %s\n",
					arrayConfederation[j].confederationName);
			printf(
					"\t\t\t\t\t\t========================================================================================================================\n");
			printf(
					"\t\t\t\t\t\t|ID|         NOMBRE       |POSICION              |N° DE CAMISETA  |      SUELDO     |CONFEDERACION   |ANIOS DE CONTRATO|\n");
			printf(
					"\t\t\t\t\t\t------------------------------------------------------------------------------------------------------------------------\n");
			for (int i = 0; i < lenArrayPlayer; i++) {

				if (arrayPlayer[i].isEmpty == OCCUPIED) {

					if (arrayPlayer[i].confederationId== arrayConfederation[j].idConfederation
							&& listOnePlayer(arrayPlayer[i], arrayConfederation,
									lenArrayConfederation)==OK) {

						ammount++;
					}

				}

			}
			if (ammount > 0) {

				rtn = OK;
				printf(
						"\t\t\t\t\t\t========================================================================================================================\n");
			}

		}

	}

	return rtn;
}

int countPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayer) {

	int returnCountPlayers = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pCounterPlayer != NULL) {

		*pCounterPlayer = 0;
		for (int i = 0; i < lenArrayPlayer; i++) {

			if (arrayPlayer[i].isEmpty == OCCUPIED) {

				(*pCounterPlayer)++;

				returnCountPlayers = OK;

			}
		}

	}

	return returnCountPlayers;
}

int accumulateTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer,
		float *pAccumulatorSalary) {

	int returnaccumulateTotalSalary = ERROR;

	if (arrayPlayer != NULL && lenArrayPlayer > 0 && pAccumulatorSalary != NULL) {

		*pAccumulatorSalary = 0;
		for (int i = 0; i < lenArrayPlayer; i++) {

			if (arrayPlayer[i].isEmpty == OCCUPIED) {

				*pAccumulatorSalary += arrayPlayer[i].salary;

				returnaccumulateTotalSalary = OK;

			}

		}

	}

	return returnaccumulateTotalSalary;
}

int calculateAverageTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer,
		float *pAverageTotalSalary) {

	int returncalculateAverageTotalSalary = ERROR;
	int counterPlayer;
	float accumulatorSalary;

	if (arrayPlayer != NULL
			&& lenArrayPlayer
					> 0&& pAverageTotalSalary != NULL
					&& countPlayers(arrayPlayer, lenArrayPlayer, &counterPlayer) == OK
					&& accumulateTotalSalary(arrayPlayer, lenArrayPlayer, &accumulatorSalary)==OK) {

		for (int i = 0; i < lenArrayPlayer; i++) {

			if (arrayPlayer[i].isEmpty == OCCUPIED && counterPlayer > 0) {

				*pAverageTotalSalary = (float) accumulatorSalary
						/ counterPlayer;

				returncalculateAverageTotalSalary = OK;

			}
		}

	}

	return returncalculateAverageTotalSalary;
}

int countPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer,
		int *pCounterPlayerAboveAverageSalary) {

	float averageTotalSalary;

	int returncountPlayerAboveAverageSalary = ERROR;

	if (arrayPlayer != NULL
			&& lenArrayPlayer > 0&& pCounterPlayerAboveAverageSalary != NULL
			&& calculateAverageTotalSalary(arrayPlayer,
					lenArrayPlayer, &averageTotalSalary) == OK) {

		*pCounterPlayerAboveAverageSalary = 0;
		for (int i = 0; i < lenArrayPlayer; i++) {

			if (arrayPlayer[i].isEmpty == OCCUPIED && averageTotalSalary >= 0) {

				if (arrayPlayer[i].salary > averageTotalSalary) {

					(*pCounterPlayerAboveAverageSalary)++;

					returncountPlayerAboveAverageSalary = OK;
				}

			}
		}
	}

	return returncountPlayerAboveAverageSalary;
}


int accumulateHiringYearsByConfederationId(sPlayer arrayPlayer[],
		int lenArrayPlayer, int id, int *pAccumulatorHiringYears) {

	int returnaccumulateHiringYears = ERROR;

	if (arrayPlayer != NULL
			&& lenArrayPlayer > 0&& pAccumulatorHiringYears != NULL) {
		*pAccumulatorHiringYears=0;
		for (int i = 0; i < lenArrayPlayer; i++) {
			if (arrayPlayer[i].isEmpty == OCCUPIED
					&& arrayPlayer[i].confederationId == id) {

				*pAccumulatorHiringYears += arrayPlayer[i].hiringYears;

				returnaccumulateHiringYears = OK;

			}
		}

	}

	return returnaccumulateHiringYears;
}
int accumulateHiringYearsPerConfederation(sPlayer arrayPlayer[],
		int lenArrayPlayer, int *pAccumulatorConmebol, int *pAccumulatorUefa,
		int *pAccumulatorAfc, int *pAccumulatorCaf, int *pAccumulatorConcacaf,
		int *pAccumulatorOfc) {

	int returnaccumulateHiringYearsPerConfederation = ERROR;
	if (arrayPlayer != NULL
			&& lenArrayPlayer > 0 && pAccumulatorConmebol != NULL && pAccumulatorUefa != NULL
					&& pAccumulatorAfc != NULL && pAccumulatorCaf != NULL && pAccumulatorConcacaf!= NULL
					&& pAccumulatorOfc != NULL) {
		if (accumulateHiringYearsByConfederationId(arrayPlayer, lenArrayPlayer, 100, pAccumulatorConmebol)
		&& accumulateHiringYearsByConfederationId(arrayPlayer, lenArrayPlayer,101, pAccumulatorUefa)
		&& accumulateHiringYearsByConfederationId(arrayPlayer,lenArrayPlayer , 102, pAccumulatorAfc)
		&& accumulateHiringYearsByConfederationId(arrayPlayer,lenArrayPlayer, 103, pAccumulatorCaf)
		&& accumulateHiringYearsByConfederationId(arrayPlayer, lenArrayPlayer, 104, pAccumulatorConcacaf)
		&& accumulateHiringYearsByConfederationId(arrayPlayer,lenArrayPlayer, 105,pAccumulatorOfc)) {
			returnaccumulateHiringYearsPerConfederation = OK;
		}
	}
	return returnaccumulateHiringYearsPerConfederation;
}

int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[],
		int lenArrayPlayer) {

	int rtn = ERROR;
	int accumulatorConmebol = 0;
	int accumulatorUefa = 0;
	int accumulatorAfc = 0;
	int accumulatorCaf = 0;
	int accumulatorConcacaf = 0;
	int accumulatorOfc = 0;
	int maxYear = 0;

	if (arrayPlayer != NULL && lenArrayPlayer > 0) {

		accumulateHiringYearsPerConfederation(arrayPlayer, lenArrayPlayer,
				&accumulatorConmebol, &accumulatorUefa, &accumulatorAfc,
				&accumulatorCaf, &accumulatorConcacaf, &accumulatorOfc);

		if (accumulatorConmebol > maxYear) {
			maxYear = accumulatorConmebol;

		}
		if (accumulatorUefa > maxYear) {

			maxYear = accumulatorUefa;

		}
		if (accumulatorAfc > maxYear) {

			maxYear = accumulatorAfc;

		}
		if (accumulatorCaf > maxYear) {

			maxYear = accumulatorCaf;

		}
		if (accumulatorConcacaf > maxYear) {

			maxYear = accumulatorConcacaf;

		}
		if (accumulatorOfc > maxYear) {

			maxYear = accumulatorOfc;

		}

		rtn = OK;

	}
	printf("\n\t\t\t\t\t\t\t\t %d.\n\n",
				accumulatorConmebol);
		printf("\n\t\t\t\t\t\t\t\t %d.\n\n",accumulatorUefa);
		printf("\n\t\t\t\t\t\t\t\t %d.\n\n", accumulatorAfc);
		printf("\n\t\t\t\t\t\t\t\t %d.\n\n", accumulatorCaf);
		printf("\n\t\t\t\t\t\t\t\t %d.\n\n",
				accumulatorConcacaf);
		printf("\n\t\t\t\t\t\t\t\t%d.\n\n", accumulatorOfc);
	return rtn;
}

