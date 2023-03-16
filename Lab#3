#include <stdio.h>
typedef struct{
	int id;
	char first_name[32];
	char last_name[32];
} person_t;

int main(){
	int i;
	FILE *wfp=fopen("person.bin","wb+");
	person_t p[5]={ {1,"IU", "Lee"},
					{2,"IUU", "Lee"},
					{3,"IUUU", "Lee"},
					{4,"IUUUU", "Lee"},
					{5,"IUUUUU", "Lee"} };
	for(i=0;i<5;i++)
		fwrite(p+i,sizeof(person_t),1,wfp);
	fclose(wfp);
	
	FILE *rfp=fopen("person.bin","rb");
	person_t tmp;
	for(i=0;fread(&tmp,sizeof(person_t),1,rfp);i++)
		printf("[%d] %d: %s %s\n",i,tmp.id,tmp.first_name,tmp.last_name);
	fclose(rfp);
	
	return 0;
}
