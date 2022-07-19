
// Input Output

#include "stdio.h"

void fn1(){
    char ch;
    unsigned int count = 0;
    while ((ch = getchar()) != '\n')
    {
        putchar(ch);
        if (ch == 'a')
            count++;
        printf("Getting character: \n");
    }

    printf("\n Last Character: ** %c ** . Count : %d \n", ch, count);
}
void fn2(){
    char ch;
    unsigned int count = 0;
    while ((ch = getchar()) != EOF)
    {
        if (ch == '\n'){
            printf("\n Getting character: \n");
            continue;
        }

        putchar(ch);
        if (ch == 'a')
            count++;
    }

    printf("\n Last Character: ** %c ** . Count : %d \n", ch, count);
}

int main(){

    fn2();

    return 0;
}//
// Created by mtb on 7/7/22.
//

