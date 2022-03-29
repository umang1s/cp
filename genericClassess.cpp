#include<iostream>
using namespace std;
template <class x> class stack
{
    x p[10];
    int tos;
public:
    stack() {tos=0;}
    void push(x );
    x pop();
};
template <class x> void stack<x>::push(x z)
{
    if(tos==10) {cout<<"Stack is full "<<endl; return ;}
    p[tos] = z; tos++;
}
template <class x> x stack<x>::pop()
{
    if(tos==0)
    {
        cout<<"stack is null"<<endl; return 0;
    }
    return p[--tos];
}
int main()
{
    stack<int> a,b;
    int i=1;
    while(i)
    {
        cout<<"enter 55 for pop 0 for exit"<<endl;
        cin>>i;
        if(i==55) cout<<a.pop()<<endl;
        else a.push(i);
    }
}
