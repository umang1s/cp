#include"default.h"

int count_the_number_of_subarray_which_sum_is_given(vector<int> &arr,int k){
     unordered_map<int,int> mp;
     int sum=0,cnt=0;
     for(auto i: arr){
         sum+=i;
         if(sum==k) cnt++;
         auto it=mp.find(sum-k);
         if(it!=mp.end()) cnt+=it->second;
         mp[sum]++;
     }
     return cnt;
}

void solve(){
    int n;
    cin>>n;
    
    vector<int> arr;
}