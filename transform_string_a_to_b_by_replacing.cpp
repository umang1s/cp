#include"default.h"

/*
Can we make string a to string b by replacing all occurance of a character in a.

example a=fflp, b=ggmp
//true by f->g, l->m, p->p


*/

bool canWe(string &a, string &b){
    unordered_map<char,char> mp;
    if(a==b) return true;
    int n=a.length();
    for(int i=0; i<n; i++){
        auto it=mp.find(a[i]);
        if(it==mp.end()) mp[a[i]]=b[i];
        else{
            if(it->second!=b[i]) return false;
        }
    }
    unordered_set<char> us;
    for(auto i: mp) us.insert(i.second);
    return us.size()<26;
}

void solve(){
    string a,b;
    cin>>a>>b;
    cout<<canWe(a,b);
}