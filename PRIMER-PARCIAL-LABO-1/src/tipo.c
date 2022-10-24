/*
 * tipo.c
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "vehiculo.h"
#include "validaciones.h"
#include "tipo.h"

/// @brief getIdtype		   Funcion para obtener el ID de tipo de vehiculo elegido por usuario.
///
/// @param arrayType		   ARRAY de tipos de vehiculo harcodeado.
/// @return					   Retorno ID de tipo de vehiculo elegido por usuario a traves de auxiliar sType.
int getIdtype(sType arrayType[], int *pFlagIdType) {

	int option;
	sType auxVehicleTypeId;

	if (arrayType != NULL) {
		if (utn_getNumber(&option, "Ingrese tipo.\n"
				"1-SEDAN 3 PUERTAS\n"
				"2-SEDAN 5 PUERTAS\n"
				"3-CAMIONETA\n", "Solo entre 1-3.\n", 0, 4, 3) == -1) {
			switch (option) {
			case 1:
				auxVehicleTypeId.idtype = arrayType[0].idtype;
				break;
			case 2:
				auxVehicleTypeId.idtype = arrayType[1].idtype;
				break;
			case 3:
				auxVehicleTypeId.idtype = arrayType[2].idtype;
				break;
			}

			*pFlagIdType=-1;
		}
	}
	return auxVehicleTypeId.idtype;
}
/// @brief getDescriptionType  Funcion para obtener la descripcion de tipo de vehiculo, segun ID tipo elegido por usuario.
///
/// @param arrayType           ARRAY de tipos de vehiculo harcodeado.
/// @param lenType			   Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @param idType			   ID tipo de vehiculo elegido por usuario a comparar.
/// @param pDescription		   Puntero a cadena de texto, con descripcion de tipo de vehiculo, dependiendo del ID de tipo de vehiculo elegido por usuario.
/// @return					   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int getDescriptionType(sType arrayType[], int lenType, int idType,
		char *pDescription) {
	int rtn = ERROR;
	int i;

	if (arrayType != NULL && lenType > 0 && idType > 0 && pDescription != NULL) {

		for (i = 0; i < lenType; i++) {

			if (arrayType[i].idtype == idType) {

				strncpy(pDescription, arrayType[i].description, 31);
				rtn = OK;

				break;

			}
		}
	}

	return rtn;
}
/// @brief listTypes			Funcion para listar tipos de vehiculos ingresados.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listTypes(sVehicle arrayVehicle[], sType arrayType[], int len) {

	int rtn = ERROR;
	int ammount = 0;
	char auxDescription[31];
	sType auxDescriptions[31];
	int i;
	if (arrayVehicle != NULL && arrayType != NULL && len > 0) {
		printf(
				"\t\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		printf("%85s" "%20s\n", "LISTADO DE TIPOS", "ID\n\n");
		for (i = 0; i < len; i++) {
			if (arrayVehicle[i].isEmpty == OCCUPIED) {
				getDescriptionType(arrayType, len, arrayVehicle[i].typeId,
						auxDescription);

				strncpy(auxDescriptions[i].description, auxDescription, 31);

				printf("%85s %17d\n\n", auxDescriptions[i].description,
						arrayVehicle[i].typeId);

				ammount++;

			}

		}
		if (ammount > 0) {
			printf(
					"\t\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
			rtn = OK;

		}
	}
	return rtn;
}
/// @brief hardCode			   Funcion de harcodeo de ID tipo de vehiculo, descripcion tipo de vehiculo.
///
/// @param arrayType		   ARRAY de tipos de vehiculo a harcodear.
void hardCode(sType arrayType[]) {

	arrayType[0].idtype = 1000;
	strncpy(arrayType[0].description, "SEDAN 3 PUERTAS", 31);
	arrayType[1].idtype = 1001;
	strncpy(arrayType[1].description, "SEDAN 5 PUERTAS", 31);
	arrayType[2].idtype = 1002;
	strncpy(arrayType[2].description, "CAMIONETA", 31);

}

