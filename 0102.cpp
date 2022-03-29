//  this is stack function
#include<iostream>
using namespace std;
class stacks
{
    int arr[20],tos;
public:
    void init();
    void push(int i);
    int pop();
};
void stacks::init()
{
    tos=0;
}
void stacks::push(int j)
{
    if(tos==20)
    {
        cout<<"Stack is full\n"; return ;
    }
    arr[tos]=j;
    tos++;
}
int stacks::pop()
{
    if(tos==0)
    {
        cout<<"stack is empty\n";
        return 0;
    }
    tos--;
    return arr[tos];
}
int main()
{
    int j,k;
    stacks stac;
    stac.init();
    while(j!=-1)
    {
        cout<<"enter a number to push and -1 for exit and 0 for pop\n";
        cin>>j;
        if(j==0) cout<<" pop value "<<stac.pop()<<endl;
        else if(j==-1) continue;
        else stac.push(j);
    }
}
