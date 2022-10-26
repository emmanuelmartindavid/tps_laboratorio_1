/*
 * informes.h
 *
 *  Created on: 20 oct. 2022
 *      Author: cuerpos
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "jugador.h"

int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);

int listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);

int countPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayer);

int accumulateTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAcumulatorSalary);

int calculateAverageTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAverageTotalSalary);

int countPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayerAboveAverageSalary);

int accumulateHiringYearsByConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[]);

int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int *pMaximusHiringYears, int arrayAccumulatorHiringYears[]);

int accumulatePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);

int calculatePorcentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, float porcentagePlayersPerConfederation[], int arrayAccumulatorPlayerPerConfederation[]);

int calculateMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[], int *pMaximusPlayersPerConfederation);

int showMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
#endif /* INFORMES_H_ */
