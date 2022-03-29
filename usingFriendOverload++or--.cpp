#include<iostream>
using namespace std;
class loc
{
    int longitude,latitude;
public:
    loc() {}
    loc(int i, int j)
    {
        longitude=i;
        latitude=j;
    }
    void show()
    {
        cout<<longitude<<"  ";
        cout<<latitude<<endl;
    }
    loc operator=(loc op2);
    friend loc operator++(loc &op);
    friend loc operator--(loc &op);
};
loc loc::operator=(loc op2)
{
    longitude = op2.longitude;
    latitude= op2.latitude;
    return *this;
}
loc operator++(loc &op)
{
    op.longitude++;
    op.latitude++;
    return op;
}
loc operator--(loc &op)
{
    op.longitude--;
    op.latitude--;
    return op;
}
int main()
{
    loc ob1(10,20),ob2;
    ob1.show();
    ++ob1;
    ob1.show();
    ob2=++ob1;
    ob2.show();
    --ob2;
    ob2.show();
    return 0;
}
