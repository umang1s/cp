#include<stdio.h>
void finalPrint(char x,int y)
{
    int k=1;
    char p;
    k+=((x-48)*3)+y;
    if(x=='8' || x=='9') k++;
    p=k+57;
    printf("%c",p);
}
void getValue(char x,int y,int l)     // 88626640062887779992
{
    char p=57;
    int k=1;
    if(x=='7' || x=='9' )
    {
        while(y>4)
        {
            finalPrint(x,4);    y-=4;
            getValue(x,y,1);
        }   if(!l)finalPrint(x,y);
    }
    else if(x=='0')
    {
        p=0;
        while(y>0)
        {
            printf("%c",p); y--;
        }
    }
    else
    {
        while(y>3)
        {
            finalPrint(x,3);    y-=3;
            getValue(x,y,1);
        }   if(!l)finalPrint(x,y);
    }
}
int main()
{
    char num[50];
    int i,k=1,loop=1;
    printf("COMPLETED\n\n");
    printf("Welcome to keypad mobile decoding\n\n");
    while(loop)
    {
        printf("\nPlease enter your number :  ");
        gets(num);
        for(i=1; i<strlen(num); i++)
        {
            if(num[i-1]==num[i])    k++;
            else
            {
                getValue(num[i-1],k,0);
                k=1;
            }
        }
        getValue(num[i-1],k,0);
        k=1;
        printf("\ncompleted Next...\n");
    }
}
