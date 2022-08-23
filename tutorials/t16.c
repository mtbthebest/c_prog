//
// Created by mtb on 8/15/22.
//

#include "stdio.h"
#include "stdlib.h"

#define DIM 1

struct Vector {
    int size;
    int *el;
    int dim[DIM];
};

void setitem(struct Vector v, int key, int value){
    if(key >= v.size){
        printf("Out of range");
        return;
    }
    *(v.el + key) = value;
}
void initialize(struct Vector v, int default_val){
    for(int i=0; i<v.size; i++){
        setitem(v, i, default_val);
    }
}

void display(struct Vector v){
    for(int i=0; i<v.size; i++){
        printf("%d ", *(v.el + i));
    }
    printf("\n");
}

void destroy(struct Vector v){
    free(v.el);
}

void fn1(){
    size_t size = 10;
    int *p = malloc(sizeof(int) * size);
    struct Vector v = {size, p, {size} };
    initialize(v, 2);
    display(v);

    destroy(v);
    printf("%d ", p[0]);
}



int main(){

    fn1();

    return 0;
}