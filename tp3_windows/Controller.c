#include <stdio.h>
#include <stdlib.h>
#include "Jugador.h"
#include "Seleccion.h"
#include "LinkedList.h"
#include "parser.h"
#include "validaciones.h"
#include "controller.h"
#include "menus.h"
#include "string.h"
int controllerFindPlayerById(LinkedList *pArrayListPlayer, int idPlayer)
{
	int returncontrollerFindPlayerById = ERROR;
	int lenListPlayers;
	int auxId;
	sPlayer *pPlayer = NULL;

	if (pArrayListPlayer != NULL && ll_isEmpty(pArrayListPlayer) == 0)
	{
		lenListPlayers = ll_len(pArrayListPlayer);
		for (int i = 0; i < lenListPlayers; i++)
		{
			pPlayer = (sPlayer*) ll_get(pArrayListPlayer, i);
			if (getIdPlayer(pPlayer, &auxId) && auxId == idPlayer)
			{
				returncontrollerFindPlayerById = ll_indexOf(pArrayListPlayer, pPlayer);
			}
		}
	}
	return returncontrollerFindPlayerById;
}

int controllerFindNationalTeamById(LinkedList *pArrayListNationalTeam, int idNationalTeam)
{
	int returncontrollerFindPlayerById = ERROR;
	int lenListNationalTeam;
	int auxId;
	sNationalTeam *pNationalTeam = NULL;

	if (pArrayListNationalTeam != NULL && ll_isEmpty(pArrayListNationalTeam) == 0)
	{
		lenListNationalTeam = ll_len(pArrayListNationalTeam);
		for (int i = 0; i < lenListNationalTeam; i++)
		{
			pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, i);
			if (getIdNationalTeam(pNationalTeam, &auxId) && auxId == idNationalTeam)
			{
				returncontrollerFindPlayerById = ll_indexOf(pArrayListNationalTeam, pNationalTeam);
			}
		}
	}
	return returncontrollerFindPlayerById;
}

