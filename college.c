#include<stdio.h>
#include<string.h>
int schoolLocation()
{
    char state[29][30],district[29][75][30];
    char scanning[1000][30];
    int State[29],s1,s2,total,s3;
    FILE *read;
    read=fopen("area.txt","r");
    fscanf(read,"%d",&total);
    for(int i=0; i<total; i++) fscanf(read,"%s",scanning[i]);
    fclose(read);
    s1=s2=s3=0;
    //for(int i=0; i<total; i++) printf("%s\n",scanning[i]);
    for(int i=0; i<total; i++)
    {
       if(scanning[i][0]=='*' && scanning[i][1]=='*') {State[s2++]=s3; s3=0;  s1=0;}
       else
       {
           if(s1==0)   {strcpy(state[s2],scanning[i]); s1++;}
           else  {strcpy(district[s2][s3],scanning[i]); s3++;}
       }
    }
    printf("Please select your state\n");
    for(int i=0; i<29; i++) {if(i%3==0 ) printf("\n");  printf("%d\t%s\t",i+1,state[i]); }
    scanf("%d",&s1);
    printf("Please select your district it has %d district\n",State[s1-1]);
    for(int j=0; j<State[s1-1]; j++) {if(j%3==0) printf("\n"); printf("\t%d\t%s\t\t",j+1,district[s1-1][j]); }
    scanf("%d",&s2);
    system("cls");
    return s1*100 + s2;
}
void gotoStu()
{
    int ID[100],num;
    char Password[30][100];
    FILE *data;
    data=fopen("login.txt","r");
    fscanf(data,"%d",&num);
    for(int i=0; i<num; i++) fscanf(data,"%d %s",&ID[i],Password[i]);
    fclose(data);
    printf("*********************************************Students");
    printf("*********************************************\n");
    int x=3;
    while(x!=2){
        printf("Please enter your ID :  ");
        scanf("%d",&ID);
        printf("Please enter your Passwords if you forgot password please enter 1:  ");
        scanf("%s",Password);
    }




}
void gotoTea(){
    printf("*********************************************Teachers");
    printf("*********************************************\n");
}
void gotoPri(){
    printf("*********************************************Principal");
    printf("*********************************************\n");
}
int main()
{
    int x=5,l;
    while(x!=0){
        printf("\nPlease choose one option\n\t\t1..Students\n\t\t2..Teachers\n\t\t3..Principal\n");
        scanf("%d",&x);
        if(x==1) gotoStu();
        else if(x==2) gotoTea();
        else if(x==3) gotoPri();
        printf("\n\n%d\n\n",schoolLocation());
    }
}
