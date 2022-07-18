#include<stdio.h>
#include<math.h>
#include<assert.h>
#include<stdlib.h>

int isEmpty(const long *start, const long *end){
    if (start == end || start == NULL || end == NULL){
        return 1;
    }else{
        return 0;
    }
}

void push(long **start, long **end, long value){
    if (isEmpty(*start, *end)) {
        *start = malloc(sizeof(long));
        *end = *start + 1;
        (*start)[0] = value;
    } else {
        /*
        (*end)[0] = value;
        long temp = *end - *start + 1;
        *end = malloc(sizeof(long));
        *end = realloc(*end, sizeof(long) * (temp));
        *end = *start + temp;
        */
        long temp = *end - *start + 1;
        *start = realloc(*start, sizeof(long) * temp);
        (*start)[*end - *start] = value;
        *end = *start + temp;
    }
}

long pop(long **start, long **end){
    if (isEmpty(*start, *end)) {
        //printf("Stack is empty\n");
        return -1;
    } else {
        long temp = *end - *start;
        long value = (*start)[temp - 1];
        *end = *start + temp - 1;
        *start = realloc(*start, sizeof(long) * temp);
        return value;
    }
}

void printStack(long **start, long **end) {
    printf("Stack --> [ ");
    if (!isEmpty(*start, *end)) {
        for (int i = 0; *start + i < *end; i++) {
            printf("%ld ", (*start)[i]);
        }
    } 
    printf("]\n");
}

int main () {
    printf("Starting...\n");
    long *start = NULL;
    long *stop = NULL;
    printStack(&start, &stop);
    push(&start, &stop, 1L);
    printStack(&start, &stop);
    push(&start, &stop, 2L);
    printStack(&start, &stop);
    push(&start, &stop, 3L);
    printStack(&start, &stop);
    push(&start, &stop, 4L);
    printStack(&start, &stop);
    push(&start, &stop, 5L);
    printStack(&start, &stop);
    
    long out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
    out = pop(&start, &stop);
    printf("popped %ld\n", out);
    printStack(&start, &stop);
    
/***Expected Output:****

Starting...
Stack --> [ ]
Stack --> [ 1 ]
Stack --> [ 1 2 ]
Stack --> [ 1 2 3 ]
Stack --> [ 1 2 3 4 ]
Stack --> [ 1 2 3 4 5 ]
popped 5
Stack --> [ 1 2 3 4 ]
popped 4
Stack --> [ 1 2 3 ]
popped 3
Stack --> [ 1 2 ]
popped 2
Stack --> [ 1 ]
popped 1
Stack --> [ ]
popped 0
Stack --> [ ]

**********************/
    
}

