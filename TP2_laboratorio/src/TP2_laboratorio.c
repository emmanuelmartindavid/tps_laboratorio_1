/*
 ============================================================================
 Name        : TP2_laboratorio.c
 Author      :   EMMANUEL MARTIN. 1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "validaciones.h"
#include "informes.h"
#define LEN_ARRAYPLAYERS 3000
#define LEN_ARRAYCONFEDERATION 6

int main(void)
{

	setbuf(stdout, NULL);
	sConfederation arrayConfederation[LEN_ARRAYCONFEDERATION];
	sPlayer arrayPlayer[LEN_ARRAYPLAYERS];
	int idPlayer = 1;
	int idConfederation = 100;
	int option = 0;
	char exit[3];
	int returnRegisterPlayer;
	int returnMainMenu;
	int returnReportMenu;
	int optionReports;
	int flagRegisterOrDownPlayer;
	int arrayAccumulatorPlayers[LEN_ARRAYCONFEDERATION];

	initializeArrayPlayer(arrayPlayer, LEN_ARRAYPLAYERS);

	initializeArrayConfederation(arrayConfederation, LEN_ARRAYCONFEDERATION);

	//DESCOMENTAR EN CASO DE QUERER USAR HARCODEO DE JUGADORES.
	hardCodePlayers(arrayPlayer, LEN_ARRAYPLAYERS, 24, &idPlayer);

	hardCodeConfederations(arrayConfederation, LEN_ARRAYCONFEDERATION, 6, &idConfederation);

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
				returnRegisterPlayer = registerPlayer(arrayPlayer, LEN_ARRAYPLAYERS, &idPlayer, arrayConfederation, LEN_ARRAYCONFEDERATION);
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
				validateRegisterOrDownPlayer(arrayPlayer, LEN_ARRAYPLAYERS, &flagRegisterOrDownPlayer);
				if (flagRegisterOrDownPlayer == OK)
				{
					sortPerIdPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
					listPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);

					if (downPlayer(arrayPlayer, LEN_ARRAYPLAYERS) == OK)
					{
						printf("\t\t\t\t\t\t\t\tSU JUGADOR FUE DADO DE BAJA CORRECTAMENTE\n");
					}
					else
					{
						printf("\t\t\t\t\t\t\t\tBAJA DE JUGADOR CANCELADA\n");
					}

				}
				else
				{
					printf("\t\t\t\t\t\t\t\tNADA PARA DAR DE BAJA. PRIMERO DEBE DAR DE ALTA UN JUGADOR\n\n");
				}

				break;
			case 3:
				printf("\t\t\t\t\t\t\t\t\t\tMODIFICAR JUGADOR\n\n");
				validateRegisterOrDownPlayer(arrayPlayer, LEN_ARRAYPLAYERS, &flagRegisterOrDownPlayer);
				if (flagRegisterOrDownPlayer == OK)
				{
					sortPerIdPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
					listPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);

					if (modifyPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION) == OK)
					{
						printf("\t\t\t\t\t\t\t\t\t\tMODIFICACION EXITOSA\n");
					}
					else
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
				validateRegisterOrDownPlayer(arrayPlayer, LEN_ARRAYPLAYERS, &flagRegisterOrDownPlayer);
				if (flagRegisterOrDownPlayer == OK)
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
								sortPerConfederationAndPlayerName(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
								listPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
								break;
							case 2:
								listConfederationPerPlayers(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
								break;
							case 3:
								listTotalSalary(arrayPlayer, LEN_ARRAYPLAYERS);
								listAverageTotalSalary(arrayPlayer, LEN_ARRAYPLAYERS);
								listPlayerAboveAverageSalary(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION);
								break;
							case 4:
								listMaximusHiringYearsConfederation(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION, arrayAccumulatorPlayers);
								break;
							case 5:
								listPercentagePlayersPerConfederation(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION, arrayAccumulatorPlayers);
								break;
							case 6:
								listMaximusPlayersPerRegion(arrayPlayer, LEN_ARRAYPLAYERS, arrayConfederation, LEN_ARRAYCONFEDERATION, arrayAccumulatorPlayers);
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

				utn_getDescriptionExit(exit, "\t\t\t\t\t\t\tPresione si para salir. Presione no para continuar en el menu.\n", "\t\t\t\t\t\t\tError. Solo si o no.\n", 3);
				break;
			}
		}
		else if (returnMainMenu == -1)
		{
			printf("\n\t\t\t\t\t\t\t\t¡¡ALGO SALIO MAL. INGRESE LOS DATOS DE FORMA CORRECTA!!");
			break;
		}
	} while (stricmp(exit, "si") != 0);

	printf("\n\t\t\t\t\t\t\t\t\t\t¡¡HASTA LUEGO!!\n");

	return EXIT_SUCCESS;
}

