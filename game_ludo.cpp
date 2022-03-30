#include<iostream>
#include<cstdlib>
#include<conio.h>
#include"graphic.h"
using namespace std;
int UP=72,DOWN=80,LEFT=75,RIGHT=77,ENTER=13; // key handling
int getArrow()
{
    char x;
    int k;
    while(!kbhit()){x=getch(); if(x==13) return 10;}
    x=getch();
    k=x;
    return k;
}
void display();
void GameProgress2();
void GameProgress4();
char Map[4][22], Maps[4][22], Turns[16], V=-37,H=-2,S=-16,P=-36,Q=-33,T=-78;
char R,Y,B,G;
int Breaker[8]={1,9,14,22,27,35,40,48};     //stop position
int Red[4],Green[4],Blue[4],Yellow[4];
void Alive(int i,int Num) ;             // i for color and num for which
int Multiplayer=2;      //2 for duo and four four for quad
char PlayerTurn[4],stored[5];
int PlayerTurns;
int dice=0,Dice[5],stores=0,firstd=0,tds=0;   //firstd =1 for throw dice  2 for enter number
int ThrowDice()
{
    int k;
    cin>>k;
    firstd=0;
    stored[tds++] = k+48;
    return k;
}
void pop()
{
    for(int i=0; i<tds-1; i++) stored[i]=stored[i+1];
    for(int i=tds; i<5; i++) stored[i]=' ';
    tds--;
}
void Initilize()
{
    for(int i=0; i<4; i++) for(int j=0; j<18;j++) {Map[i][j]=' '; Maps[i][j]=' '; }
    for(int i=18; i<22; i++) Map[0][i] ='%'; //Red
    for(int i=18; i<22; i++) Map[1][i] ='@'; //Greeen
    for(int i=18; i<22; i++) Map[2][i] ='#'; //Yellow
    for(int i=18; i<22; i++) Map[3][i] =':'; //Blue
    for(int i=0; i<5; i++) stored[i]=' ';
}
void SDPosition(int SoD)        //SoD=1 for show
{
    if(Multiplayer==2)      //for duo
    {
        if(PlayerTurns==0)       //for Red
        {

        }
    }
    else            //for quad
    {

    }
}
void Alive(int i,int Num)
{
    if(i==1) Red[Num]=14;       //red at stop
    else if(i==2)  Green[Num] = 27; //Green at stop
    else if(i==3) Yellow[Num]= 40;    //Yellow at stop
    else Blue[Num]=1;   //Blue at stop
}
int Progress2()    // if another chance than return 1;
{
    int num;
    SDPosition(1);
    for(int j=0; j<stores; j++)
    {
        if(j==1) return 1;
        pop();
    }
    firstd=2;
    display();
    SDPosition(0);
    return 0;
}
int Progress4()    // if another chance than return 1;
{
    return 0;
}


int main()
{
    Initilize();
    cout<<"Enter Mode of Player \n\t1.. Duo\n\t2..Quad\n";
    int l,m;
    cin>>l;
    if(l==2)
    {
        Multiplayer=4;
        GameProgress4();
    }
    else
    {
        Multiplayer=2;
        GameProgress2();
    }
}

