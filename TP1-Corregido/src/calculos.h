/*
 * calculos.h
 *
 *  Created on: 17 nov. 2022
 *      Author: cuerpos
 */

#ifndef CALCULOS_H_
#define CALCULOS_H_
/// @brief calculateTotalCost				CALCULA COSTOS DE MANTENIMIENTO.
///
/// @param lodginPrice						FLOTANTE.
/// @param foodPrice						FLOTANTE.
/// @param transportPrice					FLOTANTE.
/// @param pResult
/// @return									RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
int calculateTotalCost(float lodginPrice, float foodPrice, float transportPrice, float *pResult);
/// @brief calculatePriceIncremented		CALCULA PRECIO INCREMENTADO DE MANTENIMIENTO.
///
/// @param totalPrice						FLOTANTE.
/// @param pResult							PUNTERO FLOTANTE.
/// @return									RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
int calculatePriceIncremented(float totalPrice, float *pResult);
/// @brief countPlayersOrConfederation		CUENTA JUGADORES O CONFEDERACIONES SEGUN CRITERIO PASADO POR PARAMETRO.
///
/// @param pCounter							PUNTERO ENTERO.
/// @param max								ENTERO
/// @return									RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
int countPlayersOrConfederation(int *pCounter, int max);
/// @brief calculateAveragePlayersPerConfederation		CALCULA PROMEDIO SEGUN PARAMETROS.
///
/// @param confederationCounter					ENTERO
/// @param playerCounter						ENTERO
/// @param pResult								PUNTERO FLOTANTE.
/// @return										RETORNO, SUCCES (1) EN CASO DE HANER FUNCIONADO CORRECTAMENTE. RETORNO, ERROR (-1) EN CASO CONTRARIO.
int calculateAveragePlayersPerConfederation(int confederationCounter, int playerCounter, float *pResult);
/// @brief disccountCounter					DESCUENTA CONTADOR SEGUN CRITERIO PASADO POR PARAMETRO.
///
/// @param counter							PUNTERO ENTERO.
/// @param pFlag							PUNTERO ENTERO.
void disccountCounter(int *counter, int *pFlag);

#endif /* CALCULOS_H_ */
