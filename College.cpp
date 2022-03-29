#include<iostream>
using namespace std;
class Students{
    int ID;
    char FirstName[20],MiddleName[20],LastName[20];
};
class Teachers{
    int ID;
};
class School{
    int ID;
    char PrincipalFirstName[20],PrincipalMiddleName[20],PrincipalLastName[20];
public:
    void setID(int x){ID=x;}
};

int main()
{
    //goto file and save
    int i=2;
    while(i!=0){
        cout<<"Please choose one option \n\t\t1..Students\n\t\t2..Teacher\n\t\t3..Principal\n";
        cin>>i;
    }
}
