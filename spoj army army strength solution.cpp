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

void print(int i=1){
    if(i) cout<<"Godzilla";
    else cout<<"MechaGodzilla";
}
void solve(){
    int a,b;
    cin>>a>>b;
    vector<int> c(a),d(b);
    scanA(c,a); scanA(d,b);
    sortA(d);
    sortA(c);
    if(c[a-1]>d[b-1]) print();
    else if(c[a-1]==d[b-1]){
        int winner=2;
        int bs=b-1,as=a-1;
        while(winner==2){
            if(c[as]>c[bs]) winner=1;
            else if(c[as]<c[bs]) winner=0;
            else{
                bs--;
                as--;
                if(as<0) winner=0;
                if(bs<0) winner=1;
            }
        }
        print(winner);
    }else print(0);
}