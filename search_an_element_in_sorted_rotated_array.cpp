#include"default.h"

int find_an_element_in_sorted_rotated_array(vector<int> &arr,int key){
    int n=arr.size();
    int low=0,high=n-1;
    while(low<=high){
        int mid=(low+high)/2;
        if(arr[mid]==key) return mid;
        if(arr[mid]>arr[low]){//it means it is sorted
            if(key>=arr[low] && key<arr[mid]) high=mid-1;
            else low=mid+1;
        }else{
            if(key>arr[mid] && key<arr[high]) low=mid+1;
            else high=mid-1;
        }
    }
    return -1;
}

void solve(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    cout<<find_an_element_in_sorted_rotated_array(arr,k);

}