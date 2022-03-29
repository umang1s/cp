#include"default.h"

void stockSpanProblem(int arr[],int n){
    //count the number of smaller elements before the current elements.
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
        if(arr[i]<10) cout<<" ";
    }
    cout<<endl;
    stack<pair<int,int>> b;
    b.push(make_pair(arr[0],1));
    cout<<"1  ";
    for(int i=1; i<n; i++){
        int p=1;
        while(!b.empty() &&  b.top().first<=arr[i]) { p+=b.top().second; b.pop();}
        cout<<p<<" ";
        if(p<10) cout<<" ";
        b.push(make_pair(arr[i],p));
    }
    cout<<endl;
}

void solve(){
    
}