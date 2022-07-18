#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <math.h>
#include <stdbool.h>


//removes all duplicates from an array
void removeDups(int* in, int size) {
    int i;
    int j;
    int loop_count;
    for (i = 0; i < size; i++) {
        for (j = i + 1,loop_count = 1; j < size; j++) {
            if (in[i] == in[j]) {
                int k;
                for (k = j; k < size - 1; k++) {
                    in[k] = in[k + 1];
                }
                in[size - 1] = '\0';
                j--;
            }    
            loop_count++;
            if(loop_count > size ) {
                break;
            }
        }
    }
}
