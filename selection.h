/*
 * selection.h
 *
 *  Created on: Nov 7, 2018
 *      Author: iskandar
 */

#ifndef SELECTION_H_
#define SELECTION_H_

int selectR(int *, int, int, int);

int rand_partition(int *, int, int);

int partitionM(int *pa, int aleft, int aright, int x);

int partition(int *, int, int);

int selectM3(int *, int, int);

int selectM5(int *pa, int aleft, int aright, int k);

int selectM9(int *, int, int);

void swap(int *a, int *b);

void insertion_sort(int *, int);

#endif /* SELECTION_H_ */
