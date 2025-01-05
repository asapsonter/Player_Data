#include <stdio.h> 

int main(void){
    FILE *fp;
    int x = 32;

    fp = fopen("test.txt", "a");
    fputc('B', fp);
    fputc('\n', fp);//new line
    fprintf(fp, "x=%d \n", x); 
    fputs("this puts line \n", fp);

    fclose(fp);




    // char name[1024];
    // float length;
    // int mass;

    // fp = fopen("test.txt", "r"); //read file

    // while ( fscanf(fp, "%s %f %d", name, &length, &mass) != EOF) // while memory is not wrong
    //     printf("%s whale, %d tonnes, %.1f metters \n", name, mass, length);
    //     fclose(fp);


    return 0;
}
