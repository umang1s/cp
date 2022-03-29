#include<bits/stdc++.h> 
#define int long long
#define spc ' '
#define nl '\n'
#define inf LONG_LONG_MAX
#define mod 1000000007
#define String string
using namespace std;
#define dec(num,b) std::fixed<<std::setprecision(b)<<num
#define google(i) "Case #"<<i<<": "
void solve(int i);
int32_t main(){ /* Author-Umang Maurya */
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    if(true){int t,p=0; cin>>t;while(p<t){ p++;solve(p); cout<<nl;}}
    else {solve(1); cout<<nl;}
}

class BST{
    struct Node{
        int val;
        Node *left,*right;
        int child;

        Node(int vl){
            val=vl;
            left=NULL;
            right=NULL;
            child=0;
        }
    };
    Node *root;

    void printData(Node *node, vector<vector<int>> &arr,int ind=0){
        vector<int> temp;
        if(arr.size()==ind) arr.push_back(temp);
        if(node==NULL){
            arr[ind].push_back(INT_MAX);
            return;
        }
        arr[ind].push_back(node->val);
        cout<<node->val<<" ";
        printData(node->left,arr,ind+1);
        printData(node->right,arr,ind+1);
    }

    void graphical(vector<vector<int>> &arr){
        int level=arr.size();
        for(auto i: arr){
            for(int j=0; j<level; j++) cout<<"\t";
            for(int j: i){
                if(j==INT_MAX) cout<<"N\t";
                else cout<<j<<"\t";
            }
            cout<<nl;
            level--;
        }
    }

    public:
    BST(){root=NULL;}

    void insert(int val){
        cout<<"inserting "<<val<<nl;
        Node *cur=new Node(val);
        if(root=NULL) root=cur;
        else{
            Node *temp=root,*parent=root;
            if(parent==NULL) cout<<"NULL";
            while(temp){
                parent=temp;
                if(temp->val>val) temp=temp->left;
                else temp=temp->right;
            }
            //if(parent->val>val) parent->left=cur;
            // else parent->right=cur;
        }
    }

    void remove(int val){
        cout<<val;
    }

    void printNode(Node *node,int level=0){
        if(node==NULL) return;
        cout<<node->val<<" ";
        printNode(node->left,level+1);
        printNode(node->right,level+1);
    }

    void print(){
        // vector<vector<int>> data;
        // printData(root,data);
        // graphical(data);
        printNode(root);

    }

    bool search(int val){
        cout<<val;
        return false;
    }
};





// bool checkBST(Node *node,int low=INT_MIN,int high=INT_MAX){
//     if(node==NULL) return true;
//     if(node->val<=low || node->val>=high) return false;
//     return checkBST(node->left,low,node->val) && checkBST(node->right,node->val,high);
// }

void solve(int t){
    int n;
    cin>>n;
    BST bst=BST();
    while(n--){
        int a;
        cin>>a;
        bst.insert(a);
    }
    //bst.print();
}