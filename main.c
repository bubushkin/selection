/*
 * main.c
 *
 *  Created on: Nov 7, 2018
 *      Author: iskandar
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "udef.h"
#include "random.h"
#include "selection.h"



int main(int argc, char **argv){

	extern int rand_cmpct;
	extern int med3_cmpct;
	extern int med5_cmpct;
	extern int med9_cmpct;

	int *prdata = MALLOC(int, MAXLEN);
	CLEAR(prdata, 0x0, MAXLEN);

	gen_rand_vector(prdata, MAXLEN);

	PRINT_SEQ(prdata, MAXLEN);

	//int kth = selectR(prdata, 0x0, MAXLEN - 1, 5);
	int m5kth = selectM5(prdata, 0x0, MAXLEN - 1, 5);

//	printf("\n %d ", kth);
//	printf("\n %d ", rand_cmpct);
	printf("\n %d ", m5kth);


	return EXIT_SUCCESS;
}



