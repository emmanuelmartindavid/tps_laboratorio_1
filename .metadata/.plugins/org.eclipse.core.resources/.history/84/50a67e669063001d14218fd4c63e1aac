#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#define ERROR -1
#define SUCCESS 1

typedef struct
{
	int id;
	char fullName[100];
	int age;
	char position[30];
	char nationality[30];
	int idNationalTeam;
} sPlayer;
/// @brief	newPlayer 						 CONTRSTRUCTOR DE ENTIDAD JUGADOR EN MEMORIA DINAMICA.
///
/// @return			 						 RETORNA PUNTERO DE ENTIDAD CREADO EN MEMORIA DINAMICA EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sPlayer* newPlayer();
/// @brief newPlayerParameters				CONTRUCTOR DE ENTIDAD JUGADOR CON SU PARAMETROS A SETEAR.
///
/// @param idStr							PUNTERO STRING.
/// @param fullNameStr						PUNTERO STRING.
/// @param ageStr							PUNTERO STRING.
/// @param positionStr						PUNTERO STRING.
/// @param nationalityStr					PUNTERO STRING.
/// @param idNationalTeamStr				PUNTERO STRING.
/// @return									RETORNA PUNTERO DE ENTIDAD CREADO CON SUS PARAMETROS SETEADOS EN CASO CORRECTO. RETORNA NULL EN CASO CONTRARIO.
sPlayer* newPlayerParameters(char *idStr, char *fullNameStr, char *ageStr, char *positionStr, char *nationalityStr, char *idNationalTeamStr);
/// @brief	deletePlayer					LIBERA ESPACIO EN MEMORIA DINAMICA DEL TIPO PUNTERO POR PARAMETRO EN CASO DE SER NECESARIO.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
void deletePlayer(sPlayer *this);
/// @brief setIdPlayer						SETEA ID DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param id								ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setIdPlayer(sPlayer *this, int id);
/// @brief	getIdPlayer						OBTIENE ID DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param id								PUNTERO ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdPlayer(sPlayer *this, int *id);
/// @brief setFullNamePlayer				SETEA NOMBRE DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param fullName							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setFullNamePlayer(sPlayer *this, char *fullName);
/// @brief getFullNamePlayer				OBTIENE NOMBRE DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param fullName							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getFullNamePlayer(sPlayer *this, char *fullName);
/// @brief setAgePlayer						SETEA EDAD DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param age								ENTERO
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setAgePlayer(sPlayer *this, int age);
/// @brief getAgePlayer						OBTIENE EDAD DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param age								PUNTERO ENTERO.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getAgePlayer(sPlayer *this, int *age);
/// @brief setPositionPlayer 				SETEA POSICION DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param position							PUNTERO STRING.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setPositionPlayer(sPlayer *this, char *position);
/// @brief getPositionPlayer					OBTIENE POSICION DE JUGADOR.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param position								PUNTERO STRING.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getPositionPlayer(sPlayer *this, char *position);
/// @brief setNationalityPlayer					SETEA NACIONALIDAD DE JUGADOR.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param nationality							PUNTERO STRING.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setNationalityPlayer(sPlayer *this, char *nationality);
/// @brief	getNationalityPlayer					OBTIENE NACIONALIDAD DE JUGADOR.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param nationality								PUNTERO STRING.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getNationalityPlayer(sPlayer *this, char *nationality);
/// @brief	setIdNationalTeamPlayer						SETEA ID SELECCION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param idNationalTeam								ENTERO
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int setIdNationalTeamPlayer(sPlayer *this, int idNationalTeam);
/// @brief getIdNationalTeamPLayer						OBTIENE ID SELECCION DE JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @param idNationalTeam								PUNTERO ENTERO.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int getIdNationalTeamPLayer(sPlayer *this, int *idNationalTeam);
/// @brief	listOnePlayer								LISTA UN JUGADOR.
///
/// @param this											PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return												RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int listOnePlayer(sPlayer *this);
/// @brief editFullNamePlayer						EDICION DE NOMBRE DE JUGADOR.
///
/// @param this										PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return											RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editFullNamePlayer(sPlayer *this);
/// @brief editAgePlayer						EDICION DE EDAD DE JUGADOR.
///
/// @param this									PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return										RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editAgePlayer(sPlayer *this);
/// @brief editPositionPlayer				EDICION DE POSICION DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editPositionPlayer(sPlayer *this);
/// @brief editNationalityPlayer			EDICION DE NACIONALIDAD DE JUGADOR.
///
/// @param this								PUNTERO DE TIPO ESTRUCTURA JUGADOR.
/// @return									RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int editNationalityPlayer(sPlayer *this);
/// @brief comparePlayersByNationality			COMPARA JUGADORES POR NACIONALIDAD.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNO COMPARACION DE STRCIMP.
int comparePlayersByAgeAndName(void *pPlayerOne, void *pPlayerTwo);
/// @brief comparePlayersByAgeAndName			COMPARA JUGADORES POR EDAD Y NOMBRES.
///
/// @param pPlayerOne							PUNTERO TIPO VOID.
/// @param pPlayerTwo							PUNTERO TIPO VOID.
/// @return										RETORNA COMPARACION DE EDAD Y  DE  STRCIMP EN CASO DE IGUALDAD DE EDAD.
int comparePlayersByNationality(void *pPlayerOne, void *pPlayerTwo);
/// @brief comparePlayersByName			COMPARA JUGADORES POR NOMBRE.
///
/// @param pPlayerOne					PUNTERO TIPO VOID.
/// @param pPlayerTwo					PUNTERO TIPO VOID.
/// @return								RETONAR COMPARACION DE STRICMP
int comparePlayersByName(void *pPlayerOne, void *pPlayerTwo);
/// @brief showPlayerData  MUESTRA DATOS DE JUGADOR.
///
void showPlayerData();
/// @brief showPlayerDataNationalTeam		MUESTRA DATOS DE JUGADOR CON SELECCION.
///
void showPlayerDataNationalTeam();
/// @brief showLine
///
void showLine();

#endif // jug_H_INCLUDED
