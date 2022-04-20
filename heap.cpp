#include"default.h"
//Heap is a complete binary tree It means it's left must be filled before filling right node.

//node  i
//parent i/2
//left 2*i
//right 2*i+1

void insertNodeInMaxHeap(vector<int> &arr,int val,int n){
    arr[n]=val;
    int last=n;
    int parent=last/2;
    while(parent>0 && arr[last]>arr[parent]){
        swap(arr[last],arr[parent]);
        last=parent;
        parent/=2;
    }
}

void remove_from_max_heap(vector<int> &arr,int &n){
    swap(arr[1],arr[n]);
    n--;
    int start=1,last=2;
}




//Array Based 
void build_max_heap_in_Array(vector<int> &arr,int n){
    int val=n,l=2*n,r=2*n+1;
    if(arr.size()>l && arr[l]>arr[val]) val=l;
    if(arr.size()>r && arr[r]>arr[val]) val=r;
    if(val!=n){
        swap(arr[val],arr[n]);
        build_max_heap_in_Array(arr,val);
    }
}
void build_min_heap_in_Array(vector<int> &arr,int n){
    int val=n,l=2*n,r=2*n+1;
    if(arr.size()>l && arr[l]<arr[val]) val=l;
    if(arr.size()>r && arr[r]<arr[val]) val=r;
    if(val!=n){
        swap(arr[val],arr[n]);
        build_min_heap_in_Array(arr,val);
    }
}

void heapSort(vector<int> &arr){
    for(int i=arr.size()-1; i>0; i-- ){
        swap(arr[i],arr[0]);
        build_max_heap_in_Array(arr,1);
    }

}

void update_node_in_min_heap(vector<int>&arr,int ind,int val){
    arr[ind]=val;
    int i=ind;
    while(i!=0 && arr[i/2]>arr[i])swap(arr[i],arr[i/2]),i/=2;

}



void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    for(int i=n/2; i>=0; i--) build_max_heap_in_Array(arr,i);
    for(auto i: arr) cout<<i<<" ";
    cout<<nl;
    // for(int i=n/2; i>=0; i--) build_min_heap_in_Array(arr,i);
    // for(auto i: arr) cout<<i<<" ";
    // cout<<nl;
    heapSort(arr);
    for(int i=n/2; i>=0; i--) build_min_heap_in_Array(arr,i);
    for(auto i: arr) cout<<i<<" ";
    

}