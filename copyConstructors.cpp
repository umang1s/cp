#include<iostream>
#include<new>
#include<cstdlib>
using namespace std;
class array
{
    int *p;
    int size;
public:
    array(int sz)
    {
        try
        {
            p= new int[sz];
        }
        catch (bad_alloc xa)
        {
            cout<<"Allocation Failure "<<endl;
            exit(EXIT_FAILURE);
        }
        size sz;
    }
    ~array() {delete [] p;}
    array(const array &a) ; //copy constructor
    void put(int i, int j)
    {
        if(i>=0 && i<size) p[i]=j;
    }
    int get(int i) {return p[i];}
};
array::array(const array &a) // copy constructor defination
{
    int i;
    try{ p new int[a.size];}catch(bad_alloc xa)
    {
        cout<<" Allocation Failure \n";
        exit(EXIT_FAILURE);
    }
    for(i =0; i<a.size; i++) p[i] = a.p[i];
}
int main()
{
    array num(19);
    int i;
    for(i=0; i<19; i++) num.put(i,i);
    for(i=9; i>=0; i--) cout<<num.get(i);
    cout<<endl;
    // create another array an initialize with num
    array x(num);       // invokes copy constructor
    for(i=0; i<10; i++) cout<<x.get(i);
    return 0;
}
