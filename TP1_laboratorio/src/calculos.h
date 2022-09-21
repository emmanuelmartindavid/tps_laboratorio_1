#ifndef CALCULOS_H_
#define CALCULOS_H_

int calculateAverageConfederation(int AfcCounter, int CafCounter,
		int ConcacafCounter, int ConmebolCounter, int UefaCounter,
		int OfcCounter, int confederationTotal, float *pAverageAfc,
		float *pAverageCaf, float *pAverageConcacaf, float *pAverageConmebol,
		float *pAverageUefa, float *pAverageOfc);

int calculateMaintenance(float PriceLodgin, float PriceFood,
		float PriceTransport, float pAverageAfc, float pAverageCaf,
		float pAverageConcacaf, float pAverageConmebol, float pAverageUefa,
		float pAverageOfc, float *pTotalPrice, float *pIncrementPrice,
		float *pIncrementTotalPrice);

#endif /* CALCULOS_H_ */
