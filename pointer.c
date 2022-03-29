#include<stdio.h>
int *x,*y,stack[50];
void push(int x)
{
    stack[x++]=x;
}
int pop()
{
    x--;
    return stack[x+1];
}
int main()
{
    int h=32;
    int *x,*y;
    x=y=stack;
    int value=3;
    while(value!=-1)
    {
        scanf("%d",&value);
        if(value>0) push(value);
        else if(value==0) printf("%d  ",pop());
        else;
    }
}