void display()
{
    system("CLS");
    int i=0;
    for(i=0; i<91; i++) cout<<P;
    cout<<"\n"<<V<<"                                   "<<V<<" ";
    cout<<Map[0][0]<<Map[0][0]<<Map[0][0]<<" "<<V<<" "<<Map[0][6]<<Map[0][6]<<Map[0][6]<<" "<<V<<" "<<Map[0][12]<<Map[0][12]<<Map[0][12];
    cout<<" "<<V<<"                                   "<<V<<"\n"<<V<<"                                   "<<V<<" ";
    cout<<Map[0][0]<<Maps[0][0]<<Map[0][0]<<" "<<V<<" "<<Map[0][6]<<Maps[0][6]<<Map[0][6]<<" "<<V<<" "<<Map[0][12]<<Maps[0][12]<<Map[0][12]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V<<"                                   "<<V<<H<<H<<H<<H<<H;
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<"                                   "<<V<<"\n"<<V<<"                                   "<<V<<" ";
    cout<<Map[0][1]<<Map[0][1]<<Map[0][1]<<" "<<V<<" "<<Map[0][7]<<Map[0][7]<<Map[0][7]<<" "<<V<<S<<Map[0][13]<<Map[0][13]<<Map[0][13]<<S<<V;
    cout<<"                                   "<<V<<"\n";
    cout<<V<<"          "<<Map[0][18]<<Map[0][18]<<Map[0][18]<<"          "<<Map[0][19]<<Map[0][19]<<Map[0][19]<<"         ";
    cout<<V<<" "<<Map[0][1]<<Maps[0][1]<<Map[0][1]<<" "<<V<<" "<<Map[0][7]<<Maps[0][7]<<Map[0][7]<<" "<<V<<S<<Map[0][13]<<Maps[0][13]<<Map[0][13]<<S<<V;
    cout<<"          "<<Map[1][18]<<Map[1][18]<<Map[1][18]<<"          "<<Map[1][19]<<Map[1][19]<<Map[1][19]<<"         "<<V<<"\n";
    cout<<V<<"          "<<Map[0][18]<<Maps[0][18]<<Map[0][18]<<"          "<<Map[0][19]<<Maps[0][19]<<Map[0][19]<<"         "<<V<<H<<H<<H<<H<<H;
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V;
    cout<<"          "<<Map[1][18]<<Maps[1][18]<<Map[1][18]<<"          "<<Map[1][19]<<Maps[1][19]<<Map[1][19]<<"         "<<V<<"\n";                     //============
    cout<<V<<"                                   ";
    cout<<V<<S<<Map[0][2]<<Map[0][2]<<Map[0][2]<<S<<V<<" "<<Map[0][8]<<Map[0][8]<<Map[0][8]<<" "<<V<<" "<<Map[0][14]<<Map[0][14]<<Map[0][14]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V<<"                 "<<PlayerTurn[0]<<PlayerTurn[0]<<"                ";
    cout<<V<<S<<Map[0][2]<<Maps[0][2]<<Map[0][2]<<S<<V<<" "<<Map[0][8]<<Maps[0][8]<<Map[0][8]<<" "<<V<<" "<<Map[0][14]<<Maps[0][14]<<Map[0][14]<<" "<<V;
    cout<<"                 "<<PlayerTurn[1]<<PlayerTurn[1]<<"                "<<V<<"\n"<<V<<"                                   ";
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<"                                   "<<V<<"\n"<<V<<"                                   ";
    cout<<V<<" "<<Map[0][3]<<Map[0][3]<<Map[0][3]<<" "<<V<<" "<<Map[0][9]<<Map[0][9]<<Map[0][9]<<" "<<V<<" "<<Map[0][15]<<Map[0][15]<<Map[0][15]<<" "<<V;
    cout<<"                                   "<<V<<"\n";       //============
    cout<<V<<"          "<<Map[0][20]<<Map[0][20]<<Map[0][20]<<"          "<<Map[0][21]<<Map[0][21]<<Map[0][21]<<"         ";
    cout<<V<<" "<<Map[0][3]<<Maps[0][3]<<Map[0][3]<<" "<<V<<" "<<Map[0][9]<<Maps[0][9]<<Map[0][9]<<" "<<V<<" "<<Map[0][15]<<Maps[0][15]<<Map[0][15]<<" "<<V;
    cout<<"          "<<Map[1][20]<<Map[1][20]<<Map[1][20]<<"          "<<Map[1][21]<<Map[1][21]<<Map[1][21]<<"         "<<V<<"\n";
    cout<<V<<"          "<<Map[0][20]<<Maps[0][20]<<Map[0][20]<<"          "<<Map[0][21]<<Maps[0][21]<<Map[0][21]<<"         ";
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V;
    cout<<"          "<<Map[1][20]<<Maps[1][20]<<Map[1][20]<<"          "<<Map[1][21]<<Maps[1][21]<<Map[1][21]<<"         "<<V<<"\n";//============
    cout<<V<<"                                   ";
    cout<<V<<" "<<Map[0][4]<<Map[0][4]<<Map[0][4]<<" "<<V<<" "<<Map[0][10]<<Map[0][10]<<Map[0][10]<<" "<<V<<" "<<Map[0][16]<<Map[0][16]<<Map[0][16]<<" "<<V;
    cout<<"                                   "<<V<<"\n";
    cout<<V<<"                                   ";
    cout<<V<<" "<<Map[0][4]<<Maps[0][4]<<Map[0][4]<<" "<<V<<" "<<Map[0][10]<<Maps[0][10]<<Map[0][10]<<" "<<V<<" "<<Map[0][16]<<Maps[0][16]<<Map[0][16]<<" "<<V;
    cout<<"                                   "<<V<<"\n";
    cout<<V<<"                                   "<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<"                                   "<<V;
    cout<<"\n"<<V<<"                                   ";
    cout<<V<<" "<<Map[0][5]<<Map[0][5]<<Map[0][5]<<" "<<V<<" "<<Map[0][11]<<Map[0][12]<<Map[0][12]<<" "<<V<<" "<<Map[0][17]<<Map[0][17]<<Map[0][17]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V<<"                                   ";
    cout<<V<<" "<<Map[0][5]<<Maps[0][5]<<Map[0][5]<<" "<<V<<" "<<Map[0][11]<<Maps[0][12]<<Map[0][12]<<" "<<V<<" "<<Map[0][17]<<Maps[0][17]<<Map[0][17]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V;
    for(i=0; i<89; i++) cout<<H;
    cout<<V<<"\n"<<V;


    cout<<" "<<Map[3][12]<<Map[3][12]<<Map[3][12]<<" "<<V<<S<<Map[3][13]<<Map[3][13]<<Map[3][13]<<S<<V<<" "<<Map[3][14]<<Map[3][14]<<Map[3][14]<<" "<<V<<" ";
    cout<<Map[3][15]<<Map[3][15]<<Map[3][15]<<" "<<V<<" "<<Map[3][16]<<Map[3][16]<<Map[3][16]<<" "<<V<<" "<<Map[3][17]<<Map[3][17]<<Map[3][17]<<" "<<V;
    cout<<"                 "<<V<<" ";
    cout<<Map[1][17]<<Map[1][17]<<Map[1][17]<<" "<<V<<" "<<Map[1][16]<<Map[1][16]<<Map[1][16]<<" "<<V<<" "<<Map[1][15]<<Map[1][15]<<Map[1][15]<<" "<<V<<S;
    cout<<Map[1][14]<<Map[1][14]<<Map[1][14]<<S<<V<<" "<<Map[1][13]<<Map[1][13]<<Map[1][13]<<" "<<V<<" "<<Map[1][12]<<Map[1][12]<<Map[1][12]<<" "<<V<<"\n"<<V;//====
    cout<<" "<<Map[3][12]<<Maps[3][12]<<Map[3][12]<<" "<<V<<S<<Map[3][13]<<Maps[3][13]<<Map[3][13]<<S<<V<<" "<<Map[3][14]<<Maps[3][14]<<Map[3][14]<<" "<<V<<" ";
    cout<<Map[3][15]<<Maps[3][15]<<Map[3][15]<<" "<<V<<" "<<Map[3][16]<<Maps[3][16]<<Map[3][16]<<" "<<V<<" "<<Map[3][17]<<Maps[3][17]<<Map[3][17]<<" "<<V;
    if(firstd==2) cout<<"  ENTER  NUMBER  "; else if(firstd==1) cout<<"   THROW  DICE   ";  else cout<<"                 ";
    cout<<V<<" "<<Map[1][17]<<Maps[1][17]<<Map[1][17]<<" "<<V<<" "<<Map[1][16]<<Maps[1][16]<<Map[1][16]<<" "<<V<<" "<<Map[1][15]<<Maps[1][15]<<Map[1][15]<<" "<<V<<S;
    cout<<Map[1][14]<<Maps[1][14]<<Map[1][14]<<S<<V<<" "<<Map[1][13]<<Maps[1][13]<<Map[1][13]<<" "<<V<<" "<<Map[1][12]<<Maps[1][12]<<Map[1][12]<<" "<<V<<"\n"<<V;//====
    for(i=0; i<35; i++) cout<<H; cout<<V<<"                 "<<V; for(i=0; i<35; i++) cout<<H; cout<<V<<"\n"<<V;    //====================

    cout<<" "<<Map[3][6]<<Map[3][6]<<Map[3][6]<<" "<<V<<" "<<Map[3][7]<<Map[3][7]<<Map[3][7]<<" "<<V<<" "<<Map[3][8]<<Map[3][8]<<Map[3][8]<<" "<<V<<" ";
    cout<<Map[3][9]<<Map[3][9]<<Map[3][9]<<" "<<V<<" "<<Map[3][10]<<Map[3][10]<<Map[3][10]<<" "<<V<<" "<<Map[3][11]<<Map[3][11]<<Map[3][11]<<" "<<V;
    cout<<"        "<<dice<<"        "<<V<<" ";
    cout<<Map[1][11]<<Map[1][11]<<Map[1][11]<<" "<<V<<" "<<Map[1][10]<<Map[1][10]<<Map[1][10]<<" "<<V<<" "<<Map[1][9]<<Map[1][9]<<Map[1][9]<<" "<<V<<" ";
    cout<<Map[1][8]<<Map[1][8]<<Map[1][8]<<" "<<V<<" "<<Map[1][7]<<Map[1][7]<<Map[1][7]<<" "<<V<<" "<<Map[1][6]<<Map[1][6]<<Map[1][6]<<" "<<V<<"\n"<<V;//====
    cout<<" "<<Map[3][6]<<Maps[3][6]<<Map[3][6]<<" "<<V<<" "<<Map[3][7]<<Maps[3][7]<<Map[3][7]<<" "<<V<<" "<<Map[3][8]<<Maps[3][8]<<Map[3][8]<<" "<<V<<" ";
    cout<<Map[3][9]<<Maps[3][9]<<Map[3][9]<<" "<<V<<" "<<Map[3][10]<<Maps[3][10]<<Map[3][10]<<" "<<V<<" "<<Map[3][11]<<Maps[3][11]<<Map[3][11]<<" "<<V;
    cout<<"                 "<<V<<" ";
    cout<<Map[1][11]<<Maps[1][11]<<Map[1][11]<<" "<<V<<" "<<Map[1][10]<<Maps[1][10]<<Map[1][10]<<" "<<V<<" "<<Map[1][9]<<Maps[1][9]<<Map[1][9]<<" "<<V<<" ";
    cout<<Map[1][8]<<Maps[1][8]<<Map[1][8]<<" "<<V<<" "<<Map[1][7]<<Maps[1][7]<<Map[1][7]<<" "<<V<<" "<<Map[1][6]<<Maps[1][6]<<Map[1][6]<<" "<<V<<"\n"<<V;//====
    for(i=0; i<35; i++) cout<<H; cout<<V<<"                 "<<V; for(i=0; i<35; i++) cout<<H; cout<<V<<"\n"<<V;    //====================

    cout<<" "<<Map[3][0]<<Map[3][0]<<Map[3][0]<<" "<<V<<" "<<Map[3][1]<<Map[3][1]<<Map[3][1]<<" "<<V<<S<<Map[3][2]<<Map[3][2]<<Map[3][2]<<S<<V<<" ";
    cout<<Map[3][3]<<Map[3][3]<<Map[3][3]<<" "<<V<<" "<<Map[3][4]<<Map[3][4]<<Map[3][4]<<" "<<V<<" "<<Map[3][5]<<Map[3][5]<<Map[3][5]<<" "<<V;
    cout<<"  "<<stored[0]<<"  "<<stored[1]<<"  "<<stored[2]<<"  "<<stored[3]<<"  "<<stored[4]<<"  ";
    cout<<V<<" "<<Map[1][5]<<Map[1][5]<<Map[1][5]<<" "<<V<<" "<<Map[1][4]<<Map[1][4]<<Map[1][4]<<" "<<V<<" "<<Map[1][3]<<Map[1][3]<<Map[1][3]<<" "<<V<<" ";
    cout<<Map[1][2]<<Map[1][2]<<Map[1][2]<<" "<<V<<S<<Map[1][1]<<Map[1][1]<<Map[1][1]<<S<<V<<" "<<Map[1][0]<<Map[1][0]<<Map[1][0]<<" "<<V<<"\n"<<V;//====
    cout<<" "<<Map[3][0]<<Maps[3][0]<<Map[3][0]<<" "<<V<<" "<<Map[3][1]<<Maps[3][1]<<Map[3][1]<<" "<<V<<S<<Map[3][2]<<Maps[3][2]<<Map[3][2]<<S<<V<<" ";
    cout<<Map[3][3]<<Maps[3][3]<<Map[3][3]<<" "<<V<<" "<<Map[3][4]<<Maps[3][4]<<Map[3][4]<<" "<<V<<" "<<Map[3][5]<<Maps[3][5]<<Map[3][5]<<" "<<V;
    cout<<"                 ";
    cout<<V<<" "<<Map[1][5]<<Maps[1][5]<<Map[1][5]<<" "<<V<<" "<<Map[1][4]<<Maps[1][4]<<Map[1][4]<<" "<<V<<" "<<Map[1][3]<<Maps[1][3]<<Map[1][3]<<" "<<V<<" ";
    cout<<Map[1][2]<<Maps[1][2]<<Map[1][2]<<" "<<V<<S<<Map[1][1]<<Maps[1][1]<<Map[1][1]<<S<<V<<" "<<Map[1][0]<<Maps[1][0]<<Map[1][0]<<" "<<V<<"\n"<<V;//====




    for(i=0; i<89; i++) cout<<H;
    cout<<V<<"\n"<<V<<"                                   "<<V<<" ";
    cout<<Map[2][0]<<Map[2][0]<<Map[2][0]<<" "<<V<<" "<<Map[2][6]<<Map[2][6]<<Map[2][6]<<" "<<V<<" "<<Map[2][12]<<Map[2][12]<<Map[2][12];
    cout<<" "<<V<<"                                   "<<V<<"\n"<<V<<"                                   "<<V<<" ";
    cout<<Map[2][0]<<Maps[2][0]<<Map[2][0]<<" "<<V<<" "<<Map[2][6]<<Maps[2][6]<<Map[2][6]<<" "<<V<<" "<<Map[2][12]<<Maps[2][12]<<Map[2][12]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V<<"                                   "<<V<<H<<H<<H<<H<<H;
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<"                                   "<<V<<"\n"<<V<<"                                   "<<V<<" ";
    cout<<Map[2][1]<<Map[2][1]<<Map[2][1]<<" "<<V<<" "<<Map[2][7]<<Map[2][7]<<Map[2][7]<<" "<<V<<" "<<Map[2][13]<<Map[2][13]<<Map[2][13]<<" "<<V;
    cout<<"                                   "<<V<<"\n";   //=========
    cout<<V<<"          "<<Map[3][18]<<Map[3][18]<<Map[3][18]<<"          "<<Map[3][19]<<Map[3][19]<<Map[3][19]<<"         ";
    cout<<V<<" "<<Map[2][1]<<Maps[2][1]<<Map[2][1]<<" "<<V<<" "<<Map[2][7]<<Maps[2][7]<<Map[2][7]<<" "<<V<<" "<<Map[2][13]<<Maps[2][13]<<Map[2][13]<<" "<<V;
    cout<<"          "<<Map[2][18]<<Map[2][18]<<Map[2][18]<<"          "<<Map[2][19]<<Map[2][19]<<Map[2][19]<<"         "<<V<<"\n"; //===
    cout<<V<<"          "<<Map[3][18]<<Maps[3][18]<<Map[3][18]<<"          "<<Map[3][19]<<Maps[3][19]<<Map[3][19]<<"         "<<V<<H<<H<<H<<H<<H;
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V;
    cout<<"          "<<Map[2][18]<<Maps[2][18]<<Map[2][18]<<"          "<<Map[2][19]<<Maps[2][19]<<Map[2][19]<<"         "<<V<<"\n";                     //============
    cout<<V<<"                                   ";
    cout<<V<<" "<<Map[2][2]<<Map[2][2]<<Map[2][2]<<" "<<V<<" "<<Map[2][8]<<Map[2][8]<<Map[2][8]<<" "<<V<<" "<<Map[2][14]<<Map[2][14]<<Map[2][14]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V<<"                 "<<PlayerTurn[3]<<PlayerTurn[3]<<"                ";
    cout<<V<<" "<<Map[2][2]<<Maps[2][2]<<Map[2][2]<<" "<<V<<" "<<Map[2][8]<<Maps[2][8]<<Map[2][8]<<" "<<V<<" "<<Map[2][14]<<Maps[2][14]<<Map[2][14]<<" "<<V;
    cout<<"                 "<<PlayerTurn[2]<<PlayerTurn[2]<<"                "<<V<<"\n"<<V<<"                                   ";
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<"                                   "<<V<<"\n"<<V<<"                                   ";
    cout<<V<<" "<<Map[2][3]<<Map[2][3]<<Map[2][3]<<" "<<V<<" "<<Map[2][9]<<Map[2][9]<<Map[2][9]<<" "<<V<<S<<Map[2][15]<<Map[2][15]<<Map[2][15]<<S<<V;
    cout<<"                                   "<<V<<"\n";       //============
    cout<<V<<"          "<<Map[3][20]<<Map[3][20]<<Map[3][20]<<"          "<<Map[3][21]<<Map[3][21]<<Map[3][21]<<"         ";
    cout<<V<<" "<<Map[2][3]<<Maps[2][3]<<Map[2][3]<<" "<<V<<" "<<Map[2][9]<<Maps[2][9]<<Map[2][9]<<" "<<V<<S<<Map[2][15]<<Maps[2][15]<<Map[2][15]<<S<<V;
    cout<<"          "<<Map[2][20]<<Map[2][20]<<Map[2][20]<<"          "<<Map[2][21]<<Map[2][21]<<Map[2][21]<<"         "<<V<<"\n"; //=====================
    cout<<V<<"          "<<Map[3][20]<<Maps[3][20]<<Map[3][20]<<"          "<<Map[3][21]<<Maps[3][21]<<Map[3][21]<<"         ";
    cout<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V;
    cout<<"          "<<Map[2][20]<<Maps[2][20]<<Map[2][20]<<"          "<<Map[2][21]<<Maps[2][21]<<Map[2][21]<<"         "<<V<<"\n";//============
    cout<<V<<"                                   ";
    cout<<V<<S<<Map[2][4]<<Map[2][4]<<Map[2][4]<<S<<V<<" "<<Map[2][10]<<Map[2][10]<<Map[2][10]<<" "<<V<<" "<<Map[2][16]<<Map[2][16]<<Map[2][16]<<" "<<V;
    cout<<"                                   "<<V<<"\n";
    cout<<V<<"                                   ";
    cout<<V<<S<<Map[2][4]<<Maps[2][4]<<Map[2][4]<<S<<V<<" "<<Map[2][10]<<Maps[2][10]<<Map[2][10]<<" "<<V<<" "<<Map[2][16]<<Maps[2][16]<<Map[2][16]<<" "<<V;
    cout<<"                                   "<<V<<"\n";
    cout<<V<<"                                   "<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<H<<H<<H<<H<<H<<V<<"                                   "<<V;
    cout<<"\n"<<V<<"                                   ";
    cout<<V<<" "<<Map[2][5]<<Map[2][5]<<Map[2][5]<<" "<<V<<" "<<Map[2][11]<<Map[2][12]<<Map[2][12]<<" "<<V<<" "<<Map[2][17]<<Map[2][17]<<Map[2][17]<<" "<<V;
    cout<<"                                   "<<V<<"\n"<<V<<"                                   ";
    cout<<V<<" "<<Map[2][5]<<Maps[2][5]<<Map[2][5]<<" "<<V<<" "<<Map[2][11]<<Maps[2][12]<<Map[2][12]<<" "<<V<<" "<<Map[2][17]<<Maps[2][17]<<Map[2][17]<<" "<<V;
    cout<<"                                   "<<V<<"\n";
    for(i=0; i<91; i++) cout<<Q;
    cout<<"\n";
}

