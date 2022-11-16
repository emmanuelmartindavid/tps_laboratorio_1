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
	char exit[3];
	int flag = 0;
	int flagCallupCallOff;
	int flagSaveBinary = 0;
	int returnLoadBinary;
	LinkedList *listPLayers = ll_newLinkedList();
	LinkedList *listNationalTeam = ll_newLinkedList();
	do
	{
		showMainMenu();
		if (utn_getNumber(&option, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 11, 3) == 0)
		{
			switch (option)
			{
			case 1:
				if (ll_isEmpty(listPLayers) == 1 && ll_isEmpty(listNationalTeam) == 1)
				{
					if (controllerLoadPlayerFromText("jugadores.csv", listPLayers) == SUCCESS && controllerLoadNationalTeamFromText("selecciones.csv", listNationalTeam) == SUCCESS)
					{
						printf("ARCHIVOS DE TEXTO CARGADOS CORRECTAMENTE.\n");
					}
					else
					{
						printf("ERROR AL CARGAR EL ARCHIVO.\n");
					}
				}
				else
				{
					printf("YA REALIZO LA CARGA DE ARCHIVOS.\n");
				}
				flag = 1;
				break;
			case 2:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					if (controllerAddPlayer(listPLayers) == SUCCESS)
					{
						printf("ALTA DE JUGADOR EXITOSA.\n");
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
				flag = 1;
				break;
			case 3:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					returnEditPlayer = controllerEditPlayer(listPLayers);
					if (returnEditPlayer == SUCCESS)
					{
						printf("JUGADOR MODIFICADO EXITOSAMENTE.\n");
					}
					else if (returnEditPlayer == ERROR)
					{
						printf("ERROR. REINTENTE\n");
					}
					else if (returnEditPlayer == NOEDIT)
					{
						printf("NO REALIZO MODIFICACIONES.\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				flag = 1;
				break;
			case 4:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					returnRemovePlayer = controllerRemovePlayer(listPLayers, listNationalTeam);
					if (returnRemovePlayer == SUCCESS)
					{
						printf("JUGADOR DADO DE BAJA EXITOSAMENTE.\n");
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
				flag = 1;
				break;
			case 5:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					do
					{
						showListMenuPlayers();
						if (utn_getNumber(&option, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 4, 3) == 0)
						{
							switch (option)
							{
							case 1:
								controllerListCallupAndCallOffPlayers(listPLayers, listNationalTeam);
								break;
							case 2:
								controllerListNationalTeams(listNationalTeam);
								break;
							case 3:
								controllerValidateCallUpPlayers(listPLayers, &flagCallupCallOff);
								if (flagCallupCallOff == CALLUP)
								{
									controllerListCallupPlayers(listPLayers, listNationalTeam);
								}
								else
								{
									printf("\n\t\t\t\t\t\t\t\t\t\t NO HAY JUGADORES CONVOCADOS.\n\n");
								}
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
				flag = 1;
				break;
			case 6:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					do
					{
						showCallPlayersMenu();
						if (utn_getNumber(&option, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 3, 3) == 0)
						{
							switch (option)
							{
							case 1:
								returnCallUpPlayers = controllerCallUpPlayers(listPLayers, listNationalTeam);
								if (returnCallUpPlayers == SUCCESS)
								{
									printf("JUGADOR CONVOCADO EXITOSAMENTE.\n");
								}
								else if (returnCallUpPlayers == ERROR)
								{
									printf("ERROR. REINTENTEe\n");
								}
								else if (returnCallUpPlayers == -2)
								{
									printf("MAXIMO DE CONVOCADOS PARA SELECCION ALCANZADO.\n");
								}
								else if (returnCallUpPlayers == -3)
								{
									printf("ERROR. JUGADOR YA FUE CONVOCADO POR SELECCION. REINTENTE.\n");
								}
								else if (returnCallUpPlayers == -4)
								{
									printf("NO EXISTE JUGADOR.\n");
								}
								break;
							case 2:
								controllerValidateCallUpPlayers(listPLayers, &flagCallupCallOff);
								if (flagCallupCallOff == CALLUP)
								{
									if (controllerCallOffPlayers(listPLayers, listNationalTeam) == SUCCESS)
									{
										printf("JUGADOR QUITADO DE SELECCION EXITOSAMENTE.\n");
									}
									else
									{
										printf("ERROR. NO EXISTE ID DE JUGADOR. REINTENTE.\n");
									}
									break;
								}
								else
								{
									printf("\n\t\t\t\t\t\t\t\t\t\t NO HAY JUGADORES CONVOCADOS.\n\n");
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
				flag = 1;
				break;
			case 7:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					do
					{
						showSortMenu();
						if (utn_getNumber(&option, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 3, 3) == 0)
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
				flag = 1;
				break;
			case 8:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					showConfederationMenu();
					if (utn_getNumber(&option, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 5, 3) == 0)
					{
						switch (option)
						{
						case 1:
							if (controllerSavePlayersByConfederationBinaryMode("AFC.bin", listPLayers, listNationalTeam, "AFC") == SUCCESS)
							{
								printf("ARCHIVO BINARIO GENERADO EXITOSAMENTE.\n");
								flagSaveBinary = 1;
							}
							else
							{
								printf("ERROR . NO SE PUDO GENERAR ARCHIVO BINARIO. NO HAY JUGADORES CONVOCADOS EN CONFEDERACION AFC.\n");
							}
							break;
						case 2:
							if (controllerSavePlayersByConfederationBinaryMode("CAF.bin", listPLayers, listNationalTeam, "CAF") == SUCCESS)
							{
								printf("ARCHIVO BINARIO GENERADO EXITOSAMENTE.\n");
								flagSaveBinary = 1;
							}
							else
							{
								printf("ERROR . NO SE PUDO GENERAR ARCHIVO BINARIO. NO HAY JUGADORES CONVOCADOS EN CONFEDERACION CAF.\n");
							}
							break;
						case 3:
							if (controllerSavePlayersByConfederationBinaryMode("CONCACAF.bin", listPLayers, listNationalTeam, "CONCACAF") == SUCCESS)
							{
								printf("ARCHIVO BINARIO GENERADO EXITOSAMENTE.\n");
								flagSaveBinary = 1;
							}
							else
							{
								printf("ERROR . NO SE PUDO GENERAR ARCHIVO BINARIO. NO HAY JUGADORES CONVOCADOS EN CONFEDERACION CONCACAF.\n");
							}
							break;
						case 4:
							if (controllerSavePlayersByConfederationBinaryMode("CONMEBOL.bin", listPLayers, listNationalTeam, "CONMEBOL") == SUCCESS)
							{
								printf("ARCHIVO BINARIO GENERADO EXITOSAMENTE.\n");
								flagSaveBinary = 1;
							}
							else
							{
								printf("ERROR . NO SE PUDO GENERAR ARCHIVO BINARIO. NO HAY JUGADORES CONVOCADOS EN CONFEDERACION CONMEBOL.\n");
							}
							break;
						case 5:
							if (controllerSavePlayersByConfederationBinaryMode("UEFA.bin", listPLayers, listNationalTeam, "UEFA") == SUCCESS)
							{
								printf("ARCHIVO BINARIO GENERADO EXITOSAMENTE.\n");
								flagSaveBinary = 1;
							}
							else
							{
								printf("ERROR . NO SE PUDO GENERAR ARCHIVO BINARIO. NO HAY JUGADORES CONVOCADOS EN CONFEDERACION UEFA.\n");
							}
							break;
						}
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				flag = 1;
				break;
			case 9:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					if (flagSaveBinary == 1)
					{
						showConfederationMenuLoad();
						if (utn_getNumber(&option, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 5, 3) == 0)
						{
							switch (option)
							{
							case 1:
								returnLoadBinary = controllerListPLayersByConfederationFromBinaryData("AFC.bin", listPLayers, listNationalTeam, "AFC");
								if (returnLoadBinary == SUCCESS)
								{
									printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE ARCHIVO BINARIO.\n");
								}
								else if (returnLoadBinary == ERROR)
								{
									printf("ERROR. NO SE PUDO CARGAR ARCHIVO BINARIO. AUN NO HA SIDO GENERADO EL MISMO.\n");
								}
								else if (returnLoadBinary == CALLOFF)
								{
									printf("\t\t\t\t\t\tSE HA ELIMINADO SU ARCHIVO BINARIO DEBIDO A QUE, O HA ELIMINADO O HA DESCONVOCADO AL UNICO JUGADOR EN ESTA CONFEDERACION DE SU ARCHIVO BINARIO.\n\n");
								}
								break;
							case 2:
								returnLoadBinary = controllerListPLayersByConfederationFromBinaryData("CAF.bin", listPLayers, listNationalTeam, "CAF");
								if (returnLoadBinary == SUCCESS)
								{
									printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE ARCHIVO BINARIO.\n");
								}
								else if (returnLoadBinary == ERROR)
								{
									printf("ERROR. NO SE PUDO CARGAR ARCHIVO BINARIO. AUN NO HA SIDO GENERADO EL MISMO.\n");								}
								else if (returnLoadBinary == CALLOFF)
								{
									printf("\t\t\t\t\t\tSE HA ELIMINADO SU ARCHIVO BINARIO DEBIDO A QUE, O HA ELIMINADO O HA DESCONVOCADO AL UNICO JUGADOR EN ESTA CONFEDERACION DE SU ARCHIVO BINARIO.\n\n");
								}
								break;
							case 3:
								returnLoadBinary = controllerListPLayersByConfederationFromBinaryData("CONCACAF.bin", listPLayers, listNationalTeam, "CONCACAF");
								if (returnLoadBinary == SUCCESS)
								{
									printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE ARCHIVO BINARIO.\n");
								}
								else if (returnLoadBinary == ERROR)
								{
									printf("ERROR. NO SE PUDO CARGAR ARCHIVO BINARIO. AUN NO HA SIDO GENERADO EL MISMO.\n");								}
								else if (returnLoadBinary == CALLOFF)
								{
									printf("\t\t\t\t\t\tSE HA ELIMINADO SU ARCHIVO BINARIO DEBIDO A QUE, O HA ELIMINADO O HA DESCONVOCADO AL UNICO JUGADOR EN ESTA CONFEDERACION DE SU ARCHIVO BINARIO.\n\n");
								}
								break;
							case 4:
								returnLoadBinary = controllerListPLayersByConfederationFromBinaryData("CONMEBOL.bin", listPLayers, listNationalTeam, "CONMEBOL");
								if (returnLoadBinary == SUCCESS)
								{
									printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE ARCHIVO BINARIO.\n");
								}
								else if (returnLoadBinary == ERROR)
								{
									printf("ERROR. NO SE PUDO CARGAR ARCHIVO BINARIO. AUN NO HA SIDO GENERADO EL MISMO.\n");								}
								else if (returnLoadBinary == CALLOFF)
								{
									printf("\t\t\t\t\t\tSE HA ELIMINADO SU ARCHIVO BINARIO DEBIDO A QUE, O HA ELIMINADO O HA DESCONVOCADO AL UNICO JUGADOR EN ESTA CONFEDERACION DE SU ARCHIVO BINARIO.\n\n");
								}
								break;
							case 5:
								returnLoadBinary = controllerListPLayersByConfederationFromBinaryData("UEFA.bin", listPLayers, listNationalTeam, "UEFA");
								if (returnLoadBinary == SUCCESS)
								{
									printf("\t\t\t\t\t\t\t\t\t\tLISTA CONVOCADOS DESDE ARCHIVO BINARIO.\n");
								}
								else if (returnLoadBinary == ERROR)
								{
									printf("ERROR. NO SE PUDO CARGAR ARCHIVO BINARIO. AUN NO HA SIDO GENERADO EL MISMO.\n");								}
								else if (returnLoadBinary == CALLOFF)
								{
									printf("\t\t\t\t\t\tSE HA ELIMINADO SU ARCHIVO BINARIO DEBIDO A QUE, O HA ELIMINADO O HA DESCONVOCADO AL UNICO JUGADOR EN ESTA CONFEDERACION DE SU ARCHIVO BINARIO.\n\n");
								}
								break;
							}
						}
					}
					else
					{
						printf("PRIMERO DEBE GENERAR EL ARCHIVO BINARIO.\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				flag = 1;
				break;
			case 10:
				if (ll_isEmpty(listPLayers) == 0 && ll_isEmpty(listNationalTeam) == 0)
				{
					if (controllerSaveIdplayerTextMode("IdJugadoresAutoincremental.csv") == SUCCESS && controllerSavePlayersTextMode("jugadores.csv", listPLayers) == SUCCESS && controllerSaveNationalTeamTextMode("selecciones.csv", listNationalTeam) == SUCCESS)
					{
						flag = 2;
						printf("ARCHIVO DE TEXTO GUARDADO  EXITOSAMENTE.\n");
					}
					else
					{
						printf("ERROR AL GUARDAR EL ARCHIVO.\n");
					}
				}
				else
				{
					printf("PRIMERO DEBE CARGAR LOS ARCHIVOS DE TEXTO.\n");
				}
				break;
			case 11:
				if (flag != 2)
				{
					if (utn_getDescriptionExit(exit, "VA A SALIR SIN GUARDAR CAMBIOS.\n"
									"\t\t\t\t\t\t\tTENGA EN CUENTA. SI GENERO ARCHIVOS BINARIOS, LOS MISMOS SERAN ELIMINADOS AL CERRAR EL PROGRAMA.\n"
									"INGRESE SI PARA SALIR SIN GUARDAR.\n"
									"INGRESE NO PARA SEGUIR EN EL MENU.\n", "Error. Solo si o no.\n", 3) == 0)
					{
						if ((stricmp(exit, "si") == 0))
						{
							remove("AFC.bin");
							remove("CAF.bin");
							remove("CONCACAF.bin");
							remove("CONMEBOL.bin");
							remove("UEFA.bin");
							printf("\n\t\t\t\t\t\t\tSE HAN REMOVIDO TODOS LOS ARCHIVOS BINARIOS QUE HAYA CREADO AL NO GUARDAR SUS ARCHIVOS DE TEXTO DEL PROGRAMA.\n");
						}
					}
					else
					{
						printf("\n\t\t\t\t ERROR. REINTENTE.\n");
					}
				}
				else if (flag == 2)
				{
					utn_getDescriptionExit(exit, "INGRESE SI PARA SALIR.\n"
									"INGRESE NO PARA SEGUIR EN EL MENU.\n", "Error. Solo si o no.\n", 3);
				}
				break;
			}
		}
		else
		{
			printf("ALGO SALIO MAL.\n");
			break;
		}
	} while (stricmp(exit, "si") != 0);
	printf("\n\t\t\t\t\t\t\t\t\t\t\tHASTA LUEGO C. GRACIAS POR TODO.");
	ll_deleteLinkedList(listPLayers);
	ll_deleteLinkedList(listNationalTeam);
	return EXIT_SUCCESS;
}

