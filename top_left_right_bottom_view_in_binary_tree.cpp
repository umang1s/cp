#include"default.h"

void topView(Node * node){
    if(node==NULL) return ;
    queue<pair<Node*,int>> q;
    q.push({node,0});
    map<int,int> mp;
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        auto it=mp.find(top.second);
        if(it==mp.end()) mp[top.second]=top.first->val;
        if(top.first->left!=NULL) q.push({top.first->left,top.second-1});
        if(top.first->right!=NULL) q.push({top.first->right,top.second+1});
    }
    for(auto it: mp) cout<<it.second<<spc;
    cout<<nl;
}

void bottomView(Node *node){
    if(node==NULL) return ;
    queue<pair<Node*,int>> q;
    q.push({node,0});
    map<int,int> mp;
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        mp[top.second]=top.first->val;
        if(top.first->left!=NULL) q.push({top.first->left,top.second-1});
        if(top.first->right!=NULL) q.push({top.first->right,top.second+1});
    }
    for(auto it: mp) cout<<it.second<<spc;
    cout<<nl;

}

void leftView(Node *node,vector<int> &arr,int level){
    if(node==NULL) return;
    if(arr.size()==level) arr.push_back(INT_MIN);
    if(arr[level]==INT_MIN) arr[level]=node->val;
    leftView(node->left,arr,level+1);
    leftView(node->right,arr,level+1);
}

void rightView(Node *node,vector<int> &arr,int level){
    if(node==NULL) return;
    if(arr.size()==level) arr.push_back(INT_MIN);
    arr[level]=node->val;
    rightView(node->left,arr,level+1);
    rightView(node->right,arr,level+1);
}

void levelOrderTraversal(Node *node){
    if(node==NULL) return;
    queue<Node*> q;
    q.push(node);
    while(!q.empty()){
        auto top=q.front();
        q.pop();
        cout<<top->val<<spc;
        if(top->left!=NULL) q.push(top->left);
        if(top->right!=NULL) q.push(top->right);
    }
    cout<<nl;

}


void solve(){
    Node * node= new Node(10);
    node->left= new Node(5);
    node->right = new Node(7);
    node->left->left= new Node(8);
    node->left->right= new Node(9);
    node->left->right->right= new Node(11);
    node->right->right= new Node(87);
    node->right->right->right= new Node(91);
    node->right->right->right->right=new Node(90);

    topView(node);
    bottomView(node);
    vector<int> left,right;
    leftView(node,left,0);
    rightView(node,right,0);
    for(auto i: left) cout<<i<<spc;
    cout<<nl;
    for(auto i: right) cout<<i<<spc;
    cout<<nl;
    levelOrderTraversal(node);

}