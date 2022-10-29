/*
 ============================================================================
 Name        : TP1-Corregido.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#define SUCCESS 1
#define ERROR -1

void menu(float priceLodgin, float priceFood, float priceTransport, int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter);
void menuCost(float priceLodgin, float priceFood, float priceTransport);
void menuPlayers(int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter);
int countPlayersOrConfederation(int *pCounter, int max);
int main(void)
{
	setbuf(stdout, NULL);
	int options;
	int optionCost;
	int optionPlayers;
	float priceFood = 0;
	float priceLodgin = 0;
	float priceTransport = 0;
	int goalkeeperCounter = 0;
	int defenderCounter = 0;
	int midfielderCounter = 0;
	int strikerCounter = 0;

	do
	{
		menu(priceLodgin, priceFood, priceTransport, goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
		if (utn_getNumber(&options, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 5, 3) == 0)
		{

			switch (options)
			{

			case 1:
				menuCost(priceLodgin, priceFood, priceTransport);
				if (utn_getNumber(&optionCost, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 5, 3) == 0)
				{
					switch (optionCost)
					{

					case 1:
						if (utn_getNumberFloat(&priceLodgin, "Ingrese costo de hospedaje. Desde $1000\n", "Ingrese precio valido\n", 1000, 10000000, 3) == 0)
						{
							printf("CARGA CORRECTA.\n");
						}
						else
						{
							printf("DATO INVALIDO. REINTENTE. \n");
						}
						break;
					case 2:
						if (utn_getNumberFloat(&priceFood, "Ingrese costo de comida. Desde $1000\n", "Ingrese precio valido\n", 1000, 10000000, 3) == 0)
						{
							printf("CARGA CORRECTA.\n");
						}
						else
						{
							printf("DATO INVALIDO. REINTENTE. \n");
						}
						break;
					case 3:
						if (utn_getNumberFloat(&priceTransport, "Ingrese costo de transporte. Desde $1000\n", "Ingrese precio valido\n", 1000, 10000000, 3) == 0)
						{
							printf("CARGA CORRECTA.\n");
						}
						else
						{
							printf("DATO INVALIDO. REINTENTE. \n");
						}
						break;

					}
				}
				else
				{
					printf("DATO INVALIDO. REINTENTE. \n");
				}
				break;
			case 2:
				if (goalkeeperCounter != 2 || defenderCounter != 8 || midfielderCounter != 8 || strikerCounter != 4)
				{
					menuPlayers(goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
					if (utn_getNumber(&optionPlayers, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 5, 3) == 0)
					{

						switch (optionPlayers)
						{

						case 1:
							if (countPlayersOrConfederation(&goalkeeperCounter, 2) == SUCCESS)
							{
								printf("CARGA CORRECTA.\n");
							}
							else
							{
								printf("NO MAS DE 2 ARQUEROS.\n");
							}
							break;
						case 2:
							if (countPlayersOrConfederation(&defenderCounter, 8) == SUCCESS)
							{
								printf("CARGA CORRECTA.\n");
							}
							else
							{
								printf("NO MAS DE 8 DEFENSORES.\n");
							}
							break;
						case 3:
							if (countPlayersOrConfederation(&midfielderCounter, 8) == SUCCESS)
							{
								printf("CARGA CORRECTA.\n");
							}
							else
							{
								printf("NO MAS DE 8 MEDIOCAMPISTAS.\n");
							}
							break;
						case 4:
							if (countPlayersOrConfederation(&strikerCounter, 4) == SUCCESS)
							{
								printf("CARGA CORRECTA.\n");
							}
							else
							{
								printf("NO MAS DE 4 DELANTEROS.\n");
							}
							break;
						}
					}
					else
					{
						printf("DATO INVALIDO. REINTENTE. \n");
					}
				}
				else
				{
					printf("\t\tYa realizo la carga de jugadores\n\n");
				}
				break;
			case 3:

				break;
			case 4:

				break;
			case 5:
				break;
			}
		}
		else
		{
			printf("\t\tAlgo salió mal.\n\n");
			break;
		}

	} while (options != 5);

	return EXIT_SUCCESS;
}

void menu(float priceLodgin, float priceFood, float priceTransport, int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter)
{

	printf("\t\t MENU PRINCIPAL\n"
					"1. Carga de los costos de Mantenimiento\n"
					" Costo de Hospedaje -> $%.2f\n"
					" Costo de Comida -> $%.2f\n"
					" Costo de Transoporte -> $%.2f\n\n"
					"2. Carga de Jugadores\n"
					" Arqueros -> %d\n"
					" Defensores -> %d\n"
					" Mediocampistas -> %d\n"
					" Delanteros -> %d\n\n"
					"3. Realizar todos los calculos\n\n"
					"4. Informar resultados\n\n"
					"5. Salir", priceLodgin, priceFood, priceTransport, goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);

}

void menuCost(float priceLodgin, float priceFood, float priceTransport)
{

	printf("1. Ingresar costo hospedaje -> $%.2f\n"
					"2. Ingresar costo de comida -> $%.2f\n"
					"3. Ingresar costo de transporte-> $%.2f\n", priceLodgin, priceFood, priceTransport);

}

void menuPlayers(int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter)
{

	printf("1. Arquero -> %d\n"
					"2. Defensor -> %d\n"
					"3. Mediocampista -> %d\n"
					"4. Delantero -> %d\n\n", goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);

}

float calculateTotalCost(float priceLodgin, float priceFood, float priceTransport)
{

	float result;

	result = priceLodgin + priceFood + priceTransport;

	return result;
}

float calculatePriceIncremented(float totalPrice)
{

	float result;

	result = totalPrice + (totalPrice * 0.35);

	return result;

}

int countPlayersOrConfederation(int *pCounter, int max)
{

	int returnCountPlayers;
	if (*pCounter < max)
	{

		(*pCounter)++;
		returnCountPlayers = SUCCESS;

	}
	else
	{

		returnCountPlayers = ERROR;
	}

	return returnCountPlayers;
}

float calculateAveragePlayersPerConfederation(int confederationCounter, int playerCounter)
{

	float result;

	if (playerCounter > 0)
	{
		result = (float) confederationCounter / playerCounter;
	}
	else
	{
		result = ERROR;
	}
	return result;
}