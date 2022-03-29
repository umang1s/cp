#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
class Monitor
{
    int Height,Width;
    char DisplayContent[200][200],Border;
    int InitialH,InitialV;
public:
    Monitor() {Height = 30; Width=40; Border='%';InitialH=0; InitialV=0;}  //default
    void SetDisplayPosition(int Vert, int Hori) {InitialH=Hori; InitialV=Vert;}
    void DisplayResolution(int Vertical,int Horizontal) {Height=Vertical; Width=Horizontal;}  // first vertical and than horizontal
    void Mid(char words[], int line=0);      // string taken and int line
    void End(char words[],int line=0);
    void Start(char words[], int line=0);
    void Clr(int);
    void Reset();
    void Display();
    void DisplayBorder(char border) {Border=border;}
    void Help();
};
void Monitor::Help()
{
    cout<<endl<<"*****************************HELP**************************\n1. DisplayResolution(horizontal,vertical)"<<endl;
    cout<<"2. Mid/End/Start(words,line)"<<endl;
    cout<<"3. Clr\t\t\tfor cleanScreen"<<endl;
    cout<<"4. Display()    \t\tfor displaying"<<endl;
    cout<<"5. DisplayBorder(char)  \t\t\tfor displayborder change"<<endl;
}
void Monitor::Clr(int line)
{
    for(int i=0; i<Width; i++) DisplayContent[line][i]=' ';
}
void Monitor::Start(char words[], int line)
{
    int Wordlength=strlen(words);
    for(int i=0; i<Wordlength; i++) DisplayContent[line][i]=words[i];
}
void Monitor::End(char words[], int line)
{
    int Wordlength,EndPoint;
    Wordlength=strlen(words);
    EndPoint=Width-Wordlength;
    for(int i=EndPoint,j=0; j<Wordlength; j++,i++) DisplayContent[line][i]=words[j];
}
void Monitor::Mid(char words[],int line)
{
    int Wordlength,MidPoint;
    Wordlength=strlen(words);
    MidPoint=(Width-Wordlength)/2;
    for(int i=MidPoint,j=0; j<Wordlength; j++,i++) DisplayContent[line][i]=words[j];
}
void Monitor::Reset()
{
    for(int i=0; i<Height; i++)         for(int j=0; j<Width; j++) DisplayContent[i][j]=' ';
}
void Monitor::Display()
{
    system("CLS");
    for(int i=0; i<InitialV; i++) cout<<endl;
    for(int i=0; i<InitialH; i++) cout<<" ";
    for(int i=0; i<Width+6; i++) cout<<Border;
    cout<<endl;
    for(int i=0; i<Height; i++)
    {
        for(int i=0; i<InitialH; i++) cout<<" ";
        cout<<Border<<Border<<" ";
        for(int j=0; j<Width; j++) cout<<DisplayContent[i][j];
        cout<<" "<<Border<<Border<<endl;
    }
    for(int i=0; i<InitialH; i++) cout<<" ";
    for(int i=0; i<Width+6; i++) cout<<Border;
    cout<<endl;
}
