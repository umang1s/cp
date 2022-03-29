#include<stdio.h>
#include<stdlib.h>
typedef struct node
{
    int data;
    struct node *right;
    struct node *left;
}leaf;
leaf *root;
void insert(int );
void deleting(int );
void inserting(leaf *);
int main()
{
    int num,j;
    printf("enter the data for exit enter -199\n");
    while(num !=-199)
    {
        scanf("%d",&num);
        insert(num);
    }
    while(j !=0)
    {
        printf("for deleting a data enter.....1\t\tforinserting a data enter....2\tfor exit ....1\n");
        scanf("%d",&j);
        if(j==1) {printf("enter the data\n"); scanf("%d",&num); deleting(num);}
        else if(j==2){printf("enter the data"); scanf("%d",&num); insert(num);}
        else printf("you entered wrong entry\n");
    }
}
void insert(int num)
{
    leaf *new_node;
    new_node=(leaf *)malloc(sizeof(leaf));
    new_node->data=num;
    new_node->left=NULL;
    new_node->right=NULL;
    inserting(new_node);
}
leaf inserting(leaf *node)
{
    if(root==NULL)
}
void deleting(int num)
{
    int i;
}
