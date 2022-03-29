#include<stdio.h>
int main()
{
    int i,j,l,m,k,n,o,p,q,r;
    printf("enter the length and breadth of shape\n");
    scanf("%d%d",&l,&m);
    printf("enter thickness of length and breadth\n");
    scanf("%d%d",&n,&o);
    k=2*l-4*o;
    for(p=0; p<n; p++)
    {
        for(i=1; i<=l; i++) printf("* ");
        printf("\n");
    }
    for(i=1; i<=m-2*n;i++)
    {
        for(p=0; p<o; p++)
        printf("* ");
        for(j=1; j<=k; j++) printf(" ");
        for(p=0; p<o; p++) printf("* ");
        printf("\n");
    }
    for(p=0; p<n; p++)
    {
        for(i=1; i<=l; i++) printf("* ");
        printf("\n");
    }
}