/** \brief Carga los datos de los jugadores desde el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerLoadPlayerFromText(char *path, LinkedList *pArrayListPlayer)
{
	int returncontrollerLoadPlayerFromText = ERROR;
	FILE *pFile = NULL;

	if (path != NULL && pArrayListPlayer != NULL)
	{
		pFile = fopen(path, "r");
		if (pFile != NULL)
		{
			if (parserPlayerFromText(pFile, pArrayListPlayer) == SUCCESS)
			{
				returncontrollerLoadPlayerFromText = SUCCESS;
			}
			fclose(pFile);
		}
	}
	return returncontrollerLoadPlayerFromText;
}

/** \brief Carga los datos de los jugadores desde el archivo generado en modo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerLoadPlayerFromBinary(char *path, LinkedList *pArrayListPlayer)
{
	int returncontrollerLoadPlayerFromBinary = ERROR;
	FILE *pFile = NULL;

	if (path != NULL && pArrayListPlayer != NULL)
	{
		pFile = fopen(path, "rb");
		if (pFile != NULL)
		{
			if (parserPlayerFromBinary(pFile, pArrayListPlayer) == SUCCESS)
			{
				returncontrollerLoadPlayerFromBinary = SUCCESS;
			}
			fclose(pFile);
		}
	}
	return returncontrollerLoadPlayerFromBinary;
}

/** \brief Alta de jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerAddPlayer(LinkedList *pArrayListPlayer)
{
	int returnControllerAddPlayer = ERROR;
	int auxIdNationalTeam = 0;
	int auxIdplayer;
	sPlayer *pPlayer = NULL;

	if (pArrayListPlayer != NULL)
	{
		auxIdplayer = controllerGetIncrementalIdPlayer(pPlayer);
		pPlayer = newPlayer();
		if (pPlayer != NULL && setIdPlayer(pPlayer, auxIdplayer) && editFullNamePlayer(pPlayer) == SUCCESS && editAgePlayer(pPlayer) == SUCCESS && editPositionPlayer(pPlayer) == SUCCESS && editNationalityPlayer(pPlayer) == SUCCESS && setIdNationalTeamPlayer(pPlayer, auxIdNationalTeam) == SUCCESS)
		{
			if (ll_add(pArrayListPlayer, pPlayer) == 0)
			{
				returnControllerAddPlayer = SUCCESS;
			}
		}
		else
		{
			deletePlayer(pPlayer);
		}
	}
	return returnControllerAddPlayer;
}

/** \brief Modificar datos del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerEditPlayer(LinkedList *pArrayListPlayer)
{
	int returncontrollerEditPlayer = ERROR;
	int auxId;
	int indexListPlayer;
	int optionEditMenu;
	int flagEditPlayer = 3;
	sPlayer *pPlayer = NULL;

	if (pArrayListPlayer != NULL && ll_isEmpty(pArrayListPlayer) == 0 && controllerListPlayers(pArrayListPlayer) == SUCCESS && utn_getNumber(&auxId, "Ingrese ID de jugador a modificar.\n", "Error. Reintente.\n", 1, 500, 3) == 0)
	{
		indexListPlayer = controllerFindPlayerById(pArrayListPlayer, auxId);
		if (indexListPlayer != ERROR)
		{
			pPlayer = (sPlayer*) ll_get(pArrayListPlayer, indexListPlayer);
			if (pPlayer != NULL)
			{
				do
				{
					showEditPlayerMenu();
					showPlayerData();
					listOnePlayer(pPlayer);
					showLine();
					if (utn_getNumber(&optionEditMenu, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 7, 3) == 0)
					{
						switch (optionEditMenu)
						{
						case 1:
							if (editFullNamePlayer(pPlayer) == SUCCESS)
							{
								flagEditPlayer = SUCCESS;
							}
							else
							{
								flagEditPlayer = 3;
							}
							break;
						case 2:
							if (editAgePlayer(pPlayer) == SUCCESS)
							{
								flagEditPlayer = SUCCESS;
							}
							else
							{
								flagEditPlayer = 3;
							}
							break;
						case 3:
							if (editPositionPlayer(pPlayer) == SUCCESS)
							{
								flagEditPlayer = SUCCESS;
							}
							else
							{
								flagEditPlayer = 3;
							}
							break;
						case 4:
							if (editNationalityPlayer(pPlayer) == SUCCESS)
							{
								flagEditPlayer = SUCCESS;
							}
							else
							{
								flagEditPlayer = 3;
							}
							break;
						}
					}
					else
					{
						returncontrollerEditPlayer = ERROR;
						break;
					}
				} while (optionEditMenu != 5);
			}
		}
		returncontrollerEditPlayer = flagEditPlayer;
	}
	return returncontrollerEditPlayer;
}

/** \brief Baja del jugador
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerRemovePlayer(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam)
{
	int returncontrollerRemovePlayer = ERROR;
	int auxId;
	int indexListPlayer;
	int idNationalTeamPlayer;
	int indexListNationalTeam;
	int calledUp;
	char confirmation[3];
	sPlayer *pPlayer = NULL;
	sNationalTeam *pNationalTeam = NULL;

	if (pArrayListPlayer != NULL && pArrayListNationalTeam != NULL && controllerListPlayers(pArrayListPlayer) == SUCCESS && utn_getNumber(&auxId, "Ingrese ID de jugador a dar de baja.\n", "Error. Reintente.\n", 1, 500, 3) == 0)
	{
		indexListPlayer = controllerFindPlayerById(pArrayListPlayer, auxId);
		if (indexListPlayer != -1)
		{
			pPlayer = (sPlayer*) ll_get(pArrayListPlayer, indexListPlayer);
			if (pPlayer != NULL)
			{
				getIdNationalTeamPLayer(pPlayer, &idNationalTeamPlayer);
				indexListNationalTeam = controllerFindNationalTeamById(pArrayListNationalTeam, idNationalTeamPlayer);
				pNationalTeam = ll_get(pArrayListNationalTeam, indexListNationalTeam);
				showPlayerData();
				listOnePlayer(pPlayer);
				showLine();
				if (utn_getDescriptionExit(confirmation, "Se dara de baja. Ingrese si para continuar, no para cancelar baja.\n", "Error. Reintente.\n", 3) == 0)
				{
					if (stricmp(confirmation, "si") == 0)
					{
						if (indexListNationalTeam != ERROR && pNationalTeam != NULL)
						{
							if (idNationalTeamPlayer > 0)
							{
								getCalledUpNationalTeam(pNationalTeam, &calledUp);
								calledUp--;
								setCalledUpNationalTeam(pNationalTeam, calledUp);
							}
						}
						ll_remove(pArrayListPlayer, indexListPlayer);
						deletePlayer(pPlayer);
						returncontrollerRemovePlayer = SUCCESS;
					}
					else
					{
						returncontrollerRemovePlayer = -2;
					}
				}
			}
		}
	}
	return returncontrollerRemovePlayer;
}

/** \brief Listar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerListPlayers(LinkedList *pArrayListPlayer)
{
	int returncontrollerListPlayer = ERROR;
	int lenListPlayers;
	sPlayer *pPlayer = NULL;

	if (pArrayListPlayer != NULL && ll_isEmpty(pArrayListPlayer) == 0)
	{
		lenListPlayers = ll_len(pArrayListPlayer);
		showPlayerData();
		for (int i = 0; i < lenListPlayers; i++)
		{
			pPlayer = (sPlayer*) ll_get(pArrayListPlayer, i);
			if (listOnePlayer(pPlayer) == SUCCESS)
			{
				returncontrollerListPlayer = SUCCESS;
			}
		}
		showLine();
	}
	return returncontrollerListPlayer;
}

int controllerListPlayersNationalTeam(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam, int condition)
{

	int returncontrollerListPlayer = ERROR;
	int lenListPlayers;
	int auxId;
	char auxFullName[100];
	int auxAge;
	char auxPosition[30];
	char auxNationality[30];
	char country[30];
	int auxIdNationalTeam;
	sPlayer *pPlayer = NULL;

	if (pArrayListPlayer != NULL && pArrayListNationalTeam != NULL && ll_isEmpty(pArrayListPlayer) == 0)
	{
		lenListPlayers = ll_len(pArrayListPlayer);
		if (condition == 1)
		{
			showPlayerDataNationalTeam();
			for (int i = 0; i < lenListPlayers; i++)
			{
				pPlayer = (sPlayer*) ll_get(pArrayListPlayer, i);
				if (pPlayer != NULL && getIdPlayer(pPlayer, &auxId) && getFullNamePlayer(pPlayer, auxFullName) && getAgePlayer(pPlayer, &auxAge) && getPositionPlayer(pPlayer, auxPosition) && getNationalityPlayer(pPlayer, auxNationality) && getIdNationalTeamPLayer(pPlayer, &auxIdNationalTeam)
								&& controllerGetCountry(pArrayListNationalTeam, auxIdNationalTeam, country) && auxIdNationalTeam > 0)
				{
					printf("\t\t\t\t\t\t|%-5d| %-35s| %-5d| %-25s| %-24s| %-23s|\n", auxId, auxFullName, auxAge, auxPosition, auxNationality, country);
				}
			}
			printf("\t\t\t\t\t\t=================================================================================================================================\n");
		}
		else if (condition == 2)
		{
			showPlayerDataNationalTeam();
			for (int i = 0; i < lenListPlayers; i++)
			{
				pPlayer = (sPlayer*) ll_get(pArrayListPlayer, i);
				if (pPlayer != NULL && getIdPlayer(pPlayer, &auxId) && getFullNamePlayer(pPlayer, auxFullName) && getAgePlayer(pPlayer, &auxAge) && getPositionPlayer(pPlayer, auxPosition) && getNationalityPlayer(pPlayer, auxNationality) && getIdNationalTeamPLayer(pPlayer, &auxIdNationalTeam)
								&& controllerGetCountry(pArrayListNationalTeam, auxIdNationalTeam, country))
				{
					printf("\t\t\t\t\t\t|%-5d| %-35s| %-5d| %-25s| %-24s| %-23s|\n", auxId, auxFullName, auxAge, auxPosition, auxNationality, country);
				}
			}
			printf("\t\t\t\t\t\t=================================================================================================================================\n");
		}
		returncontrollerListPlayer = SUCCESS;
	}
	return returncontrollerListPlayer;
}

int controllerCallUpPlayers(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam)
{
	int returncontrollerCallUpPlayers = ERROR;
	int idPlayer;
	int idNationalTeam;
	int indexListPlayer;
	int indexListNationalTeam;
	int idNationalTeamPlayer;
	int calledUp;
	sPlayer *pPlayer = NULL;
	sNationalTeam *pNationalTeam = NULL;

	if (pArrayListPlayer != NULL && pArrayListNationalTeam != NULL)
	{
		if (controllerListPlayersNationalTeam(pArrayListPlayer, pArrayListNationalTeam, 2) == SUCCESS && utn_getNumber(&idPlayer, "Ingrese id de jugador a convocar.\n", "Error. Reintente.\n", 1, 500, 3) == 0)
		{
			indexListPlayer = controllerFindPlayerById(pArrayListPlayer, idPlayer);

			pPlayer = (sPlayer*) ll_get(pArrayListPlayer, indexListPlayer);

			if (pPlayer != NULL)
			{
				if (getIdNationalTeamPLayer(pPlayer, &idNationalTeamPlayer) == SUCCESS && idNationalTeamPlayer > 0)
				{
					returncontrollerCallUpPlayers = -3;
				}
				else if (indexListPlayer != ERROR)
				{
					if (controllerListNationalTeams(pArrayListNationalTeam) == SUCCESS && utn_getNumber(&idNationalTeam, "Ingrese id de seleccion a la que sera convocado.\n", "Error. Reintente.\n", 1, 40, 3) == 0)
					{
						indexListNationalTeam = controllerFindNationalTeamById(pArrayListNationalTeam, idNationalTeam);

						if (indexListNationalTeam != ERROR)
						{
							pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, indexListNationalTeam);

							if (pNationalTeam != NULL)
							{
								setIdNationalTeamPlayer(pPlayer, idNationalTeam);
								getCalledUpNationalTeam(pNationalTeam, &calledUp);
								calledUp++;
								returncontrollerCallUpPlayers = SUCCESS;
								if (setCalledUpNationalTeam(pNationalTeam, calledUp) == ERROR)
								{
									returncontrollerCallUpPlayers = -2;
								}
							}
						}
					}
				}
			}
		}
	}
	return returncontrollerCallUpPlayers;
}

int controllerCallOffPlayers(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam)
{
	int returncontrollerCallOffPlayers = ERROR;
	int idPlayer;
	int indexListPlayer;
	int indexListNationalTeam;
	int idNationalTeamPlayer;
	int calledUp;
	sPlayer *pPlayer = NULL;
	sNationalTeam *pNationalTeam = NULL;
	if (pArrayListPlayer != NULL && pArrayListNationalTeam != NULL)
	{
		if (controllerListPlayersNationalTeam(pArrayListPlayer, pArrayListNationalTeam, 1) == SUCCESS && utn_getNumber(&idPlayer, "Ingrese id de jugador a quitar de seleccion.\n", "Error. Reintente.\n", 1, 500, 3) == 0)
		{
			indexListPlayer = controllerFindPlayerById(pArrayListPlayer, idPlayer);

			pPlayer = (sPlayer*) ll_get(pArrayListPlayer, indexListPlayer);

			if (pPlayer != NULL)
			{
				if (indexListPlayer != ERROR)
				{
					getIdNationalTeamPLayer(pPlayer, &idNationalTeamPlayer);
					indexListNationalTeam = controllerFindNationalTeamById(pArrayListNationalTeam, idNationalTeamPlayer);

					if (indexListNationalTeam != ERROR)
					{
						pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, indexListNationalTeam);
						if (pNationalTeam != NULL)
						{
							setIdNationalTeamPlayer(pPlayer, 0);
							getCalledUpNationalTeam(pNationalTeam, &calledUp);
							calledUp--;
							if (setCalledUpNationalTeam(pNationalTeam, calledUp) == SUCCESS)
							{
								returncontrollerCallOffPlayers = SUCCESS;
							}
						}
					}
				}
			}
		}
	}

	return returncontrollerCallOffPlayers;
}
/** \brief Ordenar jugadores
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerSortPlayers(LinkedList *pArrayListPlayer)
{
	int returnControllerSortPlayers = ERROR;
	int option;
	int sortOption;

	if (pArrayListPlayer != NULL)
	{
		do
		{
			showSortPlayerMenu();
			if (utn_getNumber(&option, "Ingrese opcion.\n", "Error. Reintente.\n", 1, 4, 3) == 0)
			{
				if (option != 4 && utn_getNumber(&sortOption, "1 para ordenar de forma ascendente, 0 de forma descendente.\n", "Error. Reintente.\n", 0, 1, 3) == 0)
				{
					switch (option)
					{
					case 1:
						ll_sort(pArrayListPlayer, comparePlayersByNationality, sortOption);
						controllerListPlayers(pArrayListPlayer);
						break;
					case 2:
						ll_sort(pArrayListPlayer, comparePlayersByAge, sortOption);
						controllerListPlayers(pArrayListPlayer);
						break;
					case 3:
						ll_sort(pArrayListPlayer, comparePlayersByName, sortOption);
						controllerListPlayers(pArrayListPlayer);
						break;
					}
					returnControllerSortPlayers = SUCCESS;
				}
				else
				{
					returnControllerSortPlayers = ERROR;
					break;
				}
			}
			else
			{
				returnControllerSortPlayers = ERROR;
				break;
			}
		} while (option != 4);
	}
	return returnControllerSortPlayers;
}

/** \brief Guarda los datos de los jugadores en el archivo jugadores.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controllerSavePlayersTextMode(char *path, LinkedList *pArrayListPlayer)
{

	int returnControllerSavePlayersTextMode = ERROR;
	FILE *pFile = NULL;
	int len;
	sPlayer *pPlayer = NULL;
	int auxId;
	char auxFullName[100];
	int auxAge;
	char auxPosition[30];
	char auxNationality[30];
	int auxIdNationalTeam;

	if (path != NULL)
	{
		pFile = fopen(path, "w");
		if (pFile != NULL)
		{
			len = ll_len(pArrayListPlayer);
			fprintf(pFile, "Id,nombreCompleto,edad,posicion,nacionalidad,idSelecion\n");
			for (int i = 0; i < len; i++)
			{
				pPlayer = (sPlayer*) ll_get(pArrayListPlayer, i);
				if (pPlayer != NULL)
				{
					if (getIdPlayer(pPlayer, &auxId) == SUCCESS && getFullNamePlayer(pPlayer, auxFullName) == SUCCESS && getAgePlayer(pPlayer, &auxAge) == SUCCESS && getPositionPlayer(pPlayer, auxPosition) == SUCCESS && getNationalityPlayer(pPlayer, auxNationality) == SUCCESS
									&& getIdNationalTeamPLayer(pPlayer, &auxIdNationalTeam) == SUCCESS)
					{
						fprintf(pFile, "%d,%s,%d,%s,%s,%d\n", auxId, auxFullName, auxAge, auxPosition, auxNationality, auxIdNationalTeam);
					}
				}
			}

			fclose(pFile);
		}
		returnControllerSavePlayersTextMode = SUCCESS;
	}
	return returnControllerSavePlayersTextMode;
}

/** \brief Guarda los datos de los jugadores en el archivo binario.
 *
 * \param path char*
 * \param pArrayListJugador LinkedList*
 * \return int
 *
 */
