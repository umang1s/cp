//  this is inheritance program 04feb20
#include<iostream>
using namespace std;
class building
{
    int rooms,floor,area;
public :
    void SetRoom(int i){rooms =i;}
    int GetRoom(){return rooms;}
    void SetFloor(int i){floor=i;}
    int GetFloor(){return floor;}
    void SetArea(int i){area=i;}
    int GetArea() {return area;}
};
//  house is derived from building
class house : public building
{
    int bedrooms,baths;
public:
    void SetBedrooms(int i){bedrooms=i;}
    int GetBedrooms(){return bedrooms;}
    void SetBaths(int i){baths=i;}
    int GetBaths(){return baths;}
};
//  school is also inherite from buliding
class school : public building
{
    int classrooms,offices;
public:
    void SetClassrooms(int i);
    int GetClassrooms();
    void SetOffices(int i);
    int GetOffices();
};
void school::SetClassrooms(int i) {classrooms=i;}
void school::SetOffices(int i){offices=i;}
int school::GetClassrooms(){return classrooms;}
int school::GetOffices(){return offices;}
int main()
{
    house house1;
    school lower;
    house1.SetBedrooms(12);
    house1.SetBaths(2);
    house1.SetRoom(34);
    house1.SetFloor(3);
    house1.SetArea(2300);
    lower.SetClassrooms(123);
    lower.SetOffices(4);
    lower.SetArea(7834);
    lower.SetFloor(5);
    lower.SetRoom(19);
    cout<<"HOUSE :"<<endl;
    cout<<"Area     : "<<house1.GetArea()<<endl;
    cout<<"Floor    : "<<house1.GetFloor()<<endl;
    cout<<"Bedrooms : "<<house1.GetBedrooms()<<endl;
    cout<<"Bathsroom: "<<house1.GetBaths()<<endl;
    cout<<"Room     : "<<house1.GetRoom()<<endl;
    cout<<endl<<"School :"<<endl;
    cout<<"Area     : "<<lower.GetArea()<<endl;
    cout<<"Floor    : "<<lower.GetFloor()<<endl;
    cout<<"Rooms    : "<<lower.GetRoom()<<endl;
    cout<<"Classroom: "<<lower.GetClassrooms()<<endl;
    cout<<"offices  : "<<lower.GetOffices()<<endl;
}
