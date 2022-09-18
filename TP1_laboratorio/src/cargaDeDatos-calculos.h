#ifndef CARGADEDATOS_CALCULOS_H_
#define CARGADEDATOS_CALCULOS_H_


void loadCost(float* pPriceLodgin, float* pPriceFood, float* pPriceTransport);
void loadPlayer(int *pGoalkeeperCounter, int *pDefenderCounter,
		int *pMidfieldCounter, int *pStrikerCounter);
void loadLeague(int *pAfcCounter, int *pCafCounter, int *pConcacafCounter,
		int *pConmebolCounter, int *pUefaCounter, int *pOfcCounter);
void calculates(int* pAfcCounter, int* pCafCounter, int* pConcacafCounter,
		int* pConmebolCounter, int* pUefaCounter, int* pOfcCounter, int* pTotalCounter,
		float* pPriceLodgin, float* pPriceFood, float* pPriceTransport, float* pAverageAfc,
		float* pAverageCaf, float* pAverageConcacaf, float* pAverageConmebol,
		float* pAverageUefa, float* pAverageOfc, float* pTotalPrice, float* pIncrementPrice, float* pIncrementTotalPrice);

#endif /* CARGADEDATOS_CALCULOS_H_ */
