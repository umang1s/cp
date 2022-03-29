//  this is freing function 04feb20
#include<iostream>
using namespace std;
class lets
{
    string name;
    int id;
    public:
    friend Display(lets);
    void setId()
    {
        cout<<"enter the name : "; cin>>name;
        cout<<"enter the id   : "; cin>>id;
    }
};
Display(lets le)
{
    cout<<endl<<le.name<<" "<<le.id<<endl;
}
int main()
{
    lets let;
    let.setId();
    Display(let);
}
