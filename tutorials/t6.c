//
// Created by mtb on 6/29/22.
//

#include "stdio.h"
#include "ctype.h"
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

int main(){
    fn2();
}