#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Seleccion.h"
#define ERROR -1
#define SUCCESS 1
/// @brief	newNationalTeam 					CONTRSTRUCTOR DE ENTIDAD SELECCION EN MEMORIA DINAMICA.
///
/// @return			 						    RETORNA PUNTERO DE ENTIDAD CREADO EN MEMORIA DINAMICA EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
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
/// @brief newNationalTeamParameters				CONTRUCTOR DE ENTIDAD SELECCION CON SU PARAMETROS A SETEAR.
///
/// @param idStr									PUNTERO STRING.
/// @param countryStr								PUNTERO STRING.
/// @param confederationStr							PUNTERO STRING.
/// @param calledUpStr								PUNTERO STRING.
/// @return											RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
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
/// @brief	deleteNatioanalTeam				LIBERA ESPACIO EN MEMORIA DINAMICA DEL TIPO PUNTERO POR PARAMETRO EN CASO DE SER NECESARIO.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA SELECCION.
void deleteNatioanalTeam(sNationalTeam *this)
{
	free(this);
}
/// @brief getIdNationalTeam				OBTIENE ID DE SELECCION.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param id								PUNTERO ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdNationalTeam(sNationalTeam *this, int *id)
{
	int returnGetIdNationalTeam = ERROR;

	if (this != NULL && id != NULL)
	{
		*id = this->id;
		returnGetIdNationalTeam = SUCCESS;
	}
	return returnGetIdNationalTeam;
}
/// @brief getCountryNationalTeam				OBTIENE PAIS DE SELECCION.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param country								PUNTERO ENTERO.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCountryNationalTeam(sNationalTeam *this, char *country)
{
	int returnGetCountryNationalTeam = ERROR;

	if (this != NULL && country != NULL)
	{
		strcpy(country, this->country);
		returnGetCountryNationalTeam = SUCCESS;
	}
	return returnGetCountryNationalTeam;
}
/// @brief getConfederationNationalTeam					OBTIENE CONFEDERACION DE SELECCION.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param confederation								PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getConfederationNationalTeam(sNationalTeam *this, char *confederation)
{
	int returnGetConfederationNationalTeam = ERROR;

	if (this != NULL && confederation != NULL)
	{
		strcpy(confederation, this->confederation);
		returnGetConfederationNationalTeam = SUCCESS;
	}
	return returnGetConfederationNationalTeam;
}
/// @brief setCalledUpNationalTeam			SETEA CONVOCADOS DE SELECCION.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param calledUp							ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setCalledUpNationalTeam(sNationalTeam *this, int calledUp)
{

	int returnSetCalledUpNationalTeam = ERROR;

	if (this != NULL && calledUp >= 0 && calledUp <= 22)
	{
		this->calledUp = calledUp;
		returnSetCalledUpNationalTeam = SUCCESS;
	}

	return returnSetCalledUpNationalTeam;
}
/// @brief getCalledUpNationalTeam				OBTIENE CONVOCADOS DE SELECCION.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param calledUp									PUNTERO ENTERO.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCalledUpNationalTeam(sNationalTeam *this, int *calledUp)
{

	int returnGetCalledUpNationalTeam = ERROR;

	if (this != NULL && calledUp != NULL)
	{
		*calledUp = this->calledUp;
		returnGetCalledUpNationalTeam = SUCCESS;
	}

	return returnGetCalledUpNationalTeam;
}
/// @brief	listOneNationalTeam								LISTA UNA SELECCION.
///
/// @param this												PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @return													RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int listOneNationalTeam(sNationalTeam *this)
{
	int returnListOneNationalTeam = ERROR;
	int auxId;
	char auxCountry[30];
	char auxConfederation[30];
	int auxCalledUp;

	if (this != NULL)
	{
		if (getIdNationalTeam(this, &auxId) == SUCCESS && getCountryNationalTeam(this, auxCountry) == SUCCESS && getConfederationNationalTeam(this, auxConfederation) == SUCCESS && getCalledUpNationalTeam(this, &auxCalledUp) == SUCCESS)
		{

			printf("\t\t\t\t\t\t|%-5d| %-25s| %-25s| %-10d|\n", auxId, auxCountry, auxConfederation, auxCalledUp);
			returnListOneNationalTeam=SUCCESS;
		}
	}
	return returnListOneNationalTeam;
}
/// @brief compareNationalTeamByConfederation			COMPARA SELECCIONES POR CONFEDERACION.
///
/// @param pPlayerOne									PUNTERO TIPO VOID.
/// @param pPlayerTwo									PUNTERO TIPO VOID.
/// @return												RETORNO COMPARACION DE STRCIMP.
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
/// @brief compareNationalTeamById				COMPARA SELECCIONES POR ID.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNO IDS
int compareNationalTeamById(void *nationaTeamOne, void *nationalTeamTwo)
{
	int returnCompareNationalTeamById;
	int id1;
	int id2;
	if (nationaTeamOne != NULL && nationalTeamTwo != NULL)
		{
			getIdNationalTeam(nationaTeamOne, &id1);
			getIdNationalTeam(nationalTeamTwo, &id2);

			if(id1>id2)
			{
				returnCompareNationalTeamById=1;
			}

		}


	return returnCompareNationalTeamById;
}
/// @brief 			MUESTRA DATOS DE SELECCION
///
void showNationalTeamData()
{
	printf("\t\t\t\t\t\t=========================================================================\n");
	printf("\t\t\t\t\t\t|  ID |        PAIS              |       CONFEDERACION      |CONVOCADOS |\n");
	printf("\t\t\t\t\t\t=========================================================================\n");
}
/// @brief
///
void showLineNT()
{
	printf("\t\t\t\t\t\t=========================================================================\n");

}
