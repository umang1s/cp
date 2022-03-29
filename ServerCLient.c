#include<stdio.h>
#include<windows.h>
void readd()
{
    char c[20];
    FILE *read;
        read= fopen("x.txt","r");
        fscanf(read,"%s",c);
        fclose(read);
        printf("%s\n",c);
}
void writee()
{
    char p[20];
    printf("                    ");
    scanf("%s",p);
    FILE *read;
        read= fopen("y.txt","w");
        fprintf(read,"%s",p);
        fclose(read);
}
int main()
{
    char fileName[100][20],name[100],chat[100][1000];
    FILE *read,*write;
    int client=0;
    int req=1000,id[100],pin[100],sex[100],dob[100];
    printf("welcome to this server client  \n\n\n");
    char c[20];
    while(1)
    {
     readd();
     writee();
        Sleep(1000);
    }
}
