//
// Created by mtb on 7/7/22.
//
#include "stdio.h"
#include "stdlib.h"
void fn1(){
    FILE *fp;
    printf("Reading from file \n");

    fp = fopen("/home/mtb/Projects/c_prog/tutorials/test.txt", "r");
    if(fp == 0){
        printf("File not available ");
        exit(1);
    }
    int ch;
    while ((ch=getc(fp)) != EOF )
        putchar(ch);

    fclose(fp);
}

void fn2(){
    int ch;
    int row, col;
    while ((ch = getchar()) != '\n')
    {
        scanf("%d %d", &row, &col);
        for(int i=0; i<row; i++) {
            for(int j=0; j<col; j++){
                printf("%c ", ch);
            }
            printf("\n");
        }

        while (getchar() != '\n')
            continue;

    }

}

int main() {
    fn2();

    return 0;
}
