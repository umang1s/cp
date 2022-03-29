#include<stdio.h>
#include<windows.h>
int x1=0,x2=0;
left()
{
    int b1,b2;
    b1=x1; b2=x2;
    erase(b1,b2);
    if(x2>4)
    {
     x2-=4;
     display(x1,x2);
    }
}
right()
{
    int b1,b2;
    b1=x1; b2=x2;
    erase(b1,b2);
     x2+=4;
     display(x1,x2);
}
up()
{
    int b1,b2;
    b1=x1; b2=x2;
    erase(b1,b2);
    if(x1>3)
    {
     x1-=3;
     display(x1,x2);
    }
}
down()
{
    int b1,b2;
    b1=x1; b2=x2;
    erase(b1,b2);
     x1+=3;
     display(x1,x2);
}
void display(int a1,int a2)
{
    int a3=0,a4,a5;
    for(a5=0; a5<a2; a5++)
    printf("#");
}
void erase(int d1,int d2)
{
    int d3=0,d4,d5,d6;
    for(d4=0; d4<3; d4++)
    {
        for(d5=0; d5<d2; d5++)
        printf("\b");
    }
}
int main()
{
    int w=0;
    char control,input[10];
    printf("welcome to this moving object game\n");
    printf("use A S D F to move \t for exit enter Q\n");
    display(x1,x2);
    scanf("%s",input);
    while(control !='q' && w<strlen(input))
    {
       // control=input[w]; w++;
       scanf("%c",&control);
        if(control=='a' || control=='A') left();
        else if(control=='d' || control=='D') right();
        else if(control=='w' || control=='W') up();
        else if(control=='s' || control=='S') down();
        //Sleep(2000);
    }
}
