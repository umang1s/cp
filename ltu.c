#include<stdio.h>
int main()
{
    char word[100];
    int n;
    printf("enter the word\n");
    scanf("%[^\n]s",word);
    for(n=0; n<100; n++)
    {

         if(word[n]<='z' && word[n]>='a')
            word[n]-=32;
            else ;
    }
    printf("upper case is equal to \n\n %s",word);
}
