#include<stdio.h>
#include<malloc.h>
#include<string.h>

typedef struct node
{
    char name[30];
    struct node *next;
}Node;
Node *insertNode(){
    Node *newNode,*ptr,*start;
    char name[30];
    int ix=0;
    start=NULL;
    while(ix<5){
        printf("enter Name to insert : ");
        scanf("%s",name);

        newNode = (Node *)malloc(sizeof(Node));
        for(int j=0; j<strlen(name); j++){
            newNode->name[j]=name[j];
        }
        if(start==NULL){
            newNode->next=NULL;
            start=newNode;
        }else{
            ptr=start;
            while(ptr -> next != NULL) ptr = ptr -> next; newNode -> next = NULL;
                ptr -> next = newNode;
        }
        ix++;
    }

    displays(start);
    return start;
}
Node* deleteNode(Node *start)
{
    Node *ptr, *preptr;
    ptr = start;
    char name[30];
    preptr = ptr;
    printf("\nenter the name to delete  : ");
    scanf("%s", name);
    while(start->next!=NULL)
    {
        int comp=0;
        printf('compating %s ---%s\n',ptr->name,name);
        for(int j=0; j<strlen(name); j++){
            if(ptr ->name[j]== name[j]) comp++;
        }
        if(comp==strlen(name)){
            printf("found");
            if(ptr->next==NULL){
                free(ptr);
            }else{
                preptr->next=ptr->next;
            }
            printf("deleted\n");
        return start;
        }
        preptr = ptr;
        ptr = ptr -> next;
    }
    displays(start);
    return start;
}
void displays(Node *start)
{
    Node *ptr;
    ptr=start;
    while(ptr -> next != NULL)
    {
        printf("\t %s", ptr -> name);
        ptr = ptr -> next;
    }
    printf("\t %s\n", ptr -> name);

}
int main(){
    char name[30];
    Node *allNode;
    printf("enter the number for inserting \n");
    allNode=insertNode();
    printf("Completed\n");
    while(1){
        allNode=deleteNode(allNode);
    }
}


