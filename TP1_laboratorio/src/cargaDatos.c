#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "UTN_validaciones.h"
#include "cargaDatos.h"

/// @brief loadCosts          Funcion para cargar los costos de Mantenimiento(Hospedaje, Comida, Transporte).
///
/// @param pPriceLodgin       Puntero precio de Hospedaje.
/// @param pPriceFood         Puntero precio de Comida.
/// @param pPriceTransport    Puntero precio de Transporte.
/// @return                   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadCosts(float *pPriceLodgin, float *pPriceFood, float *pPriceTransport) {

	float minimumPrice = 1;
	float maximusPrice = 100000000000;
	int retryPrice = 3;
	int option;
	float priceFood = 0;
	float priceLodgin = 0;
	float priceTransport = 0;
	char optionNewPrice;
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
				} else if (*pPriceLodgin > 0) {

					printf(
							"\t\tYa ingreso este costo.\n\n"
									"\t\tTenga en cuenta. Al reingresar su costo de HOSPEDAJE,\n"
									"\t\treemplazara el costo previamente ingresado\n\n");

					fflush(stdin);
					printf(
							"\t\tPresione S para reingresar costo. Presione cualquier tecla para salir.\n");
					scanf("%c", &optionNewPrice);

					if (isalpha(optionNewPrice) && optionNewPrice == 's'
							&& utn_getNumberFloat(&priceLodgin,
									"Ingrese costo de hospedaje $\n",
									"Ingrese precio valido\n", minimumPrice,
									maximusPrice, retryPrice) == 0) {

						*pPriceLodgin = priceLodgin;
						printf("\t\tSu costo se cargo correctamente\n\n");

					} else {
						printf("\t\tNo reingreso costo\n\n");
					}

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
					} else if (*pPriceFood > 0) {

						printf(
								"\t\tYa ingreso este costo.\n\n"
										"\t\tTenga en cuenta. Al reingresar su costo de COMIDA,\n"
										"\t\treemplazara el costo previamente ingresado\n\n");

						fflush(stdin);
						printf(
								"\t\tPresione S para reingresar costo. Presione cualquier tecla para salir.");
						scanf("%c", &optionNewPrice);

						if (isalpha(optionNewPrice) && optionNewPrice == 's'
								&& utn_getNumberFloat(&priceFood,
										"Ingrese costo de comida $\n",
										"Ingrese precio valido\n", minimumPrice,
										maximusPrice, retryPrice) == 0) {

							*pPriceFood = priceFood;
							printf("\t\tSu costo se cargo correctamente\n\n");

						} else {
							printf("\t\tNo reingreso costo\n\n");
						}

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
					} else if (*pPriceTransport > 0) {
						{

							printf(
									"\t\tYa ingreso este costo.\n\n"
											"\t\tTenga en cuenta. Al reingresar su costo de TRANSPORTE,\n"
											"\t\treemplazara el costo previamente ingresado\n\n");

							fflush(stdin);
							printf(
									"\t\tPresione S para reingresar costo. Presione cualquier tecla para salir.");
							scanf("%c", &optionNewPrice);

							if (isalpha(optionNewPrice) && optionNewPrice == 's'
									&& utn_getNumberFloat(&priceTransport,
											"Ingrese costo de transporte $\n",
											"Ingrese precio valido\n", minimumPrice,
											maximusPrice, retryPrice) == 0) {

								*pPriceTransport = priceTransport;
								printf("\t\tSu costo se cargo correctamente\n\n");

							} else {
								printf("\t\tNo reingreso costo\n\n");
							}

						}
					break;
				}
			}
		} else {
			printf("\t\tREINTENTE POR FAVOR. SOLO COSTOS VALIDOS\n\n");
		}
	}

	return ret;

}

/// @brief loadShirtNumber    Funcion para cargar numero de camiseta de jugador.
///
/// @param NumberShirt        Parametro numero de camiseta de jugador.
/// @return                   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadShirtNumber(int numberShirt) {

	int ret = -1;

	if (utn_getNumber(&numberShirt,
			"\nIngrese numero de camiseta. Solo entre el 1 y el 99\n",
			"\nOpcion incorrecta\n", 1, 99, 5) == 0) {
		ret = 0;

	}
	return ret;
}

/// @brief loadPlayerPosition Funcion para cargar posicion de jugador.
///
/// @param pGoalkeeperCounter Puntero de Contador de Arquero.
/// @param pDefenderCounter   Puntero de Contador de Defensor.
/// @param pMidfielderCounter Puntero de Contador de Mediocampista.
/// @param pStrikerCounter    Puntero de Contador de Delantero.
/// @return                   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadPlayerPosition(int *pGoalkeeperCounter, int *pDefenderCounter,
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
					printf("\t\tNo puede haber mas de 2 arqueros\n");

				}
				break;
			case 2:
				if (*pDefenderCounter < 8) {
					(*pDefenderCounter)++;
					ret = 0;

				} else {
					printf("\t\tNo puede haber mas de 8 defensores\n");

				}
				break;
			case 3:
				if (*pMidfielderCounter < 8) {
					(*pMidfielderCounter)++;
					ret = 0;
				} else {
					printf("\t\tNo puede haber mas de 8 mediocampistas\n");
				}
				break;
			case 4:
				if (*pStrikerCounter < 4) {
					(*pStrikerCounter)++;
					ret = 0;
				} else {
					printf("\t\tNo puede haber mas de 4 delanteros\n");
				}
				break;
			}
		} else {
			printf("\t\tREINTENTE POR FAVOR. SOLO NUMEROS VALIDOS\n");
		}
	}
	return ret;
}

/// @brief loadPlayerConfederation Funcion para cargar Confederacion de jugador
///
/// @param pAfcCounter       Puntero de Contador AFC.
/// @param pCafCounter       Puntero de Contador CAF.
/// @param pConcacafCounter  Puntero de Contador CONCACAF.
/// @param pConmebolCounter  Puntero de Contador CONMEBOL.
/// @param pUefaCounter      Puntero de Contador UEFA.
/// @param pOfcCounter       Puntero de Contador OFC.
/// @return                  Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadPlayerConfederation(int *pAfcCounter, int *pCafCounter,
		int *pConcacafCounter, int *pConmebolCounter, int *pUefaCounter,
		int *pOfcCounter) {

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
			printf("\t\tREINTENTE POR FAVOR. SOLO NUMEROS VALIDOS\n");
		}
	}
	return ret;
}
