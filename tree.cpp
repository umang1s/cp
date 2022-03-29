#include"default.h"


struct Node{
    int data;
    Node *left;
    Node *right;
    Node(int val){
        data=val;
        left=NULL;
        right=NULL;
    }
};

void printTree(Node * root){
    if(root==NULL) return;
    cout<<root->data<<spc;
    printTree(root->left);
    printTree(root->right);
}

Node* insertBinaryTree(Node *root,int data){
    Node *temp=root;
    Node *parent=NULL;
    while(temp!=NULL){
        parent=temp;
        if(temp->data>data) temp=temp->left;
        else temp=temp->right;
    }
    if(parent==NULL) return new Node(data);
    if(parent->data>data) parent->left=new  Node(data);
    else parent->right=new Node(data);
    return root;
}

Node *getSuccessor(Node *root){
    root=root->right;
    while(root!=NULL && root->left!=NULL) root=root->left;
    return root;
}

Node * deleteInBinaryTree(Node *root,int data){
    if(root==NULL) return root;
    if(root->data>data) root->left=deleteInBinaryTree(root->left,data);
    else if(root->data<data) root->right=deleteInBinaryTree(root->right,data);
    else{
        if(root->left==NULL){
            Node *temp=root->right;
            delete root;
            return temp;
        }else if(root->right==NULL){
            Node *temp=root->left;
            delete root;
            return temp;
        }else{
            Node *succ=getSuccessor(root);
            root->data=succ->data;
            root->right=deleteInBinaryTree(root->right,succ->data);
        }
        return root;
    }
}

int floorInBST(Node *root,int val){
    //It calculates the largest value which is lesser than val
    int mx=-1;
    while(root!=NULL){
        if(root->data>val) root=root->left;
        else{
            mx=root->data;
            root=root->right;
        }
    }

    return mx;
}

Node * floorInBSTs(Node *root,int val){
    Node *ret=NULL;
    while(root!=NULL){
        if(root->data==val) return root;
        else if(root->data>val) root=root->left;
        else{
            ret=root;
            root=root->right;
        }
    }
    return ret;
}

Node *ceilInBST(Node *root,int val){
    //It calculates the minimum value which is greater than val
    Node *ret=NULL;
    while(root!=NULL){
        if(root->data==val) return root;
        else if(root->data<val) root=root->right;
        else{
            ret=root;
            root=root->left;
        }
    }
    return ret;
}




// Node* Binary_Tree_to_Double_Linked_List(Node *binary_tree){
    
//     Node *current=new Node(binary_tree->data);
//     Node *root;
//     if(binary_tree->left!=nullptr) root=Binary_Tree_to_Double_Linked_List(binary_tree->left);

//     if(root==nullptr) root=current;
//     else { root->right=current; current=root->right;}

//     if(binary_tree->right!=nullptr) current->right=Binary_Tree_to_Double_Linked_List(binary_tree->right);
//     return root;
// }

// void Print_doubly_linked_list(Node *root){
//     Node *temp=root;
//     while(temp!=nullptr){
//         if(temp->left!=nullptr) cout<<temp->left->data<<spc;
//         cout<<temp->data<<spc;
//         if(temp->right!=nullptr) cout<<temp->right->data<<nl;
//         temp=temp->right;
//     }
// }

// Node* create_binary_tree_from_array(int arr[],int n){
//     Node *root=new Node(arr[0]);

//     for(int i=1; i<n;i++){
//         Node *newNode=new Node(arr[i]);
//         Node *temp=root;
//         while(temp->le!=nullptr){
//             if(temp->data<arr[i]) temp=temp->left;
//             else temp=temp->right;
//         }
        
        
//     }

    
// }


// Node *construct_binary_tree_from_inorder_and_preorder_array(int inorder[],int preorder[],int n){

//     /*
//         in 20 10 30
//         pre 10 20 30

//         10
//        /  \
//      20    30


//     */

// }


// int get_maximum_diameter_of_a_binary_tree(Node *binary_tree,int &dia){
//     if(binary_tree==nullptr) return 0;
//     int left=get_maximum_diameter_of_a_binary_tree(binary_tree->left);
//     int right=get_maximum_diameter_of_a_binary_tree(binary_tree->right);

//     dia=max(dia,left+right+1);
//     return max(left,right);
// }


// bool check_value_in_tree(Node *current,int val){
//     if(current==nullptr) return false;
//     if(current->data==val) return true;
//     if(check_value_in_tree(current->left)) return true;
//     return check_value_in_tree(current->right);
// }


// Node* get_lowest_common_ancestor(Node *current,int n1,int n2){
//     if(current==nullptr) return -1;
//     if(current->data==n1 || current->data==n2) return current;
    
//     Node *lca_of_left=get_lowest_common_ancestor(current->left,n1,n2);
//     Node *lca_of_right=get_lowest_common_ancestor(current->right,n1,n2);

//     if(lca_of_left!=nullptr && lca_of_right!=nullptr) return current;
//     if(lca_of_left!=nullptr) return lca_of_left;
//     return lca_of_right;    
// }


// int burn_a_binary_tree_from_leaf(Node *current,int leaf){
//     //at 0sec leaf will burn than adjacent of leaf burn and keep burn until all tree burnt

//     //calculate length of the farthest node from given leaf node.
//     return 0;
// }

// int count_the_number_of_nodes_in_complete_binary_tree(Node<int> *current){

//     //(nlogn)^2
//     if(current==nullptr) return 0;
//     int left_height=0,right_height=0;
//     Node *going_left=current,*going_right;
//     while(going_left!=nullptr) left_height++,going_left=going_left->left;
//     while(going_right!=nullptr) right_height++,going_right=going_right->left;

//     if(left_height==right_height) return int(pow(2,left_height)-1);

//     return 1+count_the_number_of_nodes_in_complete_binary_tree(current->left)+
//         count_the_number_of_nodes_in_complete_binary_tree(current->right);

// }



Node *selfBalancingBinaryTree(Node *root){
    
}


int solve(){
    int n;
    cin>>n;
    Node *root=NULL;
    for(int i=0; i<n; i++){
        int a;
        cin>>a;
        root=insertBinaryTree(root,a);
    }

    cout<<nl;
    printTree(root);
    cout<<nl;
    
    cout<<floorInBSTs(root,32)->data;
    cout<<nl;
    cout<<ceilInBST(root,54)->data;
    
    return 0;
}