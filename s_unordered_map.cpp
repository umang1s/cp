#include"default.h"

//unordered map is based on hashing
//map is used red black tree.

void printMap(const unordered_map<string,int> &s){
    for(auto j: s) cout<<j.first<<"  "<<j.second<<nl;
}

int solve(){
    unordered_map<string,int> s;
    s["Umang"]=5;
    s["Maurya"]=4;
    s.insert({"Hii",2});
    printMap(s);
    return 0;
}