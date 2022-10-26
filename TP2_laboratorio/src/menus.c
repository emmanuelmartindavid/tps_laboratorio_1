/*
 * menus.c
 *
 *  Created on: 23 oct. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
void showMainMenu(void)
{

	printf("\t\t\t\t\t\t\t==========================MENU-PRINCIPAL-FIFA============================"
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 1. ALTA DE JUGADOR.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 2. BAJA DE JUGADOR.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 3. MODIFICACION DE JUGADOR.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 4. INFORMES.\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 5. SALIR.\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
			"\t\t\t\t\t\t\t=========================================================================\n");

}

void showModifyPlayerMenu(void)
{

	printf("\t\t\t\t\t\t\t=========================MENU MODIFICACION==============================="
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 1. NOMBRE:\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 2. POSICION:\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 3. NUMERO DE CAMISETA:\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 4. CONFEDERACION:\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 5. SALARIO:\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 6. ANIOS DE CONTRATO:\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t 7. SALIR.\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
			"\t\t\t\t\t\t\t=========================================================================\n");
}

void showReportMenu(void)
{

	printf("\t\t\t\t\t\t=====================================INFORMES===================================="
			"\n\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|"
			"\n\t\t\t\t\t\t|\t 1. LISTADO DE JUGADORES ORDENADOS ALFABETICAMENTE,\t\t\t|\n"
			"\t\t\t\t\t\t|\t     POR NOMBRE DE CONFEDERACION Y NOMBRE DE JUGADOR.\t\t\t|"
			"\n\t\t\t\t\t\t|\t 2. LISTADO DE CONFEDERACIONES CON SUS JUGADORES.\t\t\t|"
			"\n\t\t\t\t\t\t|\t 3. TOTAL Y PROMEDIO DE TODOS LOS SALARIOS.\t\t\t\t|"
			"\n\t\t\t\t\t\t|\t     Y CUANTOS JUGADORES COBRAN MAS DEL SALARIO PROMEDIO.\t\t|"
			"\n\t\t\t\t\t\t|\t 4. CONFEDERACION CON MAYOR CANTIDAD DE ANIOS DE CONTRATO TOTAL.\t|"
			"\n\t\t\t\t\t\t|\t 5. PORCENTAJE DE JUGADORES POR CADA CONFEDERACION.\t\t\t|"
			"\n\t\t\t\t\t\t|\t 6. SALIR:\t\t\t\t\t\t\t\t|"
			"\n\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t\t|\n"
			"\t\t\t\t\t\t=================================================================================\n");
}