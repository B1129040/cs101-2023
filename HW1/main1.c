#include <stdio.h>

int main()
{
    char a[]="AABBBCCCCddd";
    int n = sizeof(a)-1;
    int k=1,b;
    for(int i=0;i<n;i++){
        b=i+1;
        if(a[i]==a[b]){
            k=k+1;
        }else{
            printf("%c%d",a[i],k);
            k=1;
        }
    }
    return 0;
}
