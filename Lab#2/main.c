#include <stdio.h>
#include <string.h>
typedef struct employee{
	int em_id;
	char em_name[10];
	int em_age;
	char em_phone[12];
	float em_salary;
}employee_t;
void employee_info(employee_t my_emp){
	printf("id: %d\n"
		   "name: %s\n"
		   "age: %d\n"
		   "phone: %s\n"
		   "salary: %f\n", 
		   my_emp.em_id, my_emp.em_name, my_emp.em_age, my_emp.em_phone, my_emp.em_salary);
}
int main(){
	employee_t e;
	e.em_id=12345;
	strcpy(e.em_name,"Claire");
	e.em_age=18;
	strcpy(e.em_phone,"0912345678");
	printf("%f",e.em_salary);
	employee_info(e);
	return 0;
} 
