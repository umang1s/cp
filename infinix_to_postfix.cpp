#include"default.h"

string infix_to_postfix(string s){
    stack<char> c;
    string ans="";
    for(auto i: s){
        if(i=='(') c.push(i); //push into stack
        else if(i=='+' || i=='-') {while(!c.empty() && (c.top()=='*' || c.top()=='/')) ans+=c.top(),c.pop(); c.push(i);}
        else if(i=='*' || i=='/') ans+=i; 
        else if(i==')') {while(!c.empty() && c.top()!='(') ans+=c.top(),c.pop();  c.pop();}//pop while ( not found
        else if(i==' ') continue;
        else ans+=i;
    }
    while(!c.empty()) ans+=c.top(),c.pop();
    return ans;
}

void solve(){
    string str="a+b*(c+d)";
    cout<<str<<nl;
    cout<<infix_to_postfix(str);
}