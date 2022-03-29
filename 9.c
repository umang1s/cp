#include<stdio.h>
int main()
{
int h,mh,roll,age,gh,kk;
FILE *f1,*f2;
char grade,name[20],course[10];
float spi,mark,unit,t=0,o=0,g,marks,ll,mn=0,op=0,spii,cpi;
f1=fopen("input.txt","r");
fscanf(f1,"%s%s%d%d%d",name,course,&roll,&age,&gh);
printf("name    :\t%s\ncourse  :\t%s\nage     :\t%d\nroll no :\t%d\n",name,course,age,gh);
for(mh=0; mh<4; mh++)
{
printf("\n\t\t\t\t\t YEAR %d\nsemster:%d\n",mh+1,2*mh+1);
printf("SUBJECT\t\tCREDIT\t\tGRADE\t\t\tSPI\t\t\tCPI");
for(h=0; h<5; h++)
{
fscanf(f1,"%f%s",&unit,&grade);
fprintf("\n   %d  \t\t  %f   \t\t  %s",h+1,unit,grade);
if(grade=='a' || grade=='A') mark=10;
else if (grade=='B' || grade=='b') mark=8;
else if(grade=='c' || grade=='C') mark=6;
else if (grade=='d' || grade=='D') mark=4;
else if(grade=='f' || grade=='F') mark=2;
else{ printf(" you enter wrong entery\n");break;}
g=mark*unit;
t=t+g;
o=o+unit;
}
spi=t/o;
printf("\t\t\t %f\t\t\t%f\n",spi,spi);
printf("semster:%d\n",2*mh+2);
printf("SUBJECT\t\tCREDIT\t\tGRADE\t\t\tSPI\t\t\tCPI");
for(kk=0; kk<5; kk++)
{
fscanf(f1,"%f%s",&unit,&grade);
fprintf("\n   %d  \t\t  %f   \t\t  %s",h+1,unit,grade);
if(grade=='a' || grade=='A') marks=10;
else if (grade=='B' || grade=='b') marks=8;
else if(grade=='c' || grade=='C') marks=6;
else if (grade=='d' || grade=='D') marks=4;
else if(grade=='f' || grade=='F') marks=2;
else{ printf(" you enter wrong entery\n");break;}
ll=mark*unit;
mn+=ll;
op+=unit;
}
spii=mn/op;
cpi=2*(spii+spi);
printf("\t\t\t %f\t\t\t%f\n",spii,cpi);
}
fclose(f1);
}


