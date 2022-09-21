#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_validaciones.h"
#include "cargaDatos.h"

int loadCost(float *pPriceLodgin, float *pPriceFood, float *pPriceTransport) {

	float minimumPrice = 1;
	float maximusPrice = 100000000000;
	int retryPrice = 3;
	int option;
	float priceFood = 0;
	float priceLodgin = 0;
	float priceTransport = 0;
	int ret = -1;

	if (pPriceLodgin != NULL && pPriceFood != NULL && pPriceTransport != NULL) {
		ret = 0;
		if (utn_getNumber(&option, "\nIngrese costo a cargar:\n"
				"1. Costo hospedaje.\n"
				"2. Costo comida.\n"
				"3. Costo transporte.\n", "\nOpcion incorrecta.\n ", 1, 3, 5)
				== 0) {

			switch (option) {
			case 1:

				if (*pPriceLodgin == 0
						&& utn_getNumberFloat(&priceLodgin,
								"Ingrese costo de hospedaje $\n",
								"Ingrese precio valido\n", minimumPrice,
								maximusPrice, retryPrice) == 0) {
					*pPriceLodgin = priceLodgin;
					ret = 0;
				} else {
					printf("\n\nYa ingresó este costo\n\n");
				}
				break;
			case 2:

				if (*pPriceFood == 0
						&& utn_getNumberFloat(&priceFood,
								"Ingrese costo de comida $\n",
								"Ingrese precio valido\n", minimumPrice,
								maximusPrice, retryPrice) == 0) {
					*pPriceFood = priceFood;
					ret = 0;
				} else {
					printf("\n\nYa ingresó este costo\n\n");
				}

				break;
			case 3:

				if (*pPriceTransport == 0
						&& utn_getNumberFloat(&priceTransport,
								"Ingrese costo de transporte $\n",
								"Ingrese precio valido\n", minimumPrice,
								maximusPrice, retryPrice) == 0) {
					*pPriceTransport = priceTransport;
					ret = 0;
				} else {
					printf("\n\nYa ingresó este costo\n\n");
				}
				break;
			}
		} else {
			printf("\n\nAlgo salió mal.\n\n");
		}
	}

	return ret;

}

int loadNumberShirt(int NumberShirt) {

	int shirt = 0;
	int ret = -1;
	//int i;
	//int j;
	if (utn_getNumber(&shirt,
			"\nIngrese numero de camiseta. Solo entre el 1 y el 99\n",
			"\nOpcion incorrecta\n", 1, 99, 5) == 0) {
		ret = 0;

	}

//		for (i = 0; i < 100; i++)
//			for (j = i + 1; j < 100; j++) {
//				if ( ==) {
//
//					printf(
//							"position[%d] = number %d = position[%d] = number %d\n",
//							i, number[i], j, number[j]);
//				}
//			}
//		}

	return ret;

}

int loadPlayer(int *pGoalkeeperCounter, int *pDefenderCounter,
		int *pMidfielderCounter, int *pStrikerCounter) {

	int ret = -1;
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
				"4. Delantero\n", "\nOpcion incorrecta\n", minimum, maximus,
				retry) == 0) {

			switch (position) {

			case 1:
				if (*pGoalkeeperCounter < 2) {
					(*pGoalkeeperCounter)++;
					ret = 0;
				} else {
					printf("No puede haber mas de 2 arqueros\n");

				}
				break;
			case 2:
				if (*pDefenderCounter < 2) {
					(*pDefenderCounter)++;
					ret = 0;

				} else {
					printf("No puede haber mas de 8 defensores\n");

				}
				break;
			case 3:
				if (*pMidfielderCounter < 2) {
					(*pMidfielderCounter)++;
					ret = 0;
				} else {
					printf("No puede haber mas de 8 mediocampistas\n");
				}
				break;
			case 4:
				if (*pStrikerCounter < 2) {
					(*pStrikerCounter)++;
					ret = 0;
				} else {
					printf("No puede haber mas de 4 delanteros\n");
				}
				break;
			}
		} else {
			printf("\nREINTENTE POR FAVOR. SOLOS NUMEROS VALIDOS\n");
		}
	}
	return ret;
}

int loadConfederation(int *pAfcCounter, int *pCafCounter, int *pConcacafCounter,
		int *pConmebolCounter, int *pUefaCounter, int *pOfcCounter) {

	int ret = -1;
	int league = 0;
	int minimum = 1;
	int maximus = 6;
	int retry = 3;
	if (pAfcCounter != NULL && pCafCounter != NULL && pConcacafCounter != NULL
			&& pConmebolCounter != NULL && pUefaCounter != NULL
			&& pOfcCounter != NULL) {
		if (utn_getNumber(&league, "Ingresar su Confederacion:\n"
				"1. AFC\n"
				"2. CAF\n"
				"3. CONCACAF\n"
				"4. CONMEBOL\n"
				"5. UEFA\n"
				"6. OFC\n", "\nOpcion incorrecta\n", minimum, maximus, retry)
				== 0) {

			switch (league) {
			case 1:
				(*pAfcCounter)++;
				ret = 0;
				break;
			case 2:
				(*pCafCounter)++;
				ret = 0;
				break;
			case 3:
				(*pConcacafCounter)++;
				ret = 0;
				break;
			case 4:
				(*pConmebolCounter)++;
				ret = 0;
				break;
			case 5:
				(*pUefaCounter)++;
				ret = 0;
				break;
			case 6:
				(*pOfcCounter)++;
				ret = 0;
				break;
			}
		} else {
			printf("\nREINTENTE POR FAVOR. SOLOS NUMEROS VALIDOS\n");
		}
	}
	return ret;
}
