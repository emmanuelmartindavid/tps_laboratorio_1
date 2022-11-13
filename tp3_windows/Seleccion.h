#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char country[30];
	char confederation[30];
	int calledUp;

}sNationalTeam;
/// @brief	newNationalTeam 					CONTRSTRUCTOR DE ENTIDAD SELECCION EN MEMORIA DINAMICA.
///
/// @return			 						    RETORNA PUNTERO DE ENTIDAD CREADO EN MEMORIA DINAMICA EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sNationalTeam* newNationalTeam();
/// @brief newNationalTeamParameters				CONTRUCTOR DE ENTIDAD SELECCION CON SU PARAMETROS A SETEAR.
///
/// @param idStr									PUNTERO STRING.
/// @param countryStr								PUNTERO STRING.
/// @param confederationStr							PUNTERO STRING.
/// @param calledUpStr								PUNTERO STRING.
/// @return											RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sNationalTeam* newNationalTeamParameters(char *idStr, char *countryStr, char *confederationStr, char *calledUpStr);
/// @brief	deleteNatioanalTeam				LIBERA ESPACIO EN MEMORIA DINAMICA DEL TIPO PUNTERO POR PARAMETRO EN CASO DE SER NECESARIO.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA SELECCION.
void deleteNatioanalTeam(sNationalTeam* this);
/// @brief getIdNationalTeam				OBTIENE ID DE SELECCION.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param id								PUNTERO ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdNationalTeam(sNationalTeam* this,int* id);
/// @brief getCountryNationalTeam				OBTIENE PAIS DE SELECCION.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param country								PUNTERO ENTERO.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCountryNationalTeam(sNationalTeam* this,char* country);
/// @brief getConfederationNationalTeam					OBTIENE CONFEDERACION DE SELECCION.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param confederation								PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getConfederationNationalTeam(sNationalTeam* this,char* confederation);
/// @brief setCalledUpNationalTeam			SETEA CONVOCADOS DE SELECCION.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param calledUp							ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setCalledUpNationalTeam(sNationalTeam* this,int calledUp);
/// @brief getCalledUpNationalTeam				OBTIENE CONVOCADOS DE SELECCION.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @param calledUp									PUNTERO ENTERO.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getCalledUpNationalTeam(sNationalTeam* this,int* calledUp);
/// @brief	listOneNationalTeam								LISTA UNA SELECCION.
///
/// @param this												PUNTERO DE TIPO ESTRUCTURA SELECCION.
/// @return													RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int compareNationalTeamById(void *nationaTeamOne, void *nationalTeamTwo);
/// @brief compareNationalTeamByConfederation			COMPARA SELECCIONES POR CONFEDERACION.
///
/// @param pPlayerOne									PUNTERO TIPO VOID.
/// @param pPlayerTwo									PUNTERO TIPO VOID.
/// @return												RETORNO COMPARACION DE STRCIMP.
int compareNationalTeamByConfederation(void *nationaTeamOne, void *nationalTeamTwo);
/// @brief compareNationalTeamById				COMPARA SELECCIONES POR ID.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNO IDS
int listOneNationalTeam(sNationalTeam *this);
/// @brief 			MUESTRA DATOS DE SELECCION
///
void showNationalTeamData();
/// @brief
///
void showLineNT();



#endif // selec_H_INCLUDED
