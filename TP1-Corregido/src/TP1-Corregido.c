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

void mainMenu(float lodginPrice, float foodPrice, float transportPrice, int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter);
void costsMenu(float lodginPrice, float foodPrice, float transportPrice);
void playersMenu(int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter);
void conferationMenu(int afcCounter, int cafCounter, int concacafCounter, int conmebolCounter, int uefaCounter, int ofcCounter);
void disccountCounter(int *counter, int *pFlag);
int countPlayersOrConfederation(int *pCounter, int max);
int main(void)
{
	setbuf(stdout, NULL);
	int options;
	int optionCost;
	int optionPlayers;
	float lodginPrice = 0;
	float foodPrice = 0;
	float transportPrice = 0;
	int goalkeeperCounter = 0;
	int defenderCounter = 0;
	int midfielderCounter = 0;
	int strikerCounter = 0;
	int afcCounter = 0;
	int cafCounter = 0;
	int concacafCounter = 0;
	int conmebolCounter = 0;
	int uefaCounter = 0;
	int ofcCounter = 0;
	int shirtNumber;
	int flagSubstracCounter = 0;
	int optionConfederation;
	int flagMax = 0;
	float totalPrice;
	int counterTotalPlayers = 0;
	float afcAverage;
	float cafAverage;
	float concacafAverage;
	float conmebolAverage;
	float uefaAverage;
	float ofcAverage;
	float incrementedTotalPrice;

	do
	{
		mainMenu(lodginPrice, foodPrice, transportPrice, goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
		if (utn_getNumber(&options, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 5, 3) == 0)
		{

			switch (options)
			{

			case 1:
				costsMenu(lodginPrice, foodPrice, transportPrice);
				if (utn_getNumber(&optionCost, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 5, 3) == 0)
				{
					switch (optionCost)
					{

					case 1:
						if (utn_getNumberFloat(&lodginPrice, "Ingrese costo de hospedaje. Desde $1000\n", "Ingrese precio valido\n", 1000, 10000000, 3) == 0)
						{
							printf("CARGA CORRECTA.\n");
						}
						else
						{
							printf("DATO INVALIDO. REINTENTE. \n");
						}
						break;
					case 2:
						if (utn_getNumberFloat(&foodPrice, "Ingrese costo de comida. Desde $1000\n", "Ingrese precio valido\n", 1000, 10000000, 3) == 0)
						{
							printf("CARGA CORRECTA.\n");
						}
						else
						{
							printf("DATO INVALIDO. REINTENTE. \n");
						}
						break;
					case 3:
						if (utn_getNumberFloat(&transportPrice, "Ingrese costo de transporte. Desde $1000\n", "Ingrese precio valido\n", 1000, 10000000, 3) == 0)
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
					if (utn_getNumber(&shirtNumber, "\nIngrese numero de camiseta. Solo entre el 1 y el 99\n", "\nOpcion incorrecta\n", 1, 99, 3) != 0)
					{
						printf("DATO INVALIDO. REINTENTE. \n");
						break;
					}
					else
					{
						playersMenu(goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
						if ((utn_getNumber(&optionPlayers, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 5, 3) != 0))
						{
							printf("DATO INVALIDO. REINTENTE. \n");
							break;
						}
						else
						{
							flagMax = 0;
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
									flagMax = 1;
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
									flagMax = 1;

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
									flagMax = 1;
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
									flagMax = 1;
								}
								break;
							}
						}

						if (flagMax == 0)
						{
							conferationMenu(afcCounter, cafCounter, concacafCounter, conmebolCounter, uefaCounter, ofcCounter);
							if (utn_getNumber(&optionConfederation, "\nIngrese su confederacion. Solo entre el 1 y el 5\n", "\nOpcion incorrecta\n", 1, 6, 3) != 0)
							{
								flagSubstracCounter = 1;
								if (optionPlayers == 1)
								{
									disccountCounter(&goalkeeperCounter, &flagSubstracCounter);
								}
								if (optionPlayers == 2)
								{
									disccountCounter(&defenderCounter, &flagSubstracCounter);
								}
								if (optionPlayers == 3)
								{
									disccountCounter(&midfielderCounter, &flagSubstracCounter);
								}
								if (optionPlayers == 4)
								{
									disccountCounter(&strikerCounter, &flagSubstracCounter);
								}
								printf("DATO INVALIDO. REINTENTE. \n");
								break;
							}
							else
							{
								counterTotalPlayers++;
								switch (optionConfederation)
								{
								case 1:
									afcCounter++;
									break;
								case 2:
									cafCounter++;
									break;
								case 3:
									concacafCounter++;
									break;
								case 4:
									conmebolCounter++;
									break;
								case 5:
									uefaCounter++;
									break;
								case 6:
									ofcCounter++;
									break;
								}
							}
						}
					}
				}
				else
				{
					printf("\t\t\t\t\t\t\t\t\tYA REALIZO LA CARGA DE JUGADORES\n\n");
				}
				printf(" CONTADOR %d", counterTotalPlayers);
				break;
			case 3:

				if (lodginPrice == 0 || foodPrice == 0 || transportPrice == 0)
				{
					if (goalkeeperCounter == 0 || defenderCounter == 0 || midfielderCounter == 0 || strikerCounter == 0)
					{
						printf("\t\t\t\t\t\t\t\t\tPRIMERO DEBE INGRESAR TODOS LOS COSTOS Y AL MENOS UN JUGADOR.\n");
					}
					else
					{
						if (calculateAveragePlayersPerConfederation(afcCounter, counterTotalPlayers, &afcAverage) == SUCCESS && calculateAveragePlayersPerConfederation(cafCounter, counterTotalPlayers, &cafAverage) == SUCCESS
										&& calculateAveragePlayersPerConfederation(concacafCounter, counterTotalPlayers, &concacafAverage) == SUCCESS && calculateAveragePlayersPerConfederation(conmebolCounter, counterTotalPlayers, &conmebolAverage) == SUCCESS
										&& calculateAveragePlayersPerConfederation(uefaCounter, counterTotalPlayers, &uefaAverage) == SUCCESS && calculateAveragePlayersPerConfederation(ofcCounter, counterTotalPlayers, &ofcAverage) == SUCCESS)

							if (calculateTotalCost(lodginPrice, foodPrice, transportPrice, &totalPrice) == SUCCESS)
							{
								printf("\t\tSE REALIZARON LOS CALCULOS CORRECTAMENTE.\n\n");
							}
						if (uefaAverage > 0.5)
						{
							calculatePriceIncremented(totalPrice, &incrementedTotalPrice);
						}
					}
				}

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

void mainMenu(float lodginPrice, float foodPrice, float transportPrice, int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter)
{

	printf("\t\t\t\t\t\t\t=============================MENU-PRINCIPAL=============================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. CARGA DE COSTOS DE MANTENIMIENTO.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  COSTO DE HOSPEDAJE -> $%.2f.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  COSTO DE COMIDA -> $%.2f.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  COSTO DE TRANSPORTE -> $%.2f.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. CARGA DE JUGADORES.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  ARQUEROS -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  DEFENSORES -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  MEDIOCAMPISTAS -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  DELANTEROS -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. REALIZAR TODOS LOS CALCULOS\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 4. INFORMAR RESULTADOS.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 5. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
					"\t\t\t\t\t\t\t=========================================================================\n", lodginPrice, foodPrice, transportPrice, goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
}

void costsMenu(float lodginPrice, float foodPrice, float transportPrice)
{

	printf("\t\t\t\t\t\t\t=============================MENU-COSTOS================================="
					"\n\t\t\t\t\t\t\t|\t\t1. INGRESAR COSTO DE HOSPEDAJE -> $%.2f.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t2. INGRESAR COSTO DE COMIDA -> $%.2f.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t3. INGRESAR COSTO DE TRANSPORTE -> $%.2f.\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n", lodginPrice, foodPrice, transportPrice);

}

void playersMenu(int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter)
{
	printf("\t\t\t\t\t\t\t============================MENU-JUGADORES==============================="
					"\n\t\t\t\t\t\t\t|\t\t\t1.  ARQUERO -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t2.  DEFENSOR -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t3.  MEDIOCAMPISTA -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t4.  DELANTERO -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n", goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
}

void conferationMenu(int afcCounter, int cafCounter, int concacafCounter, int conmebolCounter, int uefaCounter, int ofcCounter)
{
	printf("\t\t\t\t\t\t\t============================MENU-CONFEDERACIONES========================="
					"\n\t\t\t\t\t\t\t|\t\t\t1.  AFC -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t2.  CAF -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t3.  CONCACAF -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t4.  CONMEBOL -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t5.  UEFA -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t6.  OFC -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n", afcCounter, cafCounter, concacafCounter, conmebolCounter, uefaCounter, ofcCounter);
}

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
	if (pFlag != NULL)
	{
		if (*pFlag == 1)
		{
			(*counter)--;
		}
	}
}
