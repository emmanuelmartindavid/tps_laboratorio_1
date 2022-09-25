#ifndef CARGADATOS_H_
#define CARGADATOS_H_


/// @brief loadCosts          Funcion para cargar los costos de Mantenimiento(Hospedaje, Comida, Transporte).
///
/// @param pPriceLodgin       Puntero precio de Hospedaje.
/// @param pPriceFood         Puntero precio de Comida.
/// @param pPriceTransport    Puntero precio de Transporte.
/// @return                   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadCosts(float *pPriceLodgin, float *pPriceFood, float *pPriceTransport) ;
/// @brief loadShirtNumber    Funcion para cargar numero de camiseta de jugador.
///
/// @param NumberShirt        Parametro numero de camiseta de jugador.
/// @return                   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadShirtNumber(int numberShirt);
/// @brief loadPlayerPosition Funcion para cargar posicion de jugador.
///
/// @param pGoalkeeperCounter Puntero de Contador de Arquero.
/// @param pDefenderCounter   Puntero de Contador de Defensor.
/// @param pMidfielderCounter Puntero de Contador de Mediocampista.
/// @param pStrikerCounter    Puntero de Contador de Delantero.
/// @return                   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadPlayerPosition(int *pGoalkeeperCounter, int *pDefenderCounter,
		int *pMidfielderCounter, int *pStrikerCounter) ;
/// @brief loadPlayerConfederation Funcion para cargar Confederacion de jugador
///
/// @param pAfcCounter       Puntero de Contador AFC.
/// @param pCafCounter       Puntero de Contador CAF.
/// @param pConcacafCounter  Puntero de Contador CONCACAF.
/// @param pConmebolCounter  Puntero de Contador CONMEBOL.
/// @param pUefaCounter      Puntero de Contador UEFA.
/// @param pOfcCounter       Puntero de Contador OFC.
/// @return                  Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int loadPlayerConfederation(int *pAfcCounter, int *pCafCounter, int *pConcacafCounter,
		int *pConmebolCounter, int *pUefaCounter, int *pOfcCounter);


#endif /* CARGADATOS_H_ */
