#include<stdio.h>
#include<stdlib.h>
#include<math.h>
typedef struct{
        char name[4];
		char gender;
		int age;
  		}stack_2;
    stack_2 stk2[12];
int stk1[4];

void push_1(int );
void push_2(char [],char,int);
int  top1=-1,top2=-1;

int main()
{
	int i,j,k,d=0;
	char c,s[3];
        float avg_age=0.0;

        FILE *fp_r,*fp_w;

	fp_r=fopen("read.txt","r");
	fp_w=fopen("write.txt","w");



	for(i=0; i<4; i++)
	{
	fscanf(fp_r,"%d",&d);
	push_1(d);

	for(j=0; j<stk1[i]; j++)
	{
        fscanf(fp_r,"%s %c %d" ,s,&c,&d);
	push_2(s,c,d);
	}
	}


for(k=0; k<4; k++)
{
avg_age=0;
      for(i=0;   i<stk1[k]; i++)
      {

	  if(stk2[i].age>d)
             {

             d=stk2[i].age;
             c=stk2[i].gender;
             for(i=0; i<3; i++)
             s[i]=stk2[i].name[i];
             }
	  avg_age=avg_age+stk2[i].age;

      }
     fprintf(fp_w,"AVERAGE AGE OF GENERATION %d=%f\nname of the elder is \n************************************\n",k+1,avg_age/k);
     printf("AVERAGE AGE OF GENERATION %d=%f\n",k+1,avg_age/stk1[k]);

}
	fclose(fp_r);
	fclose(fp_w);
        return 0;

	}

void push_1(int d)
	{
		top1=top1+1;
		stk1[top1]=d;
	}
void push_2(char s[0],char c ,int d)
	{
	    int i;

		top2=top2+1;
		i=0;
		stk2[top2].name[i]=s[i];
		stk2[top2].gender=c;
		stk2[top2].age=d;

	}



