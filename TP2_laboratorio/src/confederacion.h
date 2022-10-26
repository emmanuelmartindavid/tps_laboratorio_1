/*
 * confederacion.h
 *
 *  Created on: 14 oct. 2022
 *      Author: cuerpos
 */

#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{

	int idConfederation;
	char confederationName[50];
	char region[50];
	int creationYear;
	short isEmpety;

} sConfederation;

int getIdConfederation(sConfederation arrayConfederation[], int lenArrayConfederation);

void listOneConfederation(sConfederation OneConfederation);
int listConfederation(sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief getDescriptionType  Funcion para obtener la descripcion de tipo de vehiculo, segun ID tipo elegido por usuario.
///
/// @param arrayType           ARRAY de tipos de vehiculo harcodeado.
/// @param lenType			   Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @param idType			   ID tipo de vehiculo elegido por usuario a comparar.
/// @param pDescription		   Puntero a cadena de texto, con descripcion de tipo de vehiculo, dependiendo del ID de tipo de vehiculo elegido por usuario.
/// @return					   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int getConfederationDescription(sConfederation arrayConfederation[], int lenArrayConfederation, int idConfederation, char *pCofederationDescription);
int hardCodeConfederations(sConfederation arrayConfederation[], int lenArrayConfederation, int ammount, int *pNextId);

#endif /* CONFEDERACION_H_ */