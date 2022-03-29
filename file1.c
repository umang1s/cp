#include<stdio.h>
#include"file2.c"
static int l=32;
int x;
void going(char name[2][10])
{
    printf("%s  ",name[0]);
    printf("%s\n",name[1]);
}
void doing(char name[][10])
{
   printf("%s  ",name[0]);
    printf("%s\n",name[1]);
}
void nextDoing(char *name)
{
    printf("%s  ",name[0]);
    printf("%s\n",name[1]);
}
int main()
{
   char x[2][10]={"umang","maurya"};
   going(x);
    doing(x);
    nextDoing(&x);
}
