#ifndef CALCULOS_H_
#define CALCULOS_H_
/// @param AfcCounter
/// @param CafCounter
/// @param ConcacafCounter
/// @param ConmebolCounter
/// @param UefaCounter
/// @param OfcCounter
/// @param confederationTotal
/// @param pAverageAfc
/// @param pAverageCaf
/// @param pAverageConcacaf
/// @param pAverageConmebol
/// @param pAverageUefa
/// @param pAverageOfc
/// @return
int calculateAverageConfederation(int AfcCounter, int CafCounter,
		int ConcacafCounter, int ConmebolCounter, int UefaCounter,
		int OfcCounter, int confederationTotal, float *pAverageAfc,
		float *pAverageCaf, float *pAverageConcacaf, float *pAverageConmebol,
		float *pAverageUefa, float *pAverageOfc);
/// @param PriceLodgin
/// @param PriceFood
/// @param PriceTransport
/// @param pAverageAfc
/// @param pAverageCaf
/// @param AverageConcacaf
/// @param AverageConmebol
/// @param AverageUefa
/// @param AverageOfc
/// @param pTotalPrice
/// @param pIncrementPrice
/// @param pIncrementTotalPrice
/// @return
int calculateMaintenance(float PriceLodgin, float PriceFood,
		float PriceTransport, float pAverageAfc, float pAverageCaf,
		float AverageConcacaf, float AverageConmebol, float AverageUefa,
		float AverageOfc, float *pTotalPrice, float *pIncrementPrice,
		float *pIncrementTotalPrice);

#endif /* CALCULOS_H_ */
