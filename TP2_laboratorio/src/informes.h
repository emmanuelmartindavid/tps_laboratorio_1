/*
 * informes.h
 *
 *  Created on: 20 oct. 2022
 *      Author: cuerpos
 */

#ifndef INFORMES_H_
#define INFORMES_H_
#include "jugador.h"
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @return
int sortPerConfederationAndPlayerName(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
void listConfederationPerPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pCounterPlayer
/// @return
int countPlayers(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayer);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pAcumulatorSalary
/// @return
int accumulateTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAcumulatorSalary);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pAverageTotalSalary
/// @return
int calculateAverageTotalSalary(sPlayer arrayPlayer[], int lenArrayPlayer, float *pAverageTotalSalary);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param pCounterPlayerAboveAverageSalary
/// @return
int countPlayerAboveAverageSalary(sPlayer arrayPlayer[], int lenArrayPlayer, int *pCounterPlayerAboveAverageSalary);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorHiringYears
/// @return
int accumulateHiringYearsByConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[]);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param pMaximusHiringYears
/// @param arrayAccumulatorHiringYears
/// @return
int calculateMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int *pMaximusHiringYears, int arrayAccumulatorHiringYears[]);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorHiringYears
/// @return
int showMaximusHiringYearsConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorHiringYears[]);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
/// @return
int accumulatePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param porcentagePlayersPerConfederation
/// @param arrayAccumulatorPlayerPerConfederation
/// @return
int calculatePercentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, float porcentagePlayersPerConfederation[], int arrayAccumulatorPlayerPerConfederation[]);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
void showPercentagePlayersPerConfederation(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
/// @param pMaximusPlayersPerConfederation
/// @return
int calculateMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[], int *pMaximusPlayersPerConfederation);
/// @brief
///
/// @param arrayPlayer
/// @param lenArrayPlayer
/// @param arrayConfederation
/// @param lenArrayConfederation
/// @param arrayAccumulatorPlayerPerConfederation
void showMaximusPlayersPerRegion(sPlayer arrayPlayer[], int lenArrayPlayer, sConfederation arrayConfederation[], int lenArrayConfederation, int arrayAccumulatorPlayerPerConfederation[]);
#endif /* INFORMES_H_ */
