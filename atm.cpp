#include<iostream>
#include"graphic.h"
#include<cstdlib>
#include<cstring>
#include<conio.h>
using namespace std;
int normal, background,text;
int UP=72,DOWN=80,LEFT=75,RIGHT=77,ENTER=13; // key handling
char *passwordEncryption(char characters[])
{
    return characters;
}
class Date
{
    public:
    short dd,mm;
    int yy;
    short dayInMonth[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    bool setDate(int day, int month, int year)  // true for setted
    {
        if(year%4==0) dayInMonth[2]=29; // setting months in feb if lear year found
        if(year>9999 && year<1000) return false;
        if(day<=dayInMonth[month])
        {
            dd=day; mm=month; yy=year; return true;
        }
        return false;
    }
    void showDate()
    {
        if(dd<10) cout<<"0";
        cout<<dd<<":";
        if(mm<10) cout<<"0";
        cout<<mm<<":"<<yy;
    }
};

class Transaction
{
    double ammount,remainingAmmount;
public:
    void Transactioning(double ammounts,double remainT)
    {
        ammount=ammounts;
        remainingAmmount=remainT;
    }
    double showTransaction()
    {
        return ammount;
    }
    double showRemaining()
    {
        return remainingAmmount;
    }
};
class Costomer
{
    char Name[30],Password[30];
    int AccountNumber,Totaltransaction=0,accountType,pin=0;
    int card[3]={0,0,0},Card=0;
    double balance;
    Date date[25],createDate;
    Transaction transaction[25];
    bool access=false,atmAccess=false;
public:
    void setNewAccount(char name[],char password[],int type,Date pp)
    {
        if(access)
        strcpy(Name,name);
        strcpy(Password,passwordEncryption(password));
        balance=0;
        if(type) accountType=1; // 1 for current defalult saving
        createDate.setDate(pp.dd,pp.mm,pp.yy);
    }
    bool showAccess(){return access;}
    void administratorWantsToLook()
    {
        cout<<AccountNumber<<"\t"<<Name<<"\t"<<Password<<"\t"<<balance<<"\t"; createDate.showDate();
        cout<<"\t"<<pin<<"\t";
        for(int i=0; i<Card; i++) cout<<card[i]<<"\t";
        cout<<endl;
        for(int i=0; i<Totaltransaction; i++)
        {
            cout<<i+1<<"\t"<<transaction[i].showTransaction()<<"\t"<<transaction[i].showRemaining()<<"\t";
            date[i].showDate(); cout<<endl;
        }
    }
    bool changeNewPassword(char oldPassword[])
    {
        if(access) {strcpy(Password,oldPassword); access=false; return true;}
        return false;
    }
    double showAccountBalance(int accountnumber)
    {
        if(accountnumber==AccountNumber) return balance;
        return 0;
    }
    int adminAccountNumberMatch()
    {
        return AccountNumber;
    }
    double withdrawMoney(double howMuch,Date pp)
    {
        if(access)
        {
            transaction[Totaltransaction].Transactioning((howMuch)*-1,balance-howMuch);
            balance-=howMuch;
            date[Totaltransaction].setDate(pp.dd,pp.mm,pp.yy);
            Totaltransaction++;
            access=false; return balance;
        }
        return 0;
    }
    double depositeMoney(double howMuch,Date pp)
    {
        if(access)
        {
            transaction[Totaltransaction].Transactioning(howMuch,balance+howMuch);
            balance+=howMuch;
            date[Totaltransaction].setDate(pp.dd,pp.mm,pp.yy);
            Totaltransaction++;
            access=false; return balance;
        }
        return 0;
    }
    void removeAccess(){access=false;}
    bool matchPassword(char password[])
    {
        if(strcmp(Password,password)) {access=true; return false;}
        return false;
    }
    void showAllTransaction()
    {
        for(int i=0; i<Totaltransaction; i++)
        {
            cout<<i+1<<"\t"<<transaction[i].showTransaction()<<"\t"<<transaction[i].showRemaining()<<"\t";
            date[i].showDate();
            cout<<endl;
        }
    }
    void setPin(int PIN)
    {
        if(access) pin=PIN;
        access=false;
    }
    bool matchPin(int PIN)
    {
        if(PIN==pin && pin!=0) return true;
        return false;
    }
    void SaveCard(int num)
    {
            card[Card++]=num;
    }
    bool checkCard(int x)
    {
        for(int i=0; i<3; i++) {
                if(card[i]==0) return false;
                if(card[i]==x) {atmAccess=true; return true; }
        }
        return false;
    }
    void setAccountNumber(int kk)
    {
        if(access) AccountNumber=kk;
    }
    void changeAccountType(int jj)
    {
        if(access) accountType=jj;
    }
};
class ATM
{
    double ammount;
public:
    //ATM(ammount);
};
class Bank
{
    Costomer costomer[100];
    char Branch[50];
public:

};
int getArrow()
{
    char x;
    int k;
    while(!kbhit()){x=getch(); if(x==13) return 10;}
    x=getch();
    k=x;
    return k;
}
bool startBanking()
{
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    setcolor(1,12);
    for(int i=0; i<30; i++) {for(int j=1; j<5; j++) cout<<"                             "; cout<<endl;}
    COORD P;
    P.X=10;
    P.Y=5; setcolor(12,15);
    SetConsoleCursorPosition(hhh,P);
    cout<<"BANK";
    bool Banking=true;
    while(Banking)
    {
        ;
    }
    return true;
}
bool startATM()
{
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    COORD p;
    setcolor(10,14);
    bool processing=true;
    for(int i=0; i<30; i++) {for(int j=1; j<5; j++) cout<<"                             "; cout<<endl;}
    p.X=25; p.Y=5;
    SetConsoleCursorPosition(hhh,p);
    cout<<"ATM SERVICE\n";
    cout<<"\n\tPlease insert your card : ";
    int cardNumber;
    cin>>cardNumber;
    int cursor=1;
    while(processing)
    {

    }
    return true;
}
bool saveDataInAdiministrator()
{
    cout<<"saved\t\t"; return true;
}
void initializing()
{
    cout<<"yes initialized";
}
void NewPageLoad()
{
    system("CLS");
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    setcolor(0,15);
    COORD p;
    for(int i=0; i<30; i++) {for(int j=1; j<5; j++) cout<<"                             "; cout<<endl;}
    p.X=25; p.Y=5;
    setcolor(12,15);
    SetConsoleCursorPosition(hhh,p); cout<<"WELCOME TO THIS BANK\n\n\tATM SERVICE\n\n\tBANK SERVICE\n\n\tEXIT";
}
/*
int main()
{
    initializing();
    COORD p;
    HANDLE hhh=GetStdHandle(STD_OUTPUT_HANDLE);
    int x;
    NewPageLoad();
    int cursor=1;
    bool exitting=false,services=false;
    char xs;
    while(!exitting)
    {
        if(services) {NewPageLoad(); services=false;}
        if(cursor==1)
        {
            p.Y=7; p.X=8;
            SetConsoleCursorPosition(hhh,p);
            setcolor(15,10); cout<<"ATM SERVICE    ";
            setcolor(normal);
            xs=getch(); setcolor(12,15);
            SetConsoleCursorPosition(hhh,p); cout<<"ATM SERVICE    ";
        }
        else if(cursor==2)
        {
            p.Y=9; p.X=8;
            SetConsoleCursorPosition(hhh,p);
            setcolor(15,10); cout<<"BANK SERIVECE  ";
            setcolor(normal);
            xs=getch(); setcolor(12,15);
            SetConsoleCursorPosition(hhh,p); cout<<"BANK SERVICE   ";
        }
        else
        {
            p.Y=11; p.X=8;
            SetConsoleCursorPosition(hhh,p);
            setcolor(15,10); cout<<"EXIT           ";
            setcolor(normal);
            xs=getch(); setcolor(12,15);
            SetConsoleCursorPosition(hhh,p); cout<<"EXIT           ";
        }
        if(xs==UP)  cursor--;
        else if(xs==DOWN) cursor++;
        else if(xs==ENTER)
        {
            system("CLS");
            if(cursor==1) services=startATM();
            else if(cursor==2) services=startBanking();
            else
            {
                exitting=true;
                cout<<"SAVING DATA......";
                if(saveDataInAdiministrator())  cout<<endl<<"saved \n\t\tpress any key";
                else cout<<"not saved ";
                getch();
            }
        }
        else ;
        if(cursor==4) cursor=1;
        if(cursor==0) cursor=3;
    }
} */
int main()
{
    startATM();
}
