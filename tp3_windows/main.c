#include <stdio.h>
#include <stdlib.h>
#include "LinkedList.h"
#include "Controller.h"
#include "Jugador.h"
#include "validaciones.h"
#include "menus.h"
#include "string.h"

int main()
{
	setbuf(stdout, NULL);
	int option = 0;
	int flagLoadPlayerFromTextAndBinary = 0;
	int returnRemovePlayer;
	int returnCallUpPlayers;
	char exit[3];
	LinkedList *listPLayers = ll_newLinkedList();
	LinkedList *listNationalTeam = ll_newLinkedList();

	do
	{
		showMainMenu();
		if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 11, 3) == 0)
		{
			switch (option)
			{
			case 1:
				if (flagLoadPlayerFromTextAndBinary == 0)
				{
					if (controllerLoadPlayerFromText("jugadores.csv", listPLayers) == SUCCESS && controllerLoadNationalTeamFromText("selecciones.csv", listNationalTeam) == SUCCESS)
					{
						flagLoadPlayerFromTextAndBinary = 1;
						printf("Archivo de texto cargado correctamente.\n");

					}
					else
					{
						printf("Error al cargar el archivo.\n");
					}
				}
				else
				{
					printf("Ya realizo la carga de jugadores.\n");
				}
				break;
			case 2:
				if (flagLoadPlayerFromTextAndBinary == 1)
				{
					if (controllerAddPlayer(listPLayers) == SUCCESS)
					{

						printf("Alta exitosa.\n");
					}
					else
					{
						printf("DATOS INVALIDOS. REINTENTE\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHVIVOS DE TEXTO.\n");
				}
				break;
			case 3:
				if (controllerEditPlayer(listPLayers) == SUCCESS)
				{
					printf("Jugador modificado exitosamente.\n");

				}
				else
				{
					printf("ERROR. REINTENTE\n");
				}
				break;
			case 4:
				returnRemovePlayer = controllerRemovePlayer(listPLayers, listNationalTeam);
				if (returnRemovePlayer == SUCCESS)
				{
					printf("Jugador dado de baja exitosamente.\n");

				}
				else if (returnRemovePlayer == ERROR)
				{
					printf("ERROR. REINTENTE\n");
				}
				else
				{
					printf("BAJA CANCELADA.\n");
				}
				break;
			case 5:
				do
				{
					showListMenuPlayers();
					if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 4, 3) == 0)
					{
						switch (option)
						{
						case 1:
							controllerListPlayers(listPLayers);
							break;
						case 2:
							controllerListNationalTeams(listNationalTeam);
							break;
						case 3:
							controllerListPlayersNationalTeam(listPLayers, listNationalTeam, 1);
							break;
						}
					}
					else
					{
						printf("ALGO SALIO MAL.\n");
						break;
					}
				} while (option != 4);
				break;
			case 6:
				do
				{
					showCallPlayersMenu();
					if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 3, 3) == 0)
					{
						switch (option)
						{
						case 1:
							returnCallUpPlayers = controllerCallUpPlayers(listPLayers, listNationalTeam);
							if (returnCallUpPlayers == SUCCESS)
							{
								printf("Jugador convocado exitosamente\n");
							}
							else if (returnCallUpPlayers == ERROR)
							{
								printf("Error. Reintente\n");
							}
							else if (returnCallUpPlayers == -2)
							{
								printf("Maximo de convocados para seleccion alcanzado.\n");
							}
							else
							{
								printf("Jugador ya convocado por seleccion.\n");
							}
							break;
						case 2:
							if (controllerCallOffPlayers(listPLayers, listNationalTeam) == SUCCESS)
							{
								printf("Jugador quitado de seleccion exitosamente.\n");
							}
							else
							{
								printf("Error. No existe id de jugador.\n");
							}
							break;
						}
					}
					else
					{
						printf("ALGO SALIO MAL.\n");
						break;
					}
				} while (option != 3);
				break;
			case 7:
				do
				{
					showSortMenu();
					if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 3, 3) == 0)
					{
						switch (option)
						{
						case 1:
							controllerSortPlayers(listPLayers);

							break;
						case 2:
							controllerSortNationalTeam(listNationalTeam);
							break;
						}
					}
				} while (option != 3);
				break;
			case 8:
				showSortConfederationMenu();
				if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 5, 3) == 0)
				{
					switch (option)
					{
					case 1:
						if(controllerSavePlayerByConfederationBinaryMode("AFC.bin",listPLayers, listNationalTeam, "AFC")==SUCCESS)
						{
							printf("Archivo binario generado correctamente.\n");
						}
						else
						{
							printf("Error al generar el archivo.\n");
						}
						break;
					case 2:
						controllerSavePlayerByConfederationBinaryMode("CAF.bin", listPLayers, listNationalTeam, "CAF");
						break;
					case 3:
						controllerSavePlayerByConfederationBinaryMode("CONCACAF.bin", listPLayers, listNationalTeam, "CONCACAF");
						break;
					case 4:
						controllerSavePlayerByConfederationBinaryMode("CONMEBOL.bin",listPLayers, listNationalTeam, "CONMEBOL");
						break;
					case 5:
						controllerSavePlayerByConfederationBinaryMode("UEFA.bin",listPLayers, listNationalTeam, "UEFA");
						break;
					}
				}
				break;
			case 10:
				if (controllerSaveIdplayerTextMode("IdJugadoresAutoincremental.csv") == SUCCESS && controllerSavePlayersTextMode("jugadores.csv", listPLayers) == SUCCESS && controllerSaveNationalTeamTextMode("selecciones.csv", listNationalTeam) == SUCCESS)
				{
					printf("Archivo de texto guardado correctamente.\n");
				}
				else
				{
					printf("Error al guardar el archivo.\n");
				}
				break;
			case 11:
				utn_getDescriptionExit(exit, "Ingrese si para salir, no para continuar en el menu.\n", "Error. Solo si o no.\n", 3);
				break;
			}
		}
		else
		{
			printf("ALGO SALIO MAL.\n");
			break;
		}
	} while (stricmp(exit, "si") != 0);
	ll_deleteLinkedList(listPLayers);
	ll_deleteLinkedList(listNationalTeam);

	return 0;
}

