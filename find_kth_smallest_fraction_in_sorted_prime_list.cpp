#include"default.h"

pair<int,int> kth_smallest(vector<int> &arr,int k){
    //given a sorted list of prime number including 1 and we have to find kth smallest fraction
    //p/q
    int start=0,last=arr.size();
    int i=start,j=last,m=start+1,n=last-1;
    while(k){
        cout<<i<<spc<<j<<"--"<<m<<spc<<n<<nl;
        k--;
        if(i==j && m==n){
            start++;
            last--;
            if(start==last) break;
            i=start;
            m=start+1;
            j=last;
            n=last-1;
        }
        double left=(arr[i]*1.0)/arr[j];
        double right=(arr[m]*1.0)/arr[n];
        if(left>right){
            m++;
            if(k==0) return{m,n};
        }else{
            i++;
            if(k==0) return {i,j};
        }
        
    }
    return {0,0};
}

void solve(){
    int n;
    cin>>n;
    vector<int> arr(n);
    for(auto &i: arr) cin>>i;
    auto pr=kth_smallest(arr,6);
}