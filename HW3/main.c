#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int chick_list(int num, int list[6]){
    for (int i =0;i<5;i++){
        if (num == list[i])
            return 0;
    }

    return 1 ;
}

void swap_list(int list[6]){
    for (int i = 0; i < 6; ++i) {
    for (int j = 0; j < i; ++j) {
      if (list[j] > list[i]) {
        int temp = list[j];
        list[j] = list[i];
        list[i] = temp;
        }
    }}
}

typedef struct {
    int receipt_id;
    int receipt_price;
    char receipt_time[32];
    int lotto_set[5][7];
} lotto_record_t;


int main()
{
    lotto_record_t lotto; // create struct var called with "lotto"
    time_t now; // time function setting
    time(&now);
    FILE* fp,* fp2_w, *fp2_i; // file io setting
    int n ,j=0 ,i=0 , type, num, buy, add=1;
    int a[7] = {-1,-1,-1,-1,-1,-1} ;
    char o;
    char c[100];
    char chick[100];
    char a1[] = "========Lucky lotto========\n";
    
    srand((unsigned) time(NULL));
    fp = fopen("lotto.txt","wb+");
    fp2_i = fopen("record.bin","rb+");
    fp2_w = fopen("record.bin","ab");
    if (fgetc(fp2_i)==EOF) buy = 1;
    else{
      while((fgets(c,100,fp2_i)!=NULL)){
          //puts(c);
         /* for(int i=0;i<sizeof(c);i++){
              if (c[i] == "0")
                break;
              else{
                  if (c[i] != " "){
                    buy*=add; 
                    buy+=(int)c[i]-47;  
                  }
              }
          }
      } */ 
    }}   
    
        
    
    
    
    fwrite(a1,sizeof(a1)-1,1,fp);
    fwrite(ctime(&now),25,1,fp);
    
    printf("Welcome! How many set of lotto to buy?\n");
    scanf("%d",&n);
    printf("Create the number into lotto.txt.");
    
    lotto.receipt_id = buy;
    lotto.receipt_price = n*100;
    strcpy(lotto.receipt_time, ctime(&now));
    fprintf(fp2_w,"%d ",lotto.receipt_id);
    fprintf(fp2_w,"%d ",lotto.receipt_price);
    fprintf(fp2_w,"%s0 ",lotto.receipt_time);
    
    while(i<n){
        int a[7] = {-1,-1,-1,-1,-1,-1} ;
        j=0;
    while(j<6){
        num = rand()%69+1;
        type = chick_list(num,a);
    
        if (type){
           a[j] = num;
           j++;
        }
         
    }
    swap_list(a);
    while (1){
    num = rand()%10+1;
    type = chick_list(num,a);
    if (type){
        a[j] = num;
        break;
    } 
    }
    fprintf(fp,"[%d]:",i+1);
    for (int i = 0; i < 7; i++) {
        fprintf(fp, "%02d ", a[i]);
        fprintf(fp2_w , "%d ",a[i]);
    }
    fwrite("\n",1,1,fp);
    fprintf(fp2_w, "%s","#");

    i++;
    }
    fwrite("===========================",27,1,fp);
    fprintf(fp2_w, "%s","\n");
    fseek(fp,0,SEEK_SET);
    fclose(fp);
    
    
    return 0;
}
