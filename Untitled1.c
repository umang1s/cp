#include <stdio.h>
#include <stdlib.h>
#define NB 3  //no.of books
#define NS 50 //no.of student
//studentdetails

typedef struct{
char name[20];
}student;

student stud[50];

typedef struct{
    int top2;
    student stud[50];
}stack;
stack stk2={-1,""};
//book details
struct book{
char title[10];
char name[10];
};
//stack declaration
struct my_stack{
     int top1;
    struct book b[20];
};
struct my_stack stk1={2,""};

struct my_queue{
int front;
int rear;
student stud[50];
};
struct my_queue q={49,49,""};

void borrow()
{
    if(stk1.top1!=-1)
    {  printf("Enter your NAME:");
    scanf("%s",stk2.stud[++stk2.top2].name);
        printf("BOOK IS SUCCESSFULLY ALLOTED TO- %s.\n",stk2.stud[stk2.top2].name);
        stk1.top1--;
        printf("REMAINING BOOK IN STOCK IS (%d)\n",stk1.top1+1);
    }
    else { printf("SORRY!!!_NO BOOKS AVAILABLE:\n");
        printf("**PLEASE GO TO OPTION 3.FOR WAITING.\n ");
    }
}

void returnb()
{
    if(stk1.top1==2)
    printf("NO BOOK IS ISSUED.\n");
    else
   { if(stk2.top2!=-1){
    printf("Book is successfully returned.\n");
    stk1.top1++;
    stk2.top2--;
    printf("Remaining BOOK in STOCK is (%d)\n",stk1.top1+1);
       if(q.rear!=q.front)
        {
        if(q.front==49)
            q.front=0;
        else q.front++;


    printf("NOW THIS BOOK IS ISSUED TO WAITING STUDENT- %s\n",q.stud[q.front].name);
    stk1.top1--;

    printf("Remaining BOOK in STOCK is (%d)\n",stk1.top1+1);
         } else printf("NOBODY IS IN WAITING QUEUE.\n"); }

     else
          {
            printf("ALL BOOKS ARE SUCCESSFULLY RETURNED.\n");
           printf("PRESS 1.\n");}
   }
}
void waiting()
{
    if(stk1.top1==-1)
     {if(q.rear==q.front)
       { q.rear=0;
       }
      else
        q.rear++;
         printf("ENTER YOUR NAME:");
         scanf("%s",q.stud[q.rear].name);
          printf("You are Added to waiting list.\n");

       }
    else
      {
        printf("NO NEED.> BOOKS ARE AVAILABLE.\n");
        printf("PRESS 1.\n");}
}


int main()
{    printf("TOTAL NO.OF BOOKS AVAILABLE : %d\n\n",NB);
    int option=0;
    do{
        printf("\t\t\t\*********| MENU |**************\n");
        printf("-------------------------------------------------------\n");
        printf("\t\tPRESS 1. To Borrow Book:\n");
        printf("\t\tPRESS 2. To Return Book:\n");
        printf("\t\tPRESS 3. To get into waiting queue\n");
        printf("\t\tPRESS 4. To Exit.\n");
        printf("-------------------------------------------------------\n");
        printf("ENTER YOUR CHOICE. ");
        scanf("%d",&option);
        switch(option)
        {
    case 1:
        borrow();
        break;
    case 2:
        returnb();
        break;
    case 3:
        waiting();
        break;
    case 4:
        exit(0);
    default:
        printf("WRONG INPUT!!,TRY AGAIN.");
         exit(0);
        }

    }while(option!=4);

}

