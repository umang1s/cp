#include <iostream>
#include <iomanip>
#include <time.h>
#include <cstdlib>
#include <windows.h>
#include"graphic.h"
using namespace std;
int main()
{
    char c=-78;
    cout<<" on 0 it is in copletely black and on 255 it is in completely white "<<endl;
    for(int i=1; i<16; i++)
    {
        if(i<10) cout<<" ";
        cout<<"   "<<i;
        setcolor(i);
        cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<"       ";
        setcolor(7);
        if((i)%5==0) cout<<endl;
    }
    for(int i=16; i<256; i++)
    {
        if(i<100) cout<<" ";
        cout<<"  "<<i;
        setcolor(i);
        cout<<c<<c<<c<<c<<c<<c<<c<<c<<c<<c<<"       ";
        setcolor(7);
        if(i%5==0) cout<<endl;
    }
    int x,y;
    cin>>x>>y;
    setcolor(x,y);
    cout<<"hello umang       "<<endl;
}
