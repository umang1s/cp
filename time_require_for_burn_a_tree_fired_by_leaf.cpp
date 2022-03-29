#include"default.h"

int getHeight(Node* cur){
    if(cur==NULL) return 0;
    return 1+max(getHeight(cur->left),getHeight(cur->right));
}

int searchElement(Node *node,int val,int &mx){
    if(node==NULL) return 0;
    if(node->val==val){
        mx=1+max(getHeight(node->left),getHeight(node->right));
        return 1;
    }
    int l=searchElement(node->left,val,mx);
    if(l>0){
        int h=getHeight(node->right)+l+1;
        mx=max(mx,h);
        return l+1;
    }
    l=searchElement(node->right,val,mx);
    if(l>0){
        int h=getHeight(node->left)+l+1;
        mx=max(mx,h);
        return l+1;
    }
    return -1;
}

void printBt(Node*node){
    if(node){
        cout<<node->val<<spc;
        printBt(node->left);
        printBt(node->right);
    }
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
    int mx=-1;
    int tt=searchElement(node,2,mx);
    if(tt!=-1){
        cout<<"Found "<<mx;
    }
    else cout<<"Not found";


}