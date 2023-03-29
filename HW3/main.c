#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

int mm,n[5][7] ,count=1,num[3]={0},truncation;
char lottoID[10];
typedef struct{
	int receipt_id;
	int receipt_price;
	char receipt_time[32];
	int lotto_set[5][7];
} lotto_record_t;
lotto_record_t lrt1;

void readID(){
	FILE *id;
	//find lotto id to int count 
	sprintf(lottoID,"lotto[%05d].txt",count);
	if((id=fopen(lottoID,"r")) == NULL)
		return;
	else{
		while((id=fopen(lottoID,"r")) != NULL){
			count++;
			sprintf(lottoID,"lotto[%05d].txt",count);
			fclose(id);
		}
	}
	sprintf(lottoID,"lotto[%05d].txt",count-1);
	fclose(id);
}
void buildLotto(){
	int i,j,k;
	int rd,b1,b2;
	for(k=0;k<mm;k++){
		b2=0;
		for(i=0;i<7;i++){
			rd=(i!=6)?rand()%69+1:rand()%9+1;
			b1=1;
			for(j=0;j<i;j++){
				if(rd==n[k][j]){
					i--;
					b1=0;
					break;
				}
			}
			if(i==6 && k>0){
				b2=1;
				for(j=0;j<mm && (1<=n[j][6]&&n[j][6]<=10);j++){ 
					if(rd==n[j][6]){
						i--;
						b2=0;
						break;
					}
				}
			}
			if(b1&&!b2)
				n[k][i]=rd;
			else if(b1&&b2)
				n[k][6]=rd;
		}
	}
}
void insert(int t,int i,int j){
	int e=t;
	while(e<n[i][j]){
		n[i][j+1]=n[i][j];
		j--;
	}
	n[i][j+1]=e;
}
void sort(){
	int i,j;
	for(i=0;i<mm;i++)
		for(j=1;j<6;j++){
			int t=n[i][j];
			insert(t,i,j-1);
		}
}
void printToFile(){
	FILE *lot;
	int i,j;
	time_t t=time(0);
	char *c=ctime(&t);
	c[strlen(c)-1]=0;
	// generate lotto[00001], lotto[00002], ... file
	sprintf(lottoID,"lotto[%05d].txt",count);
	lot = fopen(lottoID,"w+");
	fprintf(lot,"========= lotto649 =========\n");
	fprintf(lot,"========+ No.%05d +========\n",count);
	fprintf(lot,"= %s =",c);
	for(i=1;i<=5;i++){
		fprintf(lot,"\n[%d]: ",i);
		if(i<=mm)
			for(j=0;j<7;j++)
				fprintf(lot,"%02d ",n[i-1][j]);
		else
			for(j=0;j<7;j++)
				fprintf(lot,"-- ");
	}
	fprintf(lot,"\n========= csie@CGU =========");
	fclose(lot);
}
void readLottoTXT(){
	FILE *read;
	int i,j,flag=0;
	char c[32];
	//read one of lotto[00001], lotto[00002], ..., and get value into struct
	read = fopen(lottoID,"r");
	while(fgets(c,sizeof(c),read) != NULL){
		if(flag==0){
			flag++;
			continue;
		}
		else if(flag==1){
			char temp[5];
			for(i=0;c[i]!=0;i++)
				if(c[i-1]=='.'){
					for(j=0;j<5;j++,i++)
						temp[j]=c[i];
					lrt1.receipt_id=atoi(temp);
					break;
				}
		}
		else if(flag==2){
			for(i=2,j=0;c[i]!='=';i++,j++)
				lrt1.receipt_time[j]=c[i];
		}
		else if(3<=flag && flag<=7){
			char temp[2];
			int k=0;
			if(c[5]!='-')
				lrt1.receipt_price+=100;
			for(i=5,j=0;c[i]!=0 && c[i]!='-';i++){
				if(c[i]==' '){
					k=0;
					lrt1.lotto_set[flag-3][j++]=atoi(temp);
					continue;
				}
				temp[k++]=c[i];
			}
		}
		flag++;
	}
	fclose(read);
}
void writeRecord(){
	FILE *record;
	record = fopen("record.bin","ab+");
	fwrite(&lrt1,sizeof(lotto_record_t),1,record);
	fclose(record);
}
void checkWinNum(){
	FILE *record;
	int k=0;
	record=fopen("record.bin","rb");
	if(record == NULL){
		printf("\n無人購買\n");
		return;
	}
	while(fread(&lrt1,sizeof(lotto_record_t),1,record) != 0){
		if(lrt1.receipt_id<=truncation){
			continue;
		}
		int i,j,win[5]={0},data=lrt1.receipt_price/100;
		for(i=0;i<data;i++)
			for(j=0;j<7;j++)
				if(lrt1.lotto_set[i][j]==num[0] || lrt1.lotto_set[i][j]==num[1] || lrt1.lotto_set[i][j]==num[2])
					win[i]=1;
		if(win[0]==1 || win[1]==1 || win[2]==1 || win[3]==1 || win[4]==1){
			printf("彩券 NO. %d\n",lrt1.receipt_id);
			printf("售出時間：%s\n",lrt1.receipt_time);
			printf("號碼：");
			
			int cnt=0;
			for(i=0;i<data;i++)
				if(win[i]==1){
					if(cnt!=0)
						printf("      ");
					for(j=0;j<7;j++)
						printf("%02d ",lrt1.lotto_set[i][j]);
					cnt++;
					printf("\n");
				}
		}
	}
	fclose(record);
}
void readTruncation(){
	FILE *tru;
	if((tru=fopen("truncation.bin","rb")) == NULL){
		truncation=0;
		return;
	}
	fread(&truncation,sizeof(int),1,tru);
	fclose(tru);
}
void changeTruncation(){
	FILE *tru;
	tru=fopen("truncation.bin","wb+");
	fwrite(&lrt1.receipt_id,sizeof(int),1,tru);
	fclose(tru);
}

int main(){
	srand(time(0));
	printf("歡迎光臨長庚樂透，請問您要買幾組樂透彩：");
	scanf("%d",&mm);
	
	if(mm==0){
		printf("請輸入中獎號碼(最多三個)：");
		int n1,i=0;
		while(scanf("%d",&n1)){
			num[i++]=n1;
			if(getchar()=='\n')	break;
		}
		printf("輸入中獎號碼為：");
		for(i=0;1<=num[i] && num[i]<=69;i++)
			printf("%02d ",num[i]);
		printf("\n以下為中獎彩券：\n");
		readTruncation();
		checkWinNum();
		changeTruncation();
	} 
	else{
		readID();
		printf("已為您購買的 %d 組樂透組合輸出至 lotto[%05d].txt\n",mm,count);
		
		buildLotto();
		sort();
		printToFile();
		readLottoTXT();
		writeRecord();
	}
	return 0;
}
