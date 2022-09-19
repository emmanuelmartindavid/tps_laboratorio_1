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
#include "cargaDeDatos-calculos.h"

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
	float averageAfc;
	float averageCaf;
	float averageConcacaf;
	float averageConmebol;
	float averageUefa;
	float averageOfc;
	float totalPrice = 0;
	float incrementPrice = 0;
	float incrementTotalPrice = 0;
	int totalCounter = 0;
	int shirt = 0;

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
				if (loadCost(&priceLodgin, &priceFood, &priceTransport) == 0) {

					printf("\n\nSe cargó correctamente\n\n");
				}

				break;
			case 2:
				if (loadShirt(shirt) == 0
						&& loadPlayer(&goalkeeperCounter, &defenderCounter,
								&midfielderCounter, &strikerCounter) == 0
						&& loadConfederation(&afcCounter, &cafCounter,
								&concacafCounter, &conmebolCounter,
								&uefaCounter, &ofcCounter) == 0) {

					printf("\n\nSe realizo la carga de su jugador\n\n");

				} else {

					printf("\nAlgo no se cargo correctamente\n");
				}

				printf(" AFC CONTADOR %d\n", afcCounter);
				printf(" AFC CONTADOR %d\n", cafCounter);
				printf(" AFC CONTADOR %d\n", concacafCounter);
				printf(" AFC CONTADOR %d\n", conmebolCounter);
				printf(" AFC CONTADOR %d\n", uefaCounter);
				printf(" AFC CONTADOR %d\n", ofcCounter);

				break;
			case 3:
				flagCalculations = 1;
				if (priceLodgin != 0 && priceFood != 0 && priceTransport != 0
						&& goalkeeperCounter == 2 && defenderCounter == 2
						&& midfielderCounter == 2 && strikerCounter == 2
						&& calculateAverage_Price(afcCounter, cafCounter,
								concacafCounter, conmebolCounter, uefaCounter,
								ofcCounter, totalCounter, priceLodgin,
								priceFood, priceTransport, &averageAfc,
								&averageCaf, &averageConcacaf, &averageConmebol,
								&averageUefa, &averageOfc, &totalPrice,
								&incrementPrice, &incrementTotalPrice) == 0) {

					printf("\n\nSe realizaron todos los resultados correctamente.\n\n");

				} else {
					printf("\n\nNo puede ingresar a esta opcion sin cargar los datos (SU EQUIPO COMPLETO, TODOS SUS COSTOS).\n\n");
				}
				break;
			case 4:

				if (flagCalculations == 1 && priceLodgin != 0 && priceFood != 0
						&& priceTransport != 0 && goalkeeperCounter == 2
						&& defenderCounter == 2 && midfielderCounter == 2
						&& strikerCounter == 2) {

					printf("\t\t INFORMAR TODOS LOS RESULTADOS\n"
							"Promedio AFC %.2f\n"
							"Promedio CAF %.2f\n"
							"Promedio CONCACAF %.2f\n"
							"Promedio CONMEBOL %.2f\n"
							"Promedio UEFA %.2f\n"
							"Promedio OFC %.2f\n", averageAfc, averageCaf,
							averageConcacaf, averageConmebol, averageUefa,
							averageOfc);

					if (incrementTotalPrice > 0) {
						printf("El costo de mantenimiento era $%.2f y recibio un aumento de $%.2f. Su nuevo valor es de $%.2f\n\n",
								totalPrice, incrementPrice,
								incrementTotalPrice);
					} else {
						printf("Costo de mantenimiento es $%.2f\n\n",
								totalPrice);
					}

				} else {
					printf("\n\nNo puede ingresar a esta opcion sin cargar TODOS LOS DATOS Y REALIZAR LOS CALCULOS\n\n");
				}
				break;
			case 5:
				printf("AD10S");
				break;
			}
		} else {

			printf("\nAlgo salió mal. VOLVAMOS A INTERTARLO\n");
		}

	} while (options != 5);

	return EXIT_SUCCESS;
}
