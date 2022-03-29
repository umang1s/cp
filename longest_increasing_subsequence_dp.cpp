/*
Longest increasing subsequences
4
5
3 4 2 8 10
8
4 10 6 5 8 11 2 20
3
10 20 30
3
30 20 10

o/p
4
5
3
1

first
3 4 8 10
second
4 6 11

Application
    Minimum number of element to be delete to make an array sorted.
    Maximum sum increasing subsequence
    Maximum length bitonic subsequence //first increasing and then decreasing
    Building bridge //build bridge such that no two bridge cross eachother
    The longest chain

*/
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



int cnt=0;
int count(vector<int> &arr,vector<int> &dp,int index,int last){
    cnt++;
    //if(index==arr.size()) return 0;
    if(index==arr.size()-1){
        if(arr[index]>=arr[last]) return 1;
        else return 0;
    }
    if(dp[index]!=-1) return dp[index];
    int without=count(arr,dp,index+1,last);
    if(arr[index]>=arr[last]) without=max(1+count(arr,dp,index+1,index),without);
    return dp[index]=without;
}

int otherApproach(vector<int> &arr){
    vector<int> temp(arr.size());

    int filled=1;
    temp[0]=arr[0];

    for(int i=1; i<arr.size(); i++){
        if(arr[i]>=temp[filled-1]){
            temp[filled]=arr[i];
            filled++;
        }else{
            auto it=upper_bound(temp.begin(),temp.begin()+filled,arr[i]);
            *it=arr[i];
        }
        cnt++;
    }
    return filled;
}

void solve(int t){
    int n;
    cin>>n;
    cnt=0;
    vector<int> arr(n);
    vector<int> dp(n+1,-1);
    for(int i=0; i<n; i++) cin>>arr[i];
    cout<<count(arr,dp,0,0)<<spc<<cnt<<spc;
    cnt=0;
    cout<<otherApproach(arr)<<spc<<cnt;

}