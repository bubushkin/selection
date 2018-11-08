/*
 * udef.h
 *
 *  Created on: Oct 15, 2018
 *      Author: iskandar
 */

#ifndef UDEF_H_
#define UDEF_H_

#include <stdlib.h>
#include <string.h>

//#ifndef DEBUG
//#define DEBUG
//#endif

#define MAX_VAL 99
#define MAXLEN 10

#define PRINT_ERR(M, ...) fprintf(stderr, "[ERROR] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define MALLOC(X, S) (X*)malloc(sizeof(X)*S);

#define CLEAR(X, T, N) memset(X, 0x0, sizeof(T)*N);


#define EXIT_ERR exit(-1);

#define PRINT_SEQ(X, L) for(int i = 0x0; i < L; i++)    \
						printf("%d: %d \n", i, X[i]); 			\
					printf("\n");						\

#define STDOUT stdout

#define PRINT_INFO(M, ...) fprintf(stdout, "[INFO] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#define PRINT_WARN(M, ...) fprintf(stderr, "[WARN] (%s:%d) " M "\n", __FILE__, __LINE__, ##__VA_ARGS__)

#endif /* UDEF_H_ */
