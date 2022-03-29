#include<stdio.h>
int main()
{
    int i,j,k,l;
    printf("check your display if right than enter 0\n");
    while(i !=0)
    {
        j=0;
        scanf("%d",&i);
        while(j !=i)
        {
            printf("#");
            j++;
        }
        printf("\n");
    }
    while(k !=0)
    {
        printf("0.exit\n1.for printing\n2.deleting\n");
        l=0;
        j=120;
        scanf("%d",&k);
        if(k==1)
        {while(l !=j)
        {
            printf("#");
            l++;
        }}
        if(k==2)
        {while(l !=j)
        {
            printf("\b");
            l++;
        }}
        printf("\n");
    }
}
