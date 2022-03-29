#include<stdio.h>
#include<stdlib.h>
int total, k[100],sort[100];
int digit(int num)
{
    int d=1;
    while(num > 9) {   d++; num=num/10;}
    return(d);
}
void sorting()
{
    int i,j,temp;
    for(j=0; j<total; j++)
    for(i=0; i<total-1; i++)
    {
        if(sort[i]<sort[i+1]){temp=sort[i]; sort[i]=sort[i+1]; sort[i+1]=temp;}
    }
}
void checkin()
{
    int i,l,temp,kk,p;
    for(i=0; i<total ; i++)
    {
        kk=0;
        p=1;
        for(l=0; l<total; l++)
        {
            if(l !=i){
            kk+=k[l]*p;
            p*=10;}
        }
        sort[i]=kk;
    }
    sorting();
}
int main()
{
    int j,m,p,num;
    printf("enter the number\n");
    scanf("%d",&num);
    j=digit(num);
    p=j;
    total=j;
    for(m=0; m<j; m++)
    {
        k[m]=num%10;
        num/=10;
    }
    checkin();
    printf("greatest is %d\t smallest is %d\n",sort[0],sort[total-1]);
}