int controllerSavePlayersBinarytMode(char *path, LinkedList *pArrayListPlayer)
{
	int returnControllerSavePlayersBinarytMode = ERROR;
	FILE *pFile = NULL;
	int len;
	sPlayer *pPlayer = NULL;

	if (path != NULL)
	{
		pFile = fopen(path, "wb");
		if (pFile != NULL)
		{
			len = ll_len(pArrayListPlayer);
			for (int i = 0; i < len; i++)
			{
				pPlayer = (sPlayer*) ll_get(pArrayListPlayer, i);

				if (pPlayer != NULL)
				{
					fwrite(pPlayer, sizeof(sPlayer), 1, pFile);
				}
			}
			fclose(pFile);
		}
		returnControllerSavePlayersBinarytMode = SUCCESS;
	}
	return returnControllerSavePlayersBinarytMode;
}

/** \brief Carga los datos de los selecciones desde el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controllerLoadNationalTeamFromText(char *path, LinkedList *pArrayListNationalTeam)
{
	int returnControllerLoadNationalTeamFromText;
	FILE *pFile = NULL;

	if (path != NULL && pArrayListNationalTeam != NULL)
	{
		pFile = fopen(path, "r");

		if (pFile != NULL)
		{
			if (parserNationalTeamFromText(pFile, pArrayListNationalTeam) == SUCCESS)
			{
				returnControllerLoadNationalTeamFromText = SUCCESS;
			}
			else
			{
				returnControllerLoadNationalTeamFromText = ERROR;
			}
			fclose(pFile);
		}
	}
	return returnControllerLoadNationalTeamFromText;
}

/** \brief Modificar datos de empleado
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controllerEditNationalTeam(LinkedList *pArrayListNationalTeam)
{
	int returnControllerEditSeleccion = ERROR;

	return returnControllerEditSeleccion;
}

/** \brief Listar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controllerListNationalTeams(LinkedList *pArrayListNationalTeam)
{
	int returncontrollerListNationalTeams = ERROR;
	int lenListNationalTeam;
	sNationalTeam *pNationalTeam = NULL;

	if (pArrayListNationalTeam != NULL && ll_isEmpty(pArrayListNationalTeam) == 0)
	{
		lenListNationalTeam = ll_len(pArrayListNationalTeam);

		showNationalTeamData();

		for (int i = 0; i < lenListNationalTeam; i++)
		{
			pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, i);

			if (pNationalTeam != NULL)
			{
				if (listOneNationalTeam(pNationalTeam) == SUCCESS)
				{
					returncontrollerListNationalTeams = SUCCESS;
				}
			}
		}
		showLineNT();
	}
	return returncontrollerListNationalTeams;
}

/** \brief Ordenar selecciones
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controllerSortNationalTeam(LinkedList *pArrayListNationalTeam)
{
	int returnControllerSortNationalTeam;
	int sortOption;
	if (utn_getNumber(&sortOption, "1 para ordenar de forma ascendente, 0 de forma descendente.\n", "Error. Reintente.\n", 0, 1, 3) == 0)
	{
		ll_sort(pArrayListNationalTeam, compareNationalTeamByConfederation, sortOption);
		controllerListNationalTeams(pArrayListNationalTeam);
		returnControllerSortNationalTeam = SUCCESS;
	}
	return returnControllerSortNationalTeam;
}

/** \brief Guarda los datos de los selecciones en el archivo selecciones.csv (modo texto).
 *
 * \param path char*
 * \param pArrayListSeleccion LinkedList*
 * \return int
 *
 */
