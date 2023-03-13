#include <stdio.h>

int main()
{
    FILE *fp_in ,*fp_out;
    char c;
    fp_in = fopen("main2.c","r");
    fp_out = fopen("main2.txt","w");
    while ((c = fgetc(fp_in)) != EOF) {
        fputc(c, fp_out);
    }
    fclose(fp_in);
    fclose(fp_out);
    return 0;
}
