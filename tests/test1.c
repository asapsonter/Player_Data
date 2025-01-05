#include <stdio.h>

int main(void){

    FILE *fp;
    int lineCount = 0;
    //int c;
    char s[1024]; //big enough to read many lines
    fp = fopen("test.txt", "r");
    while(fgets(s, sizeof s, fp) != NULL)
        printf("%d: %s", ++lineCount, s);

    // stop reading charaters when line is empty.
    // while ((c = fgetc(fp)) != EOF)
    //     printf("%c", c);

    fclose(fp);
    return 0;
}
