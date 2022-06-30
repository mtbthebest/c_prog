//
// Created by mtb on 6/27/22.
//

#include "stdio.h"
#include "string.h"
#include "stdlib.h"
#include "time.h"

enum  {ARR_SIZE = 1024000000LU};


void fn1(){
    const int size = 100;
    int a[size];

    for(int i=0; i<size; i++){
        a[i] = i;
    }
    for(int i=0; i<size; i++){
        if (i > 0 && i % 10 == 0)
            printf("\n");
        printf(" %2d ", a[i]);
    }
    printf("\n");
    printf("Size of a: %zd \n", sizeof(a));
    printf("Value at invalid position of a: %d \n", a[105]);
}

void fn2(){
    char a[]={'M', 'T', 'W', 'T', 'F', 'S', 'S'};
    printf("Size of a : %zd", sizeof(a));
}

void fn3() {
    int *p = malloc(ARR_SIZE * sizeof(int));
    if(!p){
        fprintf(stderr, "Not enough memory");
    }

    srand((unsigned ) time(NULL));
    for(int i=0; i<ARR_SIZE; i++){
        p[i] = (int)(rand() * 10);
    }

    free(p);
    printf("\n. Memory freed");
}

int main(){

    fn3();

    return 0;
}