#include<iostream>
using namespace std;
class loc
{
    int longitude,latitude;
public:
    loc() {}
    loc(int i, int j) {longitude = i; latitude=j;}
    void show()
    {
        cout<<longitude<<"  ";
        cout<<latitude<<endl;
    }
    loc operator+(loc op2) //here # is used
    {
        loc temp;
        temp.longitude = op2.longitude + longitude;
        temp.latitude = op2.latitude + latitude;
        return temp;
    }
    loc operator-(loc op2)
    {
        loc temp;
        temp.longitude = op2.longitude - longitude;
        temp.latitude = op2.latitude - latitude;
        return temp;
    }
    loc operator=(loc op2)
    {
        longitude = op2.longitude;
        latitude = op2.latitude;
        return *this;   //Return object that generated call
    }
    loc operator++()
    {
        longitude++;
        latitude++;
        return *this;
    }
};
int main()
{
    loc ob1(10,20), ob2(5,30),ob3;
    // ob1=ob2=ob3; we can assign multiple assignment
    ob1.show();         //displays 10,20
    ob2.show();         //displays 5, 30
    ob3 = ob1 +ob2;
    ob3.show();         // displays 15,50
    (ob1+ob2).show();
    ++ob1;
    ob1.show();
    return 0;
}