int controllerSaveNationalTeamTextMode(char *path, LinkedList *pArrayListNationalTeam)
{
	int returnControllerSaveNationalTeamTextMode = ERROR;
	FILE *pFile = NULL;
	int len;
	sNationalTeam *pNationalTeam = NULL;
	int auxId;
	char auxCountry[30];
	char auxConfederation[30];
	int auxCalledUp;

	if (path != NULL && pArrayListNationalTeam != NULL)
	{
		pFile = fopen(path, "w");

		if (pFile != NULL)
		{
			len = ll_len(pArrayListNationalTeam);
			fprintf(pFile, "id,pais,confederacion,convocados\n");
			for (int i = 0; i < len; i++)
			{
				pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, i);

				if (pNationalTeam != NULL && getIdNationalTeam(pNationalTeam, &auxId) == SUCCESS && getCountryNationalTeam(pNationalTeam, auxCountry) == SUCCESS && getConfederationNationalTeam(pNationalTeam, auxConfederation) == SUCCESS && getCalledUpNationalTeam(pNationalTeam, &auxCalledUp) == SUCCESS)
				{
					fprintf(pFile, "%d,%s,%s,%d\n", auxId, auxCountry, auxConfederation, auxCalledUp);
					returnControllerSaveNationalTeamTextMode = SUCCESS;
				}
			}
		}
	}
	fclose(pFile);
	return returnControllerSaveNationalTeamTextMode;
}

