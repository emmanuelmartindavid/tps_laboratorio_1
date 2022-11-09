#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
#include "validaciones.h"
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

sPlayer* newPlayerParameters(char *idStr, char *fullNameStr, char *ageStr, char *positionStr, char *nationalityStr, char *idNationalTeamStr)
{

	sPlayer *auxNewPlayer = newPlayer();

	if (idStr != NULL && fullNameStr != NULL && ageStr != NULL && positionStr != NULL && nationalityStr != NULL && idNationalTeamStr != NULL && auxNewPlayer != NULL)
	{
		if (!(setIdPlayer(auxNewPlayer, atoi(idStr))
			&& setFullNamePlayer(auxNewPlayer, fullNameStr)
			&& setAgePlayer(auxNewPlayer, atoi(ageStr))
			&& setPositionPlayer(auxNewPlayer, positionStr)
			&& setNationalityPlayer(auxNewPlayer, nationalityStr)
			&& setIdNationalTeamPlayer(auxNewPlayer, atoi(idNationalTeamStr))))
		{
			deletePlayer(auxNewPlayer);
			auxNewPlayer = NULL;
		}
	}

	return auxNewPlayer;

}

void deletePlayer(sPlayer *this)
{

	free(this);

}

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

int setAgePlayer(sPlayer *this, int age)
{
	int returnSetHiringYears = ERROR;

	if (this != NULL && age > 0)
	{
		this->age = age;
		returnSetHiringYears = SUCCESS;
	}

	return returnSetHiringYears;
}

int getAgePlayer(sPlayer *this, int *age)
{
	int returnGetHiringYears = ERROR;

	if (this != NULL && age != NULL)
	{
		*age = this->age;
		returnGetHiringYears = SUCCESS;
	}

	return returnGetHiringYears;
}

int setPositionPlayer(sPlayer *this, char *position)
{

	int returnSetPostion = ERROR;

	if (this != NULL && position != NULL)
	{
		strcpy(this->position, position);
		returnSetPostion = SUCCESS;
	}

	return returnSetPostion;
}

int getPositionPlayer(sPlayer *this, char *position)
{

	int returnGetPostion = ERROR;

	if (this != NULL && position != NULL)
	{
		strcpy(position, this->position);
		returnGetPostion = SUCCESS;
	}

	return returnGetPostion;
}

int setNationalityPlayer(sPlayer *this, char *nationality)
{

	int returnSetPostion = ERROR;

	if (this != NULL && nationality != NULL)
	{
		strcpy(this->nationality, nationality);
		returnSetPostion = SUCCESS;
	}

	return returnSetPostion;
}

int getNationalityPlayer(sPlayer *this, char *nationality)
{

	int returnGetPostion = ERROR;

	if (this != NULL && nationality != NULL)
	{
		strcpy(nationality, this->nationality);
		returnGetPostion = SUCCESS;
	}

	return returnGetPostion;
}

int setIdNationalTeamPlayer(sPlayer *this, int idNationalTeam)
{
	int returnSetShirtNumber = ERROR;

	if (this != NULL && idNationalTeam >= 0)
	{
		this->idNationalTeam = idNationalTeam;
		returnSetShirtNumber = SUCCESS;
	}

	return returnSetShirtNumber;
}

int getIdNationalTeamPLayer(sPlayer *this, int *idNationalTeam)
{
	int returnGetShirtNumber = ERROR;

	if (this != NULL && idNationalTeam != NULL)
	{
		*idNationalTeam = this->idNationalTeam;
		returnGetShirtNumber = SUCCESS;
	}

	return returnGetShirtNumber;
}

int editFullNamePlayer(sPlayer *this)
{
	int returnModifyFullNamePlayer;
	char auxFullName[100];
	if (this != NULL)
	{
		if (utn_getAlphabeticDescription(auxFullName, "Ingrese su nombre.\n", "Error. Reintente.\n", 3, 100, 1) == 0)
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

int editAgePlayer(sPlayer *this)
{
	int returnEditAgePlayer;
	int auxAge;
	if (this != NULL)
	{
		if (utn_getNumber(&auxAge, "Ingrese su edad. Rangos entre 18 a 40 anios.\n", "Error. Reintente.\n", 18, 40, 3) == 0)
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

int comparePlayersByAge(void *pPlayerOne, void *pPlayerTwo)
{
	int returncomparePlayersByAge = ERROR;
	int agePlayerOne;
	int agePlayerTwo;

	if (pPlayerOne != NULL && pPlayerTwo != NULL)
	{
		getAgePlayer(pPlayerOne, &agePlayerOne);
		getAgePlayer(pPlayerTwo, &agePlayerTwo);

		if (agePlayerOne > agePlayerTwo)
		{
			returncomparePlayersByAge = 1;
		}
		else
		{
			returncomparePlayersByAge = 0;
		}
	}
	return returncomparePlayersByAge;
}

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

void showPlayerData()
{

	printf("\t\t\t\t\t\t========================================================================================================\n");
	printf("\t\t\t\t\t\t|  ID |               NOMBRE               | EDAD |        POSICION          |   NACIONALIDAD          |\n");
	printf("\t\t\t\t\t\t========================================================================================================\n");

}

void showPlayerDataNationalTeam()
{
	printf("\t\t\t\t\t\t=================================================================================================================================\n");
			printf("\t\t\t\t\t\t|  ID |               NOMBRE               | EDAD |        POSICION          |   NACIONALIDAD          |   SELECCION            |\n");
			printf("\t\t\t\t\t\t=================================================================================================================================\n");
}
void showLine()
{
	printf("\t\t\t\t\t\t========================================================================================================\n");

}
