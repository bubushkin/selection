/*
 * selection.c
 *
 *  Created on: Nov 7, 2018
 *      Author: iskandar
 */

#include "selection.h"
#include "udef.h"

int rand_cmpct = 0;
int med3_cmpct = 0;
int med5_cmpct = 0;
int med9_cmpct = 0;

int get_median(int *pa, int an){
    insertion_sort(pa, an);
    return pa[an/2];
}

int partitionM(int *pa, int aleft, int aright, int x){

	// Search for x in arr[l..r] and move it to end
	int i;
    for (i = aleft; i < aright; i++){
        if (pa[i] == x)
           break;
    }
    swap(&pa[i], &pa[aright]);

    // Standard partition algorithm
    i = aleft;
    for (int j = aleft; j <= aright - 1; j++){
        if (pa[j] <= x)
        {
            swap(&pa[i], &pa[j]);
            i++;
        }
    }
    swap(&pa[i], &pa[aright]);
    return i;
}

int selectM5(int *pa, int aleft, int aright, int k){
    // If k is smaller than number of elements in array
	int palen = aright - aleft + 1;

    if (k > 0 && k <= palen){

    	int n = palen; // Number of elements in arr[l..r]

        // Divide arr[] in groups of size 5, calculate median
        // of every group and store it in median[] array.
        int i;
        int median[(n+4) / 5]; // There will be floor((n+4)/5) groups;
        for (i = 0; i < n/5; i++){
            median[i] = get_median(pa + aleft + i*5, 5);
        }
        if (i*5 < n) { //For last group with less than 5 elements
        	median[i] = get_median(pa + aleft + i*5, n % 5);
            i++;
        }

        // Find median of all medians using recursive call.
        // If median[] has only one element, then no need
        // of recursive call
        int medOfMed;

        if(i == 1){
        	medOfMed = median[i-1];
        } else {
        	medOfMed = selectM5(median, 0, i-1, i/2);
        }

        // Partition the array around a random element and
        // get position of pivot element in sorted array
        int pos = partitionM(pa, aleft, aright, medOfMed);

        // If position is same as k
        if (pos- aleft == k-1){
            return pa[pos];
		}
        if (pos- aleft > k-1){  // If position is more, recur for left
            return selectM5(pa, aleft, pos-1, k);
        }

        // Else recur for right subarray
        return selectM5(pa, pos+1, aright, k-pos+ aleft - 1);
    }

    // If k is more than number of elements in array
    return -1;
}


void insertion_sort(int *pa, int an){

	int i, key, j;
	for (i = 1; i < an; i++){
		key = pa[i];
		j = i-1;

		while (j >= 0 && pa[j] > key){
			pa[j+1] = pa[j];
			j = j-1;
		}
		pa[j+1] = key;
	}
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int pa[], int aleft, int aright){
    int x = pa[aright];
    int i = aleft;

    for (int j = aleft; j <= aright - 1; j++){
        if (pa[j] <= x){
            swap(&pa[i], &pa[j]);
            i++;
            rand_cmpct++;
        }
    }
    swap(&pa[i], &pa[aright]);
    return i;
}

int rand_partition(int *pa, int aleft, int aright){

    int pivot = rand() % MAXLEN;
    swap(&pa[aleft + pivot], &pa[aright]);
    return partition(pa, aleft, aright);
}


int selectR(int *pa, int aleft, int aright, int kth){

	if (kth > 0 && kth <= aright - aleft + 1){
        int pos = rand_partition(pa, aleft, aright);
        if (pos-aleft == kth-1){
            return pa[pos];
        }
        if (pos-aleft > kth-1){
            return selectR(pa, aleft, pos-1, kth);
        }

        return selectR(pa, pos+1, aright, kth-pos+aleft-1);
    }
    return -1;
}
