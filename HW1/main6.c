#include <stdio.h>
void output(char n){
    if (n == '8')
     printf("VIII ");
    else if(n == '1')
     printf("I ");
    else if(n == '6')
     printf("VI ");
    else
     printf("%c ",n);
}

int main()
{
    char a[] = "81c8g8u168";
    int n = sizeof(a)-1;
    for (int i=0;i<n;i++)
        output(a[i]);
        return 0;
}
