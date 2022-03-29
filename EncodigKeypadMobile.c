#include<stdio.h>
void converging(char x)
{
    int z=x-65;
    int loop=1;
    if(z<18)
    {
        loop=z%3;
        loop++;
        z/=3;
        z+=2;
    }
    else if(z==18)  {z=7; loop=4;}
    else if(z>18 && z<22)
    {
        loop=z-18;
        z=8;
    }
    else
    {
        loop=z-21;
        z=9;
    }
    if(loop==0) loop=1;
    for(int k=0; k<loop; k++) printf("%d",z);
}
void getValue(char x)     // 88626640062887779992
{
    if(x>96 && x<123) x-=32;
    int k=1;
    if(x>64 && x<91)
    {
        converging(x);
    }
    else printf("%");
}
int main()
{
    char num[50];
    int i,k=1,loop=1;
    printf("COMPLETED\n\n");
    printf("Welcome to keypad mobile decoding\n\n");
    while(loop)
    {
        printf("\nPlease enter your Latter :  ");
        gets(num);
        for(i=0; i<strlen(num); i++)
        {
           if(num[i]==' ') printf("0");
           else getValue(num[i]);
        }
        printf("\ncompleted Next...\n");
    }
}

