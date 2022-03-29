#include<stdio.h>
int main()
{
int h,mh,roll,age,gh;
FILE *f1,*f2;
char grade,name[20],course[10];
float spi,mark,t=0,o=0,unit,g,z=0,cpi,sec,spii,to,mo;
f1=fopen("input.txt","r");
fscanf(f1,"%s%s%d%d%d",name,course,&roll,&age,&gh);
printf("name    :\t%s\ncourse  :\t%s\nage     :\t%d\nroll no :\t%d\n",name,course,age,roll);
for(mh=0; mh<4; mh++)
{
printf("\n\t\t\t\t\t*********YEAR %d**********\n",mh+1);
printf("\t\t\tSUBJECT\t\tGRADE\t\tCREDIT\t\tSPI\t\tCPI\nsemster:%d",2*mh+1);
for(h=0; h<5; h++)
{
fscanf(f1,"%s%f",&grade,&unit);
printf("\n\t\t\t%d\t\t%c\t\t%d\t\t",h+1,grade,(int)unit);
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
printf("%f\t%f\n",spi,spi);
//even semster//
printf("semster:%d\t\t",2*mh+2);
for(h=0; h<5; h++)
{
fscanf(f1,"%f%s",&unit,&grade);
printf("\n\t\t\t%d\t\t%c\t\t%d",h+1,grade,(int)unit);
if(grade=='a' || grade=='A') mark=10;
else if (grade=='B' || grade=='b') mark=8;
else if(grade=='c' || grade=='C') mark=6;
else if (grade=='d' || grade=='D') mark=4;
else if(grade=='f' || grade=='F') mark=2;
else{ printf(" you enter wrong entery\n");break;}
sec=mark*unit;
to+=sec;
mo+=unit;
}
spii=to/mo;
printf("\t\t%f\t%f\n",spii,(spii+spi)/2);
}
fclose(f1);
}


