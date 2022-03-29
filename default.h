#include<bits/stdc++.h>
#define int long long
#define v vector
#define spc ' '
#define nl '\n'
#define mod 1000000007
using namespace std;
#define scanA(arr,total) for(int i=0; i<total; i++) cin>>arr[i]
#define sortA(x) sort(x.begin(),x.end())
#define printA(z) for(auto in:z) cout<<in<<' '
//Aurthor umang1s

void solve();   
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    solve();
    cout<<endl;
}

struct Node{
    int val;
    Node* left,*right;
    Node(int data){
        val=data;
        left=NULL;
        right=NULL;
    }
};


// String lcs(String x,String y, int a,int b,vector<vector<String>> &dp){
//     String ret="";
//     if(a<x.length() && b<y.length()){
//         if(dp[a][b]!="$") return dp[a][b];

//         if(x[a]==y[b]) ret=x[a]+lcs(x,y,a+1,b+1,dp);
//         else{
//             String z=lcs(x,y,a+1,b,dp);
//             String h=lcs(x,y,a,b+1,dp);
//             cout<<z<<spc<<h<<nl;
//             if(z.length()>h.length()) ret=z;
//             else ret=h;
//         }
//     }

//     return dp[a][b]=ret;
// }
// //1 2 3 4 5 6 7

// vector<int> lis(vector<int> &arr,int i,int last){
//     vector<int> ret;
//     if(i==arr.size()-1){
//          if(arr[i]>=arr[last]) ret.push_back(arr[i]);
//     }else if(i<arr.size()){
//         vector<int> came=lis(arr,i+1,i);
//         vector<int> came2=lis(arr,i+1,last);
//         if(came.size()>came2.size()){
//             ret.push_back(arr[i]);
//             for(int i: came) ret.push_back(i);
//         }else return came2; 
//     }
//     return ret;
// }

void printTree(Node* node){
    if(node){
        cout<<node->val<<" ";
        printTree(node->left);
        printTree(node->right);
    }
}

int __insertNodeInTree(vector<vector<int>> &arr,Node* node,int level){
    if(node==NULL){
        int times=1;
        for(int i=level; i<20; i++,times*=2) for(int j=0; j<times; j++) 
        arr[i].push_back(INT_MIN); 
        return level;
    }
    arr[level].push_back(node->val);
    int ret=__insertNodeInTree(arr,node->left,level+1);
    ret=max(ret,__insertNodeInTree(arr,node->right,level+1));
    return ret;
}

void visualizeTree(Node *node){
    vector<vector<int>> arr(20);
    int cnt=__insertNodeInTree(arr,node,0);
    int star=1,rev=2,space=0;
    for(int i=1; i<cnt; i++) rev+=rev+4,space+=space+3;
    for(int i=0; i<cnt; i++){
        cout<<nl;
        for(int j=0; j<space; j++) cout<<" ";
        for(int j=0; j<star; j++){
            int val=arr[i][j];
            if(val==INT_MIN) cout<<"    ";
            else{
                if(j%2==0){
                    cout<<"  ";
                    if(val<10) cout<<val<<"   ";
                    else if(val<100) cout<<val<<"  ";
                    else if(val<1000) cout<<val<<" ";
                    else cout<<val;
                }else{
                    if(val<10) cout<<"   "<<val;
                    else if(val<100) cout<<"  "<<val;
                    else if(val<1000) cout<<" "<<val;
                    else cout<<val;
                }
            }
            for(int k=0; k<rev; k++) cout<<" ";
        }
        star*=2;
        rev=((rev+4)/2)-4;
        space=(space-3)/2;
        cout<<nl;
    }
}

