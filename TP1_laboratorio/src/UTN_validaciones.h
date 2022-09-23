#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

/// @brief
///
/// @param string
/// @param len
/// @return
int getString(char *string, int len);
/// @brief
///
/// @param pResult
/// @return
int getInt(int *pResult);
/// @brief
///
/// @param string
/// @return
int isNumeric(char *string);
/// @brief
///
/// @param pResult
/// @param message
/// @param errorMessage
/// @param minimus
/// @param maximus
/// @param retry
/// @return
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus, int retry);
/// @brief
///
/// @param pResult
/// @return
int getFloat(float *pResult);
/// @brief Funcion valida si la cadena de caracteres esta dentro de los parametros esperados de un numero flotante
///
/// @param string   Puntero a cadena de caracteres
/// @return
int isFloat(char *string);
/// @brief Función para pedir un número flotante  por consola
///
/// @param pResult       Puntero a direccion de la variable ingresada en el caso de ser correcta.
/// @param message       Puntero a cadena de caracteres con mensaje a imprimir antes de pedirle al usuario el dato.
/// @param errorMessage  Puntero a cadena de caracteres con mensaje de error en el caso de que el dato ingresado no sea válido.
/// @param minimus 	     Valor mínimo a ingresar valido
/// @param maximus       Valor máximo a ingresar valido
/// @param retry         Cantidad de veces que se le volverá a pedir al usuario que ingrese el dato, en caso de ingresar un dato invalido.
/// @return ret          Retorno, 0 en caso de haber funcionado correctamente. Retorno, -1 en caso contrario.
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus, int retry);

#endif /* UTN_VALIDACIONES_H_ */
