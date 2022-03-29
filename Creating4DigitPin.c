#include<stdio.h>
int main()
{
    printf("Your pass word is creating wait...\n");
    FILE *x;
    int y[10000],m=0;
    for(int i=0; i<10000; i++) y[i]=i;
    printf("created\n");
    for(int i=0; i<10000; i++)
    {
        printf("%04d",y[i]);
        if(i%30==0) printf("\n");
        else printf("  ");
    }
}
