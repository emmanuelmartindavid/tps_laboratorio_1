/*
 * calculos.c
 *
 *  Created on: 17 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#define SUCCESS 1
#define ERROR -1

int calculateTotalCost(float lodginPrice, float foodPrice, float transportPrice, float *pResult)
{
	int returnCalculateTotalCost = ERROR;
	if (pResult != NULL)
	{
		*pResult = lodginPrice + foodPrice + transportPrice;
		returnCalculateTotalCost = SUCCESS;
	}
	return returnCalculateTotalCost;
}

int calculatePriceIncremented(float totalPrice, float *pResult)
{
	int returnCalculatePriceIncremented = ERROR;
	if (pResult != NULL)
	{
		*pResult = (totalPrice * 1.35);
		returnCalculatePriceIncremented = SUCCESS;
	}
	return returnCalculatePriceIncremented;
}

int countPlayersOrConfederation(int *pCounter, int max)
{
	int returnCountPlayers = ERROR;
	if (pCounter != NULL)
	{
		if (*pCounter < max)
		{
			(*pCounter)++;
			returnCountPlayers = SUCCESS;
		}
	}
	return returnCountPlayers;
}

int calculateAveragePlayersPerConfederation(int confederationCounter, int playerCounter, float *pResult)
{
	int returnCalculateAveragePlayersPerConfederation = ERROR;
	if (playerCounter > 0 && pResult != NULL)
	{
		*pResult = (float) confederationCounter / playerCounter;
		returnCalculateAveragePlayersPerConfederation = SUCCESS;
	}
	return returnCalculateAveragePlayersPerConfederation;
}

void disccountCounter(int *counter, int *pFlag)
{
	if (counter != NULL && pFlag != NULL)
	{
		if (*pFlag == 1)
		{
			(*counter)--;
		}
	}
}
