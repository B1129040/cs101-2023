#include <stdio.h>
void multiplication(int i,int j){
	printf("%d*%d=%d ",i,j,i*j);
	if(i==9 && j==9){
		return ;
	}
	else if(j==9){
		printf("\n");
		multiplication(++i,1);
	}
	else{
		multiplication(i,++j);
	}
}
int main(){
	multiplication(1,1);
	return 0;
} 
