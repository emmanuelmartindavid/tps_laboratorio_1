#include <stdio.h>
#include <stdlib.h>
#include "calculos.h"

int calculateAverageConfederation(int AfcCounter, int CafCounter,
		int ConcacafCounter, int ConmebolCounter, int UefaCounter,
		int OfcCounter, int confederationTotal, float *pAverageAfc,
		float *pAverageCaf, float *pAverageConcacaf, float *pAverageConmebol,
		float *pAverageUefa, float *pAverageOfc) {

	int ret = -1;

	if (pAverageAfc != NULL && pAverageCaf != NULL && pAverageConcacaf != NULL
			&& pAverageConmebol != NULL && pAverageUefa != NULL
			&& pAverageOfc != NULL) {

		confederationTotal = AfcCounter + CafCounter + ConcacafCounter
				+ ConmebolCounter + UefaCounter + OfcCounter;

		*pAverageAfc = (float) AfcCounter / confederationTotal;
		*pAverageCaf = (float) CafCounter / confederationTotal;
		*pAverageConcacaf = (float) ConcacafCounter / confederationTotal;
		*pAverageConmebol = (float) ConmebolCounter / confederationTotal;
		*pAverageUefa = (float) UefaCounter / confederationTotal;
		*pAverageOfc = (float) OfcCounter / confederationTotal;

		ret = 0;
	}
	return ret;
}

int calculateMaintenance(float PriceLodgin, float PriceFood,
		float PriceTransport, float pAverageAfc, float pAverageCaf,
		float pAverageConcacaf, float pAverageConmebol, float pAverageUefa,
		float pAverageOfc, float *pTotalPrice, float *pIncrementPrice,
		float *pIncrementTotalPrice) {

	int ret = -1;

	if (pTotalPrice != NULL && pIncrementPrice != NULL
			&& pIncrementTotalPrice != NULL) {

		*pTotalPrice = PriceFood + PriceLodgin + PriceTransport;

		if (pAverageUefa > pAverageAfc && pAverageUefa > pAverageCaf
				&& pAverageUefa > pAverageConcacaf
				&& pAverageUefa > pAverageConmebol
				&& pAverageUefa > pAverageOfc) {
			*pIncrementPrice = *pTotalPrice * 0.35;
			*pIncrementTotalPrice = *pTotalPrice + *pIncrementPrice;
		}

		ret = 0;
	}
	return ret;
}
