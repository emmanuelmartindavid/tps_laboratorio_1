
#ifndef PARSER_H_
#define PARSER_H_
/// @brief parserPlayerFromText	PARSEA DATOS DE JUGADORES DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param pFile				PUNTERO A FILE.
/// @param pArrayListPlayer		LINKEDLIST JUGADORES.
/// @return						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserPlayerFromText(FILE *pFile, LinkedList *pArrayListPlayer);
/// @brief parserPlayerFromBinary PARSEA DATOS DE JUGADORES DESDE ARCHIVO CSV EN BINARIO.
///
/// @param pFile				PUNTERO A FILE.
/// @param pArrayListPlayer		LINKEDLIST JUGADORES.
/// @return						RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserPlayerFromBinary(FILE* pFile , LinkedList* pArrayListPlayer);
/// @brief parserNationalTeamFromText 	PARSEA DATOS DE SELECCIONES DESDE ARCHIVO CSV EN BINARIO.
///
/// @param pFile						PUNTERO A FILE.
/// @param pArrayListNationalTeam		LINKEDLIST SELECCIONES.
/// @return								RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserNationalTeamFromText(FILE *pFile, LinkedList *pArrayListNationalTeam);
/// @brief parserIdPlayerFromText 	PARSEA DATO DE ID JUGADORES A DAR DE ALTA DESDE ARCHIVO CSV EN MODO TEXTO.
///
/// @param pFile					PUNTERO A FILE.
/// @param pIdPlayer				PUNTERO ENTERO.
/// @return							RETORNO SUCCESS(1) EN CASO CORRECTO. ERROR(-1) EN CASO CONTRARIO.
int parserIdPlayerFromText(FILE *pFile, int *pIdPlayer);


#endif /* PARSER_H_ */
