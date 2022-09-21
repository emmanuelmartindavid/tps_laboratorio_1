#ifndef UTN_VALIDACIONES_H_
#define UTN_VALIDACIONES_H_

int getString(char *string, int len);
int getInt(int *pResult);
int isNumeric(char *string);
int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus, int retry);
int getFloat(float *pResult);
int isFloat(char *string);
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus, int retry);

#endif /* UTN_VALIDACIONES_H_ */
