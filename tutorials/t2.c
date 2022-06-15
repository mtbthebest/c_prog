//
// Created by mtb on 12/4/22.
//

#include "stdio.h"
#include "string.h"
#include "float.h"
// Define constant. Cannot change this value
#define PI 3.14



double area(double r){
    return PI * r * r;
}

void fn1() {
    char name[10];
    scanf("%s", name);
    // Alex Thomas -> Alex. scanf stops reading after blank tab newline whitespace
    // AlexThomas -> AlexThomas
    // AlexiaThomas -> *** stack smashing detected ***: <unknown> terminate
    // Maximum number of character to be saved is 9 characters + \O(NULL character)
    printf("The name is:  %s \n", name);
    printf("The name is:  %zd \n", strlen(name)); // Alex has length 4
    printf("The name is:  %zd \n", sizeof(name)); // name has size of 10. 10 bytes

}


void fn2(){
    int x = 105;

    printf("x: %d \n", x); // 105
    printf("x: %12d \n", x); // x:          105
    printf("x: %02d \n", x); // x: 105
    printf("x: %04d \n", x); // x: 0105
    printf("x: %x \n", x); // x:  69 hexadecimal
    printf("x: %#x \n", x); // x:  0x69
    printf("x: *%     d* \n", x); // x:   * 105*
    printf("x: *%15.12d* \n", x); // x:*   000000000105* 15 spaces 12 numbers
    printf("x: *%-15.12d* \n", x); // x:*000000000105   *  15 spaces 12 numbers to the right


    float y = 100.4224452421f;
    printf("y: %f \n", y); //y: 100.422447
    printf("y: %.2f \n", y); // 100.42
    printf("y: %06.2f \n", y); // 100.42
    printf("y: %07.2f \n", y); // 0100.42
    printf("y: %08.2f \n", y); // 00100.42
    printf("y: %05.0f \n", y); // 00100
    printf("y: %a \n", y); // y: 0x1.91b096p+6 exponential base 2

   unsigned int c = 256;
    printf("y: %hhu\n", c); // 0 -> unsigned short char conversion

    int z[]= {1,2,3};

    printf("Difference address %td \n", &z[2] - &z[0]); // 2
    printf("Difference address %lu \n", &z[2] - &z[0]); // 2
    printf("Difference address %zd \n", &z[2] - &z[0]); // 2
    printf("Difference address %zd \n", sizeof(z)); //12 bytes --> z for sizeof
    printf("Difference address %lu \n", sizeof(z)); // 12 bytes

    const char s[] = "Mondays is beautiful";

    printf("s : *%24s*\n", s); // s : *    Mondays is beautiful*
    printf("s : *%2s*\n", s); // s : *Mondays is beautiful*
    printf("s : *%24.3s*\n", s); // s : *                     Mon*
    printf("s : *%-24.3s*\n", s); // s : *Mon                     *
    printf("d : *%24.3d*\n", 1200000); // d :  *                 1200000*
    printf("d : *%-6.1d*\n", 1200); // d :  *1200  *
    printf("d : *%6.5d*\n", 1200); // d :  * 01200  *

}


// Printing with scanf
void fn3() {

    int age;
    char name[30];



    printf("Enter age: ");
    scanf("%d", &age);
    printf("\n");
    printf("Enter Name --------\b\b\b\b\b\b\b");

    scanf("%s", name);
    printf("\n");
    int width,  precision;
    printf("Enter width and precision: ");
    scanf("%d %d", &width, &precision);
    printf("\n");

    int n;
    printf("Enter year: ");
    scanf("%*d %*d %d", &n); // Skip 2 columns

    printf("The values entered are: name - %s age - |%*.*d| \n", name,  width, precision, age); // %*.* modifier
    printf("Entered year: %d\n", n);

}

int main(int argc, char *argv[]){

//    printf("%e\n", area(4.0));
//    fn1();
//    fn2();

    fn3();
    return 0;
}
