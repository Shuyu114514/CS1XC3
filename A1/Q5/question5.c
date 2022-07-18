#include <stdio.h>
#include <assert.h>
#include <math.h>


int insertionsort(int* x, int size) {
    int i, j, temp;
    int num_swaps = 0;
    for (i = 1; i < size; i++)
    {
        if (x[i - 1] > x[i])
        {
            temp = x[i];
            num_swaps+=1;         
            for ( j = i - 1; x[j] > temp && j >= 0; j--)
            {
                x[j + 1] = x[j];
                num_swaps+=1;
            }
            x[j + 1] = temp;  
        } 
    }
    return num_swaps;
}
