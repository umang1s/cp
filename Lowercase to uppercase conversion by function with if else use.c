#include<stdio.h>
char l(char c1)
{
    if(c1>='a' && c1<='z') return('A'+ c1-'a');
    else return(c1);
}
main()
{
    char c2;
    printf("enter charecter \n");
    scanf("%c",&c2);
    printf("\n %c",l(c2));
}
