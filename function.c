#include<stdio.h>
char lu(char c1)
{
   if (c1>= 'a' && c1<= 'z') return('A' + c1 -'a');
   else return(c1);

}
main()
{
    char u,l;
    printf("enter the charecter\n");
    scanf("%c",&l);
    u= lu(l);
    printf("equivalent charecter of entered is %c\n\n",u);
}
