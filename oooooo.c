#include<stdio.h>
#include<string.h>
main()
{
int c;
char ram[10],neh[10];
scanf("%s",ram);
for(c=0; c<strlen(ram); c++)
{
    ram[c]=neh[c];
}
printf("\n name is %s\t nem is %s",ram,neh);
}
