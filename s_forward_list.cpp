#include<iostream>
#include<forward_list>

using namespace std;
 
//we are using const because we don't want it to modified
//we are using & because it doesn't take copy of data it only takes address.
void print(const forward_list<int> &v){
    //here auto is forward_list<int>::iterator
    for(auto p: v) cout<<p<<" ";
    cout<<endl;

    //for(std::forward_list<int>::iterator i= v.begin(); i!=v.end(); i++) cout<<(*i)<<" ";cout<<endl;
}

int main(){
    forward_list<int> j={1,5,1};
    j.push_front(6);
    print(j);
    j.pop_front();
    print(j);

    forward_list<int> k;
    k.assign({5,2,12,3});
    print(k);
    k.assign(j.begin(),j.end()); //it erases the data and assign new data.
    print(k);

    //insert after here it is iterator.
    //emplace_after is same like insert after.
    auto it=j.insert_after(j.begin(),3); //1 3 5 1
    print(j);
    it=j.insert_after(it,{4,2,1}); //1 3 4 2 1 5 1
    print(j);
    it=j.emplace_after(it,40); //1 3 4 2 1 40 5 1
    print(j);
    it=j.erase_after(it); //1 3 4 2 1 40 1
    print(j);



}




/*  Time complexity
insert_after        O(1) for one items O(m) for m items.
erase_after                 ""
assign                      ""
push_front          O(1)
pop_front           O(1)
reverse             O(n)
sort                O(nlog n)
remove              O(n)





*/