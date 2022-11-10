#include "LinkedList.h"

#ifndef selec_H_INCLUDED
#define selec_H_INCLUDED

typedef struct
{
	int id;
	char country[30];
	char confederation[30];
	int calledUp;

}sNationalTeam;

sNationalTeam* newNationalTeam();
sNationalTeam* newNationalTeamParameters(char *idStr, char *countryStr, char *confederationStr, char *calledUpStr);
void deleteNatioanalTeam(sNationalTeam* this);

int getIdNationalTeam(sNationalTeam* this,int* id);
int getCountryNationalTeam(sNationalTeam* this,char* country);
int getConfederationNationalTeam(sNationalTeam* this,char* confederation);

int setCalledUpNationalTeam(sNationalTeam* this,int calledUp);
int getCalledUpNationalTeam(sNationalTeam* this,int* calledUp);

int compareNationalTeamByConfederation(void *nationaTeamOne, void *nationalTeamTwo);

int listOneNationalTeam(sNationalTeam *this);
void showNationalTeamData();
void showLineNT();



#endif // selec_H_INCLUDED
