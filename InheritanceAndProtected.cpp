#include<iostream>
using namespace std;
class base
{
protected:
    int i,j;    //private to base , but accessible by derived
public:
    void set(int a, int b){i=a; j=b;}
    void show()
    {
        cout<< i<<"   "<<j<<endl;
    }
};
class derived : public base
{
    int k;
public :        //derived may access base's i and j
    void setk() {k=i*j;}
    void showk()    {cout <<k<<endl;}
};
int main()
{
    derived ob;
    ob.set(2,3);
    ob.show();
    ob.setk();
    ob.showk();
    return 0;
}
