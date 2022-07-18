#include <stdio.h> 
#include <stdlib.h> 
#include <assert.h> 
#include <math.h> 
/*
int compare(const void* a, const void* b) {
    return *(int*)a - *(int*)b;
}
*/
double mean(int* x, int size) {
    double sum = 0;
    int i;
    for (i = 0; i < size; i++) {
        sum += x[i];
    }
    return sum / size;
}
double median(int* x, int size){
    int* y = (int*)malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        y[i] = x[i];
    }
    //qsort(y, size, sizeof(int), compare);
    if (size % 2 == 0) {
        return (y[size / 2] + y[size / 2 - 1]) / 2;
    } else {
        return y[size / 2];
    }
}; 
int mode(int* x, int size){
    int* y = (int*)malloc(sizeof(int) * size);
    int i;
    for (i = 0; i < size; i++) {
        y[i] = x[i];
    }
    //qsort(y, size, sizeof(int), compare);
    int max = 0;
    int count = 0;
    for (i = 0; i < size; i++) {
        if (y[i] == y[i + 1]) {
            count++;
        } else {
            if (count > max) {
                max = count;
            }
            count = 0;
        }
    }
    return y[max];
};
