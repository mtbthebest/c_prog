//
// Created by mtb on 6/23/22.
//

#include "stdio.h"
#include "stdbool.h"
void fn1(){

    int status;

    printf("Enter q to exit \n");
    int sum = 0;
    int num;
    status = scanf("%d", &num);
    while(status == 1){
        sum += num;
        status = scanf("%d", &num); // 1 on success 0 when not integer
    }

    printf("Total sum: %d\n", sum);
}



void fn2() {
    bool S =  11 == 11;
    printf("%d", S);
}

int *range(int start, int stop, int step) {
    const int SIZE = stop -start;
    int n = 0;
    int x[SIZE];
    while(n++ < SIZE){
        x[n] = 0;
    }
    for(int i=start; i<stop; i += step){
        x[i] = i;
    }
    int *p = x;
    return p;

}

void fn3() {
    int start = 0, stop = 5;
    int *r = range(start, stop, 1);
    int j = -1;
    while(++j < stop - start)
        printf("%d ", r[j]);
    printf("\n");

}

void fn4(){
    int x, y, z;

    x = (y = 4, (z = ++y + 1) + 2);
    printf("x: %d, y: %d, z:%d", x, y, z); // x: 8, y: 5, z:6
    printf("\n");

    x = y = 4, (z = ++y + 1) + 2;
    printf("x: %d, y: %d, z:%d", x, y, z); // x: 4, y: 5, z:6
    printf("\n");

    x = (259, 300);
    printf("x: %d \n", x); //x: 300

    x = 259, 300;
    printf("x: %d \n", x); //x: 259

}

void fn5() {
    int n = 5;

    do {
        printf("n: %d \n", n);
    }while (n-- > 0);
    printf("End n: %d", n);
    int i=0;
    for(; i<5; i++);
    printf("\nAfter end loop i: %d", i);
}

void fn6(){

}

int main(){
    fn6();

    return 0;
}