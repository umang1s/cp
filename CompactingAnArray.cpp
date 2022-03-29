#include<iostream>
using namespace std;
template <class x> void compact(x *w,int start,int end, int siz)
{
    int k=end;
    for(int i=start ; i<=end; i++ ) w[i]=w[k++];
    for(int i=end+1; i<siz; i++) w[i]=0;
}
int main()
{
    int j[10];
    for(int i=0; i<10; i++) j[i]=i;
    for(int i=0; i<10; i++) cout<<j[i]<<"  "; cout<<endl;
    compact(j,3,6,10);
    for(int i=0; i<10; i++) cout<<j[i]<<"  "; cout<<endl;
}
