#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char country[30];
	char confederation[30];
	int calledUp;
	int isEmpty;
}sNationalTeam;

sNationalTeam* newNationalTeam();
sNationalTeam* sNationalTeamParameters(char* idStr,char* countryStr,char* confederationStr, char* calledUpStr);
void deleteNatioanalTeam(sNationalTeam* this);

int getIdNationalTeam(sNationalTeam* this,int* id);
int getCountryNationalTeam(sNationalTeam* this,char* country);
int getConfederationNationalTeam(sNationalTeam* this,int* confederation);
int getIsEmptyNationalTeam(sNationalTeam* this,int* isEmpty);

int setcalledUpNationalTeam(sNationalTeam* this,int calledUp);
int getcalledUpNationalTeam(sNationalTeam* this,int* calledUp);



#endif // selec_H_INCLUDED
