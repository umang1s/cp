/*
    Aurthor: Umang maurya
    Date:
    Problem:

*/
#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
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
    while(n--) {solve(); cout<<endl;}
}
int inNumber(string x){
    int num=0;
    int len=x.length();
    int ten=1;
    for(int i=len-1; i>=0; i--){
        num+=ten*(x[i]-48);
        ten*=10;
    }
    return num;
}
bool checkMachula(string x){
    int len=x.length();
    for(int i=0; i<len; i++) if(x[i]<48 || x[i]>57) return true;
    return false;
}

void solve(){
    string first,second,third;
    char temp;
    int hidden;
    cin>>first>>temp>>second>>temp>>third;
    
    if(checkMachula(first)){
        hidden=inNumber(third)-inNumber(second);
        cout<<hidden<<" + "<<second<<" = "<<third;
    }else if(checkMachula(second)){
        hidden=inNumber(third)-inNumber(first);
        cout<<first<<" + "<<hidden<<" = "<<third;
    }else{
        hidden=inNumber(first)+inNumber(second);
        cout<<first<<" + "<<second<<" = "<<hidden;
    } 
}