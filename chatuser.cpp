#include<iostream>
#include<stdlib.h>
#include<fstream>
using namespace std;
class working
{
    public:
    int hight, width;   //for display resolution
    char displaying[30][40],ReciveName[15];
    int line[];
    void DisplayInilize() {for(int i=0; i<hight; i++) for(int j=0; j<width;j++) displaying[i][j]=' '; }
    void display();
    void MidPrinting(string,int);       // printing string at mid of line
    void EndPrinting(string,int);       // printing string at end of lien
    void StartPrinting(string,int);     // printing string at start of line
    bool loginPage();
    void MainMenu();
    void FollwingFeed();    // in option
    void Chatting();
    void ShowContacts();
    void Posting();
    void NewsFeed();
    void Plan();     // story name changes to Plan or mood
    void Notification();
    int setting();
    long ConnectServer(long ,int); // long for mobile number and int for operation
};
struct Contacts
{
    int id;
    string chats[],name;
};


bool working::loginPage()
{
    // if(cache file) returned to mainmenu page and makedefault
    MidPrinting("WELCOME TO VARTA",5);
    MidPrinting("enter mobile number",hight/2 -2);
    long int num,num2;
    display();
    cin>>num;
    num2=num/10000; num2=num2/10000;
    if(num2>99 && num2<60) return false;
    char NumFile[14];
    for(int i=9; i>=0; i--){ NumFile[i]=num%10; num/=10; }

    MidPrinting("An OTP sended on your number",hight/2);
    MidPrinting("please enter:",hight/2+1);
    FILE *read;
    //string filename=ConnectToServer();

    return 1;
}

void working::MainMenu()
{
    DisplayInilize();
    MidPrinting("[1].Latest Post",3);   // Latest post means all feed
}

void working::FollwingFeed()
{
    ;
}

void working::Chatting()
{
    ;
}

void working::ShowContacts()
{
    ;
}

void working::Posting()
{
    ;
}

void working::NewsFeed()
{
    ;
}

void working::Plan()
{
    ;
}

void working::Notification()
{
    ;
}

void working::setting()
{
    ;
}


int main()
{
    working place;
    place.hight=30; place.width=40;     // set resolution of display
    place.DisplayInilize();
    int option;
    if(place.loginPage() == true)
    {
        while(1)
        {
            place.MainMenu(); cin>>option;
            switch(option)
            {
                case 1: place.FollwingFeed(); break;
                case 2: place.Chatting(); break;
                case 3: place.ShowContacts(); break;
                case 4: place.Posting(); break;
                case 5: place.NewsFeed(); break;
                case 6: place.Plan();  break;
                case 7: place.Notification(); break;
                case 8: place.setting(); break;
                case 9: return 0;
            }

        }
    }
}


void working::display()
{
    system("CLS");
    cout<<"%%%";
    for(int i=0; i<width; i++) cout<<"%";
    cout<<"%%%"<<endl;
    for(int i=0; i<hight; i++)
    {
        cout<<"%% ";
        for(int j=0; j<width; j++) cout<<displaying[i][j];
        cout<<" %%"<<endl;
    }
    cout<<"%%%";
    for(int i=0; i<width; i++) cout<<"%";
    cout<<"%%%"<<endl;
}


void working::MidPrinting(string words,int i)
{
    i--;
    int j=words.size();
    int k=(width-j)/2;
    for(int m=k,p=0; p<j; m++,p++) displaying[i][m]=words[p];
}


void working::EndPrinting(string words,int i)
{
    i--;
    int j=words.size();
    int k=(width-j);
    for(int m=k,p=0; p<j; m++,p++) displaying[i][m]=words[p];
}


void working::StartPrinting(string words,int i)
{
    i--;
    int j=words.size();
    for(int p=0; p<j; p++) displaying[i][p]=words[p];
}

/*string working::ConnectServer(long MobileNumebr , int Task)
{
    FILE *read,*write;
    write =
} */
