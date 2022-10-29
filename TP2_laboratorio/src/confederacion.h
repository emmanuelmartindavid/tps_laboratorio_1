/*
 ============================================================================
 Name        : TP2_laboratorio.c
 Author      :   EMMANUEL MARTIN. 1-E
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#ifndef CONFEDERACION_H_
#define CONFEDERACION_H_

typedef struct
{

	int idConfederation;
	char confederationName[50];
	char region[50];
	int creationYear;
	short isEmpty;

} sConfederation;
/// @brief initializeArrayConfederation     Funcion inicializa en 0 el array de confederaciones.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
void initializeArrayConfederation(sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief getFreeIndexArrayConfederation		Funcion obtiene posicion de ARRAY de confederaciones libre a dar de alta.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return									 Retorna la posicion del ARRAY de jugadores libre a dar de alta.
int getFreeIndexArrayConfederation(sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief findByIdArrayConfederation				 Funcion obtiene posicion de ARRAY a traves de ID ingresado por parametro.
///
/// @param arrayConfederation						ARRAY de confederaciones.
/// @param idConfederation							ID ingresado por usuario a ser localizado en su posicion del ARRAY.
/// @param lenArrayConfederation				     Tamanio de ARRAY de confederaciones.
/// @return								 			Retorna la posicion del ARRAY buscado a traves del ID ingresado por usuario.
int findByIdArrayConfederation(sConfederation arrayConfederation[], int idConfederation, int lenArrayConfederation);\
/// @brief loadDataConfederation		Carga datos de confederacion a dar de alta.
///
/// @param pConfederation			Puntero a una confederacion de struct.
/// @param pIdConfederation			Puntero a entero autoincremental a traves de contador.
/// @return							  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int loadDataConfederation(sConfederation *pConfederation, int *pIdConfederation);
/// @brief registerConfederation			Da de alta una confederacion.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param pIdConfederation						Puntero a entero autoincremental a traves de contador.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return								  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int registerConfederation(sConfederation arrayConfederation[], int *pIdConfederation, int lenArrayConfederation);
/// @brief downConfederation					Da de baja confederacion.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return								 Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int downConfederation(sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief modifyOneConfederation			Modifica un jugador.
///
/// @param pConfederation				Puntero a una confederacion de struct.
/// @return						  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyOneConfederation(sConfederation *pConfederation);
/// @brief modifyConfederations					 Funcion para dar de modificar confederaciones dado de alta, atraves de ID.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @return							  Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int modifyConfederations(sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief listOneConfederation				Lista una confedracion.
///
/// @param OneConfederation			 Una confederacion de estructura sConfederation, dado de alta.
void listOneConfederation(sConfederation OneConfederation);
/// @brief listConfederation			Lista confederaciones
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
void listConfederation(sConfederation arrayConfederation[], int lenArrayConfederation);
/// @brief getConfederationDescription  Funcion para obtener la descripcion de tipo de vehiculo, segun ID tipo elegido por usuario.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @param idConfederation			   ID de confederacion elegido por usuario a comparar.
/// @param pCofederationDescription		   Puntero a cadena de texto, con nombre de confederacion.
/// @return					   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int getConfederationDescription(sConfederation arrayConfederation[], int lenArrayConfederation, int idConfederation, char *pCofederationDescription);
/// @brief hardCodeConfederations			 Funcion para harcodear confederaciones.
///
/// @param arrayConfederation			         ARRAY de confederaciones.
/// @param lenArrayConfederation				         Tamanio de ARRAY de confederaciones.
/// @param ammount								Entero, cantidad.
/// @param pNextId					 Puntero a entero autoincremental a traves de contador.
/// @return							   Retorno, OK(1) en caso de haber funcionado correctamente. Retorno, ERROR(-1) en caso contrario.
int hardCodeConfederations(sConfederation arrayConfederation[], int lenArrayConfederation, int ammount, int *pNextId);

#endif /* CONFEDERACION_H_ */
