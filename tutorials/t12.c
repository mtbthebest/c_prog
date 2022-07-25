//
// Created by mtb on 7/20/22.
//

#include "stdio.h"
#include "ctype.h"
#include "string.h"
#include "stdlib.h"
#define SIZE 10
#define SIZE1 5
#define PI 3.14

void fn1(){
    const int size = 10L;
//    int x[10] ={1,2}; // ok
//    int x[size] ={1,2}; // error: variable-sized object may not be initialized
    int x[SIZE] ={1,2}; // ok
//     int y[] = {1,2}; // ok

    for(int i=0; i<size; i++){
        printf("%d ", x[i]);
    }
    printf("\n");
}

void fn2(){
    const int y[SIZE]= {1,2,3,4,5,6,7,8,9,10};

//    y[0] = 10; // error: assignment of read-only location ‘y[0]’
}

void fn3(){
    int z[10] = {0, [8] = 8, [4] =4, 5, 6, [0]=-1};
    printf("z[8] = %d, ", z[8]);
    printf("z[0] = %d, ", z[0]);
    printf("z[4] = %d, ", z[4]);
    printf("z[5] = %d, ", z[5]);
    printf("z[7] = %d", z[7]);
}

void fn4(){
    char s[10] ={[2] = 'A'};
    printf("s[8] = %d, ", s[8]);
    printf("s[2] = %c, ", s[2]);
}

void fn5(){

    int x[3][3] = {
            {1,2,3},
            {3,4,5},
            {6,7,8},
    };

    int y[3][3] ={
            {1,2,3},
            {4},
            {5, 6, 7}
    };
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", *(y[0] + 3*i + j));
        }
        printf("\n");
        //1 2 3
        //4 0 0
        //5 6 7
    }

    printf("\n");
    int z[3][3] ={
            1,2,3, 4
    };
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            printf("%d ", *(z[0] + 3*i + j));
        }
        printf("\n");
       //1 2 3
        //4 0 0
        //0 0 0
    }
    printf("\n");
    printf("Pointer diff %ld \n", z[1] - z[0]);

    int a , b = 0;

    int *p=&a, *q=&b;

    printf("%p, %p, %ld \n", p, q, q - p); // 0x7ffc06633bc8, 0x7ffc06633bcc, 1  Number of elements

    double *pp = (double *)p;
    double *qq = (double *)q;
    printf("%p, %p, %ld \n", pp, qq, qq - pp); // 0 content

}

int sum(int ar[], int);

void fn6(){
    int x[] = {1,2,3};
    int y = sum(x, 3);
    printf("%d ", y);
}

double square(const double x){
    return x * x;
}

float cubic(float x){
    return x*x*x;
}

const double get_pi(){
    return PI;
}

void fn7(){
    const double s = square(4);
    printf("Value of s: %04.1lf\n", s);
    double u = 2.0;
    printf("Value of s: %05.2f\n", square(u));
    const float v = 3.0f;
    printf("Value of s: %.2f\n", cubic(v));

    const float w = cubic((const float)5.0f);
    printf("Value of s: %.2f\n", w);

}

void fn77(){
    double pi = get_pi();
    pi = 7.0;
    printf("PI: %f", pi);

}

const void *map(const void *arr, void *res_arr, size_t arr_size, size_t it_size,
        void(*fn)(const void *, void *)){
    for(int j=0; j<arr_size; j+= it_size){
        fn(arr, res_arr);
        res_arr += it_size;
        arr += it_size;
    }

    return res_arr;


}

void get_square(void *arr, void *res_arr){
    int a = *(int *)arr;
    *(int *)res_arr = a * a;
}

void fn8(){
    int arr[SIZE1] = {1, 2, 3, 4, 5};
    int * square_arr = malloc(SIZE1 * sizeof(int));
    map(arr, square_arr, SIZE1 * sizeof(int), sizeof(int), get_square);

    for(int i=0; i<SIZE1; i++){
        printf("%d ", square_arr[i]);
    }
    printf("\n");
    free(square_arr);

}


void fn9(){
    int arr[SIZE1] = {1, 2, 3, 4, 5};
    int *p = arr;
    *p = 10;
    printf("a[0]: %d \n", p[0]);
    printf("a[0]: %d \n", arr[0]);

    const int *q = arr;

    printf("q[1] = %d \n", *(q + 1));

//    *q = 4;// Error
    const int barr[] = {1,2,3,4,5};

    q = barr;

    q++;

    printf("q[1] = %d \n", *(q + 3));

//    p = barr; Error

    int *const r = p;
//    r += 1; // Error constant pointer
//    r = q; // Error
    *(r + 4) = 5; // Allowed


}

