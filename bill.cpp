#include<iostream>
#include"display.h"
using namespace std;
class bill
{
public:
    int SN;
    float Bal;
    char reason[80],date[10];
};
int main()
{
    bill Bill[30],History[50];
    int Loop=1,Total=0,PIN,Stored,Records,TotalBalance;
    char Username[20];
    Monitor X1;
    X1.DisplayResolution(25,110);
    X1.Mid("WELCOME TO DIGITAL PASSBOOK");
    while(Loop)             // Initilizing stored data
    {
        Loop=0;
        Records=0;
    }
    if(Records==0)          // if no data found
    {
        TotalBalance=0;
        X1.Mid("No data found ",1);
        X1.Start("Enter Your Name",2);
        X1.Display();
        cin.getline(Username,20);
        X1.Clr(1); X1.Clr(2);
        X1.Start(Username,1);
        while(Records!=1)
        {
            X1.Mid("create the new Passkey",3);
            X1.Display();
            X1.Clr(4);
            cin>>Stored;
            X1.Mid("Please confirm New Passkey",4);
            X1.Display();
            cin>>PIN;
            if(PIN==Stored)
            {
                X1.Clr(3); X1.Clr(4); X1.Mid("Matched",4); X1.Clr(4); X1.Display(); Records=1;
            }
            else
            {
                X1.Mid("Passkey did not matched",4);
            }
        }
    }
    else
    {
        X1.Start(Username,1);
        X1.End("Balance : ",1);
    }
    if(PIN==Stored) Loop=1;
    while(Loop)
    {
        X1.Reset();
    }
}
