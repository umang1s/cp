#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef struct nn
{
    int data;
    struct nn *left;
    struct nn *right;
}leaf;
leaf *tree;
void insert_in_node(int num)
{
    int set=0;
    leaf *node,*temp1;
    node=(leaf *)malloc(sizeof(leaf));
    node->data=num;
    temp1=tree;
    if(temp1 == NULL) {tree=node;   node->left=NULL;  node->right=NULL; }
    else while(set !=99)
    {
        if(temp1->data > num)   {   temp1=temp1->left;   if(temp1 == NULL){temp1->left=node;  node->left=NULL;  node->right=NULL;  set=99; }   }
        else    { temp1=temp1->right;   if(temp1 == NULL){temp1->right=node; node->left=NULL;  node->right=NULL;    set=99;}   }
    }
}
void delete_from_node(int num)
{
    int k;
}
display()
{
    leaf *temp;

}
int main()
{
    int i,num;
    printf("enter the data to insert in node\t for exit enter 0\n");
    while(i !=0)
    {
        scanf("%d",&i); if(i!=0)insert_in_node(i);
    }
    while(i !=3)
    {
        printf("choose one operation\n\t\t1.insert a node\n\t\t2.delete a node\n\t\t3.Exit\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("enter data\t"); scanf("%d",&num); insert_in_node(num); display(); break;
            case 2: printf("enter data to delete\n"); scanf("%d",&num); delete_from_node(num); break;
        }
    }
}
