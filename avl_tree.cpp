#include"default.h"

class AVL{
    struct Node{
        int val;
        Node* left,*right;
        Node(int vl){
            val=vl;
            left=NULL;
            right=NULL;
        }
    };

    Node *root;
    public:
    AVL(){
        root=NULL;
    }
    void push(int val){
        if(root==NULL) root= new Node(val);
        else{

        }
    }

    void print(){
        
    }
};

void solve(){
    AVL avl=AVL();
    int n;
    cin>>n;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        avl.push(a);
    }

}