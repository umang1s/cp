#include"default.h"

//find minimum and swap to their position
void selection_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        int mn=i;
        for(int j=i+1; j<n; j++) if(arr[j]<arr[mn]) mn=j;
        swap(arr[i],arr[mn]);
    }
}

//take a number and put it to right position
void insertion_sort(vector<int> &arr){
    int n=arr.size();
    for(int i=0; i<n; i++){
        int j=i;
        while(j>0 && arr[j]<arr[j-1]) swap(arr[j],arr[j-1]),j--;
    }
}

//sort the two adjcent element
void bubble_sort(vector<int> &arr){
    int n=arr.size();
    bool isSorted=false;
    for(int i=0; i<n && !isSorted; i++){
        isSorted=true;
        for(int j=1; j<n; j++)  if(arr[j]<arr[j-1]) swap(arr[j],arr[j-1]),isSorted=false;
    }
}

void quick_sort(vector<int> &arr,int start,int last){
    if(start>=last || arr.size()==1) return;
    int pio=last-1;
    int i=start,j=pio-1;
    while(i<j){
        if(arr[i]>=arr[pio] && arr[j]<arr[pio]) swap(arr[i],arr[j]);
        if(arr[i]<=arr[pio])  i++;
        if(arr[j]>arr[pio])  j--;
    }
    swap(arr[j],arr[pio]);
    pio=j;
    quick_sort(arr,start,pio);
    quick_sort(arr,pio+1,last);
}

void merge_sort(vector<int> &arr){
    return;
}
//3 4 5 0 6 5



void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    quick_sort(arr,0,n);
    for(int i: arr) cout<<i<<" ";
}