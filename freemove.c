#include<stdio.h>
#include<windows.h>
int X=1,Y=1,dir=1;
void star()
{
    char z;
    do  {display();} while(!kbhit()) ;
    z=getch();
    if(z==72) dir=2;
    if(z==77) dir=3;
    if(z==80) dir=4;
    if(z==75) dir=1;
    star();
}
void display()
{
    system("cls");
    for(int i=0; i<Y; i++) printf("\n");
    for(int i=0; i<X; i++) printf(" ");
    printf("@(%d,%d)",X,Y);
    if(dir==1) X-=2;
    else if(dir==2) Y--;
    else if(dir==3) X+=2;
    else Y++;
    if(X<1 || X>100) X=1;
    if(Y<1 || Y>25) Y=1;
    Sleep(20);
}
int main()
{
    star();
}
