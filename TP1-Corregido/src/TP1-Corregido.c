/*
 ============================================================================
 Name        : TP1-Corregido.c
 Author      : EMMANUEL MARTIN - LABO - 1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "validaciones.h"
#include "calculos.h"
#include "menus.h"
#define SUCCESS 1
#define ERROR -1

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
	float afcAverage = 0;
	float cafAverage = 0;
	float concacafAverage = 0;
	float conmebolAverage = 0;
	float uefaAverage = 0;
	float ofcAverage = 0;
	float incrementedTotalPrice;
	int flagCalculate;
	float incrementedPrice;

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
					flagCalculate = 0;
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
						if ((utn_getNumber(&optionPlayers, "\nIngrese opcion\n", "\nOpcion incorrecta\n ", 1, 4, 3) != 0))
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
							}
							else
							{
								flagCalculate = 0;
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
				break;
			case 3:
				if ((lodginPrice == 0 || foodPrice == 0 || transportPrice == 0) || counterTotalPlayers == 0)
				{
					printf("\t\t\t\t\t\t\t\t\tPRIMERO DEBE INGRESAR TODOS LOS COSTOS Y AL MENOS UN JUGADOR.\n");
				}
				else
				{
					if (calculateAveragePlayersPerConfederation(afcCounter, counterTotalPlayers, &afcAverage) == SUCCESS && calculateAveragePlayersPerConfederation(cafCounter, counterTotalPlayers, &cafAverage) == SUCCESS
									&& calculateAveragePlayersPerConfederation(concacafCounter, counterTotalPlayers, &concacafAverage) == SUCCESS && calculateAveragePlayersPerConfederation(conmebolCounter, counterTotalPlayers, &conmebolAverage) == SUCCESS
									&& calculateAveragePlayersPerConfederation(uefaCounter, counterTotalPlayers, &uefaAverage) == SUCCESS && calculateAveragePlayersPerConfederation(ofcCounter, counterTotalPlayers, &ofcAverage) == SUCCESS)
					{
						if (calculateTotalCost(lodginPrice, foodPrice, transportPrice, &totalPrice) == SUCCESS)
						{
							printf("\t\t\t\t\t\t\t\tSE REALIZARON LOS CALCULOS CORRECTAMENTE.\n\n");
						}
						if (uefaAverage > afcAverage && uefaAverage > cafAverage && uefaAverage > concacafAverage && uefaAverage > conmebolAverage && uefaAverage > ofcAverage)
						{
							calculatePriceIncremented(totalPrice, &incrementedTotalPrice);
							incrementedPrice = totalPrice * 0.35;
						}
						flagCalculate = 1;
					}
				}
				break;
			case 4:
				if (flagCalculate == 1)
				{
					printf("\t\t\t\t\t\t\t\t\t\tINFORMES\n\n");
					reportAverageMenu(afcAverage, cafAverage, concacafAverage, conmebolAverage, uefaAverage, ofcAverage);

					if (uefaAverage > afcAverage && uefaAverage > cafAverage && uefaAverage > concacafAverage && uefaAverage > conmebolAverage && uefaAverage > ofcAverage)
					{

						printf("\t\t\t\t\t\tEL COSTO DE MANTENIMIENTO ERA DE $%.2f Y RECIBIO UN AUMENTO DE $%.2f. SU NUEVO VALOR ES DE $%.2f\n\n", totalPrice, incrementedPrice, incrementedTotalPrice);
					}
					else
					{
						printf("\t\t\t\t\t\t\t\t\tCOSTO DE MANTENIMIENTO $%.2f\n\n", totalPrice);
					}
				}
				else
				{
					printf("t\t\t\t\t\t\t\t\tPRIMERO DEBE REALIZAR LOS CALCULOS\n");
				}
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

