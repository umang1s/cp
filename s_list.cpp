#include<list>
#include<iostream>
using namespace std;

//This will create double linked list.


void print(const list<int> &data){
    for(auto j: data) cout<<j<<" ";
    cout<<endl;
}

int main(){
    list<int> l;
    l.push_back(5);
    l.push_back(6);
    l.push_front(4);
    l.push_front(4);
    print(l);
    l.unique(); ///it removes all duplicates.
    print(l);
}

/* Time complexity

    front,back,size,begin,end,erase,push_front,push_back,pop_front,pop_back
        O(1)

    reverse,unique,remove--         O(n)

    sort                           (nlog n)

*/