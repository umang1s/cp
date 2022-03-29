#include"default.h"


/*
    map is like set, it uses Red black tree.
    the difference between map and  set is map has pairs of key.
    it is also in sorted order.

*/

void printMap(const map<int,int> &r){
    for(auto j: r) cout<<j.first<<" "<<j.second<<nl;
    cout<<nl;
}
void solve(){
    map<int,int> r;
    r.insert({1,3});
    r.insert({5,23});
    r.insert({1,5}); //this will be ignored because 1 is used.

    printMap(r);

    //updating data
    r[1]=32;
    printMap(r);

    //we can also update this data by this
    r.at(1)=43;
    printMap(r);
}