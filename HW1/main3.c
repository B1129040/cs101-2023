#include <stdio.h>

int main()
{
    char a[]= "ABCabcABC";
    int shift = 4;
    int n = sizeof(a)-1;
    for(int i=0;i<n;i++){
        printf("%c",a[i]);
    }
    printf("\n%d\n",shift);
    
    for(int i=0; i<n;i++){
        if (i+shift>=n)
            printf("%c",a[i+shift-n]);
        else
            printf("%c",a[i+shift]);
    }
    return 0;
}
