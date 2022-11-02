#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
		newNationalTeam->isEmpty = 0;

	}

	return newNationalTeam;

}

sNationalTeam* selec_newParametros(char* idStr,char* paisStr,char* confederacionStr, char* convocadosStr)
{
	//Antes de cargar deben validarse los datos
	sNationalTeam *auxNewNationalTeam = newNationalTeam();

	if (auxNewNationalTeam != NULL)
	{
		if (!(jug_setId(auxNewNationalTeam, atoi(idStr))))
		{
			selec_delete(auxNewNationalTeam);
			auxNewNationalTeam = NULL;	//INDICA FUNCION NO ANDUVO BIEN.
		}
	}

	return auxNewNationalTeam;

}

void deleteNatioanalTeam(sNationalTeam* this)
{

	free(this);

}

int setcalledUpNationalTeam(sNationalTeam* this,int calledUp)
{

	int retorno = ERROR;

	if (this != NULL)
	{
		this->id = calledUp;
		retorno = SUCCESS;
	}

	return retorno;
}

int getcalledUpNationalTeam(sNationalTeam* this,int* calledUp)
{

	int retorno = ERROR;

	if (this != NULL && calledUp != NULL)
	{
		*calledUp = this->calledUp;
		retorno = SUCCESS;
	}

	return retorno;
}
