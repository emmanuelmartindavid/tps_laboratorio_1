#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "validaciones.h"
#include "menus.h"
#define NOEDIT 3
/// @brief	newPlayer 					CONTRSTRUCTOR DE ENTIDAD JUGADOR EN MEMORIA DINAMICA.
///
/// @return			 					 RETORNA PUNTERO DE ENTIDAD CREADO EN MEMORIA DINAMICA EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sPlayer* newPlayer()
{
	sPlayer *newPlayer = NULL;
	newPlayer = (sPlayer*) malloc(sizeof(sPlayer));
	if (newPlayer != NULL)
	{
		newPlayer->id = 0;
		strcpy(newPlayer->fullName, " ");
		newPlayer->age = 0;
		strcpy(newPlayer->position, " ");
		strcpy(newPlayer->nationality, " ");
		newPlayer->idNationalTeam = 0;
	}
	return newPlayer;
}
/// @brief newPlayerParameters				CONTRUCTOR DE ENTIDAD JUGADOR CON SU PARAMETROS A SETEAR.
///
/// @param idStr							PUNTERO STRING.
/// @param fullNameStr						PUNTERO STRING.
/// @param ageStr							PUNTERO STRING.
/// @param positionStr						PUNTERO STRING.
/// @param nationalityStr					PUNTERO STRING.
/// @param idNationalTeamStr				PUNTERO STRING.
/// @return									RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sPlayer* newPlayerParameters(char *idStr, char *fullNameStr, char *ageStr, char *positionStr, char *nationalityStr, char *idNationalTeamStr)
{
	sPlayer *auxNewPlayer = newPlayer();
	if (idStr != NULL && fullNameStr != NULL && ageStr != NULL && positionStr != NULL && nationalityStr != NULL && idNationalTeamStr != NULL && auxNewPlayer != NULL)
	{
		if (!(setIdPlayer(auxNewPlayer, atoi(idStr)) && setFullNamePlayer(auxNewPlayer, fullNameStr) && setAgePlayer(auxNewPlayer, atoi(ageStr)) && setPositionPlayer(auxNewPlayer, positionStr) && setNationalityPlayer(auxNewPlayer, nationalityStr) && setIdNationalTeamPlayer(auxNewPlayer, atoi(idNationalTeamStr))))
		{
			deletePlayer(auxNewPlayer);
			auxNewPlayer = NULL;
		}
	}
	return auxNewPlayer;
}
/// @brief	deletePlayer					LIBERA ESPACIO EN MEMORIA DINAMICA DEL TIPO PUNTERO POR PARAMETRO EN CASO DE SER NECESARIO.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
void deletePlayer(sPlayer *this)
{
	free(this);
}
/// @brief setIdPlayer						SETEA ID DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param id								ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setIdPlayer(sPlayer *this, int id)
{

	int returnSetIdPlayer = ERROR;

	if (this != NULL && id > 0)
	{
		this->id = id;
		returnSetIdPlayer = SUCCESS;
	}

	return returnSetIdPlayer;
}
/// @brief	getIdPlayer						OBTIENE ID DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param id								PUNTERO ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdPlayer(sPlayer *this, int *id)
{

	int returnGetIdPlayer = ERROR;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		returnGetIdPlayer = SUCCESS;
	}
	return returnGetIdPlayer;
}
/// @brief setFullNamePlayer				SETEA NOMBRE DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param fullName							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setFullNamePlayer(sPlayer *this, char *fullName)
{

	int returnSetName = ERROR;

	if (this != NULL && fullName != NULL)
	{
		strcpy(this->fullName, fullName);
		returnSetName = SUCCESS;
	}

	return returnSetName;
}
/// @brief getFullNamePlayer				OBTIENE NOMBRE DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param fullName							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getFullNamePlayer(sPlayer *this, char *fullName)
{

	int returnGetName = ERROR;

	if (this != NULL && fullName != NULL)
	{
		strcpy(fullName, this->fullName);
		returnGetName = SUCCESS;
	}
	return returnGetName;
}
/// @brief setAgePlayer						SETEA EDAD DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param age								ENTERO
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setAgePlayer(sPlayer *this, int age)
{
	int returnSetAgePlayer = ERROR;

	if (this != NULL && age > 0)
	{
		this->age = age;
		returnSetAgePlayer = SUCCESS;
	}

	return returnSetAgePlayer;
}
/// @brief getAgePlayer						OBTIENE EDAD DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param age								PUNTERO ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getAgePlayer(sPlayer *this, int *age)
{
	int returnGetAgePlayer = ERROR;

	if (this != NULL && age != NULL)
	{
		*age = this->age;
		returnGetAgePlayer = SUCCESS;
	}
	return returnGetAgePlayer;
}
/// @brief setPositionPlayer 				SETEA POSICION DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param position							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setPositionPlayer(sPlayer *this, char *position)
{

	int returnSetPostionPlayer = ERROR;

	if (this != NULL && position != NULL)
	{
		strcpy(this->position, position);
		returnSetPostionPlayer = SUCCESS;
	}

	return returnSetPostionPlayer;
}
/// @brief getPositionPlayer				OBTIENE POSICION DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param position							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getPositionPlayer(sPlayer *this, char *position)
{

	int returnGetPostionPlayer = ERROR;

	if (this != NULL && position != NULL)
	{
		strcpy(position, this->position);
		returnGetPostionPlayer = SUCCESS;
	}

	return returnGetPostionPlayer;
}
/// @brief setNationalityPlayer					SETEA NACIONALIDAD DE JUGADOR.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param nationality							PUNTERO STRING.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setNationalityPlayer(sPlayer *this, char *nationality)
{

	int returnSetNationalityPlayer = ERROR;

	if (this != NULL && nationality != NULL)
	{
		strcpy(this->nationality, nationality);
		returnSetNationalityPlayer = SUCCESS;
	}

	return returnSetNationalityPlayer;
}
/// @brief	getNationalityPlayer					OBTIENE NACIONALIDAD DE JUGADOR.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param nationality								PUNTERO STRING.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getNationalityPlayer(sPlayer *this, char *nationality)
{

	int returnGetNationalityPlayer = ERROR;

	if (this != NULL && nationality != NULL)
	{
		strcpy(nationality, this->nationality);
		returnGetNationalityPlayer = SUCCESS;
	}

	return returnGetNationalityPlayer;
}
/// @brief	setIdNationalTeamPlayer						SETEA ID SELECCION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param idNationalTeam								ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setIdNationalTeamPlayer(sPlayer *this, int idNationalTeam)
{
	int returnSetIdNationalTeamPlayer = ERROR;

	if (this != NULL && idNationalTeam >= 0)
	{
		this->idNationalTeam = idNationalTeam;
		returnSetIdNationalTeamPlayer = SUCCESS;
	}

	return returnSetIdNationalTeamPlayer;
}
/// @brief getIdNationalTeamPLayer						OBTIENE ID SELECCION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param idNationalTeam								PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdNationalTeamPLayer(sPlayer *this, int *idNationalTeam)
{
	int returnGetIdNationalTeamPLayer = ERROR;

	if (this != NULL && idNationalTeam != NULL)
	{
		*idNationalTeam = this->idNationalTeam;
		returnGetIdNationalTeamPLayer = SUCCESS;
	}

	return returnGetIdNationalTeamPLayer;
}
/// @brief	listOnePlayer								LISTA UN JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int listOnePlayer(sPlayer *this)
{
	int returncontrollerListOnePlayer = ERROR;
	int auxId;
	char auxFullName[100];
	int auxAge;
	char auxPosition[30];
	char auxNationality[30];

	if (this != NULL)
	{
		if (getIdPlayer(this, &auxId) == SUCCESS && getFullNamePlayer(this, auxFullName) == SUCCESS && getAgePlayer(this, &auxAge) == SUCCESS && getPositionPlayer(this, auxPosition) == SUCCESS && getNationalityPlayer(this, auxNationality) == SUCCESS)
		{
			printf("\t\t|%-5d| %-35s| %-5d| %-25s| %-24s|\n", auxId, auxFullName, auxAge, auxPosition, auxNationality);
			returncontrollerListOnePlayer = SUCCESS;
		}
	}
	return returncontrollerListOnePlayer;
}
/// @brief editFullNamePlayer						EDICION DE NOMBRE DE JUGADOR.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editFullNamePlayer(sPlayer *this)
{
	int returnModifyFullNamePlayer;
	char auxFullName[100];
	if (this != NULL)
	{
		if (utn_getAlphabeticDescription(auxFullName, "INGRESE SU NOMBRE.\n", "ERROR. REINTENTE.\n", 3, 100, 1) == 0)
		{
			if (setFullNamePlayer(this, auxFullName) == SUCCESS)
			{
				returnModifyFullNamePlayer = SUCCESS;
			}
		}
		else
		{
			returnModifyFullNamePlayer = ERROR;
		}
	}
	return returnModifyFullNamePlayer;
}
/// @brief editAgePlayer						EDICION DE EDAD DE JUGADOR.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editAgePlayer(sPlayer *this)
{
	int returnEditAgePlayer;
	int auxAge;
	if (this != NULL)
	{
		if (utn_getNumber(&auxAge, "INGRESE SU EDAD. RANGO PERMITIDO, 18 A 40 ANIOS INCLUSIVE.\n", "ERROR. REINTENTE.\n", 18, 40, 3) == 0)
		{
			if (setAgePlayer(this, auxAge) == SUCCESS)
			{
				returnEditAgePlayer = SUCCESS;
			}
		}
		else
		{
			returnEditAgePlayer = ERROR;
		}
	}
	return returnEditAgePlayer;
}
/// @brief editPositionPlayer				EDICION DE POSICION DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editPositionPlayer(sPlayer *this)
{
	int returnEditPositionPlayer;
	char auxPosition[30];
	if (this != NULL)
	{
		if (utn_getPositionPlayer(auxPosition) == 0)
		{
			if (setPositionPlayer(this, auxPosition) == SUCCESS)
			{
				returnEditPositionPlayer = SUCCESS;
			}
		}
		else
		{
			returnEditPositionPlayer = ERROR;
		}
	}
	return returnEditPositionPlayer;
}
/// @brief editNationalityPlayer			EDICION DE NACIONALIDAD DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editNationalityPlayer(sPlayer *this)
{
	int returnEditNationalityPlayer;
	char auxNationality[30];
	if (this != NULL)
	{
		if (utn_getNationalityPlayer(auxNationality) == 0)
		{
			if (setNationalityPlayer(this, auxNationality) == SUCCESS)
			{
				returnEditNationalityPlayer = SUCCESS;
			}
		}
		else
		{
			returnEditNationalityPlayer = ERROR;
		}
	}
	return returnEditNationalityPlayer;
}
/// @brief editOnePlayer			EDICION DE UN JUGADOR.
///
/// @param this						PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return							RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO. RETORNO 3 EN CASO DE NO HABER REALIZADO MODIFICACIONES EN EL JUGADOR.
int editOnePlayer(sPlayer *this)
{
	int returnrEditOnePlayer;
	int optionEditMenu;
	int flagEditPlayer = NOEDIT;
	do
	{
		showPlayerData();
		listOnePlayer(this);
		showLine();
		showEditPlayerMenu();
		if (utn_getNumber(&optionEditMenu, "INGRESE OPCION.\n", "ERROR. REINTENTE.\n", 1, 5, 3) == 0)
		{
			switch (optionEditMenu)
			{
			case 1:
				if (editFullNamePlayer(this) == SUCCESS)
				{
					flagEditPlayer = SUCCESS;
				}
				else
				{
					flagEditPlayer = NOEDIT;
				}
				break;
			case 2:
				if (editAgePlayer(this) == SUCCESS)
				{
					flagEditPlayer = SUCCESS;
				}
				else
				{
					flagEditPlayer = NOEDIT;
				}
				break;
			case 3:
				if (editPositionPlayer(this) == SUCCESS)
				{
					flagEditPlayer = SUCCESS;
				}
				else
				{
					flagEditPlayer = NOEDIT;
				}
				break;
			case 4:
				if (editNationalityPlayer(this) == SUCCESS)
				{
					flagEditPlayer = SUCCESS;
				}
				else
				{
					flagEditPlayer = NOEDIT;
				}
				break;
			}
		}
		else
		{
			returnrEditOnePlayer = ERROR;
			break;
		}
	} while (optionEditMenu != 5);
	returnrEditOnePlayer = flagEditPlayer;

	return returnrEditOnePlayer;

}

