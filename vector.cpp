#include<bits/stdc++.h>
using namespace std;
void printVectorData(vector<int> data){
    cout<<endl;
    for(int i=0; i<data.size(); i++) cout<<data[i]<<" ";
    cout<<endl;
}

// push_back  assign  pop_back  insert  erase  swap  clear
//begin,end
//size,max_size,capacity,resize,empty


int main(){
    //std::vector<int> a; //if namespace std is not declared
    vector<int> a;

    a.assign(3,12); //12,12,12
    printVectorData(a);

    a.push_back(23); //12,12,12,23
    printVectorData(a);

    a.pop_back();//12,12,12
    printVectorData(a);

    a.insert(a.begin(),5);
    printVectorData(a);

    sort(a.begin(),a.end());


    //cout<<"begin() "<<a.begin()<<endl;
   // cout<<"end() "<<a.end()<<endl;

    cout<<"size() "<<a.size()<<endl;
    cout<<"max_size() "<<a.max_size()<<endl;
    cout<<"capacity() "<<a.capacity()<<endl;
    cout<<"empty() "<<a.empty()<<endl;
    ///cout<<"resize(10) "<<a.resize()<<endl;

}
