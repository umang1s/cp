#include<iostream>
#include<bits/stdc++.h>


using namespace std;

bool comprate(char a[],char b[],long d){
    if(d%2==1){

    }

    for(long i=0; i<d; i++) if(a[i]>b[i]) return false;
    return true;
}



long long solve(){
    int n,k;
    cin>>n>>k;
    long long mod=10e9+7;
    long long ans=0;
    char str[n],char gen[n];
    cin>>str;

    long mid=n/2;
    if(mid%2==1) mid++;
    long long exp=pow(k,mid);

    for(int i=0; i<n; i++) gen[i]='a';

    for(long i=0; i<mid; i++){
        
    }



    return ans;
}

int main(){
    def();
    long long l;
    cin>>l;
    for(long long x=1; x<=l; x++){
        long long ans=solve();
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
}