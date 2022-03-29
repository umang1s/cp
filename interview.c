#include<bits/stdc++.h>

using namespace std;

int main(){

    int n=500000;
    int first[n],sol[n];
    for(int i=0; i<n; i++){
        first[i]=i;
        sol[i]=0;
    }
    for(int p=2; p<n;p++){
        if(first[p]==p){
            first[p]=p-1;
            for(int i=2*p; i<n; i+=p){
                first[i]=(first[i]/p)*(p-1);
            }
        }
    }
    for(int i=1; i<n; i++){
        sol[i]+=i-1;
        for(int j=2*i; j<n; j+=i){
             sol[j]+=i*((i+first[j/i])/2);
        }
    }

    for(int i=0; i<10; i++){
        cout<<sol[i]<<endl;
    }
    int t;
    // cin>>t;

    // while(t--){
    //     int val;
    //     cin>>val;
    //     cout<<sol[4*val+1]<<endl;
    // }
    return 0;
}
