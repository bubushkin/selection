/*
 * random.c
 *
 *  Created on: Nov 7, 2018
 *      Author: iskandar
 */

#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "udef.h"

#include "random.h"
#include "selection.h"

void shuffle(int *pa, int alen){

	for(int idx = 0x0; idx < alen; idx++){
		int rand = irandom();
		swap(&pa[idx], &pa[rand]);
	}
}

int irandom(){

	int rand = -1;

	FILE *fp=fopen("/dev/urandom","r");

	if (fp == NULL){
		PRINT_ERR("urandom opening failed");
		EXIT_ERR;
	}

	int i = fgetc(fp);
	rand = i % MAXLEN;
	fclose(fp);

	return rand;
}

void gen_rand_vector(int *pa, int alen){

	FILE *fp=fopen("/dev/urandom","r");

	if (fp == NULL){
		PRINT_ERR("urandom opening failed");
		EXIT_ERR;
	}

	for(int idx = 0; idx < alen; idx++){
		int i = fgetc(fp);
		pa[idx] = i % MAX_VAL;
	}
	fclose(fp);
}
