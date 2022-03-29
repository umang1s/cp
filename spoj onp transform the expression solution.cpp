#include<bits/stdc++.h>
//#include"algo.h"
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define psi pair<string,int>
#define vii vector<vector<int>>
#define spc ' '
#define nl '\n'
#define mod 1000000007
using namespace std;
#define scanA(arr,total) for(int i=0; i<total; i++) cin>>arr[i]
#define sortA(x) sort(x.begin(),x.end())
#define printA(z) for(auto in:z) cout<<in<<' '

void solve();
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    int n;
    cin>>n;
    while(n--) {solve(); cout<<nl;}
}


void solve(){
    string input,output;
    cin>>input;

    stack<char> q;//(+(*
    for(int i=0; i<input.length(); i++){
        char c=input[i];
        if(c>='a' &&c<='z') output+=c;
        else{
            if(c==')' || c=='}' || c==']'){
                output+=q.top();
                q.pop();
                q.pop();
            }else q.push(c);
        }
    }
    cout<<output;
}