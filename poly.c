#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int f11=0,f22=0,f33=0;
typedef struct ex   {   char expression[30];    struct exp *next;                               }exp;                exp *input,*output;     //stucture of exression
typedef struct ox   {   char variable;          int constants,power;        struct ox *next;    }components;         components *f1,*f2;     //structure of stored expression
void identify();            void addition();            void display();            void insert_node(components *,int )  ;                                                        //all fuction use in this program
int main()
{
    char var1[30],var2[30];      f1=NULL;           exp *first_node,*second_node;
    first_node=(exp *)malloc(sizeof(exp));         second_node=(exp *)malloc(sizeof(exp));              //making node
    printf("enter the first expression in term of x\n");      gets(first_node->expression);             //printing and scanning first expression
    printf("enter the second expression in term of x\n");       gets(second_node->expression);          //printing and scanning second expression
    first_node->next=second_node;       second_node->next=NULL;         input=first_node;               //inserting expression in node
    identify();
}
void identify()
{
    int i,length=0,part=0,m3,var,m5,m6,m8=0,p1,p2,c1,c2,mp1,par=45,c3;
    exp *temp,*tmp;         temp=input;         tmp=temp->next;
    components *new_node;
    char first[100],second[100],exp1[100],exp2[100];
    strcpy(exp1,temp->expression);      strcpy(exp2,tmp->expression);
    for(i=0; i<strlen(exp1); i++)   if(exp1[i] !='^' && exp1[i] !='*' && exp1[i] !='(' && exp1[i] !=')') {first[length]=exp1[i]; length++;}
    for(i=0; i<length; i++) if(first[i]==' ' && first[i+2]==' ')    if(first[i+1]=='+' || first[i+1]=='-')
    {
        new_node=(components *)malloc(sizeof(components));
        for(m3=part; m3<i; m3++) if(first[m3]>='a' && first[m3]<='z' || first[m3]>='A' && first[m3]<='Z') var=m3;        //variable solving
        new_node->variable=first[var];
        if(first[var+1]=='+' || first[var+1]=='-')                                        // solving power
        {
            m6=1; mp1=1; p1=0;
            for(m5=var+2; m5<i; m5++)
            {
                p1+=(first[i-m6]-48)*mp1;
                mp1=mp1*10;
                m6++;
            } if(m6==1) p1=1;
            if(first[var+1]=='-') p1=-1*p1;
            new_node->power=p1;
        }
        else
        {
            m6=1; mp1=1; p2=0;
            for(m5=var+1; m5<i; m5++)
            {
                p2+=(first[i-m6]-48)*mp1;
                mp1=mp1*10;
                m6++;
            } if(m6 == 1) p2=1;
            new_node->power=p2;
        }
        if(first[part]=='+' || first[part]=='-')                                                    //solving constants
        {
            m6=1; mp1=1; c1=0;
            for(m5=part+1; m5<var; m5++)
            {
                c1+=(first[var-m6]-48)*mp1;
                mp1=mp1*10;
                m6++;
            } if(m6==1) c1=1;
            if(first[part]=='-') c1*=-1;
            new_node->constants=c1;
        }
        else
        {
            m6=1; mp1=1; c2=0;
            for(m5=part; m5<var; m5++)
            {
                c2+=(first[var-m6]-48)*mp1;
                mp1=mp1*10;
                m6++;
            } if(m6==1) c2=1;
            if(first[m8]=='-')c2*=-1;
            new_node->constants=c2;
        }
        insert_node(new_node,1);
        part=i+3; m8=i+1;
    }
    free(new_node);
    if(first[part] !=NULL)
    {
        new_node=(components *)malloc(sizeof(components));
        for(m3=part; m3<i; m3++) if(first[m3]>='a' && first[m3]<='z' || first[m3]>='A' && first[m3]<='Z') par=m3;
        new_node->variable=first[par];
        if(par==45)
        {
            m6=1; mp1=1; c3=0;
            for(m5=part; m5<i; m5++)
            {
                c3+=(first[i-m6]-48)*mp1;
                mp1=mp1*10;
                m6++;
            } if(m6==1) c3=1;
            if(first[m8]=='-') c3*=-1;
            new_node->constants=c3;
            new_node->variable='$';
            new_node->power=1;
            new_node->next=NULL;
            insert_node(new_node,1);
        }
        else{
            if(first[par+1]=='+' || first[par+1]=='-')                                        // solving power
            {
                m6=1; mp1=1; p1=0;
                for(m5=par+2; m5<i; m5++)
                {
                    p1+=(first[i-m6]-48)*mp1;
                    mp1=mp1*10;
                    m6++;
                } if(m6==1) p1=1;
                if(first[par+1]=='-') p1=-1*p1;
                new_node->power=p1;
            }
            else
            {
                m6=1; mp1=1; p2=0;
                for(m5=par+1; m5<i; m5++)
                {
                    p2+=(first[i-m6]-48)*mp1;
                    mp1=mp1*10;
                    m6++;
                } if(m6 == 1) p2=1;
                new_node->power=p2;
            }
            m6=1; mp1=1; c2=0;
            for(m5=part; m5<par; m5++)
            {
                c2+=(first[par-m6]-48)*mp1;
                mp1=mp1*10;
                m6++;
            } if(m6==1) c2=1;
            if(first[m8]=='-')c2*=-1;
            new_node->constants=c2;
            insert_node(new_node,1);
        }
    }
}
void addition()
{
    int i,j,k;
    components *temp,*ptr,*tmp,*temp1,*temp2,*tmp1,*tmp2,*ptr1,*ptr2,*ptr3;
    temp=f1;
    for(i=1; i<f11; i++) for(j=0; j<f11-i; j++)//first comparision
    {
        tmp=temp->next;
        if(temp->variable==tmp->variable && temp->power==tmp->power)
        {
            temp->constants+=tmp->constants;
            if(tmp->next !=NULL) {ptr=tmp->next;   temp->next=ptr;}
            free(tmp);
            f11--;
        }
       if(i !=f11-1) temp=temp->next;
    }
    temp1=f2;
    for(i=0; i<f22; i++) for(j=0; j<f22-i; j++)//second comparision
    {
        tmp1=temp1->next;
        if(temp1->variable==tmp1->variable && temp1->power==tmp1->power)
        {
            temp1->constants+=tmp1->constants;
            if(tmp1->next !=NULL) {ptr1=tmp1->next;   temp1->next=ptr1;}
            free(tmp1);
            f22--;
        }
        if(i !=f22)temp1=temp1->next;
    }
    temp2=f1;
    tmp2=f2;
    for(i=0; i<=f11; i++) //addition of first and second
    {
        if(temp2->variable==tmp2->variable && temp2->power==tmp2->power)
        {
            temp2->constants+=tmp2->constants;
            if(tmp2->next !=NULL) {ptr2=tmp2->next; temp2->next=ptr2;}
            free(tmp2);
            f22--;
        }
        if(i !=f11) temp2=temp2->next;
        if(i == f11)if(tmp->next !=NULL) f1->next=f2;
    }
}
void display()
{
    int i=0;
    components *temp;
  /*  FILE *read,*write;
    output=(exp *)malloc(sizeof(exp));
    write=fopen("temp.txt","w");
    read=fopen("temp.txt","r");
    temp=f1;
    while(temp->next !=NULL)
    {
        fprintf(write,"%d%c^%d ",temp->constants,temp->variable,temp->power);
        temp=temp->next;
    }
    fprintf(write,"%d%c^%d ",temp->constants,temp->variable,temp->power);
    fclose(write);
    fscanf(read,"%[^\n]",output->expression);
    fclose(read);
    output->next=NULL;
    printf("%s",output->expression); */
    temp=f1;
    while(temp->next !=NULL)
    {
        printf("1.%d*%c^%d\n",temp->constants,temp->variable,temp->power);
        temp=temp->next;
    }
     printf("2.%d*%c^%d",temp->constants,temp->variable,temp->power);
}
void insert_node(components *node ,int k)
{
    printf("%d\t%c\t%d\n",node->constants,node->variable,node->power);
    node->next=NULL;
    components *temp;
    if(k==1)
    {
        if(f11==0)      {       f1=node; f11++;  }
        else{temp = f1; while(temp->next !=NULL) temp=temp->next; temp->next=node; f11++;}
    }
    else
    {
        if(f22==0)      {       f2=node;  f22++;    }
        else{temp=f2;   while(temp->next !=NULL) temp=temp->next; temp->next=node; f22++;}
    }
}
