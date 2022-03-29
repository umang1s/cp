 #include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
#include<string.h>
int books=3,max_withdrawal=40,student=-1,book=-1,hist=-1,wit=0;
char book_name[20]="math",returned[20]="book_returned";
typedef struct Node
{
    int data1,data2;
    char name[20];
    struct Node *next;
}node;
node *history,*library,*line;
void insert_book(int );
void withdrawing_book();
void returning_book();
void books_in_library();
void waiting_students();
void display_history();
void allotting_book_to_waiting(int , char o[20]);
void insert_students(int ,char n[20]);
int main()
{
    int i;
    for(i=0; i<books; i++) insert_book(1000+i);
    i=1;
    while(i !=0)
    {
        printf("\nchoose your option\n");
        printf("\t\t\t0.EXIT\n\t\t\t1.Withdrawing book\n\t\t\t2.Returning book\n\t\t\t3.Display books in library\n\t\t\t4.Display no of students in waiting\n\t\t\t5.Display records\n");
        scanf("%d",&i);
        if(book<-1) book=-1;
        if(hist<-1) hist=-1;
        if(student<-1) student=-1;
        switch(i)
        {
            case 1: withdrawing_book(); break;
            case 2: returning_book(); break;
            case 3: books_in_library(); break;
            case 4: waiting_students(); break;
            case 5: display_history(); break;
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
    printf("remaining books\t\t%d\n",book+1);
    if(book>-1)
    {
        node *temp;
        temp=library;
        while(temp->next !=NULL)
        {
            printf("book name %s\t bookid\t%d\n",temp->name,temp->data1);
            temp=temp->next;
        }
        printf("book name %s\t bookid\t%d\n",temp->name,temp->data1);
    }
}
 void withdrawing_book()
{
    node *temp,*new_node,*tmp;
    int i,j;
    char name1[20];
    if(book<-1) book=-1;
    if(hist<-1) hist=-1;
    if(student<-1) student=-1;
    new_node=(node *)malloc(sizeof(node));
    printf("enter your name and roll number\n");
    scanf("%s %d",name1,&i);
    strcpy(new_node->name,name1);
    new_node->data2=i;
    new_node->next=NULL;
    if(student==-1 && book !=-1)
    {
        temp=library;
        while(temp->next !=NULL)
        {
            tmp=temp;
            temp=temp->next;
        }
        new_node->data1=temp->data1;
        printf("\t\t\t\t\talloted book name \t%s\n\t\t\t\t\tbook id \t\t%d\n",book_name,new_node->data1);
        if(book !=0) tmp->next=NULL;
        free(temp);
        if(hist==-1)
        {
            history=new_node;
            book--;
            hist++;
        }
        else
        {
            temp=history;
            while(temp->next !=NULL)
            {
                temp=temp->next;
            }
            temp->next=new_node;
            book--;
            hist++;
        }
    }
    else
    {
        printf("books are empty if any book will be returned than book will be alloted to you\n");
        insert_students(i,name1);
    }
    if(book<-1) book=-1;
    if(hist<-1) hist=-1;
    if(student<-1) student=-1;
}
void returning_book()
{
    int i,j,k=0;
    node *temp,*new_node,*tmp;
    if(book+1 !=books)
    {
        printf("enter your roll no and book id\n");
        scanf("%d %d",&i,&j);
        if(j<1000+books && j>999)
        {
            temp=history;
            while(temp->data2 != i) temp=temp->next;
            if(temp->data2 == i)
            {
                insert_book(j);
                printf("book has inserted\n");
                strcpy(temp->name,returned);
                temp->data2 = 0;
                k++;
            }
            if(k ==0) {printf("you entered wrong roll number\n");
            returning_book();}
        }
        else
        {
            printf("You enterd wrong book id\n");
            returning_book();
        }
    }
    else printf("********************Library contains all books***************************\n");
    // allotting books to waiting students
    if(student !=-1 && book !=-1)
    {
        temp=line;
        while(temp->next !=NULL) temp=temp->next;
        allotting_book_to_waiting(temp->data2,temp->name);
    }
}
void insert_students(int j , char n[20])
{
    node *temp,*new_node;
    new_node=(node *)malloc(sizeof(node));
    new_node->data2 =j;
    new_node->next;
    strcpy(new_node->name,n);
    if(wit<=max_withdrawal-books)
    {
        if(student==-1)
        {
            line=new_node;
            student++;
        }
        else
        {
            new_node->next=line;
            line=new_node;
            student++;
        }
        wit++;
    }
    else printf(" You are reached out of withdrawal books limits\n");
}
void waiting_students()
{
    int i=1;
    node *temp,*tmp;
    temp=line;
    if(student<-1) student=-1;
    if(student !=-1)
    {
        while(temp->next !=NULL)
        {
            printf("%d\t%s\troll no\t%d\n",i,temp->name,temp->data2);
            i++;
            temp=temp->next;
        }
        printf("%d\t%s\troll no\t%d\n",i,temp->name,temp->data2);
    }
    else printf("no students are waiting\n");
}
void display_history()
{
    int k=1;
    node *temp,*tmp;
    temp=history;
    if(history==NULL) printf("no books are alloted\n");
    else
    {
        while(temp->next !=NULL)
        {
            printf("%d\t%s\tbook id %d\troll no %d\n",k,temp->name,temp->data1,temp->data2);
            k++;
            temp=temp->next;
        }
        printf("%d\t%s\tbook id %d\troll no %d\n",k,temp->name,temp->data1,temp->data2);
    }
}
void allotting_book_to_waiting(int o,char ch[20])
{
    int i;
    node *new_node,*temp,*tmp;
    if(book<-1) book=-1;
    if(hist<-1) hist=-1;
    if(student<-1) student=-1;
    new_node=(node *)malloc(sizeof(node));
    strcpy(new_node->name,ch);
    new_node->data2=o;
    new_node->next=NULL;
    temp=library;
    while(temp->next !=NULL)
    {
        tmp=temp;
        temp=temp->next;
    }
    new_node->data1=temp->data1;
    printf("*********this book is allotted to \t\t%s\n",new_node->name);
    printf("\t\t\t\t\tAlloted book name \t%s\n\t\t\t\t\tbook id \t\t%d\n",book_name,new_node->data1);
    if(book !=0) tmp->next=NULL;
    free(temp);
    temp=history;
    while(temp->next !=NULL) temp=temp->next;
    temp->next=new_node;
    book--;
    hist++;
    wit--;
    temp=line;
    while(temp->next !=NULL)
    {
        tmp=temp;
        temp=temp->next;
    }
    tmp->next=NULL;
    free(temp);
}
