#include<iostream>
using namespace std;
template <class T> class V
{
    T u;
public:
    V(T a)
    {
        cout<<" Inside generic class"<<endl;
        u=a;
    }
    T getx() {return u;}
};
//explicit specialization for int
template<> class V<int>
{
    int x;
public:
    V(int a)
    {
        cout<<" Inside specialization "<<endl;
        x= a*a;
    }
    int getx(){return x;}
};
int main()
{
    V<double> d(10.1);
    cout<<" double : "<<d.getx()<<endl<<endl;
    V<int> i(28);
    cout<<" int : "<<i.getx()<<endl;
    return 0;
}
