#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_validaciones.h"
#include "cargaDeDatos-calculos.h"

void loadCost(float *pPriceLodgin, float *pPriceFood, float *pPriceTransport) {

	float minimumPrice = 1;
	float maximusPrice = 100000000;
	int retryPrice = 3;
	int option;
	float priceFood = 0;
	float priceLodgin = 0;
	float priceTransport = 0;

	if (pPriceLodgin != NULL && pPriceFood != NULL && pPriceTransport != NULL) {
		if (utn_getNumber(&option, "\nIngrese costo a cargar:\n"
				"1. Costo hospedaje.\n"
				"2. Costo comida.\n"
				"3. Costo transporte.\n", "\nOpcion incorrecta.\n ",
				1, 3, 5) == 0) {

			switch (option) {
			case 1:

				if (*pPriceLodgin == 0 && utn_getNumberFloat(&priceLodgin,
						"Ingrese costo de hospedaje $\n",
						"Ingrese precio valido\n", minimumPrice, maximusPrice,
						retryPrice) == 0 ) {
					*pPriceLodgin = priceLodgin;
				} else {
					printf("\nYa ingresó este costo\n");
				}
				break;
			case 2:

				if (*pPriceFood == 0 && utn_getNumberFloat(&priceFood,
						"Ingrese costo de comida $\n",
						"Ingrese precio valido\n", minimumPrice, maximusPrice,
						retryPrice) == 0) {
					*pPriceFood = priceFood;
				} else {
					printf("\nYa ingresó este costo\n");
				}

				break;
			case 3:

				if (*pPriceTransport == 0&& utn_getNumberFloat(&priceTransport,
						"Ingrese costo de transporte $\n",
						"Ingrese precio valido\n", minimumPrice, maximusPrice,
						retryPrice) == 0) {
					*pPriceTransport = priceTransport;
				} else {
					printf("\n\nYa ingresó este costo\n\n");
				}
				break;
			}
		} else {
			printf("\nAlgo salió mal.\n");
		}
	}

}

void loadPlayer(int *pGoalkeeperCounter, int *pDefenderCounter,
		int *pMidfielderCounter, int *pStrikerCounter) {

	int position = 0;
	int minimum = 1;
	int maximus = 4;
	int retry = 3;
	if (pGoalkeeperCounter != NULL && pDefenderCounter != NULL
			&& pMidfielderCounter != NULL && pStrikerCounter != NULL) {
		if (utn_getNumber(&position, "Ingresar posicion:\n"
				"1. Arquero\n"
				"2. Defensor\n"
				"3. Mediocampista\n"
				"4. Delantero\n", "\nOpcion incorrecta\n ", minimum, maximus,
				retry) == 0) {

			switch (position) {

			case 1:
				if (*pGoalkeeperCounter < 2) {
					(*pGoalkeeperCounter)++;
				} else {
					printf("No puede haber mas de 2 arqueros\n");
				}
				break;
			case 2:
				if (*pDefenderCounter < 4) {
					(*pDefenderCounter)++;

				} else {
					printf("No puede haber mas de 8 defensores\n");
				}
				break;
			case 3:
				if (*pMidfielderCounter < 4) {
					(*pMidfielderCounter)++;
				} else {
					printf("No puede haber mas de 8 mediocampistas\n");
				}
				break;
			case 4:
				if (*pStrikerCounter < 4) {
					(*pStrikerCounter)++;
				} else {
					printf("No puede haber mas de 4 delanteros\n");
				}
				break;
			}
		} else {
			printf("\nAlgo salió mal\n");
		}
	}

}

void loadLeague(int *pAfcCounter, int *pCafCounter, int *pConcacafCounter,
		int *pConmebolCounter, int *pUefaCounter, int *pOfcCounter) {

	int league = 0;
	int minimum = 1;
	int maximus = 6;
	int retry = 3;
	if (pAfcCounter != NULL && pCafCounter != NULL && pConcacafCounter != NULL
			&& pConmebolCounter != NULL && pUefaCounter != NULL
			&& pOfcCounter != NULL) {
		if (utn_getNumber(&league, "Ingresar su Confederacion: \n"
				"1. AFC\n"
				"2. CAF\n"
				"3. CONCACAF\n"
				"4. CONMEBOL\n"
				"5. UEFA\n"
				"6. OFC\n", "\nOpcion incorrecta\n ", minimum, maximus, retry)
				== 0) {

			switch (league) {
			case 1:
				(*pAfcCounter)++;
				break;
			case 2:
				(*pCafCounter)++;
				break;
			case 3:
				(*pConcacafCounter)++;
				break;
			case 4:
				(*pConmebolCounter)++;
				break;
			case 5:
				(*pUefaCounter)++;
				break;
			case 6:
				(*pOfcCounter)++;
				break;
			}
		} else {
			printf("Algo salió mal");
		}
	} else {
		printf("\nAlgo salió mal\n");
	}
}

void calculates(int *pAfcCounter, int *pCafCounter, int *pConcacafCounter,
		int *pConmebolCounter, int *pUefaCounter, int *pOfcCounter,
		int *pTotalCounter, float *pPriceLodgin, float *pPriceFood,
		float *pPriceTransport, float *pAverageAfc, float *pAverageCaf,
		float *pAverageConcacaf, float *pAverageConmebol, float *pAverageUefa,
		float *pAverageOfc, float *pTotalPrice, float *pIncrementPrice,
		float *pIncrementTotalPrice) {

	*pAverageAfc = (float) *pAfcCounter / 22;
	*pAverageCaf = (float) *pCafCounter / 22;
	*pAverageConcacaf = (float) *pConcacafCounter / 22;
	*pAverageConmebol = (float) *pConmebolCounter / 22;
	*pAverageUefa = (float) *pUefaCounter / 22;
	*pAverageOfc = (float) *pOfcCounter / 22;

	*pTotalPrice = (*pPriceFood) + (*pPriceLodgin) + (*pPriceTransport);
	*pTotalCounter = *pAfcCounter + *pCafCounter + *pConcacafCounter
			+ *pConmebolCounter + *pOfcCounter + *pUefaCounter;

	if ((2 * (*pUefaCounter)) > *pTotalCounter) {
		*pIncrementPrice = *pTotalPrice * 0.35;
		*pIncrementTotalPrice = *pTotalPrice + *pIncrementPrice;
	}
}

