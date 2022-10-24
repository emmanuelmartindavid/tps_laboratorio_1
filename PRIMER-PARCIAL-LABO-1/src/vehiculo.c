/*
 * vehiculo.c
 *
 *  Created on: 6 oct. 2022
 *      Author: cuerpos
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
//#include "hojaServicio.h"
#include "validaciones.h"
#include "vehiculo.h"
/// @brief initializeVehicles   Funcion inicializa en 0 el array de vehiculos.
///
/// @param arrayVehicle			Array de vehiculos a dar de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
void initializeVehicles(sVehicle arrayVehicle[], int len) {

	int i;
	if (arrayVehicle != NULL && len > 0) {
		for (i = 0; i < len; i++) {

			arrayVehicle[i].isEmpty = FREE;

		}
	}

}
/// @brief getFreeIndex			Funcion obtiene posicion de ARRAY de vehiculos libre a dar de alta.
///
/// @param arrayVehicle			Array de vehiculos a dar de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorna la posicion del ARRAY de vehiculos libre a dar de alta.
int getFreeIndex(sVehicle arrayVehicle[], int len) {

	int i;
	int rtn = ERROR;

	if (arrayVehicle != NULL && len > 0) {
		for (i = 0; i < len; i++) {
			if (arrayVehicle[i].isEmpty == FREE) {
				rtn = i;
				break;
			}
		}
	}
	return rtn;
}
/// @brief findById				Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayVehicle			Array de vehiculos.
/// @param idVehicle			ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorna la posicion del ARRAY buescado a traves del ID ingresado por usuario.
int findById(sVehicle arrayVehicle[], int idVehicle, int len) {
	int rtn = ERROR;
	int i;

	if (arrayVehicle != NULL && idVehicle > 0 && len > 0) {

		for (i = 0; i < len; i++) {

			if (arrayVehicle[i].idVehicle
					== idVehicle&& arrayVehicle[i].isEmpty == OCCUPIED) {
				rtn = i;

				break;

			}
		}
	}

	return rtn;
}
/// @brief listOneVehicle		Funcion para listar un vehiculo.
///
/// @param vehicle				Un vehiculo de estructura sVehicle, dado de alta.
/// @param arrayType			ARRAY de tipos de vehiculos harcodeado.
/// @param lenType				Tamanio de ARRAY de tipo harcodeado.
void listOneVehicle(sVehicle vehicle, sType arrayType[], int lenType) {
	char descriptionType[31];

	if (arrayType != NULL && lenType > 0) {

		getDescriptionType(arrayType, lenType, vehicle.typeId, descriptionType);

		printf("\t\t\t\t\t\t\t%10d  %10s  %10d  %10s %20s\n", vehicle.idVehicle,
				vehicle.description, vehicle.model, vehicle.color,
				descriptionType);
	}

}
/// @brief listVehicles			Funcion lista ARRAY de vehiculos dados de alta.
///
/// @param arrayVehicle			ARRAY de vehiculos dado de alta.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculos harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int listVehicles(sVehicle arrayVehicle[], int len, sType arrayType[],
		int lenType) {

	int i = 0;
	int ammount = 0;
	int rtn = ERROR;

	if (arrayVehicle != NULL && len > 0 && arrayType != NULL && lenType > 0) {

		printf(
				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		printf("\n%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\t\t\tID ",
				"DESCRIPCION", "MODELO", "COLOR", "TIPO");

		for (i = 0; i < len; i++) {

			if (arrayVehicle[i].isEmpty == OCCUPIED) {

				listOneVehicle(arrayVehicle[i], arrayType, lenType);

				ammount++;

			}

		}
		if (ammount > 0) {
			rtn = OK;

			printf(
					"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
		}

	}

	return rtn;
}
/// @brief getId Funcion STATIC para autoincrementar ID de cada vehiculo.
///
/// @return Retorno ID autoincrementada para cada vehiculo dado de alta.
static int getId(void) {

	static int getIdIncremental = 100;

	return getIdIncremental++;
}
/// @brief loadData				Funcion de tipo sVehicle(estructura de vehiculo) para realiza la carga de datos de vehiculo.
///
/// @return						Retorno auxiliar de sVehicle(estructura de vehiculo) con los datos cargados por el usuario.
sVehicle loadData(int *pFlagAuxData) {

	sVehicle aux;

	if (pFlagAuxData != NULL) {

		if (utn_getAlphabeticDescription(aux.description,
				"Ingrese descripcion. Puede ser alfanumerica.\n",
				"Ingrese caracteres validos.\n", 3) == -1
				|| utn_getNumber(&aux.model,
						"Ingrese modelo (anio de fabricacion. 1960-2022).\n",
						"Solo entre 1960 - 2022.\n", 1959, 2023, 3) == -1
				|| utn_getAlphabeticDescription(aux.color, "Ingrese color: \n",
						"Solo 10 letras.\n", 3) == -1) {
			*pFlagAuxData = -1;
		}

	}

	return aux;
}
/// @brief registerVehicle		Funcion para dar de alta un vehiculo.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerVehicle(sVehicle arrayVehicle[], int len, sType arrayType[]) {

	int rtn = ERROR;
	int index;
	int flagData = 0;
	int flagIdType = 0;
	sVehicle auxvehicle;

	if (arrayVehicle != NULL && len > 0 && arrayType != NULL) {

		index = getFreeIndex(arrayVehicle, len);

		if (index != -1) {

			auxvehicle = loadData(&flagData);

			if (flagData == -1) {
				rtn = ERROR;

			} else {

				auxvehicle.idVehicle = getId();

				auxvehicle.typeId = getIdtype(arrayType, &flagIdType);
				if (flagIdType == -1) {
					rtn = ERROR;

				} else {

					auxvehicle.isEmpty = OCCUPIED;

					arrayVehicle[index] = auxvehicle;

					rtn = OK;
				}
			}

		}
	}

	return rtn;
}
/// @brief downVehicle			Funcion para dar de baja un vehiculo dado de alta, atraves de ID.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
/// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int downVehicle(sVehicle arrayVehicle[], int len, sType arrayType[],
//		int lenType) {
//	int rtn = ERROR;
//	char buffer[3];
//	int idVehicleAux;
//	int index;
//
//	if (arrayVehicle != NULL && len > 0 && arrayType != NULL && lenType > 0) {
//
//		if (listVehicles(arrayVehicle, len, arrayType, lenType) == OK) {
//
//			utn_getNumber(&idVehicleAux,
//					"Ingrese el ID del vehiculo a dar de baja.\n",
//					"Ingreso numero invalido.\n", -1, 10000);
//
//			while (findById(arrayVehicle, idVehicleAux, len) == ERROR) {
//
//				printf("NO EXISTE ID.");
//
//				utn_getNumber(&idVehicleAux,
//						"Ingrese el ID del vehiculo a dar de baja.\n",
//						"Ingreso numero invalido.\n", -1, 10000);
//			}
//
//			index = findById(arrayVehicle, idVehicleAux, len);
//
//			utn_getDescriptionExit(buffer,
//					"\t\t\t\t\t\t\tSu vehiculo se dara de baja. Presione si para continuar. Presione no para cancelar baja de vehiculo.\n",
//					"\t\t\t\t\t\t\tError. Solo si o no.\n");
//			if (stricmp(buffer, "si") == 0) {
//
//				arrayVehicle[index].isEmpty = DOWN;
//				rtn = OK;
//			} else {
//
//				rtn = ERROR;
//			}
//
//		}
//
//	}
//	return rtn;
//}
///// @brief modifyOneVehicle	    Funcion de tipo sVehicle(estructura de vehiculo) para realiza la carga de datos de vehiculo a modificar.
/////
///// @param vehicle				Un vehiculo de estructura sVehicle dado de alta a ser modificado.
///// @return						Retorno auxiliar de sVehicle(estructura de vehiculo) con los datos modificados por el usuario.
//sVehicle modifyOneVehicle(sVehicle vehicle) {
//
//	sVehicle auxModify = vehicle;
//	int auxOptionModify;
//	char exit[3];
//
//	do {
//
//		printf("\t\t****MODIFICACAR****\n");
//		utn_getNumber(&auxOptionModify, "1- DESCRIPCION.\n"
//				"2- MODELO.\n"
//				"3- COLOR.\n"
//				"4- SALIR", "\nOpcion incorrecta\n", 0, 5);
//
//		switch (auxOptionModify) {
//
//		case 1:
//			utn_getAlfaNumeric(auxModify.description,
//					"Ingrese descripcion. Puede ser alfanumerica.\n",
//					"Ingrese caracteres validos.\n");
//			break;
//		case 2:
//			utn_getNumber(&auxModify.model,
//					"Ingrese modelo (anio de fabricacion. 1960-2022).\n",
//					"Solo entre 1960 - 2022.\n", 1959, 2023);
//			break;
//		case 3:
//			utn_getDescription(auxModify.color, "Ingrese color:\n",
//					"Solo 10 letras.\n");
//			break;
//
//		case 4:
//			utn_getDescriptionExit(exit,
//					"\t\t\t\t\t\t\tPresione si para salir. Presione no para continuar en el menu de modificacion.\n",
//					"\t\t\t\t\t\t\tError. Solo si o no.\n");
//			break;
//
//		}
//	} while (stricmp(exit, "si") != 0);
//
//	return auxModify;
//}
///// @brief modifyVehicles		Funcion para dar de modificar vehiculos dado de alta, atraves de ID.
/////
///// @param arrayVehicle			ARRAY de vehiculos.
///// @param len					Tamanio de ARRAY de vehiculos.
///// @param arrayType			ARRAY de tipos de vehiculo harcodeado.
///// @param lenType				Tamanio de ARRAY de tipos de vehiculo harcodeado.
///// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int modifyVehicles(sVehicle arrayVehicle[], int len, sType arrayType[],
//		int lenType) {
//
//	int rtn = ERROR;
//	int idVehicle;
//	int index;
//	sVehicle auxVehicle;
//
//	if (arrayVehicle != NULL && len > 0 && arrayType != NULL && lenType > 0) {
//
//		if (listVehicles(arrayVehicle, len, arrayType, lenType) == OK) {
//
//			utn_getNumber(&idVehicle,
//					"Ingrese el ID del vehiculo a modificar.\n",
//					"Ingreso numero invalido.\n", -1, 10000);
//
//			while (findById(arrayVehicle, idVehicle, len) == -1) {
//
//				printf("NO EXISTE ID.");
//
//				utn_getNumber(&idVehicle,
//						"Ingrese el ID del vehiculo a modificar.\n",
//						"Ingreso numero invalido.\n", -1, 10000);
//			}
//
//			index = findById(arrayVehicle, idVehicle, len);
//
//			auxVehicle = modifyOneVehicle(arrayVehicle[index]);
//			arrayVehicle[index] = auxVehicle;
//
//			rtn = OK;
//
//		}
//	}
//
//	return rtn;
//}
/// @brief sortPerTypeAndDescriptionVehicle	 Funcion ordena por tipo de vehiculo(agrupa mismo tipo) y por descripcion(alfabeticamente).
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int sortPerTypeAndDescriptionVehicle(sVehicle arrayVehicle[], int len) {

	int rtn = ERROR;
	sVehicle auxVehicle;

	if (arrayVehicle != NULL && len > 0) {
		for (int i = 0; i < len - 1; i++) {
			for (int j = i + 1; j < len; j++) {

				if (arrayVehicle[i].isEmpty == OCCUPIED
						&& arrayVehicle[j].isEmpty == OCCUPIED) {

					if (arrayVehicle[i].typeId > arrayVehicle[j].typeId
							|| (arrayVehicle[i].typeId == arrayVehicle[j].typeId
									&& (stricmp(arrayVehicle[i].description,
											arrayVehicle[j].description)) > 0)) {
						auxVehicle = arrayVehicle[i];
						arrayVehicle[i] = arrayVehicle[j];
						arrayVehicle[j] = auxVehicle;
					}
					rtn = OK;
				}
			}
		}

	}

	return rtn;
}
/// @brief hardCodeVehicles		Funcion para harcodear vehiculos de prueba de programa.
///
/// @param arrayVehicle			ARRAY de vehiculos.
/// @param len					Tamanio de ARRAY de vehiculos.
/// @param pNextId				Puntero a entero autoincremental a traves de contador.
/// @return						Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodeVehicles(sVehicle arrayVehicle[], int len, int *pNextId) {

	int rtn = ERROR;

	sVehicle aux[25] =
			{

			{ 0, "Toyota", 1970, "Vegro", 1001, 1 }, { 0, "Maserati", 1974,
					"blanco", 1002, 1 },
					{ 0, "Porsche", 1976, "verde", 1001, 1 }, { 0, "Benz", 1961,
							"gris", 1000, 1 }, { 0, "Lamborghini", 1984,
							"plateado", 1000, 1 }, { 0, "Tesla", 1987, "dorado",
							1002, 1 }, { 0, "Honda", 1998, "azul", 1001, 1 }, {
							0, "Hyundai", 2000, "amarillo", 1000, 1 }, { 0,
							"Ford", 1964, "rojo", 1000, 1 }, { 0, "Alfa Romeo",
							1980, "marron", 1001, 1 }, { 0, "Audi", 2022,
							"azul", 1001, 1 }, { 0, "Ferrari", 1990, "gris",
							1001, 1 }, { 0, "Alpina", 1986, "negro", 1000, 1 },
					{ 0, "Fiat", 2010, "violeta", 1002, 1 }, { 0, "Cadillac",
							2019, "negro", 1000, 1 }, { 0, "Chevrolet", 2020,
							"cosmos", 1002, 1 }, { 0, "Subaru", 2015, "panton",
							1002, 1 }, { 0, "Dodge", 2013, "blanco", 1001, 1 },
					{ 0, "Jeep", 1994, "negro", 1002, 1 }, { 0, "Citroën", 2010,
							"negro", 1000, 1 }, { 0, "Peugeot", 2011, "verde",
							1001, 1 }, { 0, "Renault", 2013, "azul", 1002, 1 },
					{ 0, "Suzuki", 2020, "amarillo", 1002, 1 }, { 0, "Pagani",
							2022, "negro", 1001, 1 } };

	if (arrayVehicle != NULL && pNextId != NULL && len > 0) {
		for (int i = 0; i < len; i++) {
			arrayVehicle[i] = aux[i];
			arrayVehicle[i].idVehicle = *pNextId;
			(*pNextId)++;
		}
		rtn = OK;
	}
	return rtn;

}
/// @brief cls			Funcion para limpiar pantalla, debido al no funcionamiento del SYSTEM CLS en consola de ECLIPSE.
///
void cls() {

	printf(
			"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n"
					"\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n");

}

