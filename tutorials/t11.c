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

void fn2(){

}

void fn3(){

}

void fn4(){

}

int main(){

    fn1();

    return 0;
}

