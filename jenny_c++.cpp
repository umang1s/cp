#include"default.h"

void pointers(){
    int arr[10];
    for(int i=0; i<10; i++) arr[i]=i;
    cout<<arr<<nl;  //prints the address
    cout<<*arr<<nl; //gives the first value of array.
    cout<<*(arr+3)<<nl; //gives the value at 3rd index.
    cout<<3[arr]<<nl;   //gives the value at 3rd index.
    cout<<(arr+1)<<nl;  //gives the address of first index.
    cout<<(&arr+1)<<nl; //gives the address of last index.
    cout<<(&arr[0]+1)<<nl; //gives the 2nd address

    //for 2D array we need to double pointer. first stores the row address and the second stores the colums address.
}

struct Node{
    int val;
    Node* left,*right,*next,*parent;
    Node(int v){
        val=v;
        left=right=next=parent=NULL;
    }
    bool match(int vl){return vl==val;}
};

class SingleLinkedList{
    Node *root;
public:
    SingleLinkedList(){
        root=NULL;
    }

    void push(int val){
        Node *node=new Node(val);
        if(root=NULL) root=node;
        else{
            Node *temp=root;
            while(temp->next) temp=temp->next;
            temp->next=node;
        }
    }

    int size(){
        int cnt=0;
        Node *r=root;
        while(r) cnt++,r=r->next;
        return cnt;
    }

    void remove(int val){
        Node *r=root;
        if(r->val==val){
            root=root->next;
            delete r;
        }else{
            Node *parent=root;
            while(r->next){
                if(r->val==val){
                    Node *d=r;
                    parent->next=d->next;
                    delete d;
                    return;
                }
                parent=r;
                r=r->next;
            }
        }
    }

};

void types_of_linked_list(){
    //There are 4 types of linked list.
    //Single LL         Doubly LL           Circular LL             Doubly Circular LL
    SingleLinkedList sll;
    int n; 
    cin>>n;
    while(n--){
        int a;
        cin>>a;
        sll.push(a);
    }
    cout<<sll.size();
    //

}



void solve(){
    //pointers();
    types_of_linked_list();
}