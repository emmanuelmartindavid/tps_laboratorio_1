#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#define ERROR -1
#define SUCCESS 1
sNationalTeam* newNationalTeam()
{

	sNationalTeam *newNationalTeam = NULL;
	newNationalTeam = (sNationalTeam*) malloc(sizeof(sNationalTeam));

	if (newNationalTeam != NULL)
	{
		newNationalTeam->id = 0;
		strcpy(newNationalTeam->country, " ");
		strcpy(newNationalTeam->confederation, " ");
		newNationalTeam->calledUp = 0;

	}

	return newNationalTeam;

}

sNationalTeam* newNationalTeamParameters(char *idStr, char *countryStr, char *confederationStr, char *calledUpStr)
{

	sNationalTeam *auxNewNationalTeam = newNationalTeam();

	if (idStr != NULL && countryStr != NULL && confederationStr != NULL && calledUpStr != NULL && auxNewNationalTeam != NULL)
	{
		if (setCalledUpNationalTeam(auxNewNationalTeam, atoi(calledUpStr)) == SUCCESS)
		{

			auxNewNationalTeam->id = atoi(idStr);
			strcpy(auxNewNationalTeam->country, countryStr);
			strcpy(auxNewNationalTeam->confederation, confederationStr);

		}
		else
		{

			deleteNatioanalTeam(auxNewNationalTeam);
			auxNewNationalTeam = NULL;
		}
	}

	return auxNewNationalTeam;

}

void deleteNatioanalTeam(sNationalTeam *this)
{

	free(this);

}

int getIdNationalTeam(sNationalTeam *this, int *id)
{
	int retorno = ERROR;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		retorno = SUCCESS;
	}
	return retorno;
}
int getCountryNationalTeam(sNationalTeam *this, char *country)
{
	int retorno = ERROR;

	if (this != NULL && country != NULL)
	{
		strcpy(country, this->country);
		retorno = SUCCESS;
	}

	return retorno;
}
int getConfederationNationalTeam(sNationalTeam *this, char *confederation)
{
	int retorno = ERROR;

	if (this != NULL && confederation != NULL)
	{
		strcpy(confederation, this->confederation);
		retorno = SUCCESS;
	}

	return retorno;
}

int setCalledUpNationalTeam(sNationalTeam *this, int calledUp)
{

	int retorno = ERROR;

	if (this != NULL && calledUp >= 0 && calledUp <= 22)
	{
		this->calledUp = calledUp;
		retorno = SUCCESS;
	}

	return retorno;
}

int getCalledUpNationalTeam(sNationalTeam *this, int *calledUp)
{

	int retorno = ERROR;

	if (this != NULL && calledUp != NULL)
	{
		*calledUp = this->calledUp;
		retorno = SUCCESS;
	}

	return retorno;
}

int compareNationalTeamByConfederation(void *nationaTeamOne, void *nationalTeamTwo)
{
	int returnCompareNationalTeamByConfederation = ERROR;
	char confederationNationalTeamOne[30];
	char confederationNationalTeamtwo[30];

	if (nationaTeamOne != NULL && nationalTeamTwo != NULL)
	{
		getConfederationNationalTeam(nationaTeamOne, confederationNationalTeamOne);
		getConfederationNationalTeam(nationalTeamTwo, confederationNationalTeamtwo);
		returnCompareNationalTeamByConfederation = stricmp(confederationNationalTeamOne, confederationNationalTeamtwo);
	}
	return returnCompareNationalTeamByConfederation;
}
