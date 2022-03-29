#include<stdio.h>
#include<windows.h>
void erase()
{
    printf("\b");
}
int main()
{
    int i,j,k;
    printf("enter the number ");
    while(i !=0)
    {
        scanf("%d",&i);
        while(k !=120) {printf("\b"); k++;}
        for(j=0; j<i; j++)
        {
            printf("%d",j);
            Sleep(1000);
            erase();
        }
    }
}
