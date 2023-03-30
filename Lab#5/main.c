#include <stdio.h>
#include <string.h>

typedef int(*func)(int,int);

int add(int x,int y){
    return x+y;
}

int sub(int x,int y){
    return x-y;
}

int mul(int x,int y){
    return x*y;
}

int div(int x,int y){
    return x/y;
}

int calc(func func,int x,int y){
    if(func=add)
        return add(x,y);
    else if(func=sub)
        return sub(x,y);
    else if(func=mul)
        return mul(x,y);
    else if
        return div(x,y);
}

int main()
{
    printf("sum=%d\n",calc(add,4,2));
    printf("dif=%d\n",calc(sub,4,2));
    printf("product=%d\n",calc(mul,4,2));
    printf("quotient=%d\n",calc(div,4,2));

    return 0;
}
