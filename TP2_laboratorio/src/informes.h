/*
 * informes.h
 *
 *  Created on: 20 oct. 2022
 *      Author: cuerpos
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "jugador.h"
/// @brief sortPerConfederationAndPlayerName        Ordena por doble criterio, nombre de confederacion y nombre de jugadores.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @return											Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief listConfederationPerPlayers				Lista confederaciones con sus jugadores por separado.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
void listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief countPlayers								 Cuenta jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param pCounterPlayer							Puntero a entero.
/// @return  										Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int countPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayer);
/// @brief accumulateTotalSalary					   Acumula salario de jugadores dados de alta.
///
/// @param arrayPlayer              	      		   Array de jugadores.
/// @param lenArrayPlayer					 	       Tamanio Array de jugadores.
/// @param pAcumulatorSalary						   Puntero a flotante.
/// @return                                            Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int accumulateTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAcumulatorSalary);
/// @brief calculateAverageTotalSalary				 Calcula promedio de salarios de jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param pAverageTotalSalary						 Puntero a flotante.
/// @return                           				 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int calculateAverageTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAverageTotalSalary);
/// @brief countPlayerAboveAverageSalary			Cuenta jugdores que ganan más del promedio de salarios de jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param pCounterPlayerAboveAverageSalary		     Puntero a entero.
/// @return                   						 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int countPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayerAboveAverageSalary);
/// @brief listPlayerAboveAverageSalary		    	 Informa y lista jugadores ganan más del promedio de salarios de jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
void listPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief accumulateHiringYearsByConfederation		Acumula anios de contrato de jugadores dados de alta por confederacion.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param arrayAccumulatorHiringYears				 Array de enteros para acumular anios de contrato.
/// @return                                    		 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int accumulateHiringYearsByConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[]);
/// @brief  calculateMaximusHiringYearsConfederation	Calcula confederacion con mas anios de contrato de jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param pMaximusHiringYears						 Puntero a entero.
/// @param arrayAccumulatorHiringYears				 Array de enteros para acumular anios de contrato.
/// @return											 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int *pMaximusHiringYears, int arrayAccumulatorHiringYears[]);
/// @brief listMaximusHiringYearsConfederation		lista confederacion con mas anios de contrato de jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param arrayAccumulatorHiringYears				 Array de enteros para acumular anios de contrato.
void listMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[]);
/// @brief accumulatePlayersPerConfederation		Acumula  jugadores dados de alta por confederacion.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param arrayAccumulatorPlayerPerConfederation	 Array de enteros para acumular jugadores por confederacion.
/// @return											 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int accumulatePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
/// @brief  calculatePercentagePlayersPerConfederation Calcula porcentaje de jugadores por confederacion.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param porcentagePlayersPerConfederation         Array de flotantes para porcentaje de jugadores por confederacion.
/// @param arrayAccumulatorPlayerPerConfederation     Array de enteros para acumular jugadores por confederacion.
/// @return											 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int calculatePercentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, float porcentagePlayersPerConfederation[], int arrayAccumulatorPlayerPerConfederation[]);
/// @brief listPercentagePlayersPerConfederation    Lista porcentaje de jugadores por confederacion.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param arrayAccumulatorPlayerPerConfederation    Array de enteros para acumular jugadores por confederacion.
void listPercentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
/// @brief calculateMaximusPlayersPerRegion			Calcula la region con mas jugadores dados de alta.
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param arrayAccumulatorPlayerPerConfederation	 Array de enteros para acumular jugadores por confederacion.
/// @param pMaximusPlayersPerConfederation			 Puntero a entero.
/// @return											 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int calculateMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[], int *pMaximusPlayersPerConfederation);
/// @brief listMaximusPlayersPerRegion
///
/// @param arrayPlayer              	      		 Array de jugadores.
/// @param lenArrayPlayer					 	     Tamanio Array de jugadores.
/// @param arrayConfederation 						 Array de confederaciones.
/// @param lenArrayConfederation 			 		 Tamanio de  Array de jugadores.
/// @param arrayAccumulatorPlayerPerConfederation	 Array de enteros para acumular jugadores por confederacion.
void listMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
#endif /* INFORMES_H_ */
