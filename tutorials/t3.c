//
// Created by mtb on 15/4/22.
//

#include "stdio.h"

#define PI 3.14
#define AREA_CIRCLE(r) PI * (r)

void fn1(){
    int x = 11, y = 2;
    // you get a negative modulus value if the first operand is negative, and you get a positive modulus otherwise
    printf("x/y = %d, x\%y=%d\n", x / y, x%y); // x/y = 5, x%y=1
    printf("-x/y = %d, -x\%y=%d\n", -x / y, -x % y); // -x/y = -5, -x%y=-1
    printf("-x/-y = %d, -x\%-y=%d\n", -x / -y, -x % -y); // -x/-y = 5, -x%-y=-1
    printf("x/-y = %d, x\%-y=%d\n", x / -y,  x % -y); // x/-y = -5,  x%-y=1
}

void fn2() {
    int x = 5;
    int xx = x++;
    int xxx = ++x;

    printf("x: %d, xx: %d, xxx:%d \n ", x, xx, xxx); //x: 7, xx: 5, xxx:7

//    Width: 4.000000, Height: 2.000000, Area: 8.000000
//    Width: 5.000000, Height: 2.000000, Area: 10.000000
// Width: 6.000000, Height: 2.000000, Area: 12.000000
    float width = 3.0f;
    float rectangle_area, height = 2.0f;
//    while(++width < 6.0f){
    while(width++ < 6.0f){
        rectangle_area = width * height;
        printf("Width: %f, Height: %f, Area: %f", width, height, rectangle_area);
        printf("\n");
    }
    float r;
    float radius=2.0f, circle_area;
//    r: 2.000000, radius: 3.000000, Area: 6.280000
//    r: 3.000000, radius: 4.000000, Area: 9.420000
//    r: 4.000000, radius: 5.000000, Area: 12.560000
//    r: 5.000000, radius: 6.000000, Area: 15.700000
    while((r = radius++)< 6.0f){
        circle_area = AREA_CIRCLE(r);
        printf("r: %f, radius: %f, Area: %f", r, radius, circle_area);
        printf("\n");
    }
    printf("Radius  at the end: %f", radius);//Radius  at the end: 7.000000
    printf("\n");

    int z = 2*x++; // (2 *7), x = x+1 = 8

    printf("z=2*x++ = %d, x=%d\n", z, x); // z = 14, x=8
    int y = 2*++x; // (2 * 9), x = 9

    printf("z=2*++x = %d, x=%d\n", y, x); // y =  18, x=9

    int yy = 1 + (x++) + x;
    printf("y=%d,  x=%d\n", yy, x ); // y = 1 + 9 + 10,  x=10
    yy = 1 + (++x) + 2*x;
    printf("y=%d,  x=%d\n", yy, x ); // y = 1 + 11 + 2*11,  x=11

    yy = 1 + 2*x +(++x);
    printf("y=%d,  x=%d\n", yy, x ); // y = 1 + 2*11 + 12,  x=12
}

void fn3() {
    // Statement
    int x, y;
    x= 25,  x++, y=2*x;
    printf("x: %d, y: %d\n", x, y); // x: 26, y: 52

    int count=0, sum= 0;
    while(count++ < 3){

        sum += count;
        printf("Sum : %d \n", sum); // 1,3,6
    }
}

// Conversion
void fn4(){
    char c = '\x41';
    int a = c + 1;
    printf("Char c %d in int expression a: %d\n", (int)c ,a); // Char c 127 in int expression a: 128
    c = c + 1;
    a = c + 100;
    printf("Char c %d in int expression a: %d\n", (int)c ,a); // Char c 66 in int expression a: 166

    c = '\x7f';
    a = c + 1;
    printf("Char c %d in int expression a: %d\n", (int)c ,a); // Char c 127 in int expression a: 128

    c = c + 1;
    a = c + 1;
    float b = 2*c;


    printf("Char c %d in int expression a: %d, b: %.1f\n", (int)c ,a, b); // Char c -128 in int expression a: -127, b: -256.0
    c = 65.9;
    a = c + 1;
    printf("Char c %c in int expression a: %d\n", c ,a); // Char c A in int expression a: 66

    int d;
    d = (int) 6.5;
    printf("Cast of d: %d \n", d); // Cast of d: 6

    d = (int) 6.9;
    printf("Cast of d: %d \n", d); // Cast of d: 6

    d = (int) 6.0;
    printf("Cast of d: %d \n", d); // Cast of d: 6

    d = (int) -6.0;
    printf("Cast of d: %d \n", d); // Cast of d: -6

    d = (int) -6.6;
    printf("Cast of d: %d \n", d); // Cast of d: -6

    d = (int) (3.5 + 4.4);
    printf("Cast of d: %d \n", d); // Cast of d: -6

}

void cum(int n){
    printf("%d \n", n);
}

void fn5(){
    char c='\x40';
    cum(c);// 64
    cum(c);// 64
    c = '\x80';
    cum(c);  //-128
    cum(3.9); // Narrowing 3
}

void fn6() {
    double c = 7 / 4;
    printf("%f\n", c); // 1.0
    c = (double )7 / 4;

    printf("%f\n", c ); // 1.75

    int d = 5.9998 / 2;
    printf("%d\n", d ); // 2
    printf("%f\n", (float )d); // 2.000
}

int main(int argc, char *argv[]){

    fn6();
    return 0;
}
