//  using feof  03jan20
#include<stdio.h>
#include<stdlib.h>
int main(int argc,char *argv[])
{
    // parameter    int feof(FILE *fp);
    //  while(!feof(fp)) ch=getc(fp);
    FILE *in,*out;
    char ch;
    if(argc!=3){printf("you forgot to enter a filename\n"); exit(1);}
    if((in=fopen(argv[1],"wb"))==NULL)
    {
        printf("Cannot open destination file.\n");  exit(1);
    }
    while(!feof(in))
    {
        ch = getc(in);
        if(!feof(in)) putc(ch,out);
    }
    fclose(in);
    fclose(out);
    return 0;
}

