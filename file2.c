#include<stdio.h>
int main()
{
    char p[10];
    for(int i=0;i<10; i++)
    {
        p[i]=getch();
        if(islower(p[i])) p[i]=toupper(p[i]);
        putchar(p[i]);
    }
    printf("\n%s\n",p);
}
