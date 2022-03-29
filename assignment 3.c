#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include<stdlib.h>
int books=3,students=5,o=1;
char Book_name[20]="math";
typedef struct NODE
{
    int data;
    char name[20];
    struct NODE *next;
}node;
typedef struct STUDENT
{
    int book_id,roll_no;
    char student_name[20];
     struct stud *next;
}queue;
node *library;
queue *students_all,*history;
void inserting_book();
void withdrawing_book();
void remaining_book();
void remaining_students_in_waiting();
void making_library();
char name_in_capital(char student[20]);
void deleting_name();
int main()
{
    int option;
    making_library();
    while(option !=0)
    {
        printf("\n\t\t0...EXIT\n\t\t1...Inserting Book\n\t\t2...Withdrawing Book\n");
        printf("\t\t3...Checking Book in Library\n\t\t4...Checking Students in Waiting\n");
        scanf("%d",&option);
        switch(option)
        {
            case 1: inserting_book(); break;
            case 2: withdrawing_book(); break;
            case 3: remaining_book(); break;
            case 4: remaining_students_in_waiting(); break;
        }
    }
}
void making_library()
{
    int i=0;
    node *new_node,*ptr;
    while(i !=books)
    {

        if(i==0)
        {
            library=(node *)malloc(sizeof(node));
            library->data=1000;
            strcpy(library->name,Book_name);
            library->next= NULL;
            i++;
        }
        else
        {
            ptr=library;
            new_node = (node*)malloc(sizeof(node));
            new_node -> data=1000+i;
            new_node->next=NULL;
            strcpy(new_node->name,Book_name);
            while(ptr->next !=NULL) ptr=ptr->next;
            ptr->next=new_node;
            i++;
        }
    }
}
inserting_book()
{
    int i,j,k;
    char student_name[20];
    printf("enter your book id\n");
    scanf("%d",&i);
    printf("enter your name\n");
    scanf("%s",student_name);
 /*   if(stored_name==name_in_capital(student_name) && stored_id==i)
    {
        printf("insert\n");
    }
    else printf("sorry this student was not barrowed book from library \n"); */
    check_in();
}
withdrawing_book()
{
    int i,j,k;
    char name_student[20];
    queue *new_node,*ptr;
    node *temp,*pre_temp;
    new_node=(queue *)malloc(sizeof(queue));
    temp=(node *)malloc(sizeof(node));
    printf("enter your name\troll no\t\n");
    scanf("%s %d",name_student,&k);
    new_node->roll_no=k;
    strcpy(new_node->student_name,name_student);
    new_node->next=NULL;
    if(library == NULL)
    {
        printf("all books are given if any book will be returned than you can withdraw\n");
       if(o==1)
       {
            students_all=new_node;
            free(new_node);
       }
       else
       {
            ptr=students_all;
            while(ptr->next !=NULL)
            {
                ptr=ptr->next;
            }
            ptr->next=new_node;
            students_all=ptr;
            free(ptr);
       }

    }
    else
    {
       if(students_all == NULL)
       {

            temp=library;
            while(temp->next->next !=NULL) temp=temp->next;
            new_node->book_id=temp->next->data;
            pre_temp=temp->next;
            pre_temp->next=NULL;
            free(temp);
            history=new_node;
       }
    }
    o++;
}
check_in()
{
printf("you are now in check in function\n");
}
void remaining_book()
{
    node *str;
    int i=1,j;
    str=library;
    printf("\t\t1.only remaining book\n\t\t2.remaining book with name and id\n");
    scanf("%d",&j);
    while(str !=NULL)
    {
        if(j==2) printf("\t\t%d\t%s\t%d\n",i,str->name,str->data);
        str=str->next;
        i++;
    }
   if(j==1) printf("%d\n",i-1);
}
void remaining_students_in_waiting()
{
    printf("you are in remaining students in waiting function\n");
}
char name_in_capital(char student[20])
{
    int i;
    char capital[20];
    for(i=0; i<strlen(student); i++)
    {
        if(student[i]>='a' && student[i]<='z')
            capital[i]=student[i]+32;
        else capital[i]=student[i];
    }
    return(capital[20]);
}
void deleting_name()
{
    printf("you are now deleting function\n");
}
