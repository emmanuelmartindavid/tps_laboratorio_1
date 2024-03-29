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
/// @brief calculateTotalCost				CALCULA COSTOS DE MANTENIMIENTO.
///
/// @param lodginPrice						FLOTANTE.
/// @param foodPrice						FLOTANTE.
/// @param transportPrice					FLOTANTE.
/// @param pResult
/// @return									RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
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
/// @brief calculatePriceIncremented		CALCULA PRECIO INCREMENTADO DE MANTENIMIENTO.
///
/// @param totalPrice						FLOTANTE.
/// @param pResult							PUNTERO FLOTANTE.
/// @return									RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
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
/// @brief countPlayersOrConfederation		CUENTA JUGADORES O CONFEDERACIONES SEGUN CRITERIO PASADO POR PARAMETRO.
///
/// @param pCounter							PUNTERO ENTERO.
/// @param max								ENTERO
/// @return									RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
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
/// @brief calculateAveragePlayersPerConfederation		CALCULA PROMEDIO SEGUN PARAMETROS.
///
/// @param confederationCounter					ENTERO
/// @param playerCounter						ENTERO
/// @param pResult								PUNTERO FLOTANTE.
/// @return										RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
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
/// @brief disccountCounter					DESCUENTA CONTADOR SEGUN CRITERIO PASADO POR PARAMETRO.
///
/// @param counter							PUNTERO ENTERO.
/// @param pFlag							PUNTERO ENTERO.
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
