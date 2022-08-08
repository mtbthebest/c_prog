//
// Created by mtb on 8/8/22.
//

#include "stdio.h"

void fn1(){
    FILE *fp, *cfp;
    char *filename = "/home/mtb/Projects/c_prog/tutorials/test.txt";
    fp = fopen(filename, "r");

    char *cp_filename = "/home/mtb/Projects/c_prog/tutorials/test_copy.txt";
    cfp = fopen(cp_filename, "w");



    if(fp){
        int ch;
        while ((ch = getc(fp)) != EOF)
            putc(ch, cfp);

        fclose(fp);
        fprintf(stdout, "Copy successful\n");
        char words[40];
        fscanf(stdin, "%40s", words);
//        fprintf(stdout, "%s\n",words);
        fprintf(cfp, "%s\n",words);
        fclose(cfp);


    }




}

int main(int argc, char *argv[]){
    fn1();


    return 0;
}
