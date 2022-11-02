#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jugador.h"
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
		newPlayer->isEmpty = 0;

	}

	return newPlayer;

}

sPlayer* newPlayerParameters(char *idStr, char *fullNameStr, char *ageStr, char *positionStr, char *nationalityStr, char *idNationalTeamStr)
{

	sPlayer *auxNewPlayer = newPlayer();

	if (auxNewPlayer != NULL)
	{
		if (!(setIdPlayer(auxNewPlayer, atoi(idStr))
			&& setFullNamePlayer(auxNewPlayer, fullNameStr)
			&& setAgePlayer(auxNewPlayer, atoi(ageStr))
			&& setPositionPlayer(auxNewPlayer, positionStr)
			&& setNationalityPlayer(auxNewPlayer, nationalityStr)
			&& setNationalityPlayer(auxNewPlayer, atoi(idNationalTeamStr))))
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

	if (this != NULL && idNationalTeam > 0)
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

int setIsEmptyPlayer(sPlayer *this, int isEmpty)
{
	int returnSetConfederationId = ERROR;

	if (this != NULL)
	{
		this->isEmpty = isEmpty;
		returnSetConfederationId = SUCCESS;
	}

	return returnSetConfederationId;
}

int getIsEmptyPlayer(sPlayer *this, int *isEmpty)
{
	int returnGetConfederationId = ERROR;

	if (this != NULL && isEmpty != NULL)
	{
		*isEmpty = this->isEmpty;
		returnGetConfederationId = SUCCESS;
	}

	return returnGetConfederationId;
}

