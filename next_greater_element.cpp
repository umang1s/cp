#include"default.h"

void printNextGreaterElement(int arr[],int n){
    for(int i=0; i<n; i++) cout<<arr[i]<<"  ";
    cout<<nl;
    stack<int> a;
    int stc[n];
    stc[n-1]=-1;
    a.push(arr[n-1]);
    for(int i=n-2; i>-1; i--){
        while(!a.empty() &&  arr[i]>=a.top()) a.pop();
        if(a.empty()) stc[i]=-1;
        else stc[i]=a.top();
        a.push(arr[i]);

    }
    for(int i=0; i<n ; i++) cout<<stc[i]<<" ";

    cout<<nl;


}



void solve(){
    int arr[]={5,15,10,8,6,12,9,18};
    printNextGreaterElement(arr,8);
}