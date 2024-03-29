/*
 ============================================================================
 Name        : TP2_laboratorio.c
 Author      :   EMMANUEL MARTIN. 1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#ifndef JUGADOR_H_
#define JUGADOR_H_
#include "confederacion.h"
#include "menus.h"
#define OCCUPIED 1
#define FREE 0
#define DOWN -1
#define OK 1
#define ERROR -1

typedef struct
{

	int idPlayer;
	char name[50];
	char position[50];
	short shirtNumber;
	int confederationId;
	float salary;
	short hiringYears;
	short isEmpty;

} sPlayer;

/// @brief initializeArrayPlayer  		 Funcion inicializa en 0 el array de jugadores.
///
/// @param arrayPlayer					 Array de jugadores a dar de alta.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
void initializeArrayPlayer(sPlayer arrayPlayer[], int lenArrayPlayer);
/// @brief getFreeIndexArrayPlayer		 Funcion obtiene posicion de ARRAY de jugadores libre a dar de alta.
///
/// @param arrayPlayer					 Array de jugadores a dar de alta.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @return							     Retorna la posicion del ARRAY de jugadores libre a dar de alta.
int getFreeIndexArrayPlayer(sPlayer arrayPlayer[], int lenArrayPlayer);
/// @brief findByIdArrayPlayer			 Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayPlayer					 Array de jugadores.
/// @param idVehicle			   	 	 ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @return								 Retorna la posicion del ARRAY buscado a traves del ID ingresado por usuario.
int findByIdArrayPlayer(sPlayer arrayPlayer[], int idPlayer, int lenArrayPlayer);
/// @brief listOnePlayer			   	 Funcion para listar un jugador dado de alta.
///
/// @param player				         Un jugadores de estructura sPlayer, dado de alta.
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
int listOnePlayer(sPlayer player, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief listPlayeres			         Funcion lista ARRAY de jugadores dados de alta.
///
/// @param arrayPlayer			         ARRAY de jugadores dado de alta.
/// @param lenArrayPlayer					         Tamanio de ARRAY de jugadores.
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return						         Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief loadDataPlayer					Carga datos de jugador a dar de alta.
///
/// @param pPlayer								Puntero a un jugador de struct.
/// @param pIdPlayer						 Puntero a entero autoincremental a traves de contador.
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				 Tamanio de ARRAY de confederaciones.
/// @return								  	Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int loadDataPlayer(sPlayer *pPlayer, int *pIdPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief registerPlayer				 Da de alta un jugador.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param pIdPlayer					 Puntero a entero.
/// @param arrayConfederation			 ARRAY de confederaciones.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerPlayer(sPlayer arrayPlayer[], int lenArrayPlayer, int *pIdPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief downPlayer					 Funcion para dar de baja un jugador dado de alta, atraves de ID.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int downPlayer(sPlayer arrayPlayer[], int lenArrayPlayer);
/// @brief modifyOnePlayer				Modifica un jugador.
///
/// @param pPlayer						Puntero a un jugador de struct.
/// @param arrayConfederation			 ARRAY de confederaciones.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyOnePlayer(sPlayer *pPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief modifyPlayers				 Funcion para dar de modificar jugadores dado de alta, atraves de ID.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param arrayConfederation			 ARRAY de confederaciones harcodeado.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones harcodeado.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief sortPerIdPlayers				Ordena jugadores por ID.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param arrayConfederation			 ARRAY de confederaciones harcodeado.
/// @param lenArrayConfederation		 Tamanio de ARRAY de confederaciones harcodeado.
/// @return								Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int sortPerIdPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief getPositionPlayer			Obtiene la posicion de jugador elegida por usuario.
///
/// @param pPosition					puntero a cadena char.
/// @return								Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int getPositionPlayer(char *pPosition);
/// @brief validateRegisterOrDownPlayer	 Valida a traves de flag la entrada a las opciones de menu dependiendo si hay jugadores dados de alta.
///
/// @param arrayPlayer					 ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param pFlag						 Puntero a entero.
void validateRegisterOrDownPlayer(sPlayer arrayPlayer[], int lenArrayPlayer, int *pFlag);
/// @brief hardCodePlayers				 Funcion para harcodear jugadores de prueba de programa.
///
/// @param arrayPlayer			         ARRAY de jugadores.
/// @param lenArrayPlayer				 Tamanio de ARRAY de jugadores.
/// @param pNextId						 Puntero a entero autoincremental a traves de contador.
/// @param ammount						 Entero, cantidad.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodePlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int ammount, int *pNextId);

#endif /* JUGADOR_H_ */
