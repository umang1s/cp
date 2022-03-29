#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char name[34];
    FILE *in;
    if(in=fopen("Test","w+")) {printf("Cannot open file.\n"); exit(1);}
    do
    {
        printf("enter a name (CR to quit):\n");
        gets(name);
        strcat(name,"\n");   //add a new line
        fputs(name,in);
    }while(*name!='\n');
    rewind(in);
    while(!feof(in))
    {
        fgets(name,79,in);
        printf(name);
    }
}
