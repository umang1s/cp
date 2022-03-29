#include"default.h"

class DisjointSet{
    vector<int> arr;
    int total;
    public:
    DisjointSet(int size){
        total=0;
        arr=vector<int>(size);
        for(int i=0; i<size; i++) arr[i]=i;
    }

    int find_parent(int a){
        if(arr[a]==a) return a;
        return find_parent(arr[a]);
    }

    void insert(int a,int b){
        int pa=find_parent(a),pb=find_parent(b);
        if(pa==pb) return ;
        arr[pa]=pb;
    }

    bool check(int a,int b){
        return find_parent(a)==find_parent(b);
    }
};

void solve(){
    int n,q;
    cin>>n>>q;
    DisjointSet ds=DisjointSet(n);
    while(q--){
        int a,b,c;
        cin>>a>>b>>c;
        if(a) ds.insert(b,c);
        else cout<<ds.check(b,c)<<nl;
    }

}