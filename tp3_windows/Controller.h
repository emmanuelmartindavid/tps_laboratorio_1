


int controllerFindPlayerById(LinkedList *pArrayListPlayer, int idPlayer);

int controllerFindNationalTeamById(LinkedList *pArrayListNationalTeam, int idNationalTeam);

int controllerLoadPlayerFromText(char* path , LinkedList* pArrayListPlayer);

int controllerLoadPlayerFromBinary(char *path, LinkedList *pArrayListPlayer);

int controllerAddPlayer(LinkedList *pArrayListPlayer);

int controllerEditPlayer(LinkedList *pArrayListPlayer);

int controllerRemovePlayer(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam);

int controllerListOnePlayer(LinkedList *pArrayListPlayer, int indexPlayer);

int controllerListPlayers(LinkedList *pArrayListPlayer);


int controllerListPlayersNationalTeam(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam, int condition);


int controllerCallUpPlayers(LinkedList *pArrayListPlayer,  LinkedList *pArrayListNationalTeam);

int controllerCallOffPlayers(LinkedList *pArrayListPlayer, LinkedList *pArrayListNationalTeam);


int controllerSortPlayers(LinkedList *pArrayListPlayer);

int controllerSavePlayersTextMode(char *path, LinkedList *pArrayListPlayer);

int controllerSavePlayersBinarytMode(char *path, LinkedList *pArrayListPlayer);

int controllerLoadNationalTeamFromText(char *path, LinkedList *pArrayListNationalTeam);

int controllerEditNationalTeam(LinkedList *pArrayListNationalTeam);

int controllerListNationalTeams(LinkedList *pArrayListNationalTeam);

int controllerSortNationalTeam(LinkedList *pArrayListNationalTeam);

int controllerSaveNationalTeamTextMode(char *path, LinkedList *pArrayListNationalTeam);

int controllerLoadIdplayerTextMode(char *path, int *pIdPlayer);
int controllerGetIncrementalIdPlayer();
int controllerSaveIdplayerTextMode(char *path);

int controllerGetCountry(LinkedList *pArrayListNationalTeam, int idNationalTeamPLayer, char *pCountry);

