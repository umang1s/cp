#include<iostream>
#include<cstdlib>
using namespace std;
const int Siz=10;
template<class Type> class x
{
    Type a[Siz];
public:
    x()
    {
        register int i;
        for(i=0; i<Siz;i++) a[i]=i;
    }
    Type &operator[](int i);
};
template <class Type> Type &x<Type>::operator[](int i)
{
    if(i<0 || i>Siz-1)
    {
        cout<<endl<<"index value of "<<i<<"is out of bounds"<<endl;
        exit(1);
    }
    return a[i];
}
int main()
{
    x<int> integer;
    x<double> all;
    int i;
    for(i=0; i<Siz; i++) {integer[i]=i; cout<<integer[i]<<"  ";}
    cout<<endl ;
    for(i=0; i<Siz; i++) {all[i]=i; cout<<all[i]<<"  ";}
    cout<<endl;

    all[12]=233;  //generates runtime error
    return 0;
}
