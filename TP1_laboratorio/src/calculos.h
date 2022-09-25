#ifndef CALCULOS_H_
#define CALCULOS_H_


/// @brief	calculateAverageConfederation  Funcion para realizar los promedios de las Confederaciones.
///
/// @param AfcCounter                      Recibe parametro de contador de AFC.
/// @param CafCounter                      Recibe parametro de contador de CAF.
/// @param ConcacafCounter                 Recibe parametro de contador de CONCACAF.
/// @param ConmebolCounter                 Recibe parametro de contador de CONMEBOL.
/// @param UefaCounter                     Recibe parametro de contador de UEFA.
/// @param OfcCounter                      Recibe parametro de contador de OFC.
/// @param confederationTotal              Parametro recibe la suma de todas la confederaciones.
/// @param pAverageAfc                     Puntero de promedio AFC.
/// @param pAverageCaf                     Puntero de promedio CAF.
/// @param pAverageConcacaf                Puntero de promedio CONCACAF.
/// @param pAverageConmebol                Puntero de promedio CONMEBOL.
/// @param pAverageUefa                    Puntero de promedio UEFA.
/// @param pAverageOfc                     Puntero de promedio OFC.
/// @return								   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int calculateAverageConfederation(int AfcCounter, int CafCounter,
		int ConcacafCounter, int ConmebolCounter, int UefaCounter,
		int OfcCounter, int confederationTotal, float *pAverageAfc,
		float *pAverageCaf, float *pAverageConcacaf, float *pAverageConmebol,
		float *pAverageUefa, float *pAverageOfc);
/// @brief	calculateMaintenance           Funcion para realizar el calculo de Mantenimiento.
///
/// @param PriceLodgin					   Recibe parametro PRECIO DE HOSPEDAJE INGRESADO.
/// @param PriceFood					   Recibe parametro PRECIO DE COMIDA INGRESADO.
/// @param PriceTransport			       Recibe parametro PRECIO DE TRANSPORTE INGRESADO.
/// @param pAverageAfc					   Recibe puntero de PROMEDIO DE AFC.
/// @param pAverageCaf					   Recibe puntero de PROMEDIO DE CAF.
/// @param AverageConcacaf                 Recibe puntero de PROMEDIO DE CONCACAF.
/// @param AverageConmebol                 Recibe puntero de PROMEDIO DE CONMEBOL.
/// @param AverageUefa                     Recibe puntero de PROMEDIO DE UEFA.
/// @param AverageOfc                      Recibe puntero de PROMEDIO DE OFC.
/// @param pTotalPrice                     Puntero de DE PRECIO TOTAL DE MANTENIMIENTO(suma de precio Comida, Hospedaje, Transporte).
/// @param pIncrementPrice                 Puntero de DE INCREMENTO DEL 35%% DEL COSTO DE MANTENIMIENTO.
/// @param pIncrementTotalPrice            Puntero de DE PRECIO DE MANTENIMIENTO CON EL INCREMENTO DEL 35%% SUMADO.
/// @return                                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int calculateMaintenance(float PriceLodgin, float PriceFood,
		float PriceTransport, float pAverageAfc, float pAverageCaf,
		float AverageConcacaf, float AverageConmebol, float AverageUefa,
		float AverageOfc, float *pTotalPrice, float *pIncrementPrice,
		float *pIncrementTotalPrice);


#endif /* CALCULOS_H_ */