/// @brief comparePlayersByNationality			COMPARA JUGADORES POR NACIONALIDAD.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNO COMPARACION DE STRCIMP.
int comparePlayersByNationality(void *pPlayerOne, void *pPlayerTwo)
{
	int returnComparePlayersByNationality;
	char nationalityPlayerOne[30];
	char nationalityPlayerTwo[30];

	if (pPlayerOne != NULL && pPlayerTwo != NULL)
	{
		getNationalityPlayer(pPlayerOne, nationalityPlayerOne);
		getNationalityPlayer(pPlayerTwo, nationalityPlayerTwo);
		returnComparePlayersByNationality = stricmp(nationalityPlayerOne, nationalityPlayerTwo);

	}
	return returnComparePlayersByNationality;
}
/// @brief comparePlayersByAgeAndName			COMPARA JUGADORES POR EDAD Y NOMBRES.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNA COMPARACION DE EDAD Y  DE  STRCIMP EN CASO DE IGUALDAD DE EDAD.
int comparePlayersByAgeAndName(void *pPlayerOne, void *pPlayerTwo)
{
	int returncomparePlayersByAge = 0;
	int agePlayerOne;
	int agePlayerTwo;
	char fullNamePlayerOne[30];
	char fullNamePlayerTwo[30];
	if (pPlayerOne != NULL && pPlayerTwo != NULL)
	{
		getAgePlayer(pPlayerOne, &agePlayerOne);
		getAgePlayer(pPlayerTwo, &agePlayerTwo);

		if (agePlayerOne > agePlayerTwo)
		{
			returncomparePlayersByAge = 1;
		}
		else if (agePlayerOne < agePlayerTwo)
		{
			returncomparePlayersByAge = -1;
		}
		else if (agePlayerOne == agePlayerTwo)
		{
			getFullNamePlayer(pPlayerOne, fullNamePlayerOne);
			getFullNamePlayer(pPlayerTwo, fullNamePlayerTwo);
			returncomparePlayersByAge = stricmp(fullNamePlayerOne, fullNamePlayerTwo);
		}
	}
	return returncomparePlayersByAge;
}
/// @brief comparePlayersByName			COMPARA JUGADORES POR NOMBRE.
///
/// @param pPlayerOne					PUNTERO TIPO VOID.
/// @param pPlayerTwo					PUNTERO TIPO VOID.
/// @return								RETONAR COMPARACION DE STRICMP
int comparePlayersByName(void *pPlayerOne, void *pPlayerTwo)
{
	int returncomparePlayersByName = ERROR;
	char fullNamePlayerOne[30];
	char fullNamePlayerTwo[30];

	if (pPlayerOne != NULL && pPlayerTwo != NULL)
	{
		getFullNamePlayer(pPlayerOne, fullNamePlayerOne);
		getFullNamePlayer(pPlayerTwo, fullNamePlayerTwo);
		returncomparePlayersByName = stricmp(fullNamePlayerOne, fullNamePlayerTwo);
	}
	return returncomparePlayersByName;
}
/// @brief showPlayerData  MUESTRA DATOS DE JUGADOR.
///
void showPlayerData()
{

	printf("\t\t========================================================================================================\n");
	printf("\t\t|  ID |               NOMBRE               | EDAD |        POSICION          |   NACIONALIDAD          |\n");
	printf("\t\t========================================================================================================\n");

}
/// @brief showPlayerDataNationalTeam		MUESTRA DATOS DE JUGADOR CON SELECCION.
///
void showPlayerDataNationalTeam()
{
	printf("\t\t\t================================================================================================================================\n");
	printf("\t\t\t|        SELECCION      | ID  |              NOMBRE                | EDAD |          POSICION        |      NACIONALIDAD       |\n");
	printf("\t\t\t================================================================================================================================\n");
}
/// @brief showLine
///
void showLine()
{
	printf("\t\t========================================================================================================\n");

}

