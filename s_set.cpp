#include"default.h"

/*
set is based on self balanced binary tree or red black tree.

Time complexity
    begin(),end(),rbegin,rend,cbegin,cend,size,empty        O(1)
    insert,find,count,lower_bound,upper_bound,erase(val)    O(n)
    erase(it),crbegin,crend                                 O(1)


*/

void solve(){
    //always store data in sorted order
    set<int> data;
    set<int,greater<int>> second; //store data in decreasing order
    data.insert(5);
    data.insert(10);
    data.insert(2);
    data.insert(50);
    data.insert(5); //remove duplicate values
    data.insert(12);

    for(auto j: data) cout<<j<<" ";
    cout<<nl;

    second.insert(5);
    second.insert(10);
    second.insert(2);
    second.insert(50);
    second.insert(5); //remove duplicate values
    second.insert(12);

    for(auto j: second) cout<<j<<" ";
    cout<<nl;

    auto it=data.find(10); //iterator
    if(it==data.end()) cout<<"Not found\n";
    else cout<<"Found\n";

    auto yes=data.count(10); //returns it is present or not
    if(yes) cout<<"Not found\n";
    else cout<<"Found\n";

    //data.clear()      is used to clear all data

    //data.erase(val)      is used to delete only that data
    //we can also pass the iterator to this
    //data.erase(data.begin(),data.end()) //delete all data

    auto it1=data.lower_bound(5); //iterator
    //if we search a which is not present than it returns iterators to next
    if(it1!=data.end()) cout<<(*it1)<<nl; //5
    else cout<<"Not found\n";

    //same upper_bound()
}