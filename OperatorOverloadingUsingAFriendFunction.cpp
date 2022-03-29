#include<iostream>
using namespace std;
class loc
{
    int longitude, latitude;
public:
    loc()    {} //needed to construct
    loc(int i, int j)
    {
        longitude = i; latitude =j;
    }
    void show()
    {
        cout<<longitude<<"  "<<endl;
        cout<<latitude<<endl;
    }
    friend loc operator+(loc op1, loc op2); // operator overloading using friend funtion
    loc operator-(loc op1);
    loc operator+(loc op1);
    loc operator=(loc op1);
    loc operator++();
};
loc operator+(loc op1,loc op2)
{
    loc temp;
    temp.longitude = op1.longitude + op2.longitude;
    temp.latitude = op1.latitude + op2.latitude;
    return temp;
}
loc loc::operator+(loc op1)
{
    loc temp;
    temp.longitude = longitude + op1.longitude;
    temp.latitude = latitude + op1.latitude;
    return temp;
}
loc loc::operator-(loc op1)
{
    loc temp;
    temp.longitude = longitude - op1.longitude;
    temp.latitude = latitude - op1.latitude;
    return temp;
}
loc loc::operator=(loc op1)
{
    longitude = op1.longitude;
    latitude= op1.latitude;
    return *this;
}
loc loc::operator++()
{
    longitude++;
    latitude++;
    return *this;
}
int main()
{
    loc ob1(10, 20) , ob2(5,30);
    ob1 = ob1 + ob2;
    ob1.show();
    return 0;
}
