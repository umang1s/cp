#include"default.h"

void printNextGreaterElement(int arr[],int n){
    for(int i=0; i<n; i++) cout<<arr[i]<<"  ";
    cout<<nl;
    stack<int> a;
    a.push(arr[0]);
    cout<<-1<<"  ";
    for(int i=1; i<n; i++){
        while(!a.empty() &&  arr[i]>=a.top()) a.pop();
        if(a.empty()) cout<<-1<<" ";
        else cout<<a.top()<<" ";
        a.push(arr[i]);

    }

    cout<<nl;


}

void solve(){
    int arr[]={12,10,8};
    printNextGreaterElement(arr,3);
}