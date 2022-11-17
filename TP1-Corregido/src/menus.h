/*
 * menus.h
 *
 *  Created on: 17 nov. 2022
 *      Author: cuerpos
 */

#ifndef MENUS_H_
#define MENUS_H_

void mainMenu(float lodginPrice, float foodPrice, float transportPrice, int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter);
void costsMenu(float lodginPrice, float foodPrice, float transportPrice);
void playersMenu(int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter);
void conferationMenu(int afcCounter, int cafCounter, int concacafCounter, int conmebolCounter, int uefaCounter, int ofcCounter);
void reportAverageMenu(float afcAverage, float cafAverage, float concacafAverage, float conmebolAverage, float uefaAverage, float ofcAverage);
#endif /* MENUS_H_ */