int controllerLoadIdplayerTextMode(char *path, int *pIdPlayer)
{
	int returnControllerIdplayerTextMode = ERROR;
	FILE *pFile = NULL;

	if (path != NULL && pIdPlayer)
	{
		pFile = fopen(path, "r");

		if (pFile != NULL)
		{
			if (parserIdPlayerFromText(pFile, pIdPlayer) == SUCCESS)
			{
				returnControllerIdplayerTextMode = SUCCESS;
			}
			fclose(pFile);
		}
	}
	return returnControllerIdplayerTextMode;
}

int controllerGetIncrementalIdPlayer()
{
	int returnControllerGetIncrementalIdPlayer = ERROR;
	static int flag = 0;
	static int idAutoincremental;

	if (flag == 0)
	{
		controllerLoadIdplayerTextMode("IdJugadoresAutoincremental.csv", &idAutoincremental);
	}
	flag = 1;
	idAutoincremental++;

	returnControllerGetIncrementalIdPlayer = idAutoincremental;

	return returnControllerGetIncrementalIdPlayer;
}

int controllerSaveIdplayerTextMode(char *path)
{
	int returnControllerSaveIdplayerTextMode;
	int idIncremented;
	FILE *pFile = NULL;

	pFile = fopen(path, "r+");
	if (pFile != NULL)
	{
		idIncremented = controllerGetIncrementalIdPlayer();
		idIncremented = idIncremented - 1;
		fprintf(pFile, "%d\n", idIncremented);
		returnControllerSaveIdplayerTextMode = SUCCESS;
	}
	fclose(pFile);

	return returnControllerSaveIdplayerTextMode;
}

