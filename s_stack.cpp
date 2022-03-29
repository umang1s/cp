#include<iostream>
#include<bits/stdc++.h>

using namespace std;

void print(const stack<int> a){
    //for(auto j: a) cout<<j<<" ";
    cout<<endl;
}

void reverseStringUsingStack(string str){
    stack<char> a;
    for(int i=0; i<str.length(); i++) a.push(str[i]);

    string n="";
    for(int i=0; i<str.length(); i++){
        n+=a.top();
        a.pop();
    }
    cout<<n<<endl;
}

bool checkParenthesis(string str){
    stack<char> a;
    for(int i=0; i<str.length(); i++){
        if(str[i]=='[' || str[i]=='(' || str[i]=='{') a.push(str[i]);
        else{
            if(a.empty()) return false;
            if(str[i]==')' && a.top()=='(') a.pop();
            else if(str[i]==']' && a.top()=='[') a.pop();
            else if(str[i]=='}' && a.top()=='{') a.pop();
            else return false;
        }
    }
    return a.empty();
}

void stockSpanProblem(int arr[],int n){
    //count the number of smaller elements before the current elements.
    for(int i=0; i<n; i++){
        cout<<arr[i]<<" ";
        if(arr[i]<10) cout<<" ";
    }
    cout<<endl;
    stack<pair<int,int>> b;
    b.push(make_pair(arr[0],1));
    cout<<"1  ";
    for(int i=1; i<n; i++){
        int p=1;
        while(!b.empty() &&  b.top().first<=arr[i]) { p+=b.top().second; b.pop();}
        cout<<p<<" ";
        if(p<10) cout<<" ";
        b.push(make_pair(arr[i],p));
    }
    cout<<endl;
}

int main(){
    string name="ayruam gnamU";
    reverseStringUsingStack(name);
    bool check=checkParenthesis("(())[");
    cout<<check<<endl;
    int arr[10]={15,13,12,14,16,8,6,4,10,30};
    stockSpanProblem(arr,10);
}