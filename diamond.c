#include<stdio.h>
int main()
{
    int a,b,c,d;
    printf("enter the number");
    scanf("%d",&a);
    for(b=1; b<=a; b++)
    {
        c=a-1;
        for(d=1; d<=b; d++) printf(" ");
    }
}
