#include"default.h"

class Node2{
    public:
    int data;
    Node2 *left;
    Node2 *right;
    Node2(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

void printBianaryTree(Node2 *root){
    if(root==nullptr) return;
    cout<<root->data<<nl;
    printBianaryTree(root->left);
    printBianaryTree(root->right);
}

class BinaryTree{
    Node2 *root;
    int C;

    void printTreeB(Node2 *current){
        if(current!=nullptr){
            cout<<current->data;
            printBianaryTree(current->left);
            printBianaryTree(current->right);
        }
    }

    bool searchElementB(Node2 *root,int val){
        if(root!=nullptr){
            if(root->data==val) return true;
            if(root->data>val) root=root->left;
            else root=root->right;
            return searchElementB(root,val);
        }
        return false;
    }

    int getHeight(Node *root){
        if(root==nullptr) return 0;
        return max(getHeight(root->left),getHeight(root->right))+1;
    }

    void print_nth_levelB(Node *root,int k){
        if(root==nullptr) return;
        if(k==0) cout<<root->data<<spc;
        else{
            print_nth_level(root->left,k-1);
            print_nth_level(root->right,k-1);
        }
    }

    void bfsB(Node *root){
        if(root==nullptr) return;
        if(root->left !=nullptr) cout<<root->left->data<<spc;
        if(root->right !=nullptr) cout<<root->right->data<<spc;

        bfsB(root->left);
        bfsB(root->right);
    }

    int getSize(Node *root){
        if(root==nullptr) return 0;
        return 1+getSize(root->left)+getSize(root->right);
    }

    void print_leftB(Node *root){
        if(root==nullptr) return;
        if(root->left!=nullptr) cout<<root->left->data<<spc;
        print_leftB(root->left);
        print_leftB(root->right);
    }

    bool check_children_sum(Node *root){
        //sum of left+right must be equal to root
        if(root==nullptr) return true;
        if(root->left==nullptr && root->right==nullptr) return true;
        int sum=0;
        if(root->left!=nullptr) sum+=root->left->data;
        if(root->right!=nullptr) sum+=root->right->data;
        if(sum!=root->data) return false;
        return check_children_sum(root->left) && check_children_sum(root->right);
    }

    bool check_balanced(Node *root){
        //Difference of height of left sub tree and right sub tree not more than one
        if(root==nullptr) return true;
        
    }

    public:
    BinaryTree(){
        H=0;
        C=0;
    }

    void insertNode(int value){
        C++;
        Node2 *temp=root;
        Node2 *parent=root;
        while(temp!=nullptr){
            parent=temp;
            if(temp->data>value) temp=temp->right;
            else temp=temp->left;
        }
        
        
    }

    bool deleteNode(int value){
        return false;
    }

    void printTree(){printBianaryTree(root);}

    bool searchElement(int i){
        return searchElementB(root,i);
    }

    int height(){
        return getHeight(root);
    }

    int count(){return C;}

    void print_nth_level(int k){
        print_nth_level(root,k);
    }


    void level_of_traversal(){
        //also known as bfs of binary tree
        if(root==nullptr) return ;
        cout<<root->data<<spc;
        bfsB(root);
    }

    int getSize(){
        return getSizeB(root);
    }

    int getMaximum(){

    }

    void print_only_left_element(){
        if(root==nullptr) return;
        cout<<root->data<<spc;
        print_leftB(root);
    }
};

Node2* createBinaryTree(vi arr){
    Node2 *root;
    if(arr.size()==0) return root;
    root= new Node2(arr[0]);
    for(int i=1; i<arr.size(); i++){
        if(root==nullptr) root=new Node2(arr[i]);
        else{
            Node2 *newNode= new Node2(arr[i]);
            Node2 *temp=root;
            Node2 *parent=temp;
            bool inserted=false;
            while(temp!=nullptr){
                
                if(arr[i]<temp->data) temp=temp->left;
                else temp=temp->right;
            }
            temp=newNode; 
        }
    }
    return root;
}

int solve(){
    int n;
    cin>>n;
    vi arr(n);
    Node2 *root;
    for(int i=0; i<n; i++) cin>>arr[i];
    root=createBinaryTree(arr);
    cout<<"inserted\n";
    printBianaryTree(root);
    return 0;
}