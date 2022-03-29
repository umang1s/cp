#include<stdio.h>
#include<stdlib.h>
char name_in_capital(char student[20])
{
    int i;
    char capital[20];
    printf("%s\n",student);
    for(i=0; student[i] !=NULL ; i++)
    {
        if(student[i]>='a' && student[i]<='z')
            capital[i]=student[i]+32;
        else capital[i]=student[i];
    }
    printf("%s\n",capital);
    return(capital);
}
int main()
{
   int i;
   char std[20];
   printf("enter the name\n");
   gets(std);
   printf("capital is %s\n",name_in_capital(std[20]));
}
