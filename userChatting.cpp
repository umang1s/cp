#include<iostream>
#include"display.h"
#include<cstdlib>
#include<windows.h>
#include<fstream>
using namespace std;
class Working
{
    int ID;
    char Communication[15];
public:
    bool LoginPage();
    void MainMenu();
    void FollwingFeed();    // in option
    void Chatting();
    void ShowContacts();
    void Posting();
    void NewsFeed();
    void Plan();     // story name changes to Plan or mood
    void Notification();
    int Setting();
    long ConnectServer(long ,int); // long for mobile number and int for operation
};
class Contacts
{
    char name;
    long int MobileNo;
    int ID;
};
bool Working::LoginPage()
{
    Monitor Monitor;
    int i=0,m;
    char MobileNumber[14],Number;
    char MobNum[10];
    Monitor.Reset();
    Monitor.Mid("Welcome To Varta",5);
    Monitor.Mid("Enter Mobile Number",10);
    Monitor.Mid("Without Country code",12);
    Monitor.Display();
    for(m=0; m<5; m++)
    {
        cin>>MobileNumber;
        Monitor.Mid(MobileNumber,15);
        if(strlen(MobileNumber)==10)
        {
            for(int k=0; k<10; k++) if(MobileNumber[k]<58 && MobileNumber[k]>47) i++;
            if(i==10) break;
        }
        else Monitor.Mid("Wrong Mobile Number",2);
        Monitor.Display();
    }
    if(m==5){   Monitor.Reset(); Monitor.Mid("Please try next Time",15); Monitor.Display(); return false; }
    fstream file; file.open("mediate.txt",ios::in | ios::out);
   // while(1)    {   if(is_empty(file)) {file<<MobileNumber<<endl;  break; }   Sleep(500);} // check file is empty or not

    return true;
}
int main()
{
    Working page;
    int option;
    if(page.LoginPage() == true)
    {
        while(1)
        {
            page.MainMenu(); cin>>option;
            switch(option)
            {
                case 1: page.FollwingFeed(); break;
                case 2: page.Chatting(); break;
                case 3: page.ShowContacts(); break;
                case 4: page.Posting(); break;
                case 5: page.NewsFeed(); break;
                case 6: page.Plan();  break;
                case 7: page.Notification(); break;
                case 8: page.Setting(); break;
                case 9: return 0;
            }

        }
    }
}

void Working::MainMenu()
{
//    DisplayInilize();
  //  MidPrinting("[1].Latest Post",3);   // Latest post means all feed
}

void Working::FollwingFeed()
{
    ;
}

void Working::Chatting()
{
    ;
}

void Working::ShowContacts()
{
    ;
}

void Working::Posting()
{
    ;
}

void Working::NewsFeed()
{
    ;
}

void Working::Plan()
{
    ;
}

void Working::Notification()
{
    ;
}

int Working::Setting()
{
    return 0;
}
