#include<iostream>
#include<bits/stdc++.h>

using namespace std;
//Dequeue provides both stack and queue functionality
//Dequeue stands for doubley linked list.
void print(const deque<int> &val){
    for(auto j: val) cout<<j<<" ";
    cout<<endl;
}

void printMax(int arr[],int n,int k){
    ///Print largest number of k subarray.
    deque<int> s;
    for(int i=0; i<k; i++){
        while(!s.empty() && arr[s.back()]<=arr[i])
            s.pop_back();
        s.push_back(i);
    }
    
    for(int i=k; i<n; i++){
        cout<<arr[s.front()]<<" ";
        while(!s.empty() && s.front()<=i-k)
            s.pop_front();
        while(!s.empty() && arr[s.back()]<=arr[i])
            s.pop_back();
        s.push_back(i);
    }
    cout<<arr[s.front()]<<" "<<endl;

    

}


int main(){
    deque<int> x={2,4,6,7,8,9};
    auto it=x.begin(); //it is iterator.
    print(x);
    it++;
    x.insert(it,20);
    print(x);
    x.pop_front();
    print(x);
    x.pop_back();
    print(x);

    int arr[]={10,8,5,12,15,7,6};
    printMax(arr,7,3);



}



/* Time complexity
    push_back,push_front,pop_back,pop_back,random       O(1)
    insert,erase                                        O(n)






*/