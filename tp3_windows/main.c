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
	int returnRemovePlayer;
	int returnCallUpPlayers;
	int returnEditPlayer;
	char save[3];
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
				if (ll_isEmpty(listPLayers) == 1 && ll_isEmpty(listNationalTeam) == 1)
				{
					if (controllerLoadPlayerFromText("jugadores.csv", listPLayers) == SUCCESS && controllerLoadNationalTeamFromText("selecciones.csv", listNationalTeam) == SUCCESS)
					{

						printf("Archivos de texto cargados correctamente.\n");
					}
					else
					{
						printf("Error al cargar archivos.\n");
					}
				}
				else
				{
					printf("YA REALIZO LA CARGA DE ARCHIVOS.\n");
				}
				break;
			case 2:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
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
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 3:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					returnEditPlayer = controllerEditPlayer(listPLayers);
					if (returnEditPlayer == SUCCESS)
					{
						printf("Jugador modificado exitosamente.\n");

					}
					else if (returnEditPlayer == ERROR)
					{
						printf("ERROR. REINTENTE\n");
					}
					else if (returnEditPlayer == NOEDIT)
					{
						printf("No realizo modificaciones.\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 4:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					returnRemovePlayer = controllerRemovePlayer(listPLayers, listNationalTeam);
					if (returnRemovePlayer == SUCCESS)
					{
						printf("Jugador dado de baja exitosamente.\n");

					}
					else if (returnRemovePlayer == ERROR)
					{
						printf("ERROR. REINTENTE\n");
					}
					else if (returnRemovePlayer == REMOVECANCEL)
					{
						printf("BAJA CANCELADA.\n");
					}
					else
					{
						printf("NO EXISTE JUGADOR. REINTENTE.\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 5:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					do
					{
						showListMenuPlayers();
						if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 4, 3) == 0)
						{
							switch (option)
							{
							case 1:
								controllerListPlayersNationalTeam(listPLayers, listNationalTeam, CALLOFF);
								break;
							case 2:
								controllerListNationalTeams(listNationalTeam);
								break;
							case 3:
								controllerListPlayersNationalTeam(listPLayers, listNationalTeam, CALLUP);
								break;
							}
						}

						else
						{
							printf("ALGO SALIO MAL.\n");
							break;
						}
					} while (option != 4);
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 6:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
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
								if (returnCallUpPlayers == SUCCESS)
								{
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
								else
								{
									printf("Aun no ha convocado jugadores.\n");
								}
							}
						}
						else
						{
							printf("ALGO SALIO MAL.\n");
							break;
						}
					} while (option != 3);
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 7:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
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
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 8:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					showConfederationMenu();
					if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 5, 3) == 0)
					{
						switch (option)
						{
						case 1:
							if (controllerSavePlayersByConfederationBinaryMode("AFC.bin", listPLayers, listNationalTeam, "AFC") == SUCCESS)
							{
								printf("Archivo binario generado correctamente.\n");
							}
							else
							{
								printf("Error. No se pudo generar archivo binario. No hay jugadores convocados.\n");
							}
							break;
						case 2:
							if (controllerSavePlayersByConfederationBinaryMode("CAF.bin", listPLayers, listNationalTeam, "CAF") == SUCCESS)
							{
								printf("Archivo binario generado correctamente.\n");
							}
							else
							{
								printf("Error. No se pudo generar archivo binario. No hay jugadores convocados.\n");
							}
							break;
						case 3:
							if (controllerSavePlayersByConfederationBinaryMode("CONCACAF.bin", listPLayers, listNationalTeam, "CONCACAF") == SUCCESS)
							{
								printf("Archivo binario generado correctamente.\n");
							}
							else
							{
								printf("Error. No se pudo generar archivo binario. No hay jugadores convocados.\n");
							}
							break;
						case 4:
							if (controllerSavePlayersByConfederationBinaryMode("CONMEBOL.bin", listPLayers, listNationalTeam, "CONMEBOL") == SUCCESS)
							{
								printf("Archivo binario generado correctamente.\n");
							}
							else
							{
								printf("Error. No se pudo generar archivo binario. No hay jugadores convocados.\n");
							}
							break;
						case 5:
							if (controllerSavePlayersByConfederationBinaryMode("UEFA.bin", listPLayers, listNationalTeam, "UEFA") == SUCCESS)
							{
								printf("Archivo binario generado correctamente.\n");
							}
							else
							{
								printf("Error. No se pudo generar archivo binario. No hay jugadores convocados.\n");
							}
							break;
						}
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 9:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					showConfederationMenu();
					if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 5, 3) == 0)
					{
						switch (option)
						{
						case 1:
							if (controllerListPLayersByConfederationFromBinaryData("AFC.bin", listPLayers, listNationalTeam, "AFC") == SUCCESS)
							{
								printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE BINARIO.\n");
							}

							else
							{
								printf("Error. No se pudo cargar archivo binario. No exiten jugadores en esta confederacion.\n");
							}
							break;
						case 2:
							if (controllerListPLayersByConfederationFromBinaryData("CAF.bin", listPLayers, listNationalTeam, "CAF") == SUCCESS)
							{
								printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE BINARIO.\n");
							}
							else
							{
								printf("Error. No se pudo cargar archivo binario. No exiten jugadores en esta confederacion.\n");
							}
							break;
						case 3:
							if (controllerListPLayersByConfederationFromBinaryData("CONCACAF.bin", listPLayers, listNationalTeam, "CONCACAF") == SUCCESS)
							{
								printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE BINARIO.\n");
							}
							else
							{
								printf("Error. No se pudo cargar archivo binario. No exiten jugadores en esta confederacion.\n");
							}
							break;
						case 4:
							if (controllerListPLayersByConfederationFromBinaryData("CONMEBOL.bin", listPLayers, listNationalTeam, "CONMEBOL") == SUCCESS)
							{
								printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE BINARIO.\n");
							}
							else
							{
								printf("Error. No se pudo cargar archivo binario. No exiten jugadores en esta confederacion.\n");
							}
							break;
						case 5:
							if (controllerListPLayersByConfederationFromBinaryData("UEFA.bin", listPLayers, listNationalTeam, "UEFA") == SUCCESS)
							{
								printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE BINARIO.\n");
							}
							else
							{
								printf("Error. No se pudo cargar archivo binario. No exiten jugadores en esta confederacion.\n");
							}
							break;
						}
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 10:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					if (utn_getDescriptionExit(save, "Seguro desea guardar los cambios?.\n"
									"Ingrese si para guardar.\n"
									"Ingrese no para continuar en el menu.\n", "Error. Solo si o no.\n", 3) == 0)
					{
						if (controllerSaveIdplayerTextMode("IdJugadoresAutoincremental.csv") == SUCCESS && controllerSavePlayersTextMode("jugadores.csv", listPLayers) == SUCCESS && controllerSaveNationalTeamTextMode("selecciones.csv", listNationalTeam) == SUCCESS)
						{

							printf("Archivo de texto guardado correctamente.\n");
						}
						else
						{
							printf("Error al guardar el archivo.\n");
						}
					}
					else
					{
						printf("DATOS INVALIDOS. REINTENTE\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 11:
				utn_getDescriptionExit(exit, "Ingrese SI para salir.\n"
								"Ingrese NO para continuar en el menu.\n", "Error. Solo si o no.\n", 3);
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
	return EXIT_SUCCESS;
}

