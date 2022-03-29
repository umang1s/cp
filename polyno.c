#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
typedef struct ex   {   char expression[30];    struct exp *next;                               }exp;                exp *input,*output;     //stucture of exression
typedef struct ox   {   char variable;          int constants,power;        struct ox *next;    }components;         components *f1,*f2;     //structure of stored expression
void identify();            void addition();         void display();         void insert_node(components *)  ;  void division();     void multiplication();                                                  //all fuction use in this program
int main()
{
    int i;
    printf("**************************operation on polynomial***************************\n\n\t\t\tmade by ***UMANG MAURYA 2K18***\n\n");
    while(i !=0)
    {
       // printf("\n\t\t1....addtion\n\t\t2....multiplication\n\t\t3....division\n\t\t0....EXIT\n");
        scanf("%d",&i); fflush(stdin);
        char var1[30],var2[30];      f1=NULL;           exp *first_node,*second_node;
        first_node=(exp *)malloc(sizeof(exp));         second_node=(exp *)malloc(sizeof(exp));              //making node
        printf("enter the expression\n");      gets(first_node->expression);   fflush(stdin);          //printing and scanning first expression
        first_node->next=second_node;       second_node->next=NULL;         input=first_node;               //inserting expression in node
        identify(input); identify(input->next); }
        switch(i)
        {
                case 1: addition(); display(); break;
               // case 2: printf("enter the mutipler of divisor expression\n");       gets(second_node->expression); multiplication(); break;
              //  case 3: printf("enter the mutipler of divisor expression\n");       gets(second_node->expression);  division(); break;
        }
        f1=NULL; input=NULL; output=NULL; f2=NULL;
    }
}
void identify(exp *temp)
{
    int i,length=0,part=0,m3,var,m5,m6,m8=0,p1,p2,c1,c2,mp1,par=45,c3;
    components *new_node;
    char first[100],exp1[100];
    strcpy(exp1,temp->expression);
    for(i=0; i<strlen(exp1); i++)   if(exp1[i] !='^' && exp1[i] !='*' && exp1[i] !='(' && exp1[i] !=')') {first[length]=exp1[i]; length++;}
    for(i=0; i<length; i++) if(first[i]==' ' && first[i+2]==' ')    if(first[i+1]=='+' || first[i+1]=='-')
    {
        for(m3=part; m3<i; m3++) if(first[m3]>='a' && first[m3]<='z' || first[m3]>='A' && first[m3]<='Z') var=m3;
        {
            new_node=(components *)malloc(sizeof(components));
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
            new_node->next=NULL;
            insert_node(new_node);
            part=i+3; m8=i+1;
        }
    }
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
            new_node->constants=c3;     new_node->variable='$';     new_node->power=1;      new_node->next=NULL;        insert_node(new_node);
        }
        else
        {
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
            new_node->next=NULL;
            insert_node(new_node);
        }
    }
}
void addition()
{
    components *temp,*ptr,*tmp,*bac;
    temp=f1;
    while(temp->next !=NULL)
    {
        tmp=temp->next; bac=temp;
        while(tmp !=NULL)
        {
            if(temp->variable==tmp->variable && temp->power==tmp->power)
            {
                temp->constants+=tmp->constants;
                if(tmp->next !=NULL) {ptr=tmp->next;   bac->next=ptr;   }
                if(tmp->next==NULL) {bac->next=NULL;    }
                free(tmp); tmp=bac;
            }
            else    bac=bac->next;
            tmp=tmp->next;
        }
       if(temp->next !=NULL) temp=temp->next;
    }
}
void display()
{
    int i=0,j; char answer[100];
    components *temp;   temp=f1;
    FILE *read,*write;
    write=fopen("blablabla.txt","w");
    if(temp->constants !=1 && temp->constants !=0) fprintf(write,"%d",temp->constants);
    if(temp->constants !=0 && temp->variable !='$')
    {
        fprintf(write,"%c",temp->variable);
        if(temp->power !=1) fprintf(write,"^(%d)",temp->power);
    }
    temp=temp->next;
    if(temp !=NULL)while(temp !=NULL)
    {
        if(temp->constants >1)  fprintf(write," + %d",temp->constants);
        else if(temp->constants < 0) fprintf(write," - %d",-1*temp->constants);
        else if(temp->constants==1) fprintf(write," + ");
        if(temp->constants!=0 && temp->variable !='$')
        {
           fprintf(write,"%c",temp->variable);
           if(temp->power !=1)  fprintf(write,"^(%d)",temp->power);
        }
        temp=temp->next;
    }
    fclose(write);
    read=fopen("blablabla.txt","r");
    fscanf(read,"%[^\n]",answer);
    fclose(read);
    printf("\tANSWER <<< %s >>>\n\n",answer);

}
void insert_node(components *node)
{
    components *temp;
    if(f1==NULL) { f1=node; f1->next=NULL;  }
    else{temp = f1; while(temp->next !=NULL) temp=temp->next; temp->next=node;  temp->next->next=NULL;}
}
void multiplication()
{
    printf("this operation is not avaible now\n");
}
void division()
{
    printf("this operation is not avaible now\n");
}
