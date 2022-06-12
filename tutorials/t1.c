//
// Created by mtb on 6/4/22.
//

#include "stdio.h"

void fn1(){
    float weight;

    scanf("%f",&weight);

    printf("%5.2f", weight);
}

void fn2() {
    int q = getchar();

    printf("%d", q);
}

// Octal / Hexadecimal
void fn3() {
    int x = 17;

    printf("Integer: %d, octal = %o, hex= %x \n" , x, x, x);
    printf("Integer: %d, octal = %#o, hex= %#x \n" , x, x, x);

    int z = 0x17;

    printf("z: %d \n" , z);

    int y = z + 0x5;
    printf("y: %d \n", y);





}

void fn4(){
    // Signed int is -(2**32 - 1) // 2 - 1 ~ (2**32 - 1) //2
    // UnSigned int is 0 ~ (2**32 - 1)
    // Signed long int is -(2**64 - 1) // 2 - 1 ~ (2**64 - 1) //2
    int t = 2147483647; // (2**32 - 1) // 2 for signed int

    printf("Max signed int: %d \n", t + 1); // -2147483648
    printf("Max signed int: %d \n", t + 2); //  -2147483647
    printf("Max signed int: %u \n", t + 2); //  2147483649

    long t2 = t + 5;  // -2147483644. The sum is signed int and transformed back to int
    printf("Long value %ld \n", t2);

    long t3 = (long)t + 5;  // 2147483652
    printf("Long value %ld \n", t3);


    unsigned t4 = t + 5; // Ok. different from long

    printf("Unsigned int: %d \n", t4); // -2147483644
    printf("Unsigned int: %u \n", t4); // 2147483652
    printf("Unsigned int max: %u \n", 2 * t + 1); // 4294967295
    printf("Unsigned int max: %u \n", 2 * t + 2); // 0

    unsigned long t5 = 2 * t ;
    printf("Unsigned long : %lu \n", t5); // 18446744073709551614

    signed long t6 = 9223372036854775807; // (2 **64 - 1) // 2
    printf("Max  long : %ld \n", t6); // 9223372036854775807
    printf("Max  long + 1 : %ld \n", t6 + 1); //  -9223372036854775808

    unsigned long t7 = 9223372036854775807 ;
    printf("Unsigned long + 1 : %lu \n", 2*(t7) + 1 ); // 18446744073709551615
    printf("Unsigned long + 6 : %lu \n", t7 + 6 ); // 9223372036854775813
    printf("Unsigned long + 1 : %lu \n", 2*(t7) + 2 ); // 0


    long long t8 = 9223372036854775807;

    printf("Long long: %lld \n", t8 + 6); // Long long and long have same range for this machine

    short t9 = 32767;
    short t10 = (short) t9 + (short) 1;
    printf("Short %hd \n", t9 ); //  32767
    printf("Short %hd \n", t10 ); //  -32768
}

void fn5(){
    char a = 'a'; // Not "a" which is a string
    printf("Char %c \n", a);
    printf("Char %c \n", 67);

    char b= 'fate';
    printf("Char \r %c  \n", b); // Last character is chosen
    printf("Char \n %c  \n", b);
    printf("Char\b\b:%c  \n", b);

    printf("------------\n");

    char x ='\x41', y= '\101'; // 65 decimal for octal and hexadecimal
    printf("x: %c, y: %c", x, y); // x: A, y: A

}

void fn6() {
    #include "inttypes.h"

    int32_t x = 2147483647;
    printf("x + 1: %d\n", x + 1);
    printf("x + 1: %" PRId32 "\n", x + 1);
    printf("x + 1 64 bits: %" PRId64 "\n", x + 1);

}

void fn7(){
    const float t = 4.0e5f;

    printf("%f\n", t); //400000.000000
    printf("%e\n", t); // 4.000000e+05
    printf("%a\n", t); //0x1.86ap+18
    printf("%A\n", t); //0X1.86AP+18
    double u = 1.0e-34;
    printf("%f\n", u); //0.000000
    printf("%e\n", u); //1.000000e-34

    long double v = u;
    printf("%Lf\n", v); // 0.000000
    printf("%Le\n", v); // 1.000000e-34


}

void fn8(){
    // Float overflow
    float big = 3.4e38f * 100.f; // inf. Float from 10**-37 ~ 10**37

    printf("%f\n", big);
    printf("%f\n", (double)big);

    // Underflow
    float a = 2.2e20f, b=a + 1;
    float c = b - a;
    printf("%f\n", c); // 0.000000
    printf("%e\n", c); // 0.000000
//    #include "complex.h"
//    float _Complex z = 4.0 + 2I;

}

void fn9() {
    // Size of
    printf("%zd \n", sizeof(int)); // 4 bytes
    printf("%zd \n", sizeof(char)); // 1 bytes
    printf("%zd \n", sizeof(long)); // 8 bytes
    printf("%zd \n", sizeof(short)); // 2 bytes
    printf("%zd \n", sizeof(float)); // 4 bytes
    printf("%zd \n", sizeof(long long)); // 8 bytes
    printf("%zd \n", sizeof(double)); // 8 bytes
    printf("%zd \n", sizeof(long double)); // 16 bytes
}

int main(int argc, char *argv[]){
 /*
  Comments
  * */

    fn9();


    return 0;
}
