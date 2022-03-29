#include<iostream>
#include<cstring>
using namespace std;
void MyStrcat(char *s1 ,char *s2 , int len=-1);
int main()
{
    char s1[30]="hello umang";
    char s2[20]="all is";
    MyStrcat(s1,s2);
    cout<<s1<<endl;
    strcpy(s1,"hi winner");
    MyStrcat(s1,s2,4);
    cout<<s1<<endl;
}
void MyStrcat(char *s1 , char *s2, int len)
{
    if(len==-1) len=strlen(s1);
    while(*s1) s1++;
    while(*s2 && len)
    {
        *s1=*s2;
        s1++;
        s2++;
        len--;
    }
}
