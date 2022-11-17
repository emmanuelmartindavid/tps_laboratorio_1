/*
 * menus.c
 *
 *  Created on: 17 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>


void mainMenu(float lodginPrice, float foodPrice, float transportPrice, int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter)
{

	printf("\t\t\t\t\t\t\t=============================MENU-PRINCIPAL=============================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. CARGA DE COSTOS DE MANTENIMIENTO.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  COSTO DE HOSPEDAJE -> $%.2f.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  COSTO DE COMIDA -> $%.2f.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  COSTO DE TRANSPORTE -> $%.2f.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. CARGA DE JUGADORES.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  ARQUEROS -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  DEFENSORES -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  MEDIOCAMPISTAS -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t  DELANTEROS -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. REALIZAR TODOS LOS CALCULOS\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 4. INFORMAR RESULTADOS.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 5. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
					"\t\t\t\t\t\t\t=========================================================================\n\n\n", lodginPrice, foodPrice, transportPrice, goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
}

void costsMenu(float lodginPrice, float foodPrice, float transportPrice)
{

	printf("\t\t\t\t\t\t\t=============================MENU-COSTOS================================="
					"\n\t\t\t\t\t\t\t|\t\t1. INGRESAR COSTO DE HOSPEDAJE -> $%.2f.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t2. INGRESAR COSTO DE COMIDA -> $%.2f.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t3. INGRESAR COSTO DE TRANSPORTE -> $%.2f.\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n", lodginPrice, foodPrice, transportPrice);

}

void playersMenu(int goalkeeperCounter, int defenderCounter, int midfielderCounter, int strikerCounter)
{
	printf("\t\t\t\t\t\t\t============================MENU-JUGADORES==============================="
					"\n\t\t\t\t\t\t\t|\t\t\t1.  ARQUERO -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t2.  DEFENSOR -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t3.  MEDIOCAMPISTA -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t4.  DELANTERO -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n", goalkeeperCounter, defenderCounter, midfielderCounter, strikerCounter);
}

void conferationMenu(int afcCounter, int cafCounter, int concacafCounter, int conmebolCounter, int uefaCounter, int ofcCounter)
{
	printf("\t\t\t\t\t\t\t============================MENU-CONFEDERACIONES========================="
					"\n\t\t\t\t\t\t\t|\t\t\t1.  AFC -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t2.  CAF -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t3.  CONCACAF -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t4.  CONMEBOL -> %d.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t5.  UEFA -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t6.  OFC -> %d.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n", afcCounter, cafCounter, concacafCounter, conmebolCounter, uefaCounter, ofcCounter);
}

void reportAverageMenu(float afcAverage, float cafAverage, float concacafAverage, float conmebolAverage, float uefaAverage, float ofcAverage)
{
	printf("\t\t\t\t\t\t\t=========================PROMEDIO-CONFEDERACIONES========================"
					"\n\t\t\t\t\t\t\t|\t\t\t  AFC -> %.2f\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t CAF -> %.2f\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t  CONCACAF -> %.2f\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t  CONMEBOL -> %.2f\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t UEFA -> %.2f\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t  OFC -> %.2f\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t=========================================================================\n\n\n", afcAverage, cafAverage, concacafAverage, conmebolAverage, uefaAverage, ofcAverage);

}
