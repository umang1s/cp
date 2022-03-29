#include"default.h"


Node* fixBST(Node*root){
    return root;
}


Node* createTreeByArray(vector<int> &arr,int &ind){
    if(ind==arr.size()) return NULL;
    if(arr[ind]==-1){ ind++; return NULL;}
    Node* root=new Node(arr[ind]);
    ind++;
    root->left=createTreeByArray(arr,ind);
    root->right=createTreeByArray(arr,ind);
    return root;
}





void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    int ind=0;
    Node *node=createTreeByArray(arr,ind);
    visualizeTree(node);
    cout<<"After\n";
    node=fixBST()

}