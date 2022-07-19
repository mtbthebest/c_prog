//
// Created by mtb on 7/14/22.
//

#include "stdio.h"

void fn1(){
    char ch; long n;
    while( scanf("%ld", &n) == 1 && n > 0){
        printf("Entered integer %ld \n", n);
        while((ch = getchar()) !='\n')
            putchar(ch);
        printf("Put an integer \n");
    }
}

int main(){

    fn1();

    return 0;
}