int controllerSavePlayersByConfederationBinaryMode(char *path, LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam, char *confederationRegister)
{
	int returnControllerGetPlayersByConfederation = ERROR;
	int lenListPlayer;
	int auxIdPlayer;
	char auxConfederation[30];
	sPlayer *pPlayer = NULL;
	LinkedList *pArrayListPlayerAux = ll_clone(pArrayListPlayer);
	LinkedList *pArrayListPlayerAuxNew = ll_newLinkedList();
	if (pArrayListPlayer != NULL && pArrayListNationalTeam != NULL && confederationRegister != NULL)
	{
		lenListPlayer = ll_len(pArrayListPlayerAux);

		for (int i = 0; i < lenListPlayer; i++)
		{
			pPlayer = (sPlayer*) ll_get(pArrayListPlayerAux, i);

			getIdNationalTeamPLayer(pPlayer, &auxIdPlayer);

			if (auxIdPlayer > 0 && controllerGetConfederation(pArrayListNationalTeam, auxIdPlayer, auxConfederation) == SUCCESS)
			{
				if (stricmp(auxConfederation, confederationRegister) == 0)
				{
					ll_add(pArrayListPlayerAuxNew, pPlayer);
					controllerSavePlayersBinarytMode(path, pArrayListPlayerAuxNew);
					returnControllerGetPlayersByConfederation = SUCCESS;
				}
			}
		}
	}
	return returnControllerGetPlayersByConfederation;
}

