#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
struct node
{
    int data;
    struct node *left;
    struct node *right;
};
struct node *tree;
void insert_in_tree(int num)
{
    struct node *new_node, *temp;
    new_node=(struct node *)malloc(sizeof(struct node));
    new_node->data=num; new_node->left=NULL;    new_node->right=NULL;
    temp=tree;
    if(temp==NULL)  tree=new_node;
    else while(temp->left !=NULL && temp->right!=NULL)
    {
        if(temp->data > num)
        {
            if(temp->left == NULL) {temp->left=new_node; return; }
            else temp=temp->left;
        }
        else
        {
            if(temp->right ==NULL)  {temp->right=new_node; return;}
            else temp=temp->right;
        }
    }
}
void display()
{
    struct node *temp;
    temp=tree;
    while(temp->left !=NULL && temp->right !=NULL)
    {
        printf("%d",temp->data);
        if(temp->left !=NULL)   temp=temp->left;
        else temp=temp->right;
    }
}
int main()
{
    int num,i;
    printf("enter number for exit enter -999\n");
    while(i !=-999)
    {
        scanf("%d",&i);
        if(i !=-999)    insert_in_tree(i);
    } i=1;
    while(i !=0)
    {
        printf("choose one operation\n");
        printf("1.insert in tree\n2.delete from treec\n3.display\n4.traverse\n");
        scanf("%d",&i);
        switch(i)
        {
            case 1: printf("enter the number to insert\n"); scanf("%d",&num); insert_in_tree(num);    break;
           // case 2: printf("enter the number to delete\n"); scanf("%d",&num); delete_from_tree(num); break;
           // case 3: display(); break;
           // case 4: traverse(); break;
        }
    }
}
