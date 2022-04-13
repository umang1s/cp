#include"default.h"

struct Node{
    int val;
    Node *left,*right;
    Node(int v){
        val=v;
        left=NULL;
        right=NULL;
    }
};

void min_heapify(Node* root){
    if(root==NULL) return ;
    int left=INT_MAX,right=INT_MAX,cur=root->val;
    if(root->left!=NULL) left=root->left->val;
    if(root->right!=NULL) right=root->right->val;
    if(cur<left && cur<right) return ;
    if(left<cur && left<right){
        swap(root->val,root->left->val);
        min_heapify(root->left);
    }
    if(right<cur && right<left){
        swap(root->val,root->right->val);
        min_heapify(root->right);
    }

}

void min_heapfy_in_array(vector<int> &arr,int ind){
    int n=arr.size();
    int left=INT_MAX,right=INT_MAX;
    int leftInd=2*ind+1,rightInd=2*ind+2;
    int newer=ind;
    if(leftInd<n && arr[leftInd]<arr[ind]) newer=leftInd;
    if(rightInd<n && arr[rightInd]<arr[newer]) newer=rightInd;
    if(newer!=ind){
        swap(arr[ind],arr[newer]);
        min_heapfy_in_array(arr,newer); 
    }

}


void solve(){

}