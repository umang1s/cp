#include<stdio.h>
#include<stdlib.h>
int top=-1; char add[10];
int main()
{
    int i,j=0;
    char line[30],add[10],sub[10];
    printf("enter the string\n");
    gets(line);
    for(i=0; i<strlen(line); i++)
    {
        if(line[i]=='(' || line[i]=='{' || line[i]=='[')  push(line[i]);
        if(line[i]==')' || line[i]=='}' || line[i]==']')  pop(line[i]);
    }
    if(top==-1) printf("your expression is right\n");
    else printf("wrong\n");

}
void push(char ll)
{
    top++;
    add[top]=ll;
}
void pop(char ll)
{
    char kk;
    if(ll==')') kk='(';
    else if(ll=='}') kk='{';
    else kk='[';
    if(add[top]==kk) top--;
}
