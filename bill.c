#include<stdio.h>
#include<stdlib.h>                                //  statement loan encrypt decrypt end_bill
#include<string.h>
typedef struct bus
{
    int bal,s_no,ammount;
    char reason[40],date[20],sign,mark;
    struct bus *next;
}paper;
paper *bill;    int pin=1234;
void bill_open()
{
    paper *temp,*new_node;    FILE *read;     read=fopen("bill.txt","r");   int i=0,j=0,k,l,o,p=0,q,r=0,mul=1,add=0,che;
    char decoded[10000],encoded[10000],b=-126; fscanf(read,"%d %[^\n]",&che,decoded); fclose(read);
    if(che==1)  {
    for(l=0; l<strlen(decoded); l++){   if(l%2==0) encoded[l]=decoded[l]+3;     else encoded[l]=decoded[l]-6; }
    for(k=0; k<l; k++)
    {
        if(encoded[k]==b && encoded[k+1]==b && encoded[k+2]==b  &&  encoded[k+3]==b)
        {
            new_node=(paper *)malloc(sizeof(paper)); temp=bill;
            for(o=i; o<k; o++)
            {
                if(encoded[o]==b && encoded[o+1]==b)
                {
                    if(j==0)        {for(q=r; q<o; q++) {add+=mul*(encoded[q]-48); mul*=10;} new_node->s_no=add; j++;}
                    else if(j==1)   {for(q=r; q<o; q++) {add+=mul*(encoded[q]-48); mul*=10;} new_node->ammount=add; j++;}
                    else if(j==2)   {for(q=r; q<o; q++) {add+=mul*(encoded[q]-48); mul*=10;} new_node->bal=add; j++; }
                    else if(j==3)   {for(q=r; q<o; q++ && p++) new_node->date[p]=encoded[q]; j++;  }
                    else if(j==4)   {new_node->sign=encoded[o-2]; new_node->mark=encoded[o-1]; j++; }
                    else if(j==5)   {for(q=r; q<o; q++ && p++) new_node->reason[p]=encoded[q]; j++;}
                    r=o+2;  p=0;    mul=1;  add=0   ; new_node->next=NULL;
                }
            }
            i=k+5; j=0; if(temp==NULL) bill=new_node; else {while(temp->next !=NULL) temp=temp->next; temp->next=new_node; }
        }
    }
    for(k=i-1; k<l-2; k++){add+=(encoded[k]-48)*mul; mul*=10;}
    pin=add;
    } else printf("Sorry sir ! \tHistory not founds default password >>>>1234<<<<\n");
}
void bill_close()
{
    paper *temp;    FILE *write;  int i=0,j,k,l,che=1;    write=fopen("bill.txt","w");
    char encoded[10000],decoded[10000],b=-126;  temp=bill;
    while(temp !=NULL)
    {
        j=temp->s_no; if(j>9){encoded[i]=j/10 + 48; i++;} encoded[i]=j + 48; i++; encoded[i]=b; i++; encoded[i]=b; i++;
        j=temp->ammount; while(j>9) {encoded[i]=j%10 +48; i++; j/=10;}
        encoded[i]=j + 48; i++; encoded[i]=b; i++; encoded[i]=b; i++;
        j=temp->bal; while(j>9){encoded[i]=j%10 +48; i++; j/=10;}
        encoded[i]=j + 48; i++; encoded[i]=b; i++; encoded[i]=b; i++;
        for(k=0; k<strlen(temp->date); k++) {encoded[i]=temp->date[k]; i++;}    encoded[i]=b; i++; encoded[i]=b; i++;
        encoded[i]=temp->sign; i++; encoded[i]=temp->mark; i++;   encoded[i]=b; i++; encoded[i]=b; i++;
        for(k=0; k<strlen(temp->reason); k++) {encoded[i]=temp->reason[k]; i++;}    encoded[i]=b; i++; encoded[i]=b; i++;   encoded[i]=b; i++; encoded[i]=b; i++;
        temp=temp->next;
    }
    j=pin; while(j>9)   {encoded[i]=j%10 +48; i++; j/=10;}
    encoded[i]=j + 48; i++; encoded[i]=b; i++; encoded[i]=b; i++; fprintf(write,"%d\n",che);
    for(l=0; l<i; l++){   if(l%2==0) decoded[l]=encoded[l]-3;     else decoded[l]=encoded[l]+6;   fprintf(write,"%c",decoded[l]);}
    fclose(write);
}
void take_loan()
{
    paper *temp,*new_node; new_node=(paper *)malloc(sizeof(paper)); temp=bill; if(temp !=NULL)while(temp->next !=NULL) temp=temp->next;
    printf("enter amount\t"); scanf("%d",&new_node->ammount);   fflush(stdin);
    printf("enter date\t"); gets(new_node->date);   fflush(stdin);
    printf("enter name\t"); gets(new_node->reason);
    new_node->next=NULL; new_node->sign='+'; new_node->mark='L'; new_node->bal=temp->bal+new_node->ammount;
    temp->next=new_node;    printf("\n****You have taken %d Rs. successfully from %s\n",new_node->ammount,new_node->reason);
}
void give_loan()
{
    paper *temp,*new_node; new_node=(paper *)malloc(sizeof(paper)); temp=bill; if(temp !=NULL)while(temp->next !=NULL) temp=temp->next;
    printf("enter amount\t"); scanf("%d",&new_node->ammount);   fflush(stdin);
    if(temp->bal >= new_node->ammount)
    {
        printf("enter date\t"); gets(new_node->date);   fflush(stdin);
        printf("enter name\t"); gets(new_node->reason);
        new_node->next=NULL; new_node->sign='-'; new_node->mark='L'; new_node->bal=temp->bal-new_node->ammount;
        temp->next=new_node;    printf("\n****Your money %d Rs. successfully given to %s\n",new_node->ammount,new_node->reason);
    }
    else printf("Sorry Sir !\tyou don't have %d Rs less money\n",new_node->ammount-temp->bal);
}
void loan()
{
    paper *temp;  int i=1,j; system("cls");
    temp=bill;if(temp !=NULL) printf("S.N\tDate\tammount\tbal\tto/from\n");
    while(temp !=NULL)
    {
        if(temp->mark=='L') {printf("%d\t%s\t%c%d\t%d\t%s\n",i,temp->date,temp->sign,temp->ammount,temp->bal,temp->reason); i++;}
        temp=temp->next;
    }
    if(i==1)    printf("there is no loan statement\n");
    while(j !=0)
    {
        printf("\t\t1..Give Loan\n\t\t2..Take Loan\n\t\t0..Exit\n");
        scanf("%d",&j);
        if(j==1) give_loan();  if(j==2) take_loan();  if(j==2 || j==1){ bill_close(); return;   }
    }
}
void statement()
{
    system("cls");
    paper *temp;    temp=bill;
    printf("\nS.N\tDATE\tammount\tbalance\treason\n");
    while(temp !=NULL)
    {
        printf("%d\t%s\t%c%d\t%d\t%s\n",temp->s_no,temp->date,temp->sign,temp->ammount,temp->bal,temp->reason);
        temp=temp->next;
    }
}
int balance()
{
    paper *temp;    int bal;        temp=bill;
    if(temp ==NULL) bal=0;
    else  {  while(temp->next !=NULL) temp=temp->next;  bal=temp->bal;      }
    return bal;
}
void debit()
{
    system("cls");
    paper *new_node,*temp;      new_node=(paper *)malloc(sizeof(paper));    temp=bill;
    if(temp==NULL)       printf("**Sorry Sir !\tyou don't have money**\n");
    else
    {
        printf("Ammount\t");      scanf("%d",&new_node->ammount);   fflush(stdin);  while(temp->next !=NULL) temp=temp->next;  if(new_node->ammount <= temp->bal)   {
        printf("\nDate\t");         gets(new_node->date);
        printf("\nReason\t");       gets(new_node->reason); fflush(stdin); printf("\n");    new_node->next=NULL;    new_node->sign='-'; new_node->mark='N';
        new_node->s_no=temp->s_no+1;      new_node->bal=temp->bal - new_node->ammount; temp->next=new_node;
        printf("**Your account has been debited %d Rs.**\n",new_node->ammount); bill_close(); }
        else printf("Sorry Sir !\tyou don't have %d Rs less money\n",new_node->ammount-temp->bal);
    }
}
void credit()
{
    system("cls"); char r[20]="income";
    paper *new_node,*temp;      new_node=(paper *)malloc(sizeof(paper));
    printf("***enter ammount to add\t");       scanf("%d",&new_node->ammount);
    printf("\nDate\t");   fflush(stdin);       gets(new_node->date);    strcpy(new_node->reason,r);
    new_node->next=NULL;      temp=bill;    new_node->sign='+'; new_node->mark='N';
    if(temp==NULL)  {   new_node->bal=new_node->ammount;    new_node->s_no=1;   bill=new_node;}
    else    {   while(temp->next !=NULL) temp=temp->next; new_node->bal=new_node->ammount+temp->bal;    new_node->s_no=temp->s_no+1;    temp->next=new_node;    }
    printf("\n**your account has been credited %d Rs.**\n",new_node->ammount);  bill_close();
}
void change_pin()
{
    int k,l,m;
    printf("***enter old pin***\t"); scanf("%d",&k);
    if(k==pin)
    {
        printf("\n***enter new pin***\t"); scanf("%d",&l);
        printf("\n***enter pin again***\t"); scanf("%d",&m);
        if(l==m)    {   pin=l;  printf("\nyour  pin has successfully updated\n");   }
        else printf("\n pin not matched\n");
    }
    else      printf("\nwrong pin enterd\n")   ;    bill_close();
}
int main()
{
    int i,j,k,l=0,m;    printf("*********Welcome to bill**********\n"); bill_open();
    for(m=5; m>0; m--)  if(l !=1)    { if(m !=5) printf("wrong pin !\tyou have %d attemp left\n",m); printf("enter pin\t"); scanf("%d",&k); printf("\n"); if(k==pin) l=1;    }
    if(l=1){
    while(i !=0)
    {
        j=balance();
        printf("\nAvl bal..%d Rs.\n\t\t1..Withdrawing Money\n\t\t2..Deposite money\n\t\t3..Bill Statement\n\t\t4..Loan Transection\n\t\t5..change pin\n\t\t0.EXIT\n",j);
        scanf("%d",&i);
        switch(i)   {   case 1: debit(); break;     case 2: credit(); break;    case 3: statement(); break;     case 4: loan(); break; case 5: change_pin(); break; }
    }   }
}
