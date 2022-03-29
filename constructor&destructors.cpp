//      constructors and distructors 04feb20
#include<iostream>
using namespace std;
class stacks
{
    int arr[23],tos;
    public:
    stacks();       // this  is constructor
    ~stacks();       //this is distructor
    void push(int i)
    {
        if(tos==23){cout<<"stack is full"<<endl; return;}
        arr[tos]=i;
        tos++;
    }
    int pop()
    {
        if(tos==0){cout<<"stack is empty"<<endl; return 0;}
        tos--;
        return arr[tos];
    }
};
stacks::~stacks() {cout<<"distructor on "<<endl;}
stacks::stacks()
{
    tos=0;
    cout<<"stack is initialied"<<endl;
}
ram()
{
    stacks num;
}
int main()
{
    stacks stak;
    stak.push(34);
    stak.push(45);
    stak.push(12);
    cout<<"pushed   34 45 12 \npop "<<stak.pop()<<"  "<<stak.pop()<<endl;
    stacks jfd,fds;
    ram();
    stacks ui;
}
