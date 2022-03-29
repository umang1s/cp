#include"default.h"

/*  You have given an array containing integer which has an element,
        there occurance is more than half of the size of the array find that element.

    O(n2)-->run two loop which counts the no of occurance of that element. 

    O(nlog n)--> sort them and find that.
             --> Hashmap

    Moore

        creates a variable and make it to 1.
        run a loop till 1-n 
        if you get an element than incrment
        other wise decrement.
*/

int findThatNumber(vector<int> &arr){
    int last=1;
    int num=arr[0];
    for(int i=1; i<arr.size(); i++){
        if(arr[i]==num) last++;
        else last--;
        if(last==0) last=1,num=arr[i];
    }
    int occ=0;
    for(int i: arr) if(occ==num) occ++;
    if(occ>arr.size()/2) return num;
    return -1;
}

void solve(){
    // int n;
    // cin>>n;
    // vector<int> arr(n);
    // for(int i=0; i<n; i++) cin>>arr[i];
    // cout<<findThatNumber(arr);

    queue<int> q;
    for(int i=0; i<3; i++) q.push(i);
    cout<<q.back();

}