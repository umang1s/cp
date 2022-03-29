
#include<iostream>
using namespace std;
class Latlng{
    public:
    double lat,lng;
    Latlng(double lattitude,double longitude){lat=lattitude; lng=longitude;}
};
class minAndMax{
public:
    Latlng minimum,maximum;
    minAndMax(Latlng Min,Latlng Max){minimum=Min; maximum=Max;}
};
class String{
public:
    char value[30];
};
minAndMax getMinAndMax(Latlng latlng,double distance)
{
    cout<<"called"<<endl;
}
String convertInString(Latlng latlng)
{
    cout<<"starts converting \n";
}
int main()
{
    cout<<"starts"<<endl;
}