int controllerLoadPlayersByConfederationFromBinary(char *path, LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam, char *confederationRegister)
{
	int returnControllerGetPlayersByConfederation = ERROR;
	int lenListPlayer;
	int auxIdPlayer;
	char auxConfederation[30];
	LinkedList *pArrayListPlayerAux = ll_clone(pArrayListPlayer);
	LinkedList *pArrayListPlayerAuxNew = ll_newLinkedList();
	sPlayer *pPlayer;

	if (pArrayListPlayer != NULL && pArrayListNationalTeam != NULL && confederationRegister != NULL)
	{
		if (controllerLoadPlayerFromBinary(path, pArrayListPlayerAux) == SUCCESS)
		{
			lenListPlayer = ll_len(pArrayListPlayerAux);

			for (int i = 0; i < lenListPlayer; i++)
			{
				pPlayer = (sPlayer*) ll_get(pArrayListPlayerAux, i);

				getIdNationalTeamPLayer(pPlayer, &auxIdPlayer);

				if (auxIdPlayer > 0 && controllerGetConfederation(pArrayListNationalTeam, auxIdPlayer, auxConfederation) == SUCCESS)
				{
					if (stricmp(auxConfederation, confederationRegister) == 0)
					{
						ll_add(pArrayListPlayerAuxNew, pPlayer);
					}
				}
			}
			controllerListPlayersNationalTeam(pArrayListPlayerAuxNew, pArrayListNationalTeam, 1);
		}
		returnControllerGetPlayersByConfederation = SUCCESS;
	}
	return returnControllerGetPlayersByConfederation;
}

