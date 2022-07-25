//Functions
// Created by mtb on 7/14/22.
//

#include "stdio.h"

int factorial(int n){
    return n <= 1 ? 1 : n * factorial(n - 1);
}

void fn1(){
    int v = factorial(1);
    printf("Factorial of 5 = %d", v);
}

void swap(int *p, int *q){
    int temp = *p;
    *p = *q;
    *q = temp;

}

void fn2(){
    int x = 1, y=2;
    printf("before x: %d, y: %d \n", x, y);
    swap(&x, &y);
    printf("after x: %d, y: %d \n", x, y);

}

typedef void(*map_fn)(const void *p);

void map(map_fn fn, void *arr, size_t arr_size, size_t type_size){
    void *p= NULL;
    for(int i=0; i<arr_size; i++){
        p = arr + i * type_size;
        fn(p);
    }
}

void square(const void *p){
    int temp = *((int *) p);
    printf(": %d :  ", *((int *) p) );
    *(int *)p = temp * temp;
}

void fn3(int size){
    int arr[size];
    for(int i=0; i<size; i++){
        arr[i] = i;
    }

    map(square, arr, size, sizeof(int));
    printf("Squared array: ");
    for(int j=0; j<size; j++)
        printf("%d ", arr[j]);

}

void fn4(){
    int x=5, y=4;

    printf("Address x: %p, Value of x:  %d \n", &x, x);
    printf("Address y: %p, Value of y:  %d \n", &y, y);

}

int main(){

    fn4();

    return 0;
}

