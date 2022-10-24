/*
 * informes.h
 *
 *  Created on: 20 oct. 2022
 *      Author: cuerpos
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "jugador.h"

int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer,
		sConfederation arrayConfederation[], int lenArrayConfederation);
int listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer,
		sConfederation arrayConfederation[], int lenArrayConfederation);

int countPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayer);
int accumulateTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer,
		float *pAcumulatorSalary);
int calculateAverageTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer,
		float *pAverageTotalSalary);
int countPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer,
		int *pCounterPlayerAboveAverageSalary);

//int accumulateHiringYears(sPlayer arrayPlayer[], int lenArrayPlayer, int id,
//		int *pAccumulatorHiringYears) ;
int accumulateHiringYearsByConfederationId(sPlayer arrayPlayer[],
		int lenArrayPlayer, int id, int *pAccumulatorHiringYears) ;
//int accumulateHiringYears(sPlayer Player, int id, int *pAccumulatorHiringYears);
//int acumuladorFor(sPlayer arrayPlayer[], int lenArrayPlayer,
//		sConfederation arrayConfederation[], int lenArrayConfederation);

int accumulateHiringYearsPerConfederation(sPlayer arrayPlayer[],
		int lenArrayPlayer, int *pAccumulatorConmebol,
		int *pAccumulatorUefa, int *pAccumulatorAfc, int *pAccumulatorCaf,
		int *pAccumulatorConcacaf,
		int *pAccumulatorOfc);
//int accumulateHiringYearsPerConfederation(sPlayer arrayPlayer[],
//		int lenArrayPlayer, int *pAccumulatorHiringYearsConmebol,
//		int *pAccumulatorHiringYearsUefa, int *pAccumulatorHiringYearsAfc,
//		int *pAccumulatorHiringYearsCaf, int *pAccumulatorHiringYearsConcacaf,
//		int *pAccumulatorHiringYearsOfc);
//int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[],
//		int lenArrayPlayer) ;
int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[],
		int lenArrayPlayer);
#endif /* INFORMES_H_ */