void GameProgress4()
{
    int GameContinue=1,NextTerm=1,DontMove=0,stores=0;
    while(GameContinue)
    {
        PlayerTurns=1;  NextTerm=1; DontMove=0;
        int six=0;  stores=0; dice=0;
        PlayerTurn[0]=T; PlayerTurn[1]=' '; PlayerTurn[2]=' '; PlayerTurn[3]=' ';     //showing turns 1
        firstd=1;   display();
        while(NextTerm)
        {
            getch();
            dice=ThrowDice();
            display();
            if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
            else NextTerm=0;
            Dice[stores++]=dice;
        }
        while(!DontMove && Progress4())
        {
            firstd=1;   display();
            six=0; NextTerm=1;    DontMove=0;
            while(NextTerm)
            {
                getch();
                dice=ThrowDice();
                display();
                if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
                else NextTerm=0;
                Dice[stores++]=dice;
            }
        }
        six=0;  stores=0;   NextTerm=1; DontMove=0;
        PlayerTurns=2; dice=0;
        PlayerTurn[0]=' '; PlayerTurn[1]=T; PlayerTurn[2]=' '; PlayerTurn[3]=' ';     //showing turns 2
        firstd=1;   display();
        while(NextTerm)
        {
            getch();
            dice=ThrowDice();
            display();
            if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
            else NextTerm=0;
            Dice[stores++]=dice;
        }
        while(!DontMove && Progress4())
        {
             six=0; NextTerm=1;    DontMove=0;
             firstd=1;   display();
            while(NextTerm)
            {
                getch();
                dice=ThrowDice();
                display();
                if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0;  DontMove=1;}}
                else NextTerm=0;
                Dice[stores++]=dice;
            }
        }
        PlayerTurns=3;  NextTerm=1; DontMove=0;
        six=0;  stores=0; dice=0;
        PlayerTurn[0]=' '; PlayerTurn[1]=' '; PlayerTurn[2]=T;  PlayerTurn[3]=' ';     //showing turns 3
        firstd=1;   display();
        while(NextTerm)
        {
            getch();
            dice=ThrowDice();
            display();
            if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
            else NextTerm=0;
            Dice[stores++]=dice;
        }
        while(!DontMove && Progress4())
        {
            six=0; NextTerm=1;    DontMove=0;
            firstd=1;   display();
            while(NextTerm)
            {
                getch();
                dice=ThrowDice();
                display();
                if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
                else NextTerm=0;
                Dice[stores++]=dice;
            }
        }
        PlayerTurns=1;  NextTerm=1; DontMove=0;
        six=0;  stores=0; dice=0;
        PlayerTurn[0]=' '; PlayerTurn[1]=' '; PlayerTurn[2]=' '; PlayerTurn[3]=T;     //showing turns 4
        firstd=1;   display();
        while(NextTerm)
        {
            getch();
            dice=ThrowDice();
            display();
            if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
            else NextTerm=0;
            Dice[stores++]=dice;
        }
        while(!DontMove && Progress4())
        {
            six=0; NextTerm=1;    DontMove=0;
            firstd=1;   display();
            while(NextTerm)
            {
                getch();
                dice=ThrowDice();
                display();
                if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
                else NextTerm=0;
                Dice[stores++]=dice;
            }
        }
    }
}

