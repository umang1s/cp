#include<stdio.h>
void f1(char *s1, char *s2)
{
    char *tmp;
    tmp = s1;
    s1=s2;
    s2=tmp;
}
void f2(char **s1,char **s2)
{
    char *tmp;
    tmp =*s1;
    *s1=*s2;
    *s2=tmp;
}
int main()
{
    char *str1 = "HI",*str2= "BYE";
    f1(str1,str2);
    printf("%s %s ",str1,str2);
    f2(&str1,&str2);
    printf("%s %s ",str1,str2);
    return 0;
}
