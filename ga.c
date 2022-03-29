#include<stdio.h>
#include<windows.h>
int main()
{
int n,m,o,p,q,r,s;
printf("enter the number of structure to print\tenter the number of line \tenter the milisecond\n");
scanf("%d%d%d",&q,&o,&r);
for(s=0; s<q; s++)
{
for(n=0; n<=o-1; n++)
    {
    for(p=o-n; p>=0; p--)    printf(" ");
    for(m=1; m<=2*n+1; m++)  printf("*");
    printf("\n");
    Sleep(r);
    }
for(n=0; n<=o-2; n++)
    {
        for(p=-2; p<=n; p++) printf(" ");
        for(m=2*o-2*n-4; m>=0; m--) printf("*");
    printf("\n");
    Sleep(r);
    }
    }
    return 0;
}
