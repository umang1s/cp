#include<stdio.h>
#include<stdlib.h>
int main()
{
    int a=20,j;
    char name[a];
    printf("your name\n");
    scanf("%[^\n]",name);
    printf("%s\t\t%d",name,strlen(name));
    for(j=0; name[j] !='\0'; j++); printf("\n%d",j);
}

