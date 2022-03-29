#include<iostream>
#include<cstdlib>
using namespace std;
template <class P, int size> class Q
{
    P a[size];
public:
    Q()
    {
        register int i;
        for(i=0; i<size; i++) a[i]=i;
    }
    P &operator[](int i);
};
template <class P,int size>
P &Q<P,size>::operator[](int i)
{
    if(i<0 || i> size-1)
    {
        cout<<"\nIndex value of "<<i<<" is out-of-bounds."<<endl;
        exit(1);
    }
    return a[i];
}
int main()
{
    Q<int , 10> u;
    Q<double ,15> v;
    int i;
    cout<<" Integer array : ";
    for(i=0; i<10; i++)
    {
        u[i]=i;
        cout<<u[i]<<"  ";
    }
    cout<<endl;
    for(i=0; i<15; i++)
    {
        v[i]=(double) i/3;
        cout<<v[i]<<"   ";
    }
    cout<<endl;
    return 0;
}
