#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
int sec,mins,hrs,pointer,cat;
void reset();
void stop();
void exite();
void display();
int main()
{
    int i=1;
    sec=mins=hrs=pointer=cat=0;
    char c;
    display();
    c=getch();
    if(c==77) {pointer++; display(); c=getch(); if(c==75) pointer--; else if(c==77) pointer++;  else ; }
    while(i)
    {
        display();
        //c=getch();
        if(c==75)
        {
            cat--;
            if(cat<0) cat=0;
            if(cat==0) stop();
        }

        if(cat==1) sec++;
        if(sec>60) {mins++; sec=0;}
        if(mins>60) {hrs++; mins=0;}
    }
}
void stop()
{
    ;
}
void display()
{
    system("cls");
    char c=-78;
    printf("\n\n\n          %0.2d : %0.2d : %0.2d\n\n",hrs,mins,sec);
    if(pointer==0)
    {
        if(cat==0) printf("    %c%c%c%c%c%c%c\n    %cSTART%c     RESET      EXIT\n    %c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c,c,c);
        else printf("     %c%c%c%c%c%c\n     %cSTOP%c     RESET      EXIT\n     %c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c,c,c,c,c,c);
    }
    else if(pointer==1)
    {
        printf("               %c%c%c%c%c%c%c\n     ",c,c,c,c,c,c);
        if(cat==0) printf("START     %cRESET%c     EXIT\n               %c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c);
        else printf(" STOP     %cRESET%c     EXIT\n               %c%c%c%c%c%c%c\n",c,c,c,c,c,c,c,c,c);
    }
    else
    {
        printf("                          %c%c%c%c%c%c\n     ",c,c,c,c,c,c);
        if(cat==0) printf("START      RESET     %cEXIT%c\n                          %c%c%c%c%c%c",c,c,c,c,c,c,c,c,c);
        else printf(" STOP      RESET     %cEXIT%c\n                          %c%c%c%c%c%c",c,c,c,c,c,c,c,c,c);
    }
    printf("\n");
}
