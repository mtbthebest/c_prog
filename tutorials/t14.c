//
// Created by mtb on 8/8/22.
//
#include "stdio.h"
#include "stdlib.h"

int glob = 0 ; // file scope, external linkage
static  int v = 0 ; //  file scope, internal linkage

void fn() {
    glob++;
}

void fn1(){
    fn();
    fn();
    fn();

    printf(" glob %d ", glob);
}

void fn2() {
    int x = 4;
    int *q =&x;
    while(x++ < 10){
        int x = 0;
        x++;
        printf("x: %d, %p, %d", x, &x, *q); // x: 1, 0x7ffce1b34850

    }
}

void fn3(){
    int i = 4;

    for (int i = 0; i < 3; i++)
        printf("i: %d\n", i);
    printf("After i: %d", i); // Global did not change

}

void fn4(){
    static int n = 1;

    int v = 1;

    printf("n: %d, v: %d \n", n++, v++);

}
void fn5(){
    int i = 0;
    while(i++ < 3)
        fn4();
    extern int glob;
    fn();
    fn();
    fn();

    printf("Glob: %d", glob);

}

void fn6(){
    const int s = 100;
    int *p =malloc(sizeof(int) * s);
    int width=6;
    if(p){
        for(int i=0; i<s; i++){
            *(p+i) = i;
        }

        for(int i=0; i<s; i++){
            if (i % 10 == 0 && i > 0)
                puts("");
            printf("%*d", width ,*(p+i));
        }
        free(p);

    }

}

void fn7(){
    const int s = 100;
    long *p =calloc(s, sizeof(long));
    int width=6;
    if(p){
        for(int i=0; i<s; i++){
            *(p+i) = i;
        }

        for(int i=0; i<s; i++){
            if (i % 10 == 0 && i > 0)
                puts("");
            printf("%*d", width ,*(p+i));
        }
        free(p);

    }

}
int main(int argc, char *argv[]){
    fn7();
    return 0;

}
