#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<malloc.h>
int top=-1,front=-1,n;
struct node
{
    int data;
    struct node *next;
};
typedef struct node start;
start *stack,*queue;
void borrow();  void returnb(); void display(); int push(int x); int pop(); int queuein(); int dequeue();
int main()
{
    int ch,i;
    printf("faculty please enter no books\n");
    scanf("%d",&n);
    for(i=1;i<=n;i++)   push(i);
    while(1){
     printf("enter the choice \n1.for borrowing or getting in a queue\n2.for returning\n3.for dispalying no of books in library\n4.exit the program\n");
     scanf("%d",&ch);
     switch(ch) {  case 1:borrow(); break;   case 2:returnb(); break;  case 3:display(); break;  case 4:exit(0);break;  }}
}
push(int x)
{
    start *p,*q;
    p=(start*)malloc(sizeof(start));
    p->data=x;
    p->next=NULL;
    if(top==-1)        {   stack=p;       top++;                                      }
    else               {   q=stack; while(q->next !=NULL) q=q->next; q->next=p; top++; }
}
int pop()
{
    int k=0;
    start *q,*p; q=stack; p=q;
    if(top !=-1) {  while(q->next !=NULL)   { p=q;    q=q->next; } k=q->data; p->next=NULL;  free(q);  top--;}
    if(top<-1) top=-1; return(k);
}
int queuein(int z)
{
    start *p,*q;
    p=(start*)malloc(sizeof(start));
    p->data=z;
    p->next=NULL;
    if(front==-1) {   queue=p;                      }
    else          { q=queue;    while(q->next!=NULL) q=q->next; q->next=p; }
    front++;
}
int dequeue()
{
    start *p;
    p=queue;
    queue=queue->next;
    free(p);
}
void borrow()
{
    int s;
    printf("enter your student no\n");
    scanf("%d",&s);
    if(top!=-1)   printf("book %d is alloted to student no. %d\n",pop(),s);
    else    {   printf("sorry there are no books \n");  queuein(s); }
}
void returnb()
{
    int n,y;
    printf("enter the book nuumber\n");
    scanf("%d",&n);
    push(n);
    if(front<-1) front=-1;
    if(front !=-1)  {   y=pop(); printf("book no %d is alloted to student %d ",y,dequeue());    }
}
void display() { printf("total number of books %d\n",top+1);}