void GameProgress2()
{
    int GameContinue=1,NextTerm=1,DontMove=0;
    while(GameContinue)
    {
        PlayerTurns=1;  NextTerm=1; DontMove=0;
        int six=0;  dice=0; stores=0;
        PlayerTurn[0]=T; PlayerTurn[1]=' '; PlayerTurn[2]=T; PlayerTurn[3]=' ';     //showing turns
        firstd=1;   display();
        while(NextTerm)
        {
            getch();
            dice=ThrowDice();
            display();
            if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
            else NextTerm=0;
            Dice[stores++]=dice;
        }
        while(!DontMove && Progress2())
        {
            six=0; NextTerm=1;    DontMove=0;
            firstd=1;   display();
            while(NextTerm)
            {
                getch();
                dice=ThrowDice();
                display();
                if(dice==6) {six++;  if(six==3) {NextTerm=0;tds=0;  DontMove=1;}  }
                else NextTerm=0;
                Dice[stores++]=dice;
            }
        }
        six=0;     NextTerm=1; DontMove=0;
        PlayerTurns=2; dice=0; stores=0;
        PlayerTurn[0]=' '; PlayerTurn[1]=T; PlayerTurn[2]=' '; PlayerTurn[3]=T;     //showing turns
        firstd=1;   display();
        while(NextTerm)
        {
            getch();
            dice=ThrowDice();
            display();
            if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}  }
            else NextTerm=0;
            Dice[stores++]=dice;
        }
        while(!DontMove && Progress2())
        {
            six=0; NextTerm=1;    DontMove=0;
            firstd=1;   display();
            while(NextTerm)
            {
                getch();
                dice=ThrowDice();
                display();
                if(dice==6) {six++;  if(six==3) {NextTerm=0; tds=0; DontMove=1;}}
                else NextTerm=0;
                Dice[stores++]=dice;
            }
        }
    }
}










