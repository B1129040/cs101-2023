#include <stdio.h>
int main(){
	char a[]="Hello";
	int i;
	int size=sizeof(a)-1;
	int n=size-1;
	printf("a = %s\n",a);
	for(i=0;i<size/2;i++,n--){ 
		char c=a[i];
		a[i]=a[n];
		a[n]=c;
		if(i==0){
			a[i]=a[i]-'a'+'A';
			a[n]=a[n]-'A'+'a';
		}
	}
	printf("a = %s\n",a);
	return 0;
}
