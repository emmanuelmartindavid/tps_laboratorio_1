/*
 ============================================================================
 Name        : TP1_laboratorio_1.c
 Author      : EMMANUEL MARTIN
 DIVISION 1.E. LABORATORIO1
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#include "UTN_validaciones.h"
#include "cargaDatos.h"
#include "calculos.h"

int main(void) {

	setbuf(stdout, NULL);
	int options;
	int minimum = 1;
	int maximus = 5;
	int retry = 5;
	int goalkeeperCounter = 0;
	int defenderCounter = 0;
	int midfielderCounter = 0;
	int strikerCounter = 0;
	float priceFood = 0;
	float priceLodgin = 0;
	float priceTransport = 0;
	int flagCalculations = 0;
	int afcCounter = 0;
	int cafCounter = 0;
	int concacafCounter = 0;
	int conmebolCounter = 0;
	int uefaCounter = 0;
	int ofcCounter = 0;
	int confederationTotal = 0;
	float averageAfc;
	float averageCaf;
	float averageConcacaf;
	float averageConmebol;
	float averageUefa;
	float averageOfc;
	float totalPrice = 0;
	float incrementPrice = 0;
	float incrementTotalPrice = 0;
	int shirt = 0;
	int flagPlayerPosition = 0;

	do {
		printf("\t\t MENU PRINCIPAL\n"
				"1. Carga de los costos de Mantenimiento\n"
				" Costo de Hospedaje -> $%.2f\n"
				" Costo de Comida -> $%.2f\n"
				" Costo de Transoporte -> $%.2f\n"
				"2. Carga de Jugadores\n"
				" Arqueros -> %d\n"
				" Defensores -> %d\n"
				" Mediocampistas -> %d\n"
				" Delanteros -> %d\n"
				"3. Realizar todos los calculos\n"
				"4. Informar resultados\n"
				"5. Salir", priceLodgin, priceFood, priceTransport,
				goalkeeperCounter, defenderCounter, midfielderCounter,
				strikerCounter);

		if (utn_getNumber(&options, "\nIngrese opcion\n",
				"\nOpcion incorrecta\n ", minimum, maximus, retry) == 0) {

			switch (options) {

			case 1:

				if (loadCosts(&priceLodgin, &priceFood, &priceTransport) == 0) {
					printf("\t\tSu costo se cargo correctamente\n\n");
				}

				break;
			case 2:

				if (goalkeeperCounter != 2 || defenderCounter != 8
						|| midfielderCounter != 8 || strikerCounter != 4) {
					if (loadShirtNumber(shirt) == 0
							&& loadPlayerPosition(&goalkeeperCounter,
									&defenderCounter, &midfielderCounter,
									&strikerCounter) == 0
							&& loadPlayerConfederation(&afcCounter, &cafCounter,
									&concacafCounter, &conmebolCounter,
									&uefaCounter, &ofcCounter) == 0) {

						flagPlayerPosition = 1;
						printf("\t\tSe realizo la carga de su jugador\n\n");

					}
				} else {

					printf("\t\tYa realizo la carga de jugadores\n\n");
				}
				break;
			case 3:

				if (flagPlayerPosition == 1 && priceLodgin != 0
						&& priceFood != 0 && priceTransport != 0
						&& calculateAverageConfederation(afcCounter, cafCounter,
								concacafCounter, conmebolCounter, uefaCounter,
								ofcCounter, confederationTotal, &averageAfc,
								&averageCaf, &averageConcacaf, &averageConmebol,
								&averageUefa, &averageOfc) == 0
						&& calculateMaintenance(priceLodgin, priceFood,
								priceTransport, averageAfc, averageCaf,
								averageConcacaf, averageConmebol, averageUefa,
								averageOfc, &totalPrice, &incrementPrice,
								&incrementTotalPrice) == 0) {

					printf("\t\tSE REALIZARON LOS CALCULOS CORRECTAMENTE.\n\n");
					flagCalculations = 1;
				} else {
					printf(
							"\t\tNo puede ingresar a esta opcion sin cargar los datos (AL MENOS UN JUGADOR, TODOS SUS COSTOS).\n\n");
				}
				break;
			case 4:

				if (flagCalculations == 1 ) {

					printf("\t\t INFORMAR TODOS LOS RESULTADOS\n"
							"Promedio AFC %.2f\n"
							"Promedio CAF %.2f\n"
							"Promedio CONCACAF %.2f\n"
							"Promedio CONMEBOL %.2f\n"
							"Promedio UEFA %.2f\n"
							"Promedio OFC %.2f\n", averageAfc, averageCaf,
							averageConcacaf, averageConmebol, averageUefa,
							averageOfc);

					if (averageUefa > averageAfc && averageUefa > averageCaf
							&& averageUefa > averageConcacaf
							&& averageUefa > averageConmebol
							&& averageUefa > averageOfc) {
						printf(
								"El costo de mantenimiento era $%.2f y recibio un aumento de $%.2f. Su nuevo valor es de $%.2f\n\n",
								totalPrice, incrementPrice,
								incrementTotalPrice);
					} else {
						printf("Costo de mantenimiento es $%.2f\n\n",
								totalPrice);
					}
				} else {
					printf(
							"\t\tNO PUEDE INGRESAR A ESTA OPCION SIN CARGAR LOS DATOS Y REALIZAR LOS CALCULOS\n\n");
				}
				break;
			case 5:
				printf("AD10S");
				break;
			}
		} else {

			printf("\t\tAlgo salió mal.\n\n");
			break;
		}

	} while (options != 5);

	return EXIT_SUCCESS;
}
