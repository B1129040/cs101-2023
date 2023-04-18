#include <stdio.h>
#include <time.h>
int cnt=0;
void hanoi(int n,char A,char B,char C, FILE *han){
	if(n>0){
		hanoi(n-1,A,C,B, han);
		
		time_t t= time(0);
		struct tm *ts= localtime(&t);
		char cc[24];
		strftime(cc,sizeof(cc),"%Y %m%d %H:%M:%S",ts);
		fprintf(han,"%d (%s) : %dP from %c to %c\n",++cnt,cc,n,A,C);
		
		hanoi(n-1,B,A,C, han);
	}
}
int main(){
	int n=20;
	FILE *han;
	han = fopen("hanoi.txt","w+");
	hanoi(n,'A','B','C', han);
	fclose(han);
	return 0;
}
