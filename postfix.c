#include<stdio.h>
#include<string.h>
int main()
{
    int i,j=0,k;
    char name[20],postfix[20];
    printf("enter the expression\n");
    scanf("%s",name);
    for(i=0; i<strlen(name); i++)
    {
        if(name[i]=='+' || name[i]=='-' || name[i]=='*' || name[i]=='/' || name[i]=='^' || name[i]=='%')
        {
            postfix[j]=name[i+1]; j++; postfix[j]=name[i]; j++; i++;
        }
        else {postfix[j]=name[i]; j++;}
    }
    for(i=0; i<j; i++) printf("%c",postfix[i]);
}
