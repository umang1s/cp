#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void greater_smaller()
{
    int i,j[100],k,l,m,temp;
    printf("how many numbers\t0.EXIT\n");
    scanf("%d",&i);
    while(i !=0)
    {
        printf("enter numbers\n");
        for(k=1; k<=i; k++) scanf("%d",&j[k-1]);
        for(l=0; l<k; l++) for(m=0; m<k; m++){if(j[m] > j[m+1]){temp=j[m]; j[m]=j[m+1]; j[m+1]=temp;}}
        printf("greatest number is %d \t smallest number is %d\n",j[k-2],j[0]);
        printf("enter how many numbers\t0.EXIT\n");
        scanf("%d",&i);
    }
}
void addition()
{
    int i,j[100],k,l,ans;
    printf("for exit enter 0 enter how many number\n");
    scanf("%d",&i);
    while(i !=0)
    {
        l=0; ans=0;
        printf("enter the numbers for adding for end scanning enter 0\n");
        for(k=1; j[k-1] !=0; k++)
        {
           scanf("%d",&j[k-1]);
           l++;
        }
        for(k=0; k<l; k++) ans+=j[k];
        printf("your answer is \t%d\n",ans);
        printf("for exit enter 0 enter how many number\n");
        scanf("%d",&i);
    }
}
void factorial()
{
    int i,fact,k;
    printf("enter number for factorial \t0.EXIT\t 0!=1\n");
    scanf("%d",&i);
    while(i !=0)
    {
        fact=1;
       for(k=1; k<=i; k++ ) fact*=k;
       printf("your answer is %d\n",fact);
       printf("enter number for factorial \t0.EXIT\n");
       scanf("%d",&i);
    }
}
int main()
{
    int i;
    while(i !=0)
    {
        printf("\nplease choose an option\n\t\t\t0.EXIT\n");
        printf("\t\t\t1.for adding number\n\t\t\t5.factorial\n\t\t\t6.greater and smaller number\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: addition(); break;
            case 5: factorial(); break;
            case 6: greater_smaller(); break;
        }
    }
}
