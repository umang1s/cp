#include<bits/stdc++.h>

using namespace std;

int main(){
    stack<int> a;

    for(int i=0; i<10; i++) a.push(i*i);

    for(int i=0; i<10; i++){
        int j=a.top();
        cout<<j<<endl;
        a.pop();
    }

    queue<int> b;
    for(int i=0; i<10; i++) b.push(i*i);

    for(int i=0; i<10 ; i++){
        int j=b.front();
        cout<<j<<endl;
        b.pop();
        //b.pop_back();
    }
    
    //finding the minimum
}