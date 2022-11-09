
#ifndef PARSER_H_
#define PARSER_H_



int parserPlayerFromText(FILE *pFile, LinkedList *pArrayListPlayer);
int parserPlayerFromBinary(FILE* pFile , LinkedList* pArrayListPlayer);
int parserNationalTeamFromText(FILE *pFile, LinkedList *pArrayListNationalTeam);


int parserIdPlayerFromText(FILE *pFile, int *pIdPlayer);


#endif /* PARSER_H_ */
