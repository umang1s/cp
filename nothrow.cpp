#include<iostream>
#include<new>
using namespace std;
int main()
{
    int *p,i;
    p = new (nothrow) int[32];  // use nothrow option
    if(!p)
    {
        cout<<" Alloction failure ."<<endl;
        return 1;
    }
    for(i =0; i<32; i++) p[i]=i;
    for(i =0; i<32; i++) cout<<p[i]<<"   ";
    delete [] p;    // free the memory
    return 0;
}
