//  this is pointer to objrct  08feb
#include<iostream>
using namespace std;
class room
{
    int fan,bed,chair;
    string name;
public:
    void setRoom()
    {
        cout<<"enter name fan and bed : "<<endl;
        cin>>name>>fan>>bed;
        this->chair=bed;
    }
    void GetRoom()
    {
        cout<<"name : "<<name<<endl<<"fan : "<<fan<<"\nbed : "<<bed<<"chair : "<<chair<<endl;
    }
};
int main()
{
    room first, *sec;
    sec = &first;
    first.setRoom();
    first.GetRoom();
    sec->GetRoom();
}
