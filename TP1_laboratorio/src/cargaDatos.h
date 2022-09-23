#ifndef CARGADATOS_H_
#define CARGADATOS_H_
/// @brief
///
/// @param pPriceLodgin
/// @param pPriceFood
/// @param pPriceTransport
/// @return
int loadCost(float *pPriceLodgin, float *pPriceFood, float *pPriceTransport);
/// @brief
///
/// @param NumberShirt
/// @return
int loadNumberShirt(int NumberShirt);
/// @brief
///
/// @param pGoalkeeperCounter
/// @param pDefenderCounter
/// @param pMidfielderCounter
/// @param pStrikerCounter
/// @return
int loadPlayer(int *pGoalkeeperCounter, int *pDefenderCounter,
		int *pMidfielderCounter, int *pStrikerCounter);
/// @brief
///
/// @param pAfcCounter
/// @param pCafCounter
/// @param pConcacafCounter
/// @param pConmebolCounter
/// @param pUefaCounter
/// @param pOfcCounter
/// @return
int loadConfederation(int *pAfcCounter, int *pCafCounter, int *pConcacafCounter,
		int *pConmebolCounter, int *pUefaCounter, int *pOfcCounter);




#endif /* CARGADATOS_H_ */
