#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_validaciones.h"
#define LEN 1000000
/// @brief
///
/// @param string
/// @param len
/// @return
int getString(char *string, int len) {
	int ret = -1;
	char bufferString[LEN];

	if (string != NULL && string > 0) {
		fflush(stdin);
		if (fgets(bufferString, sizeof(bufferString), stdin) != NULL) {
			if (bufferString[strnlen(bufferString, sizeof(bufferString)) - 1]
					== '\n') {
				bufferString[strnlen(bufferString, sizeof(bufferString)) - 1] =
						'\0';
			}
			if (strnlen(bufferString, sizeof(bufferString)) <= len) {
				strncpy(string, bufferString, len);
				ret = 0;
			}
		}
	}
	return ret;
}
/// @brief
///
/// @param pResult
/// @return
int getInt(int *pResult) {
	int ret = -1;
	char option[LEN];
	if (pResult != NULL) {
		if (getString(option, sizeof(option)) == 0 && isNumeric(option) == 0) {
			*pResult = atoi(option);
			ret = 0;
		}

	}
	return ret;
}
/// @brief
///
/// @param string
/// @return
int isNumeric(char *string) {
	int i = 0;
	int ret = 0;
	if (string != NULL && strlen(string) > 0) {
		while (string[i] != '\0') {
			if (string[i] < '0' || string[i] > '9') {
				ret = -1;
				break;
			}
			i++;
		}
	}
	return ret;
}
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
		int maximus, int retry) {
	int ret;
	int num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL) {
		while (retry > 0) {
			printf(message);
			if (getInt(&num) == 0) {
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0) {
			ret = -1;
		} else {
			ret = 0;
			*pResult = num;
		}
	}
	return ret;

}
/// @brief
///
/// @param pResult
/// @return
int getFloat(float *pResult) {
	int ret = -1;
	char option[LEN];
	if (pResult != NULL) {
		if (getString(option, sizeof(option)) == 0 && isFloat(option)==0) {
			*pResult = atof(option);
			ret = 0;
		}
	}
	return ret;
}
/// @brief
///
/// @param string
/// @return
int isFloat(char *string) {
	int i = 0;
	int ret = 0;
	int pointCounter = 0;

	if (string != NULL && strlen(string) > 0) {
		for (i = 0; string[i] != '\0'; i++) {
			if (string[i] < '0' || string[i] > '9') {
				if (string[i] == '.' && pointCounter == 0) {
					pointCounter++;
				} else {
					ret = -1;
					break;
				}
			}
		}
	}
	return ret;
}
/// @brief
///
/// @param pResult
/// @param message
/// @param errorMessage
/// @param minimus
/// @param maximus
/// @param retry
/// @return
int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus, int retry) {
	int ret;
	float num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL) {
		while (retry > 0) {
			printf(message);
			if (getFloat(&num) == 0) {
				if (num <= maximus && num >= minimus)
					break;
			}
			fflush(stdin);
			retry--;
			printf(errorMessage);
		}
		if (retry == 0) {
			ret = -1;
		} else {
			ret = 0;
			*pResult = num;
		}
	}
	return ret;
}

