#include"default.h"




void solve(){
    int n;
    cin>>n;
    int arr[n];
    for(int i=0; i<n; i++) cin>>arr[i];

    //print greater element in array
    map<int,int> m;
    for(int i=0; i<n; i++) m[arr[i]]++;

    int cum_freq=0;
    for(auto i=m.rbegin(); i!=m.rend(); i++){
        int temp=i->second;
        i->second=cum_freq;
        cum_freq+=temp;
    }

    for(int i=0; i<n; i++) cout<<arr[i]<<" "<<m[arr[i]]<<nl;
    
}


class Ds{
    map<int,string> database;
    public:
    void addItemp(string name,int price){
        database.insert({price,name});
    }

    void findProductByPrice(int p){
        auto it=database.equal_range(p);
        for(auto j=it.first; j!=it.second; j++) cout<<j->second<<" "<<j->first<<nl; 
    }

    void printSorted(){
        for(auto k: database) cout<<k.first<<" "<<k.second<<nl;
    }

    void printGreater(int p){
        auto j=database.upper_bound(p);
        while(j++!=database.end()) cout<<j->first<<" "<<j->second<<nl;
    }

    void printSmaller(int p){
        auto j=database.lower_bound(p);
        while(j--!=database.begin()) cout<<j->first<<" "<<j->second<<nl;
    }
};

