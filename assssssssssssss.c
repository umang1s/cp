#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int books=3,student=-1,book=-1,hist=-1;
char book_name[20]="math";
typedef struct Node
{
    int data1,data2;
    char name[20];
    struct Node *next;
}node;
node *records,*library,*line;
void insert_book(int );
void withdrawing_book();
void returning_book();
void books_in_library();
void waiting_students();
void display_records();
void insert_students();
int main()
{
    int i;
    for(i=0; i<books; i++) insert_book(1000+i);
    i=1;
    while(i !=0)
    {
        printf("choose your option\n");
        printf("\t0.exit\n\t1.withdrawing book\n\t2.returning book\n\t3.display books in library\n\t4.display no of students in waiting\n\t5.display records\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: withdrawing_book(); break;
            case 2: returning_book(); break;
            case 3: books_in_library(); break;
            case 4: waiting_students(); break;
            case 5: display_records(); break;
        }

    }
}
void insert_book(int book_id)
{
    int i;
    if(book<books)
    {
        node *new_node,*temp;
        new_node=(node *)malloc(sizeof(node));
        new_node->data1=book_id;
        strcpy(new_node->name,book_name);
        new_node->next=NULL;
        if(book==-1)
        {
            library=new_node;
            free(new_node);
            book++;
        }
        else
        {
            temp=library;
            while(temp->next !=NULL) temp=temp->next;
            temp->next=new_node;
            book++;
        }
    }
    else printf("library full\n");
}
void books_in_library()
{
    printf("book remaining \t\t%d\n",book+1);
    node *temp;
    temp=library;
    while(temp->next !=NULL)
    {
        printf("book name \t%s bookid\t%d",temp->name,temp->data1);
        temp=temp->next;
    }
}
 void inserting_book()
void withdrawing_book()
{
    node *temp,*new_node;
    int i,j;
    new_node=(node *)malloc(sizeof(node));
    printf("enter your name and roll number\n");
    scanf("%s %d",new_node->name,&new_node->data2);
    new_node->next=NULL;
    if(student==-1)
    {
        temp=library;
        while(temp->next !=NULL) temp=temp->next;
        new_node->data1=temp->data1;
        free(temp);
        if(hist==-1)
        {
            history=new_node;
            book--;
        }
        else
        {
            temp=history;
            while(temp->next !=NULL) temp=temp->next;
            temp->next=new_node;
            book--;
        }
    }
    else
    {
        printf("books are empty if any book will be returned than book will be alloted to you\n");
        insert_students();
    }
}
void returning_book()
{
    int i,j;
    node *temp,*new_node,*tmp;
    new_node=(node *)malloc(sizeof(node));
    printf("enter your roll no and book id\n");
    scanf("%d %d",&i,&j);
    if(j<1001+books && j>999)
    {
        temp=history;
        while(temp->data2 !=i) temp=temp->next;
        if(temp->data2 !=i)
        {
            printf("wrong roll number enterd\n");
            returning_book();
        }
        insert_book(j);
    }
    else
    {
        printf("you enterd wrong book id\n");
        returning_book9();
    }
}
insert_students()
{
    int i;
}
void waiting_students()
{
    int j;
}
void display_records()
{
    int k;
}