void fn10() {
    int arr[] = {1,2,3,4, 5};
    int *p = arr;

    // &arr = 0x7ffc9158c340, &p = 0x7ffc9158c338
    printf("&arr = %p, &p = %p \n", &arr, &p);

    //arr = 0x7ffc9158c340, p = 0x7ffc9158c340, &arr[0]= 0x7ffc9158c340
    printf("arr = %p, p = %p, &arr[0]= %p", arr, p, &arr[0]);
}
void fn11(){

    int arr[3][2] ={
            {1,2},
            {3,4},
            {5,6}
    };

    int *p = arr[0];
//    p = *arr; // p = arr[0]
//    p = *(arr + 2); // p = arr[2]


//    &arr = 0x7ffc785aa2f0, &p = 0x7ffc785aa2e8,
//    arr = 0x7ffc785aa2f0, p = 0x7ffc785aa2f0, &arr[0] = 0x7ffc785aa2f0
//     *arr = 0x7ffc785aa2f0, *arr[0] = 1, **arr = 1
//    arr[0] = 0x7ffc785aa2f0, arr[1] = 0x7ffc785aa2f8, arr[2] = 0x7ffc785aa300
//    arr[0] = 0x7ffc785aa2f0, arr[1] = 0x7ffc785aa2f8, arr[2] = 0x7ffc785aa300
//     *arr[0] = 1, *arr[1] = 3, *arr[2] = 5
//    arr[0][0] = 0x7ffc785aa2f0, arr[0][1] = 0x7ffc785aa2f4, arr[1][0] = 0x7ffc785aa2f8
//                                                                        *arr = 0x7ffc785aa2f0, *arr + 1 = 0x7ffc785aa2f4, *arr + 2 = 0x7ffc785aa2f8
    printf("&arr = %p, &p = %p, \n", &arr, &p);
    printf("arr = %p, p = %p, &arr[0] = %p \n", arr, p, &arr[0]);
    printf("*arr = %p, *arr[0] = %d, **arr = %d \n", *arr, *arr[0], **arr);
    printf("arr[0] = %p, arr[1] = %p, arr[2] = %p \n", arr,  arr + 1, arr + 2);
    printf("arr[0] = %p, arr[1] = %p, arr[2] = %p \n", arr[0],  arr[1], arr[2]);
    printf("*arr[0] = %d, *arr[1] = %d, *arr[2] = %d \n", *arr[0],  *arr[1], *arr[2]);
    printf("arr[0][0] = %p, arr[0][1] = %p, arr[1][0] = %p \n", arr[0] + 0,  arr[0] + 1, arr[0] + 2);
    printf("*arr = %p, *arr + 1 = %p, *arr + 2 = %p \n", *arr, *arr + 1, *arr + 2);
}

void fn12() {
    int a = 1, b = 2;

    int *pk[2] = {
            &a, &b
    }; // Array of 2 pointers to int
    printf("%d , %d, %d ", **pk, *pk[0], *pk[1]);
}

int sum2(int(*s)[2], int row){
//int sum2(int s[][2], int row){ // Same
    int sum = 0;

    for(int i =0; i<row; i++ ){
        for(int j =0 ; j<2; j++){
            sum += *(*s + j);
            printf("%d \n", sum);
        }
        s += 1;
    }

    return sum;
}

int sum3(int row, int col, int a[row][col]){
    int sum = 0;
    for(int i =0; i<row; i++ ){
        for(int j =0 ; j<col; j++){
            sum += a[i][j];
            printf("%d \n", sum);
        }
    }

    return sum;
}

void fn13() {
    int arr[3][2] ={
            {1,2},
            {3,4},
            {5,6}
    };

    int (*pk)[2] = arr; // Pointer to arr of 2 ints
    printf("pk = %p , pk + 1 = %p \n", pk, pk  + 1);
    printf("*pk = %d , *pk + 1 = %d \n", **pk, **(pk  + 1));
    printf("(*pk)[0]= %d , (*pk + 1)[0] = %d \n", (*pk)[0], (*pk + 1)[0]);
    printf("sum2 =  %d \n", sum2(arr, 3));
    printf("sum3 = %d \n", sum3(3, 2, arr));
}

int sum5(int row, int *a){
    int sum = 0;
    for(int i=0; i<row; i++){
        sum += *(a + i);
    }
    return sum;
}

void fn14() {

    int s = sum5(6, (int []){1,2,3,4,5,6});
    printf("s = %d ", s);

    int (*pt)[2] = (int [][2]){
            {1,2},
            {6,7},
            {3,4},
            {5,8}
    };

    printf("Pt++ : %d", (*(pt + 2))[1]);
}

int main(){

    fn14();

    return 0;
}

int sum(int arr[], int n){
    int total = 0;
    for(int i=0; i<n; i++){
        total += arr[i];
    }

    return total;
}