#include "LinkedList.h"

#ifndef jug_H_INCLUDED
#define jug_H_INCLUDED
#define ERROR -1
#define SUCCESS 1

typedef struct
{
	int id;
	char fullName[100];
	int age;
	char position[30];
	char nationality[30];
	int idNationalTeam;
	int isEmpty;
}sPlayer;

sPlayer* newPlayer();
sPlayer* newPlayerParameters(char *idStr, char *fullNameStr, char *ageStr, char *positionStr, char *nationalityStr, char *idNationalTeamStr);

void deletePlayer(sPlayer *this);

int setIdPlayer(sPlayer *this, int id);
int getIdPlayer(sPlayer *this, int *id);

int setFullNamePlayer(sPlayer *this, char *fullName);
int getFullNamePlayer(sPlayer *this, char *fullName);

int setAgePlayer(sPlayer *this, int age);
int getAgePlayer(sPlayer *this, int *age);

int setPositionPlayer(sPlayer *this, char *position);
int getPositionPlayer(sPlayer *this, char *position);

int setNationalityPlayer(sPlayer *this, char *nationality);
int getNationalityPlayer(sPlayer *this, char *nationality);

int setIdNationalTeamPlayer(sPlayer *this, int idNationalTeam);
int getIdNationalTeamPLayer(sPlayer *this, int *idNationalTeam);

int setIsEmptyPlayer(sPlayer *this, int isEmpty);
int getIsEmptyPlayer(sPlayer *this, int *isEmpty);

#endif // jug_H_INCLUDED
