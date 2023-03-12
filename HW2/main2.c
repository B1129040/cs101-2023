#include <stdio.h>
#include <string.h>

int main(){
	FILE *main2, *self;
	main2 = fopen("main2.txt","w");
	self = fopen("main2.c","r");
	char c[48];
	int i=1;
	while((fgets(c,sizeof(c),self)) != NULL){
		fprintf(main2,"%02d %s",i++,c);
		memset(c,0,sizeof(c));
	}
	return 0;
}
