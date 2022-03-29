#include"default.h"

class Node{
    public:
    int value;
    Node *left,*right;
    Node(int val){value=val; left=nullptr; right=nullptr;}
};

Node* insertNode(Node *root,int value){
    bool inserted=false;
    Node *temp=root;
    if(temp==nullptr){temp=new Node(value); return root;}
    while(!inserted){
        if(temp==nullptr){
            temp=new Node(value);
            inserted=true;
            return root;
        }
        if(temp->value<value) temp=temp->left;
        else temp=temp->right;
    }
    return root;
}


void printNode(Node *root){
    if(root!=nullptr){
        cout<<root->value<<spc;
        printNode(root->left);
        printNode(root->right);
    }
}

void solve(){
    int n;
    cin>>n;
    Node *root;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        root =insertNode(root,a);
    }
    printNode(root);
    cout<<nl;
}