int controllerGetCountry(LinkedList *pArrayListNationalTeam, int idNationalTeamPLayer, char *pCountry)
{
	int returnControllerGetCountry = ERROR;
	int lenListNationalTeam;
	int i;
	int id;
	char country[30];
	sNationalTeam *pNationalTeam;

	if (pArrayListNationalTeam != NULL && pCountry != NULL)
	{
		lenListNationalTeam = ll_len(pArrayListNationalTeam);
		for (i = 0; i < lenListNationalTeam; i++)
		{
			pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, i);
			getIdNationalTeam(pNationalTeam, &id);
			if (id == idNationalTeamPLayer && getCountryNationalTeam(pNationalTeam, country) == SUCCESS)
			{
				strcpy(pCountry, country);
				returnControllerGetCountry = SUCCESS;
				break;
			}
			else
			{
				strcpy(pCountry, "NO CONVOCADO");
			}
		}
	}
	return returnControllerGetCountry;
}

int controllerGetConfederation(LinkedList *pArrayListNationalTeam, int idNationalTeam, char *confederation)
{
	int returnControllerGetConfederation = ERROR;
	int lenListNationalTeam;
	int auxIdNationalTeam;
	char auxConfederation[30];
	sNationalTeam *pNationalTeam = NULL;

	if (pArrayListNationalTeam != NULL && confederation != NULL && idNationalTeam > 0)
	{
		lenListNationalTeam = ll_len(pArrayListNationalTeam);

		for (int i = 0; i < lenListNationalTeam; i++)
		{
			pNationalTeam = (sNationalTeam*) ll_get(pArrayListNationalTeam, i);

			if (pNationalTeam != NULL)
			{
				getIdNationalTeam(pNationalTeam, &auxIdNationalTeam);

				if (auxIdNationalTeam == idNationalTeam && getConfederationNationalTeam(pNationalTeam, auxConfederation) == SUCCESS)
				{
					strcpy(confederation, auxConfederation);
					returnControllerGetConfederation = SUCCESS;
				}
			}
		}
	}
	return returnControllerGetConfederation;
}

