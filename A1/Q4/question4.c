#include <stdio.h>
#include <assert.h>
#include <math.h>


int bubblesort(int* x, int size) {
    int i;
    int j;
    int temp;
    int loop_count;
    int num_swaps = 0;
    for (i = 0; i < size; i++) {
        for (j = 0; j < size - 1; j++) {
            if (x[j] > x[j + 1]) {
                temp = x[j];
                x[j] = x[j + 1];
                x[j + 1] = temp;
                num_swaps+=1;
            }
        }
        loop_count++;
        if(loop_count > size ) {
            break;
        }
    }
    return num_swaps;
}
