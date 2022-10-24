///*
// * informes.c
// *
// *  Created on: 6 oct. 2022
// *      Author: cuerpos
// */
//#include <stdio.h>
//#include <stdlib.h>
//#include <string.h>
//#include "informes.h"
//#include "validaciones.h"
//
///// @brief showOneType3Doors		Funcion muestra vehículos de tipo SEDAN DE 3 PUERTAS al ser seleccionada.
/////
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @return	           				Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int showOneType3Doors(sVehicle arrayVehicle[], sType arrayType[], int len) {
//
//	int rtn = ERROR;
//	int ammount = 0;
//
//	if (arrayVehicle != NULL && arrayType != NULL && len > 0) {
//		printf(
//				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
//		printf("\n%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\t\t\tID ",
//				"DESCRIPCION", "MODELO", "COLOR", "TIPO");
//		for (int i = 0; i < len; i++) {
//
//			if (arrayVehicle[i].isEmpty == OCCUPIED
//					&& arrayVehicle[i].typeId == arrayType[0].idtype) {
//
//				listOneVehicle(arrayVehicle[i], arrayType, len);
//
//				ammount++;
//
//			}
//			if (ammount > 0) {
//
//				rtn = OK;
//
//			}
//
//		}
//		printf(
//				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
//
//	}
//	return rtn;
//}
///// @brief showOneType5Doors		Funcion muestra vehículos de tipo SEDAN DE 5 PUERTAS al ser seleccionada.
/////
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int showOneType5Doors(sVehicle arrayVehicle[], sType arrayType[], int len) {
//
//	int rtn = ERROR;
//	int ammount = 0;
//
//	if (arrayVehicle != NULL && arrayType != NULL && len > 0) {
//		printf(
//				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
//		printf("\n%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\t\t\tID ",
//				"DESCRIPCION", "MODELO", "COLOR", "TIPO");
//		for (int i = 0; i < len; i++) {
//
//			if (arrayVehicle[i].isEmpty == OCCUPIED
//					&& arrayVehicle[i].typeId == arrayType[1].idtype) {
//
//				listOneVehicle(arrayVehicle[i], arrayType, len);
//
//				ammount++;
//
//			}
//			if (ammount > 0) {
//
//				rtn = OK;
//			}
//
//		}
//		printf(
//				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
//
//	}
//	return rtn;
//}
///// @brief showOneTypeTruck			Funcion muestra vehículos de tipo CAMIONETA al ser seleccionada.
/////
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int showOneTypeTruck(sVehicle arrayVehicle[], sType arrayType[], int len) {
//
//	int rtn = ERROR;
//	int ammount = 0;
//
//	if (arrayVehicle != NULL && arrayType != NULL && len > 0) {
//		printf(
//				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
//		printf("\n%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\t\t\tID ",
//				"DESCRIPCION", "MODELO", "COLOR", "TIPO");
//		for (int i = 0; i < len; i++) {
//
//			if (arrayVehicle[i].isEmpty == OCCUPIED
//					&& arrayVehicle[i].typeId == arrayType[2].idtype) {
//
//				listOneVehicle(arrayVehicle[i], arrayType, len);
//				ammount++;
//
//			}
//			if (ammount > 0) {
//				rtn = OK;
//
//			}
//
//		}
//		printf(
//				"\t\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n");
//	}
//	return rtn;
//}
///// @brief showTypes				Funcion para mostrar los tipos de vehiculos por vehiculos dados de alta seleccionados.
/////
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param len						Tamanio de ARRAY de vehiculos.
//void showTypes(sVehicle arrayVehicle[], sType arrayType[], int len) {
//
//	int auxShowType;
//	if (arrayVehicle != NULL && arrayType != NULL && len > 0) {
//		utn_getNumber(&auxShowType, "Ingrese tipo de vehiculos a listar\n"
//				"1- SEDAN 3 PUERTAS\n"
//				"2- SEDAN 5 PUERTAS\n"
//				"3- CAMIONETA\n", "Opcion invalida\n", 0, 4);
//
//		switch (auxShowType) {
//
//		case 1:
//			cls();
//			if (showOneType3Doors(arrayVehicle, arrayType, len) == ERROR) {
//				printf("NADA PARA MOSTRAR\n");
//			}
//
//			break;
//		case 2:
//			cls();
//			if (showOneType5Doors(arrayVehicle, arrayType, len) == ERROR) {
//				printf("NADA PARA MOSTRAR\n");
//			}
//			break;
//		case 3:
//			cls();
//			if (showOneTypeTruck(arrayVehicle, arrayType, len) == ERROR) {
//				printf("NADA PARA MOSTRAR\n");
//			}
//			break;
//
//		}
//	}
//
//}
///// @brief askDate					Funcion de tipo sDate(estructura de fecha) para realizar la carga de fecha elegida por usuario.
/////
///// @return							Retorno auxiliar de sDate(estructura de fecha) con los datos de fecha cargados por el usuario.
//sDate askDate() {
//
//	sDate auxDate;
//
//	utn_getNumber(&auxDate.day, "Ingrese dia.\n", "Dia Invalido.\n", 0, 32);
//
//	utn_getNumber(&auxDate.month, "Ingrese mes.\n", "Mes invalido.\n", 0, 13);
//
//	utn_getNumber(&auxDate.year, "Ingrese anio. EJ-2020.\n", "Anio invalido.\n",
//			2000, 2023);
//
//	return auxDate;
//}
///// @brief showSheetPerDate			Funcion muestra todas las hojas de servicio efectuadas en una fecha seleccionada por el usuario.
/////
///// @param arraySheet				Array de hojas de servicio dada de alta.
///// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
///// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int showSheetPerDate(sSheet arraySheet[], int lenSheet, sVehicle arrayVehicle[],
//		int len, sType arrayType[], int lenType) {
//
//	int rtn = ERROR;
//	int ammount = 0;
//	sDate auxDatePerDate;
//
//	if (arraySheet != NULL && lenSheet > 0 && arrayVehicle != NULL && len > 0
//			&& arrayType != NULL && lenType > 0) {
//
//		if (arraySheet[0].isEmpty != OCCUPIED) {
//			rtn = ERROR;
//		} else {
//			listSheets(arraySheet, lenSheet, arrayVehicle, len, arrayType,
//					lenType);
//
//			auxDatePerDate = askDate();
//			cls();
//			printf(
//					"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
//
//			printf("%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\tID VEHICULO",
//					"DESCRIPCION DE SERVICIO", "PRECIO DE SERVICIO",
//					"FECHA DE SERVICIO", "TIPO VEHICULO");
//
//			for (int i = 0; i < lenSheet; i++) {
//
//				if (arraySheet[i].isEmpty == OCCUPIED
//						&& arraySheet[i].date.day == auxDatePerDate.day
//						&& arraySheet[i].date.month == auxDatePerDate.month
//						&& arraySheet[i].date.year == auxDatePerDate.year) {
//
//					for (int j = 0; j < len; j++) {
//						if (arrayVehicle[j].idVehicle
//								== arraySheet[i].vehicleId) {
//
//							listOneSheet(arraySheet[i], arrayVehicle[j],
//									arrayType, lenType);
//
//							ammount++;
//						}
//					}
//
//				}
//				if (ammount > 0) {
//					rtn = OK;
//
//				}
//
//			}
//			printf(
//					"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
//
//		}
//	}
//	return rtn;
//
//}
///// @brief loadDataSheetIdReports	Funcion para preguntar por ID de vehiculo a ingresar por usuario
/////
///// @return							Retorno auxiliar de sDate(estructura de fecha) con los datos de fecha cargados por el usuario.
//int loadDataSheetIdReports() {
//
//	sSheet auxSheetIdReport;
//
//	utn_getNumber(&auxSheetIdReport.vehicleId, "Ingrese Id de vehiculo.\n",
//			"Ingreso incorrecto. Reintente.\n", -1, 1000);
//
//	return auxSheetIdReport.vehicleId;
//}
///// @brief acumulatorPerVehicle		Funcion informa importe total de las hojas de servicio realizadas en un vehículo seleccionado por el usuario.
/////
///// @param arraySheet				Array de hojas de servicio dada de alta.
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
///// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int acumulatorPerVehicle(sSheet arraySheet[], sVehicle arrayVehicle[],
//		int lenSheet, int len, sType arrayType[], int lenType) {
//
//	int rtn = ERROR;
//	sSheet auxSheet;
//	float acumulator = 0;
//	int flag = 0;
//
//	if (arraySheet != NULL && lenSheet > 0 && arrayVehicle != NULL && len > 0
//			&& arrayType != NULL && lenType > 0) {
//		if (arraySheet[0].isEmpty != OCCUPIED) {
//			rtn = ERROR;
//		} else {
//
//			listSheets(arraySheet, lenSheet, arrayVehicle, len, arrayType,
//					lenType);
//			auxSheet.vehicleId = loadDataSheetIdReports(arraySheet, lenSheet);
//			cls();
//			printf(
//					"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
//
//			printf("%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\tID VEHICULO",
//					"DESCRIPCION DE SERVICIO", "PRECIO DE SERVICIO",
//					"FECHA DE SERVICIO", "TIPO VEHICULO");
//
//			for (int i = 0; i < lenSheet; i++) {
//
//				if (arraySheet[i].isEmpty == OCCUPIED
//						&& arraySheet[i].vehicleId == auxSheet.vehicleId) {
//
//					flag = 1;
//					acumulator += arraySheet[i].servicePrice;
//					listOneSheet(arraySheet[i], arrayVehicle[i], arrayType,
//							lenType);
//
//				}
//
//			}
//
//			if (flag == 1) {
//				printf(
//						"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
//
//				printf(
//						"\n\t\t\t\t\t\t\t\t EL PRECIO TOTAL DE VEHICULO CON ID %d ES: $%.2f \n\n",
//						auxSheet.vehicleId, acumulator);
//				rtn = OK;
//			} else {
//				printf("\t\t\t\t\t\t\t\t\t\tNO EXISTE ID\n\n");
//			}
//		}
//	}
//
//	return rtn;
//
//}
///// @brief askType					Funcion para obtener el ID de tipo de vehiculo elegido por usuario.
/////
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @return						    Retorno ID de tipo de vehiculo elegido por usuario a traves de auxiliar sVehicle.
//int askType(sType arrayType[]) {
//
//	int option;
//	sVehicle auxIdVehiclesIdType;
//
//	utn_getNumber(&option, "Ingrese tipo.\n"
//			"1-SEDAN 3 PUERTAS.\n"
//			"2-SEDAN 5 PUERTAS.\n"
//			"3-CAMIONETA.\n", "Solo entre 1-3.\n", 0, 4);
//	switch (option) {
//
//	case 1:
//		auxIdVehiclesIdType.typeId = arrayType[0].idtype;
//		break;
//	case 2:
//		auxIdVehiclesIdType.typeId = arrayType[1].idtype;
//		break;
//	case 3:
//		auxIdVehiclesIdType.typeId = arrayType[2].idtype;
//		break;
//	}
//	return auxIdVehiclesIdType.typeId;
//}
///// @brief pricePerDateOneType		importe total de todas las hojas de servicio de un tipo en una fecha seleccionada por el usuario.
/////
/////
///// @param arraySheet				Array de hojas de servicio dada de alta.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
///// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @return							Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
//int pricePerDateOneType(sSheet arraySheet[], sType arrayType[],
//		sVehicle arrayVehicle[], int lenSheet, int lenType, int len) {
//
//	int rtn = ERROR;
//	sDate auxDatePerDate;
//	sVehicle auxVehicleType;
//	char pDescription[31];
//	int flag = 0;
//
//	float acumulator = 0;
//
//	if (arraySheet != NULL && lenSheet > 0 && arrayVehicle != NULL && len > 0
//			&& arrayType != NULL && lenType > 0) {
//
//		if (arraySheet[0].isEmpty != OCCUPIED) {
//			rtn = ERROR;
//		} else {
//
//			listSheets(arraySheet, lenSheet, arrayVehicle, len, arrayType,
//					lenType);
//
//			auxVehicleType.typeId = askType(arrayType);
//			auxDatePerDate = askDate();
//			cls();
//			printf(
//					"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
//
//			printf("%5s  %10s  %10s  %10s %15s\n", "\t\t\t\t\t\tID VEHICULO",
//					"DESCRIPCION DE SERVICIO", "PRECIO DE SERVICIO",
//					"FECHA DE SERVICIO", "TIPO VEHICULO");
//
//			for (int i = 0; i < lenSheet; i++) {
//
//				if (arraySheet[i].isEmpty == OCCUPIED
//						&& arraySheet[i].date.day == auxDatePerDate.day
//						&& arraySheet[i].date.month == auxDatePerDate.month
//						&& arraySheet[i].date.year == auxDatePerDate.year) {
//
//					for (int j = 0; j < len; j++) {
//						if (arrayVehicle[j].idVehicle == arraySheet[i].vehicleId
//								&& arrayVehicle[j].typeId
//										== auxVehicleType.typeId) {
//
//							getDescriptionType(arrayType, lenType,
//									arrayVehicle[j].typeId, pDescription);
//							listOneSheet(arraySheet[i], arrayVehicle[j],
//									arrayType, lenType);
//							flag = 1;
//							acumulator += arraySheet[i].servicePrice;
//							break;
//
//						}
//					}
//				}
//			}
//			if (flag == 1) {
//				printf(
//						"\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*--*-*-*-*--*-*-*-\n");
//
//				printf(
//						"\n\t\t\t\t\t\t\tEL PRECIO  TOTAL DE TIPO %s, EN LA FECHA %d-%d-%d ES: $%.2f \n\n",
//						pDescription, auxDatePerDate.day, auxDatePerDate.month,
//						auxDatePerDate.year, acumulator);
//
//				rtn = OK;
//			} else {
//
//				printf("\t\t\t\t\t\t\t\t\t\tTIPO O FECHA, NO EXISTEN\n\n");
//			}
//
//		}
//	}
//	return rtn;
//
//}
///// @brief reportsMenu				Funcion para mostrar opciones de menu de informar e informar las mismas elegidas por el usuario.
/////
///// @param arraySheet				Array de hojas de servicio dada de alta.
///// @param arrayVehicle				Array de vehiculos dados de alta.
///// @param arrayType				ARRAY de tipos de vehiculo harcodeado.
///// @param len						Tamanio de ARRAY de vehiculos.
///// @param lenSheet					Tamanio de ARRAY de hojas de servicio.
///// @param lenType					Tamanio de ARRAY de tipos de vehiculo harcodeado.
//void reportsMenu(sSheet arraySheet[], sVehicle arrayVehicle[],
//		sType arrayType[], int len, int lenSheet, int lenType) {
//
//	int optionReports;
//	char exit[3];
//
//	if (arraySheet != NULL && lenSheet > 0 && arrayVehicle != NULL && len > 0
//			&& arrayType != NULL && lenType > 0) {
//
//		do {
//			utn_getNumber(&optionReports,
//					"\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-INFORMES-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*"
//							"\n\t\t\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t\t*"
//							"\n\t\t\t\t\t\t*\t 1-MOSTRAR VEHICULOS DE UN TIPO:\t\t\t\t\t\t\t*"
//							"\n\t\t\t\t\t\t*\t 2-MOSTRAR HOJAS DE SERVICIO EFECTUADAS EN FECHA SELECCIONADA:\t\t\t\t*"
//							"\n\t\t\t\t\t\t*\t 3-IMPORTE TOTAL DE LAS HOJAS DE SERVICIO REALIZADAS EN UN VEHICULO:\t\t\t*"
//							"\n\t\t\t\t\t\t*\t 4-IMPORTE TOTAL DE TODAS LAS HOJAS DE SERVICIO DE UN TIPO EN UNA FECHA SELECCIONADA\t*"
//							"\n\t\t\t\t\t\t*\t 5-SALIR DE MENU INFORMES\t\t\t\t\t\t\t\t*"
//							"\n\t\t\t\t\t\t*\t\t\t\t\t\t\t\t\t\t\t\t*\n"
//							"\t\t\t\t\t\t-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-*-\n",
//					"Opcion invalida", 0, 6);
//			cls();
//			switch (optionReports) {
//			case 1:
//				cls();
//				showTypes(arrayVehicle, arrayType, len);
//				break;
//			case 2:
//				cls();
//				if (showSheetPerDate(arraySheet, lenSheet, arrayVehicle, len,
//						arrayType, lenType) == OK) {
//					printf(
//							"\t\t\t\t\t\t\t\tLISTADO HOJA DE SERVICIO EN FECHA SELECCIONADA\n\n");
//				} else {
//
//					printf("\t\t\t\t\t\t\t\t\t\tNADA PARA MOSTRAR\t\t\n\n");
//				}
//				break;
//			case 3:
//				cls();
//				if (acumulatorPerVehicle(arraySheet, arrayVehicle, lenSheet,
//						len, arrayType, lenType) == ERROR) {
//
//					printf("\t\t\t\t\t\t\t\t\t\tNADA PARA MOSTRAR\t\t\n\n");
//				}
//				break;
//			case 4:
//				cls();
//				if (pricePerDateOneType(arraySheet, arrayType, arrayVehicle,
//						lenSheet, lenType, len) == ERROR) {
//					printf("\t\t\t\t\t\t\t\t\t\tNADA PARA MOSTRAR\t\t\n\n");
//				}
//				break;
//			case 5:
//				cls();
//				utn_getDescriptionExit(exit,
//						"\t\t\t\t\t\t\tPresione si para salir. Presione no para continuar en el menu de informes.\n",
//						"\t\t\t\t\t\t\tError. Solo si o no.\n");
//				break;
//
//			}
//
//		} while (stricmp(exit, "si") != 0);
//	}
//
//}

