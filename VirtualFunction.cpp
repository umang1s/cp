#include<iostream>
using namespace std;
class x
{
public:
    virtual void vfunc()
    {
        cout<<"This is x virtual fuction"<<endl;
    }
};
class der:public x
{
public:
    void vfunc()
    {
        cout<<" This is der function "<<endl;
    }
};
class dor:public x
{
public:
    void vfunc()
    {
        cout<<" This is dor function "<<endl;
    }
};
int main()
{
   x *u , i;
   der h;
   dor J;
   u = &i;      //point to x
   u->vfunc();      //access x's fucntion
   u= &h;         // point to der
   u->vfunc();      // access der's fucntion
   u= &J;           // point to dor;s
   u->vfunc();      //acess to dor's function
   h.vfunc();       //direct der's function
}
