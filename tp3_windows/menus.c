/*
 * menus.c
 *
 *  Created on: 4 nov. 2022
 *      Author: cuerpos
 */
#include <stdio.h>
#include <stdlib.h>
#include "menus.h"
/// @brief showMainMenu       MENU PRINCIPAL FIFA
///
void showMainMenu()
{

	printf("\t\t\t\t\t\t\t==========================MENU-PRINCIPAL-FIFA============================"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 1. CARGA DE ARCHIVOS.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 2. ALTA DE JUGADOR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 3. MODIFICACION DE JUGADOR.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 4. BAJA DE JUGADOR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 5. LISTADOS.\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 6. CONVOCAR JUGADORES.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 7. ORDENAR Y LISTAR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 8. GENERAR ARCHIVO BINARIO,\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t    POR CONFEDERACION ELEGIDA.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 9. CARGAR ARCHIVO BINARIO POR CONFEDERACION.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 	LISTADOS DE LOS MISMOS.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 10. GUARDAR ARCHIVOS .CSV.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t 11. SALIR.\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
					"\t\t\t\t\t\t\t=========================================================================\n");
}
/// @brief showPositionMenu	    MENU POSICIONES.
///
void showPositionMenu()
{
	printf("\t\t\t\t\t\t\t===========================POSICIONES============================"
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 1. PORTERO.\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 2. DEFENSOR CENTRAL.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 3. LATERAL IZQUIERDO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 4. LATERAL DERECHO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 5. PIVOTE.\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 6. MEDIOCENTRO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 7. MEDIOCENTRO OFENSIVO.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 8. EXTREMO IZQUIERDO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 9. EXTREMO DERECHO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 10. MEDIAPUNTA.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 11. DELANTERO CENTRAL.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t|\n"
			"\t\t\t\t\t\t\t=================================================================\n");
}
/// @brief showNatiolatityMenu	MENU NACIONALIDADES.
///
void showNatiolatityMenu()
{
	printf("\t\t\t\t\t\t\t======================NACIONALIDADES====================="
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 1. SAUDI.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 2. AUSTRALIANO.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 3. SURCOREANO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 4. IRANI.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 5. JAPONES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 6. QATARI.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 7. CAMERUNES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 8. GANHES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 9. MARROQUI.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 10. SENEGALES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 11. TUNECINO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 12. CANADIENCE.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 13. COSTARRICENSE.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 14. ESTADOUNIDENSE.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 15. MEXICANO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 16. ARGENTINO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 17. BRASILENIO.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 18. ECUATORIANO.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 19. URUGUAYO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 20. ALEMAN.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 21. BELGA.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 22. CROATA.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 23. DANES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 24. ESPANIOL.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 25. FRANCES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 26. GALES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 27. NEERLANDES.\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 28. INGLES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 29. POLACO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 30. PORTUGUES.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 31. SERBIO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t 32. SUIZO.\t\t\t\t|"
			"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t|\n"
			"\t\t\t\t\t\t\t=========================================================\n");
}
/// @brief showEditPlayerMenu  MENU EDICION DE JUGADOR.
///
void showEditPlayerMenu()
{

	printf("\t\t\t\t\t\t\t=========================MENU-EDITAR-JUGADOR=============================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. NOMBRE:\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. EDAD:\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. POSICION:\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 4. NACIONALIDAD:\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 5. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
		   "\t\t\t\t\t\t\t=========================================================================\n");

}
/// @brief showListMenuPlayers	MENU LISTAS.
///
void showListMenuPlayers()
{

	printf("\t\t\t\t\t\t\t=============================MENU-LISTAR================================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. TODOS LOS JUGADORES:\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. TODAS LAS SELECCIONES:\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. JUGADORES CONVOCADOS:\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 4. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
					"\t\t\t\t\t\t\t=========================================================================\n");

}
/// @brief showCallPlayersMenu	MENU CONVOCAR JUGADORES.
///
void showCallPlayersMenu()
{

	printf("\t\t\t\t\t\t\t=======================MENU-CONVOCATORIA-JUGADORES======================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. CONVOCAR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. QUITAR DE SELECCION.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
					"\t\t\t\t\t\t\t=========================================================================\n");

}
/// @brief showSortMenu	 MENU ORDENAR Y LISTAR.
///
void showSortMenu()
{

	printf("\t\t\t\t\t\t\t============================MENU-ORDENAR-LISTAR=========================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. JUGADORES.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. SELECCIONES POR CONFEDERACION.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
		   "\t\t\t\t\t\t\t=========================================================================\n");

}
/// @brief showSortPlayerMenu  MENU ORDENAR Y LISTAR JUGADORES.
///
void showSortPlayerMenu()
{

	printf("\t\t\t\t\t\t\t=========================MENU-ORDENAR-LISTAR-JUGADORES==================="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 1. JUGADORES POR NACIONALIDAD.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 2. JUGADORES POR EDAD Y NOMBRE.\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 3. JUGADORES POR NOMBRE.\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t 4. SALIR.\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
		   "\t\t\t\t\t\t\t=========================================================================\n");

}
/// @brief showConfederationMenu  MENU CONFEDERACIONES
///
void showConfederationMenu()
{

	printf("\t\t\t\t\t\t\t==================GENERAR-ARCHIVO-BINARIO-CONFEDERACIONES================"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 1. AFC.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 2. CAF.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 3. CONCACAF.\t\t\t\t|\t\t"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 4. CONMEBOL.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 5. UEFA.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
		   "\t\t\t\t\t\t\t=========================================================================\n");

}
/// @brief showConfederationMenu  MENU CONFEDERACIONES CARGA
///
void showConfederationMenuLoad()
{

	printf("\t\t\t\t\t\t\t===============CARGAR-LISTAR-ARCHIVO-BINARIO-CONFEDERACIONES============="
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 1. AFC.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 2. CAF.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 3. CONCACAF.\t\t\t\t|\t\t"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 4. CONMEBOL.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t 5. UEFA.\t\t\t\t|"
					"\n\t\t\t\t\t\t\t|\t\t\t\t\t\t\t\t\t|\n"
		   "\t\t\t\t\t\t\t=========================================================================\n");

}
