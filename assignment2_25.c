#include<stdio.h>
#include<stdlib.h>
float average[5];
int tap=-1;
struct gen{
        int member;
        char gener[5];
};
struct person{
        char name[10];
        char gender;
        float age;
};

push2(float avg_age)
{
    tap+=1;
    average[tap]=avg_age;
}
display()
{
    int a;
    for(a=0; a<tap+1; a++)
    {
        printf("average age is %f\n",average[a]);
    }
}
int main()
{
        struct gen p1[4];
        struct person p2[5];
        int i,j,k,large_age;
        float age_sum,avg_age;
        char eld[10];
        FILE *fpi,*fpo;
        fpi=fopen("inputfile.txt","r");
        fpo=fopen("outputfile.txt","w");
        while(!feof(fpi))
{
    for(i=0;i<4;i++)
{
    age_sum=0;
    fscanf(fpi,"%s %d\n",p1[i].gener,&p1[i].member);
    for(j=0;j<p1[i].member;j++)
{
        fscanf(fpi,"%s %c %f\n",p2[j].name,&p2[j].gender,&p2[j].age);
            age_sum+=p2[j].age;
            if(j==0) strcpy(eld,p2[j].name);
            if(j==p1[i].member-1) {
            avg_age=age_sum/p1[i].member;
            printf("\taverage age for %s is %f\n",p1[i].gener,avg_age);
            push2(avg_age);
            printf("\tThe oldest person in %s is %s \n",p1[i].gener,eld);
            printf("\n\t********************************\n\n");
            fprintf(fpo,"\taverage age for %s is %f\n",p1[i].gener,avg_age);
            fprintf(fpo,"\tThe oldest person in %s is %s \n",p1[i].gener,eld);
            fprintf(fpo,"\n\t********************************\n\n");
        }
}
}
}
fclose(fpi);


}
