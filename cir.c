#include<stdio.h>
#include<conio.h>
#include<windows.h>
#include<dos.h>
int main()
{
int gd=DETECT,gm;
initgraph(&gd,&gm,"C:\\TC\\BGI");
circle(100,100,50);
getch();
closegraph();
return 0;
}
