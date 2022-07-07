//
// Created by mtb on 6/29/22.
//

#include "stdio.h"
#include "ctype.h"
#include "stdlib.h"
#include "iso646.h"


#define SPACE ' '

void fn1(){
    char ch;
    while((ch = getchar()) != '\n'){
        if(ch == SPACE)
            putchar(ch);
        else
            putchar(ch +  1);
    }
}

void fn2(){
    char *s = "Po124()#e";
    while(*s){
//        if(isalnum(*s)){
        if(isdigit(*s)){
            putchar(tolower(*s)); // po124e
        }
        s++;
    }
    printf("\n");

}

typedef int (*cmp)(void*, void*) ;
void sort(void *array, long size, size_t el_size, cmp fn){
    void *a, *b;
    int result;
    int tmp;
    for(int j=0; j < size; j++){
        for(int k=j+1; k<size;k++){
            a = array + j * el_size;
            b = array + k * el_size;
            result = fn(a, b);
            if(result == -1)
            {
                tmp = *(int *)b;
                *(int *)b= *(int *)a;
                *(int *)a= tmp;
            }

        }
    }
}

int cmp_fn(void *a, void *b){
    int c = *((int *)a);
    int d = *((int *)b);
    return d > c ? 1 : (d < c ? -1: 0 );

}

void fn3(){
    const int ARR_SIZE = 50;
    int *array = malloc(ARR_SIZE * sizeof(int));
    if(array != NULL){
        for(int i=0;i<ARR_SIZE; i++){
            array[i] =  (lrand48()  * 10) / RAND_MAX;
        }
        sort(array, ARR_SIZE, sizeof(int), cmp_fn);
        for(int i=0; i < ARR_SIZE; i++){
            printf("%d \n", array[i]);
        }
    }

    free(array);
}

void fn4(){

    char ch;

    while((ch = getchar()) != 'q'){
        if(ch == '\n' or ch=='d')
            continue;

        printf("ch: %c \n", ch);
    }
}

int main(){
    fn4();
}
