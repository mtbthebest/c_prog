//
// Created by mtb on 7/26/22.
//

#include "stdio.h"
#include "string.h"

#define STR_SIZE 40

void fn1() {
   char s[STR_SIZE] = "Hello World";

    printf("s = %s \n", s);
    printf("size = %lu \n", strlen(s)); // Length of the string remove of the null value
    printf("\%-30\\s = %-30s ,  %s \n", s, "After");
    printf("\%-30.8\\s = %-25.8s ,  %s \n", s, "After");
    printf("\%30\\s = %30s ,  %s \n", s, "After");
    printf("\%30.4\\s = %30.4s ,  %s \n", s, "After");
    puts(s);

    printf("\n");


}

void fn2() {

    char *s="I am here";
//    *(s + 4) ='P'; // Error pointer array is constant
    for(int i=0; i<3; i++){
        switch (i) {
            case 1:
                printf("%c ", *s );
//                *s = 'T';
                break;
            case 3:
//                *s = 'A';
                break;
            default:
                break;
        }
        s++;
    }
    printf("New:  %s \n", s);

    char p[] = "I am here'";

    p[2] = 'U';
    printf("%s \n", p);
}

void fn3(){
    char *s = "Hello World";

    do{
        printf("%c " , *s);
    }while (*s++ != '\0');

    char *p = "Soy";
//    p[0] = 'B'; // Error
//    printf("%c ", *p);
    puts("");

    const char *q[] = {
        "Mon",
        "Tue",
        "Wed"
    };
    printf("%lu", sizeof(q));

}

void fn4(){

    char c;

    while((c = (char) getchar()) != EOF){
        putchar(c);
        if(c == 'q'){
            break;
        }
        puts("Done ");
    }
}

void fn5(){
    char words[15];

    puts("Enter a string");

    gets(words);
    puts("Your string is : ");
    puts(words);
}

void fn6(){
    char words[10];

    fgets(words, 10, stdin); // Keep new line contrary to gets . Ex HelloPoisitionjZ
    printf("%c , %c , ", words[4], words[5]);   puts(words); // o , P , HelloPois
    fputs(words, stdout); printf("A"); // HelloPoisA

}

void fn7(){
    char s[20];
    while(fgets(s, 10, stdin) != NULL && s[0] != '\n'){
        fputs(s, stdout);
        printf(" --- ");
    }
    puts("Done");
}

void fn8() {

    char *s = "Hello world";
    puts(s);
    puts(&s[7]);
    puts(s + 3);

}

void fn9(){
    const char *s = "Hello";

    printf("%s has %-10.12zd characters \n", s, strlen(s));
    printf("%s has %12.2zd characters \n", s, strlen(s));
    printf("%s has %-12.2zd characters \n", s, strlen(s));

}

void fn10() {
    char a[] = "ABCDEFG", b[4] ="Bdd", c[4] = "CCC";
    strcat(b, c);
    puts(b);

    char s[4]="Kio";

    strncat(s, a,4);
    puts(s);

    printf("\n Cmp: %d  \n", strcmp("AB", "ABC"));
    printf("\n Cmp: %d  \n", strcmp("ABCD", "ABC"));
    printf("\n Cmp: %d  \n", strcmp("ABCD", "ABCD"));
    printf("\n Cmp: %d  \n", strcmp("ABCD", "OTGHHJ"));

    char p[5]="Polo";
    char q[10];

    strcpy(q, p);

    puts(q);
    puts(p);

    char r[5];
    strncpy(r, p, 3);
    puts(r);
}

int main(int argc, char *argv[]){

    fn10();

    return 0;
}