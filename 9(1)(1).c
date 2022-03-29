#include<stdio.h>
int main()
{
int h,mh,roll,age,gh,kk;
FILE *f1,*f2;
char grade,name[20],course[10];
float spi,mark,unit,t=0,o=0,g,z=0,cpi;
f1=fopen("input.txt","r");
fscanf(f1,"%s%s%d%d%d",name,course,&roll,&age,&gh);
printf("name    :\t%s\ncourse  :\t%s\nage     :\t%d\nroll no :\t%d\n",name,course,age,roll);
for(mh=0; mh<4; mh++)
{
printf("\n\t\t\t\t\t YEAR %d\n",mh+1);
printf("\t\t\tSUBJECT\t\tCREDIT\t\tGRADE\t\tSPI\t\tCPI\nsemster:%d",2*mh+1);
for(h=0; h<5; h++)
{
fscanf(f1,"%f%s",&unit,&grade);
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
z+=spi;
printf("\t\t\t\t\t\t\t\t%f\t%f\n",spi,spi);
//even semster//
printf("semster:%d\t\t",2*mh+2);
for(h=0; h<5; h++)
{
fscanf(f1,"%f%s",&unit,&grade);
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
z+=spi;
printf("\t\t\t\t\t\t%f\t%f\n",spi,z/2); z=0;
}
fclose(f1);
}


