#ifndef CARGADEDATOS_CALCULOS_H_
#define CARGADEDATOS_CALCULOS_H_


int loadCost(float* pPriceLodgin, float* pPriceFood, float* pPriceTransport);
int loadNumberShirt(int NumberShirt);
int loadPlayer(int* pGoalkeeperCounter, int* pDefenderCounter,
		int* pMidfielderCounter, int* pStrikerCounter);
int loadConfederation(int* pAfcCounter, int* pCafCounter, int* pConcacafCounter,
		int* pConmebolCounter, int* pUefaCounter, int* pOfcCounter);

int calculateAverage_Price(int AfcCounter, int CafCounter, int ConcacafCounter,
		int ConmebolCounter, int UefaCounter, int OfcCounter,
		int confederationTotal, float PriceLodgin, float PriceFood,
		float PriceTransport, float *pAverageAfc, float *pAverageCaf,
		float *pAverageConcacaf, float *pAverageConmebol, float *pAverageUefa,
		float *pAverageOfc, float *pTotalPrice, float *pIncrementPrice,
		float *pIncrementTotalPrice);

#endif /* CARGADEDATOS_CALCULOS_H_ */
