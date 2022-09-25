#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_


/// @brief get String      Funcion para pedir dato por consola, a traves de cadena de caracteres.
///
/// @param pString          Puntero de cadena de caracteres.
/// @param len	           Limite de cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getString(char *pString, int len);
/// @brief  getInt         Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero entero.
///
/// @param pResult         Puntero numero entero de la conversion realizada con ATOI.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getInt(int *pResult);
/// @brief isNumeric       Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero entero.
///
/// @param pString          Puntero de cadena de caracteres a verificar en funcion.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isNumeric(char *pString);
/// @brief utn_getNumber   Función para pedir un número entero por consola.
///
/// @param pResult         Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message		   Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage    Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus		   Valor mínimo valido.
/// @param maximus         Valor máximo valido.
/// @param retry           Cantidad de intentos, en caso de ingresar un dato invalido.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus, int retry);
/// @brief getFloat		   Funcion verifica la cadena de caracteres ingresada, convirtiendola, si es valida, a numero flotante.
///
/// @param pResult         Puntero numero entero de la conversion realizada con ATOF.
/// @return				   Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int getFloat(float *pResult);
/// @brief isFloat         Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero flotante.
///
/// @param pString          Puntero a cadena de caracteres.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int isFloat(char *pString);
/// @brief utn_getNumber   Float Función para pedir un número flotante  por consola
///
/// @param pResult         Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message         Puntero a cadena de caracteres con mensaje a imprimir para pedirle al usuario ingresar un numero.
/// @param errorMessage    Puntero a cadena de caracteres con mensaje de error mientras el dato no sea un numero.
/// @param minimus 	       Valor mínimo valido.
/// @param maximus         Valor máximo valido.
/// @param retry           Cantidad de intentos, en caso de ingresar un dato invalido.
/// @return                Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus, int retry);



#endif /* UTN_VALIDACIONES_H_ */
