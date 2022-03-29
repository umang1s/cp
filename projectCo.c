#include<stdio.h>
#include<stdlib.h>
int verification();
void block_A();
void block_B();
void block_C();
void aim();
void work_progress()
{
    int i,j,k,l;
    j=100; k=10; l=10;
    printf("**B**<---------5 to %d-------->",j);
    printf("**A**<---------0 to %d-------->",k);
    printf("**C**<---------0 to %d-------->",l);
    printf("**CITY**--------->0 to 10-------->\n");
    while(i !=0)
    {
        printf("choose one option\n1.block A\t2.block B\t3.block C\t4.aim\t0.EXIT\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: block_A(); break; case 2: block_B(); break; case 3: block_C(); break; case 4: aim(); break;
        }
    }
}
int main()
{
    int i,j=0;
    printf("\n\t\t*******************************< FCP >*********************************");
    while(j !=5)
    {
        i=verification(); j++;
        if(i==9589) {work_progress(); return 0; }
        else printf("\nWRONG USERNAME OR PASSWORD");
    }
}
int verification()
{
    int i,j,k;
    printf("\nUsername: ");
    scanf("%d",&i);
    printf("Password: ");
    scanf("%d",&j);
    if(i==2019 && j==34567890) return(9589);
    return 0;
}
void block_A()
{
    char  fil[10000];
    FILE *a;
    a=fopen("blockA.txt","r");
    fscanf(a,"%[^\n]",fil);
    printf("\n\t\t************BLOCK A ************\n%s\n",fil);
}
void block_B()
{
    char  fil[10000];
    FILE *a;
    a=fopen("blockB.txt","r");
    fscanf(a,"%[^\n]",fil);
    printf("\n\t\t************BLOCK B ************\n%s\n",fil);
}
void block_C()
{
    char  fil[10000];
    FILE *a;
    a=fopen("blockC.txt","r");
    fscanf(a,"%[^\n]",fil);
    printf("\n\t\t************BLOCK C ************\n%s\n",fil);
}
void aim()
{
    char  fil[10000];
    FILE *a;
    a=fopen("aim.txt","r");
    fscanf(a,"%[^\n]",fil);
    printf("\n\t\t************AIM ************\n%s\n",fil);
}
