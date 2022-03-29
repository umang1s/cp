#include<iostream>
#include<bits/stdc++.h>
using namespace std;

/*Problem:
    there are n person sitting around circular disk ordering 0 to n-1,
    First person kills K'th person and K+1 'th person kills next K'th person.
    This will gone until last survival.
    Print the last survival.


*/
void print_list(const list<int> & v){
    for(auto j: v) cout<<j<<" ";
    cout<<endl;
}

int josephus_problem(int n,int k){
    int l;
    list<int> table;
    for(int i=0; i<n;i++)table.push_back(i);

    auto current=table.begin();
    while(table.size()>1){
        for(int i=1; i<k; i++){
            current++;
            if(current==table.end()) current=table.begin();
        }
        table.erase(current);
        if(current==table.end()) current=table.begin();
        print_list(table);
    }
    return *table.begin();

}

int main(){
    int n=7,k=3;
    cout<<josephus_problem(n,k)<<endl;
}