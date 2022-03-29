#include<stdio.h>
#include<windows.h>
void working(int i)
{
    FILE *write;
    write = fopen("bixer.txt","w");
    fprintf(write,"%d",i);
    fclose(write);
}
int main()
{
    printf("Control  \n");
    char I=0;
    while(I!='Q' && I!='q')
    {
        scanf("%c",&I);
        if(I=='W' ||  I=='w') working(8);
        else if(I=='d' || I=='D') working(6);
        else if(I=='A' || I=='a')  working(4);
        else if(I=='S' || I=='s')  working(2);
        else continue;
    }
}

