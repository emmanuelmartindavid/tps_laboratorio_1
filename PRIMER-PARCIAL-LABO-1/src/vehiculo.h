/*
 * vehiculo.h
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#ifndef VEHICULO_H_
#define VEHICULO_H_

#define MAX_DESCRIPTION 4096
#define MAX_DESCRIPTION_COLOR 11
#include "tipo.h"

#define OCCUPIED 1
#define FREE 0
#define DOWN -1
#define OK 1
#define ERROR -1

typedef struct {
	int idVehicle;
	char description[MAX_DESCRIPTION];
	int model;
	char color[MAX_DESCRIPTION];
	int typeId;
	int isEmpty;

} sVehicle;
/// @brief initializeVehicles   Funcion inicializa en 0 el array de vehiculos.
///
/// @param arrayVehicle			Array de vehiculos a dar de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
void initializeVehicles(sVehicle arrayVehicle[], int len);
/// @brief getFreeIndex			Funcion obtiene posicion de ARRAY de vehiculos libre a dar de alta.
///
/// @param arrayVehicle			Array de vehiculos a dar de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorna la posicion del ARRAY de vehiculos libre a dar de alta.
int getFreeIndex(sVehicle arrayVehicle[], int len);
/// @brief findById				Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayVehicle			Array de vehiculos.
/// @param idVehicle			ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorna la posicion del ARRAY buescado a traves del ID ingresado por usuario.
int findById(sVehicle arrayVehicle[], int idVehicle, int len);
/// @brief listOneVehicle		Funcion para listar un vehiculo dado de alta.
///
/// @param vehicle				Un vehiculo de estructura sVehicle, dado de alta.
/// @param arrayType			ARRAY de tipos de vehiculos harcodeado.
/// @param lenType				Tamanio de ARRAY de tipo harcodeado.
void listOneVehicle(sVehicle vehicle, sType arrayType[], int lenType);
/// @brief listVehicles			Funcion lista ARRAY de vehiculos dados de alta.
///
/// @param arrayVehicle			ARRAY de vehiculos dado de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculos harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listVehicles(sVehicle arrayVehicle[], int len, sType arrayType[],
		int lenType);
/// @brief listTypes			Funcion para listar tipos de vehiculos ingresados.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listTypes(sVehicle arrayVehicle[], sType arrayType[], int len);
/// @brief loadData				Funcion de tipo sVehicle(estructura de vehiculo) para realizar la carga de datos de vehiculo.
///
/// @return						Retorno auxiliar de sVehicle(estructura de vehiculo) con los datos cargados por el usuario.
sVehicle loadData(int *pFlagAuxData) ;
/// @brief registerVehicle		Funcion para dar de alta un vehiculo.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerVehicle(sVehicle arrayVehicle[], int len, sType arrayType[]);
/// @brief downVehicle			Funcion para dar de baja un vehiculo dado de alta, atraves de ID.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int downVehicle(sVehicle arrayVehicle[], int len, sType arrayType[],
//		int lenType);
/// @brief modifyOneVehicle	    Funcion de tipo sVehicle(estructura de vehiculo) para realiza la carga de datos de vehiculo a modificar.
///
/// @param vehicle				Un vehiculo de estructura sVehicle dado de alta a ser modificado.
/// @return						Retorno auxiliar de sVehicle(estructura de vehiculo) con los datos modificados por el usuario.
//sVehicle modifyOneVehicle(sVehicle vehicle);
/// @brief modifyVehicles		Funcion para dar de modificar vehiculos dado de alta, atraves de ID.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int modifyVehicles(sVehicle arrayVehicle[], int len, sType arrayType[],int lenType);
/// @brief sortPerTypeAndDescriptionVehicle	 Funcion ordena por tipo de vehiculo(agrupa mismo tipo) y por descripcion(alfabeticamente).
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int sortPerTypeAndDescriptionVehicle(sVehicle arrayVehicle[], int len);
/// @brief hardCodeVehicles		Funcion para harcodear vehiculos de prueba de programa.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param pNextId				Puntero a entero autoincremental a traves de contador.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodeVehicles(sVehicle arrayVehicle[], int len, int *pNextId);
/// @brief cls					Funcion para limpiar pantalla, debido al no funcionamiento del SYSTEM CLS en consola de ECLIPSE.
///
void cls();

#endif /* VEHICULO_H_ */
