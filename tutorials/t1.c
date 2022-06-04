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

int main(int argc, char *argv[]){
 /*
  Comments
  * */

    fn3();


    return 0;
}
