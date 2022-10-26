/*
 ============================================================================
 Name        : TP2_laboratorio.c
 Author      : 
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "jugador.h"
#include "informes.h"

#define LEN_ARRAYPLAYERS 3000
#define LEN_ARRAYCONFEDERATION 6

int main(void)
{

	setbuf(stdout, NULL);
	sConfederation arrayConfederation[LEN_ARRAYCONFEDERATION];
	sPlayer arrayPlayer[LEN_ARRAYPLAYERS];

	int pNextId = 30;
	int pNextIdConfederation = 100;
	int option = 0;
	char exit[3];
	int returnRegisterPlayer;
	int returnDownPlayer;
	int returnModifyPlayer;
	int returnsortPlayers;
	int returnListPlayers;
	int returnMainMenu;
	int returnReportMenu;
	int returnExit;
	int optionReports;
	float totalSalary;
	float averageSalary;
	int playersAboveAverageSalary;
	int arrayAccumulatorHiringYears[LEN_ARRAYCONFEDERATION];
	int maximusHiringYears;
	float percentagePerConfederation[LEN_ARRAYCONFEDERATION];

	initializeArrayPlayer(arrayPlayer, LEN_ARRAYPLAYERS);

	hardCodePlayers(arrayPlayer, LEN_ARRAYPLAYERS, 27, &pNextId);

	hardCodeConfederations(arrayConfederation, LEN_ARRAYCONFEDERATION, 6, &pNextIdConfederation);

	do
	{
		showMainMenu();
		returnMainMenu = utn_getNumber(&option, "\t\t\t\t\t\t\t\t\t\tINGRESE OPCION.\n", "Ingrese opcion valida\n", 0, 10, 3);
		if (returnMainMenu == 0)
		{
			switch (option)
			{
			case 1:
				printf("\t\t\t\t\t\t\t\t\t\t\tALTA DE JUGADOR\n\n");
				returnRegisterPlayer = registerPlayer(arrayPlayer,
				LEN_ARRAYPLAYERS, arrayConfederation,
				LEN_ARRAYCONFEDERATION);
				if (returnRegisterPlayer == OK)
				{

					printf("\t\t\t\t\t\t\t\t\tSU JUGADOR FUE DADO DE ALTA CORRECTAMENTE\n\n");

				}
				else if (returnRegisterPlayer == ERROR)
				{
					printf("\t\t\t\t\t\t\t\tNO HAY ESPACIO PARA DAR ALTAS\n\n");
				}
				else if (returnRegisterPlayer == -2)
				{
					printf("\t\t\t\t\t\t\t\tDATOS INVALIDOS. REINTENTE.\n");
				}
				break;
			case 2:
				printf("\t\t\t\t\t\t\t\t\t\tBAJA JUGADOR\n\n");
				returnsortPlayers = sortPerIdPlayers(arrayPlayer,
				LEN_ARRAYPLAYERS, arrayConfederation,
				LEN_ARRAYCONFEDERATION);
				returnListPlayers = listPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation,
				LEN_ARRAYCONFEDERATION);
				if (returnListPlayers == OK && returnsortPlayers == OK)
				{

					returnDownPlayer = downPlayer(arrayPlayer,
					LEN_ARRAYPLAYERS);

					if (returnDownPlayer == OK)
					{
						printf("\t\t\t\t\t\t\t\tSU JUGADOR FUE DADO DE BAJA CORRECTAMENTE\n");

					}
					else if (returnDownPlayer == ERROR)
					{
						printf("\t\t\t\t\t\t\t\tBAJA DE JUGADOR CANCELADA\n");

					}
					else if (returnDownPlayer == -2)
					{
						printf("\t\t\t\t\t\t\t\tDATOS INVALIDOS. REINTENTE.\n");

					}

				}
				else
				{

					printf("\t\t\t\t\t\t\t\tNADA PARA DAR DE BAJA. PRIMERO DEBE DAR DE ALTA UN JUGADOR\n\n");

				}

				break;
			case 3:
				printf("\t\t\t\t\t\t\t\t\t\tMODIFICAR JUGADOR\n\n");
				returnsortPlayers = sortPerIdPlayers(arrayPlayer,
				LEN_ARRAYPLAYERS, arrayConfederation,
				LEN_ARRAYCONFEDERATION);
				returnListPlayers = listPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
				if (returnListPlayers == OK && returnsortPlayers == OK)
				{

					returnModifyPlayer = modifyPlayers(arrayPlayer,
					LEN_ARRAYPLAYERS, arrayConfederation,
					LEN_ARRAYCONFEDERATION);

					if (returnModifyPlayer == OK)
					{
						printf("\t\t\t\t\t\t\t\t\t\tMODIFICACION EXITOSA\n");
					}
					else if (returnModifyPlayer == -2)
					{
						printf("\t\t\t\t\t\t\t\tDATOS INVALIDOS. REINTENTE.\n");
					}
				}
				else
				{
					printf("\t\t\t\t\t\t\t\tNADA PARA MODIFICAR. PRIMERO DEBE DAR DE ALTA UN JUGADOR\n\n");
				}

				break;
			case 4:

				if (returnRegisterPlayer == OK)
				{
					do
					{
						showReportMenu();
						returnReportMenu = utn_getNumber(&optionReports, "\t\t\t\t\t\tINGRESE OPCION.\n", "Opcion invalida", 1, 7, 3);

						if (returnReportMenu == 0)
						{

							switch (optionReports)
							{
							case 1:

								sortPerConfederationAndPlayerName(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								listPlayers(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);

								break;
							case 2:
								if (listConfederationPerPlayers(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION) == OK)
								{

								}
								break;
							case 3:
								sortPerIdPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								listPlayers(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								accumulateTotalSalary(arrayPlayer,
								LEN_ARRAYPLAYERS, &totalSalary);
								calculateAverageTotalSalary(arrayPlayer,
								LEN_ARRAYPLAYERS, &averageSalary);
								countPlayerAboveAverageSalary(arrayPlayer,
								LEN_ARRAYPLAYERS, &playersAboveAverageSalary);

								printf("\n\t\t\t\t\t\tEL TOTAL DE SALARIOS ES: $%.2f.\n"
										"\n\t\t\t\t\t\tEL PROMEDIO TOTAL DE SALARIO ES: $%.2f.\n"
										"\n\t\t\t\t\t\t%d JUGADORES COBRAN MAS DEL SALARIO PROMEDIO.\n\n", totalSalary, averageSalary, playersAboveAverageSalary);

								break;
							case 4:
								sortPerConfederationAndPlayerName(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								listPlayers(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								calculateMaximusHiringYearsConfederation(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION, &maximusHiringYears, arrayAccumulatorHiringYears);

								for (int i = 0; i < LEN_ARRAYCONFEDERATION; i++)
								{

									if (arrayAccumulatorHiringYears[i] == maximusHiringYears)
									{

										printf("\n\t\t\t\t\t\tLA CONFEDERACION CON MAS ANIOS DE CONTRATO ES %s."
												"\n\t\t\t\t\t\tCUENTA CON ANIOS %d\n", arrayConfederation[i].confederationName, maximusHiringYears);

									}

								}

								break;
							case 5:
								sortPerConfederationAndPlayerName(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								listPlayers(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION);
								accumulatePlayersPerConfederation(arrayPlayer,
								LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION, arrayAccumulatorHiringYears);
								calculatePorcentagePlayersPerConfederation(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation,
								LEN_ARRAYCONFEDERATION, percentagePerConfederation, arrayAccumulatorHiringYears);
								for (int i = 0; i < LEN_ARRAYCONFEDERATION; i++)
								{

									printf("\n\t\t\t\t\t\tLA CONFEDERACION %s."
											"\n\t\t\t\t\t\tCUENTA CON UN %% %.2f DE JUGADORES\n", arrayConfederation[i].confederationName, percentagePerConfederation[i]);

								}

								break;
							case 6:

								showMaximusPlayersPerRegion(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION, arrayAccumulatorHiringYears);

								break;

							}
						}
						else if (returnReportMenu == -1)
						{
							printf("\t\t\t\t\t\t\t\tDATOS INVALIDOS. REINTENTE.\n");

							break;
						}

					} while (optionReports != 7 || returnReportMenu != 0);
				}
				else
				{
					printf("\t\t\t\t\t\t\tNADA PARA MOSTRAR. PRIMERO DEBE PRIMERO DEBE DAR DE ALTA AL MENOS UN JUGADOR\n");
				}

				break;

			case 5:

				returnExit = utn_getDescriptionExit(exit, "\t\t\t\t\t\t\tPresione si para salir. Presione no para continuar en el menu.\n", "\t\t\t\t\t\t\tError. Solo si o no.\n", 3);
				break;
			}
		}
		else if (returnMainMenu == -1 || returnExit == -1)
		{
			printf("\n\t\t\t\t\t\t\t\t¡¡ALGO SALIO MAL. INGRESE LOS DATOS DE FORMA CORRECTA!!");

			break;
		}

	} while (stricmp(exit, "si") != 0 || returnExit != 0);

	printf("\n\t\t\t\t\t\t\t\t\t\t¡¡HASTA LUEGO!!\n");

	return EXIT_SUCCESS;
}
