#include"default.h"

void printBt(Node* node){
    if(node){
        printBt(node->left);
        cout<<node->val<<spc;
        printBt(node->right);
    }
}

void printDoublyLinked(Node *node){
    if(node){
        cout<<node->val<<spc;
        printDoublyLinked(node->right);
    }
}

Node* convertIt(Node * node){
    if(node==NULL) return NULL;
    Node * left= convertIt(node->left);
    Node *temp=left;
    while(temp->right) temp=temp->right;
    node->right=convertIt(node->right);
    temp->right=node;
    return left;
}

void solve(){
    Node *node= new Node(10);
    node->left= new Node(5);
    node->right= new Node(8);
    node->left->left=new Node(100);
    node->left->left->left=new Node(2);
    node->left->left->right=new Node(101);
    node->left->left->right->right=new Node(102);

    node->left->right=new Node(45);
    node->left->right->right=new Node(46);
    node->left->right->right->left=new Node(47);
    node->left->right->right->left->right=new Node(48);
    printBt(node);
    cout<<nl;
    Node *dd=convertIt(node);
    printDoublyLinked(dd);
    cout<<nl;
}