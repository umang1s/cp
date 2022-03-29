#include"default.h"


//Unordered set is based on hashing
//duplicate will not be stored.

void printSet(const unordered_set<int> &a){
    for(auto j: a) cout<<j<<" ";
    cout<<nl;
}
void solve(){
    unordered_set<int> s;
    s.insert(5);
    s.insert(10);
    s.insert(32);
    s.insert(2);
    printSet(s);
}

void printDifferentElement(int arr[]){
    unordered_set<int> s;
    int n=sizeof(arr)/sizeof[arr[0]];

    for(int i=0; i<n; i++){
        auto j=s.find(arr[i]);
        if(j==s.end()){
            cout<<arr[i]<<' ';
            s.insert(arr[i]);
        }
    }
}

bool checkPairHaveSum(int arr[],int sum){
    int n=sizeof(arr)/sizeof(arr[0]);
    unordered_set<int> s;

    for(int i=0; i<n; i++){
        auto it=s.find(n-arr[i]);
        if(it!=s.end()){
            cout<<(*it)<<" "<<arr[i];
            break;
        }
        s.insert(arr[i]);
    }
}