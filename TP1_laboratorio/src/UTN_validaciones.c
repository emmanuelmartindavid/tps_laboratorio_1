#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "UTN_validaciones.h"
#define LEN 1000000

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

int getInt(int *pResult) {
	int ret = 0;
	char option[LEN];
	if (pResult != NULL) {
		if (getString(option, sizeof(option)) == 0 && isNumeric(option) == 1) {
			*pResult = atoi(option);
			ret = 1;
		}

	}
	return ret;
}

int isNumeric(char *string) {
	int i = 0;
	int ret = 1;
	if (string != NULL && strlen(string) > 0) {
		while (string[i] != '\0') {
			if (string[i] < '0' || string[i] > '9') {
				ret = 0;
				break;
			}
			i++;
		}
	}
	return ret;
}

int utn_getNumber(int *pResult, char *message, char *errorMessage, int minimus,
		int maximus, int retry) {
	int ret;
	int num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL) {
		while (retry > 0) {
			printf(message);
			if (getInt(&num) == 1) {
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

int getFloat(float *pResult) {
	int ret = -1;
	char option[LEN];
	if (pResult != NULL) {
		if (getString(option, sizeof(option)) == 0 && isFloat(option)) {
			*pResult = atof(option);
			ret = 1;
		}
	}
	return ret;
}

int isFloat(char *string) {
	int i = 0;
	int ret = -1;
	int pointCounter = 0;

	if (string != NULL && strlen(string) > 0) {
		for (i = 0; string[i] != '\0'; i++) {
			if (string[i] < '0' || string[i] > '9') {
				if (string[i] == '.' && pointCounter == 0) {
					pointCounter++;
				} else {
					ret = 0;
					break;
				}
			}
		}
	}
	return ret;
}

int utn_getNumberFloat(float *pResult, char *message, char *errorMessage,
		float minimus, float maximus, int retry) {
	int ret;
	float num = 0;
	if (pResult != NULL && message != NULL && errorMessage != NULL) {
		while (retry > 0) {
			printf(message);
			if (getFloat(&num) == 1) {
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

