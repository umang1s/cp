//  using fopen(),getc()    putc()  fclose()
#include<stdio.h>
#include<stdlib.h>
int main(int arg,char *argv[])
{
    FILE *fp;
    char ch;
    if(arg !=2){printf("you forgot to enter the filename .\n"); exit(1);}
    //  KTOD: A key to disk programs

      /*
    if((fp==fopen(argv[1],"w"))==NULL){printf("Cannot open a file.\n"); exit(1);}
    do
    {
        ch=getchar(); putc(ch,fp);
    }while (ch !='$');
     */
    //  /*
    // DTOS : a program that reads files and displays them on the screen
    if((fp==fopen(argv[1],"r"))==NULL){printf("Cannot open a file.\n"); exit(1);}
    ch=getc(fp);
    while(ch!=EOF)
    {
        putchar(ch);    ch=getc(fp);
    }

       // */
    fclose(fp);
    return 0;
}
