#include<stdio.h>
#include<string.h>
int top=-1,tap=-1;
char older_name[5];
float older_age[5];
push1(float avge)
{
    top+=1;
    older_age[top]=avge;

}
push2(char old[10])
{
    tap+=1;
    old=older_name[tap];
}
display()
{
    int a;
    for(a=1; a<5; a++)
    {
    FILE *f3;
    f3=fopen("outt.txt","w");
    fprintf(f3,"\naverage age of gen%d: %f\nthe oldest age person of gen%d: %s\n......................................................\n",a,older_age[a-1],a,older_name[a-1]);
    fclose(f3);
    }
}
main()
{
    int  person , a,b,nn;
    float avge,age;
    char name[10],gen[10],gender,old[10];
    FILE *f1,*f2;
    f1=fopen("in.txt","r");
    f2=fopen("out.txt","w");
    for(b=1;b<=4; b++)
    {
        nn=0;
        fscanf(f1,"%s%d",gen,&person);
        for(a=1; a<=person; a++)
        {
            fscanf(f1,"%s%s%f",name,&gender,&age);
            if(a==1) strcpy(old,name) ;
            push2(old);
            nn+=age;
            if(a==person)
                {
                    avge=nn/person;
                    push1(avge);
                    fprintf(f2,"\naverage age of gen%d: %f\nthe oldest age person of gen%d: %s\n......................................................\n",b,avge,b,old);
                    printf("\naverage age of gen%d: %f\nthe oldest age person of gen%d: %s\n......................................................\n",b,avge,b,old);

                }
        }
    }
    fclose(f2);
    fclose(f1);
    display();
}


