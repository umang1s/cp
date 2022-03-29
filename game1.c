#include<stdio.h>
#include<windows.h>
void gameOn();
int pos=0,up;
void display(int);
void setcolor(unsigned short color)                 //The function that you'll use to
{                                                   //set the colour
    HANDLE hcon = GetStdHandle(STD_OUTPUT_HANDLE);
    SetConsoleTextAttribute(hcon,color);
}
int main()
{
    setcolor(24);
    gameOn();
}
void gameOn()
{
    char c;
    do
    {
        display(++pos);
        up=0;
    }while(!kbhit());
    c=getch();
    if(c==72) up=1;
    gameOn();
}
void display(int k)
{
    char c=4;
    system("cls");
    printf("\n\n");
    if(up==0) printf("\n\n");
    if(up==1);
    for(int i=1; i<k; i++) printf(" ");
    printf("@\n");
    if(up==1) printf("\n\n");
    for(int i=0; i<100; i++) printf("%c",c);
}
