#include<stdio.h>
int fact(int n)
{
    int a;
    long int b=1;
    for(a=1; a<=n; a++) b*=a;
    return(b);
}
main()
{
    int c;
    printf("enter the number for factorial\n");
    scanf("%d",&c);
    if(c>1) printf("factorial is %d\n",fact(c));
    else if(c==0) printf("factorial is 1\n");
    else printf("we are failed to find factorial of entered number\n")
;}
