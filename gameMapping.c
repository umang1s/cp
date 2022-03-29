#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
char maps[20][200];
int x=100,y=20,cox=0,coy=0;
void display()
{
    system("cls");
    printf("size %d x %d                            covered %d x %d  \n",y,x,coy,cox);
    printf("---------------------------------------------------------------------------------------------------------------------\n");
    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++)  printf("%c",maps[i][j]);
        printf("\n");
    }
}
int main()
{
    char p;
    int i;
    while(p!='a')
    {
        display();
        printf("\n  256 <--  257  --> 259 --x-y");
        printf("\n   enter value : ");
        scanf("%d",&i);
        if(i==256)  { maps[coy][cox]=' '; coy--;    }   // back a line
        else if(i==257){ maps[coy][cox]=' ' ; cox++;  }    // next line
        else if(i==259)
        {
            printf("Enter y and x ");
            scanf("%d %d",&y,&x);
        }
        else
        {
            maps[cox][coy]=i;
            if(y<19) coy++;
            else cox++;
        }
        if(cox<0) cox=0; if(coy<0) coy=0;
    }
    char fileName[10];
    printf("enter file name to save  ::  ");
    scanf("%s",fileName);
    FILE *write;
    write = fopen(fileName,"w");
    for(int i=0; i<y; i++)
    {
        for(int j=0; j<x; j++) fprintf(write,"%c",maps[i][j]);
        fprintf(write,"\n");
    }
    fclose(write);
    printf("saved date to this file  \n\t\t\t%s\n",fileName);
}
