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
	int retry = 3;
	int goalkeeperCounter = 0;
	int defenderCounter = 0;
	int midfielderCounter = 0;
	int strikerCounter = 0;
	float priceFood = 0;
	float priceLodgin = 0;
	float priceTransport = 0;
	int flagCost = 0;
	int flagLoad = 0;
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


		if (utn_getNumber(&options, "\n Ingrese opcion \n",
				"\n Opcion incorrecta\n ", minimum, maximus, retry) == 0)

			switch (options) {

			case 1:
				flagCost = 1;
				loadCost(&priceLodgin, &priceFood, &priceTransport);
				break;
			case 2:
				flagLoad = 1;

				loadPlayer(&goalkeeperCounter, &defenderCounter,
						&midfielderCounter, &strikerCounter);
//
//				if (goalkeeperCounter < 3 || defenderCounter < 5
//						|| midfielderCounter <5 || strikerCounter < 5) {
//					flagPlayers=1;
//
//				}

				loadLeague(&afcCounter, &cafCounter, &concacafCounter,
						&conmebolCounter, &uefaCounter, &ofcCounter);

				printf(" AFC CONTADOR %d\n", afcCounter);

				break;
			case 3:
				flagCalculations = 1;
				if (flagCost == 1 && flagLoad == 1 && priceLodgin != 0
						&& priceFood != 0 && priceTransport != 0
						&& goalkeeperCounter == 2 && defenderCounter == 4
						&& midfielderCounter == 4 && strikerCounter == 4) {

					calculates(&afcCounter, &cafCounter, &concacafCounter,
							&conmebolCounter, &uefaCounter, &ofcCounter,
							&totalCounter, &priceLodgin, &priceFood,
							&priceTransport, &averageAfc, &averageCaf,
							&averageConcacaf, &averageConmebol, &averageUefa,
							&averageOfc, &totalPrice, &incrementPrice,
							&incrementTotalPrice);

					printf(
							"\nSe realizaron todos los resultados correctamente.\n\n");

				} else {
					printf(
							"\nNo puede ingresar a esta opcion sin cargar los datos (su equipo, sus costos) y todos los costos.\n\n");
				}
				break;
			case 4:

				if (flagCost == 1 && flagLoad == 1 && flagCalculations == 1
						&& priceLodgin != 0 && priceFood != 0
						&& priceTransport != 0 && goalkeeperCounter == 2
						&& defenderCounter == 4 && midfielderCounter == 4
						&& strikerCounter == 4) {

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
						printf(
								"El costo de mantenimiento era $%.2f y recibio un aumento de $%.2f. Su nuevo valor es de $%.2f\n\n",
								totalPrice, incrementPrice,
								incrementTotalPrice);
					} else {
						printf("Costo de mantenimiento es $%.2f\n\n", totalPrice);
					}

				} else {
					printf(
							"\nNo puede ingresar a esta opcion sin cargar  TODOS los datos (SU EQUIPO, SUS COSTOS) y realizar los calculos\n\n");
				}
				break;
			case 5:
				printf("ADIOS");
				fflush(stdin);
				break;
			}

	} while (options != 5);

	return EXIT_SUCCESS;
}
