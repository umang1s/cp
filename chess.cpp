#include<iostream>         // /  BlockObject[9][9],     LiveStatus[2][2][8]={0} ,     PlayerMove[12]={0}
#include<stdlib.h>
#include"graphic.h"
using namespace std;
class Chess
{
    int Player1Move,Player2Move,GameAbort,winner,Err,Turn,Player1MoveHistory[2][300],Player2MoveHistory[2][300];
    int BlockObject[9][9],LiveStatus[2][2][8] ,PlayerMove[32]={0},ErrorCount[20],check;
    string Player1,Player2;
public :
    void SetPlayerName()    {cout<<"enter first player name : "; cin>>Player1; cout<<"enter second player name : "; cin>>Player2;}
    void ResetBoard();
    void DisplayBoard();
    void Position(int ,int);
    void Error(int );
    void GameProgress();
    void UpdateDead(int);
    void DeadPlayer(int);  // 1,2,3,4
    int ValidMove(int,int,int,int);  //0,1,2,3
    int CheckStatus(int,int,int);
    int MatchDraw();
    int Convert1Dto2D(int taken)   {int k=0;    for(int i=1; i<9; i++) for(int j=1; j<9; j++)  {    if(taken-1==k) return 10*i + j;            k++;   }}
};


int Chess::ValidMove(int Vi,int Hi,int Vf,int Hf)
{
    int i,j,tat;
    i=Vf-Vi;    j=Hf-Hi;
    switch(BlockObject[Vi][Hi])
    {
        case 5: case 29:                           //king
        {
            if(i==1 && j==1) return 0;
            else if(i==1 && j==0) return 0;
            else if(i==1 && j==-1) return 0;
            else if(i==0 && j==-1) return 0;
            else if(i==0 && j==0) return 0;
            else if(i==0 && j==1)  return 0;
            else if(i==-1 && j==-1) return 0;
            else if(i==-1 && j==0) return 0;
            else if(i==-1 && j==1) return 0;
            else return 1;
            break;
        }
        case 4: case 28:                           //queen
        {
            if(i==-j)
            {
                if(i<0) //down-left
                {
                    for(int bs=Vi+1,bd=Hi-1; Vi<Vf && Hi>Hf; bs++,bd--) {if(BlockObject[bs][bd]!=0) return 2;}
                    return 0;
                }
                else //up-right
                {
                    for(int bs=Vi-1,bd=Hi+1; Vi>Vf && Hi<Hf; bs--,bd++) {if(BlockObject[bs][bd]!=0) return 2;}
                    return 0;
                }

            }
            else if(i==j)
            {
                if(i<0) //left-up
                {
                   for(int bs=Vi+1,bd=Hi+1; Vi<Vf && Hi<Hf; bs++,bd++) if(BlockObject[bs][bd]!=0) return 2;
                   return 0;
                }
                else //right-down
                {
                    for(int bs=Vi-1,bd=Hi-1; Vi>Vf && Hi>Hf; bs--,bd--) if(BlockObject[bs][bd]!=0) return 2;
                    return 0;
                }
            }
            else if(i==0)
            {
                if(j<0){ for(int ls=Hi-1; ls>Hf; ls--) {if(BlockObject[Vf][ls]!=0) return 2;}return 0;}
                else {for(int ls=Hi+1; ls<Hf; ls++) {if(BlockObject[Vf][ls]!=0) return 2;}return 0;}
            }
            else if(j==0)
            {
                if(i<0){for(int ls=Vi-1; ls>Vf; ls--) if(BlockObject[ls][Hf]!=0) return 2;return 0;}
                else {for(int ls=Vi+1; ls<Vf; ls++) if(BlockObject[ls][Hf]!=0) return 2;return 0;}
            }
            else return 1; break;
        }
        case 1: case 8: case 25: case 32:          //rook
        {
            if(i==0)
            {
                if(j<0){ for(int ls=Hi-1; ls>Hf; ls--) {if(BlockObject[Vf][ls]!=0) return 2;}return 0;}
                else {for(int ls=Hi+1; ls<Hf; ls++) {if(BlockObject[Vf][ls]!=0) return 2;}return 0;}
            }
            else if(j==0)
            {
                if(i<0){for(int ls=Vi-1; ls>Vf; ls--) if(BlockObject[ls][Hf]!=0) return 2;return 0;}
                else {for(int ls=Vi+1; ls<Vf; ls++) if(BlockObject[ls][Hf]!=0) return 2;return 0;}
            }
            else return 1; break;
        }
        case 3 : case 6: case 27: case 30:         //bishop
        {
            if(i==-j)
            {
                if(i<0) //down-left
                {
                    for(int bs=Vi+1,bd=Hi-1; Vi<Vf && Hi>Hf; bs++,bd--) {if(BlockObject[bs][bd]!=0) return 2;}
                    return 0;
                }
                else //up-right
                {
                    for(int bs=Vi-1,bd=Hi+1; Vi>Vf && Hi<Hf; bs--,bd++) {if(BlockObject[bs][bd]!=0) return 2;}
                    return 0;
                }

            }
            else if(i==j)
            {
                if(i<0) //left-up
                {
                   for(int bs=Vi+1,bd=Hi+1; Vi<Vf && Hi<Hf; bs++,bd++) if(BlockObject[bs][bd]!=0) return 2;
                   return 0;
                }
                else //right-down
                {
                    for(int bs=Vi-1,bd=Hi-1; Vi>Vf && Hi>Hf; bs--,bd--) if(BlockObject[bs][bd]!=0) return 2;
                    return 0;
                }
            }
            else return 1; break;
        }
        case 2 : case 7: case 26: case 31:         //knight
        {
            if(i==2 && j==1) return 0;  //down-right
            else if(i==2 && j==-1) return 0;    //down-left
            else if(i==-2 && j==1) return 0;    //up-right
            else if(i==-2 && j==-1) return 0;    //up-left
            else if(i==1 && j==2)  return 0;    //right-down
            else if(i==1 && j==-2) return 0;    //left-down
            else if(i==-1 && j==2) return 0;    //right-up
            else if(i==-1 && j==-2) return 0;   //left-up
            else return 1; break;

        }
        case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16:         // white pawn
        {
            if(i==1 && j==0) {if(BlockObject[Vi+1][Hi]==0) return 0; else return 2; }     // down
            else if(i==2 && j==0){if(PlayerMove[BlockObject[Vi][Hi]]==0 && BlockObject[Vi+1][Hi]==0 && BlockObject[Vi+2][Hi]==0)
                {PlayerMove[BlockObject[Vi][Hi]]++; return 0;} else return 2; }    // down two step
            else if(i==1 && j==-1){ if(BlockObject[Vf+1][Hf-1]<33 && BlockObject[Vf+1][Hf-1]>16) return 0; else return 1; }  //down-left
            else if(i==1 && j==1) {if(BlockObject[Vf+1][Hf+1]<33 && BlockObject[Vf+1][Hf+1]>16) return 0; else return 1; }   //down-right
            else return 1; break;
        }
        case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24:        //black pawn
        {
            if(i==-1 && j==0) {if(BlockObject[Vi-1][Hi]==0) return 0; else return 2; }  //up single step
            else if(i==-2 && j==0) {if(PlayerMove[BlockObject[Vi][Hi]]==0  && BlockObject[Vi-1][Hi]==0 && BlockObject[Vi-2][Hi]==0)
                {PlayerMove[BlockObject[Vi][Hi]]++; return 0;} else return 2; }  // up two step
            else if(i==-1 && j==-1) {if(BlockObject[Vf-1][Hf-1]<17 && BlockObject[Vf-1][Hf-1]>0) return 0; else return 1;}  //up-left
            else if(i==-1 && j==1) {if(BlockObject[Vf-1][Hf+1]<17 && BlockObject[Vf-1][Hf+1]>0) return 0; else return 1;}    //up-right
            else return 1; break;
        }
    }
}


void Chess::GameProgress()
{
    int Here,There,Hi,Hf,Vi,Vf,done,CheckS;
    while(GameAbort)
    {
       DisplayBoard();
       cin>>Here>>There;
       if(Here<65 && Here>0 && There<65 && There >0)
       {
           Hi=Convert1Dto2D(Here)%10;    Vi=Convert1Dto2D(Here)/10;   Hf=Convert1Dto2D(There)%10;    Vf=Convert1Dto2D(There)/10;
           if(Turn==1 && BlockObject[Vi][Hi]<17 && BlockObject[Vi][Hi]>0)
           {
                if(BlockObject[Vf][Hf]<17 && BlockObject[Vf][Hf]>0) Error(3);
                else
                {
                    done=ValidMove(Vi,Hi,Vf,Hf);
                    if(done==0)         // *****************succussfully moved
                    {
                        Player1MoveHistory[0][Player1Move]=Here;    Player1MoveHistory[1][Player1Move++]=There;     //store history
                        if(BlockObject[Vf][Hf]!=0) UpdateDead(BlockObject[Vf][Hf]);                         // for updating dead player
                        BlockObject[Vf][Hf]=BlockObject[Vi][Hi];
                        BlockObject[Vi][Hi]=0;
                        Turn++;
                    }
                    else if(done==1) Error(4);   // move are invalid
                    else Error(5);   // there are some player b/t positions
                }
           }
           else if(Turn==2 && BlockObject[Vi][Hi]<33 && BlockObject[Vi][Hi]>16)
           {
               if(BlockObject[Vf][Hf]<33 && BlockObject[Vf][Hf]>16) Error(3);
               else
               {
                    done=ValidMove(Vi,Hi,Vf,Hf);
                    if(done==0)         // *****************succussfully moved
                    {
                        Player2MoveHistory[0][Player2Move]=Here;    Player2MoveHistory[1][Player2Move++]=There;   // store history
                        if(BlockObject[Vf][Hf]!=0) UpdateDead(BlockObject[Vf][Hf]);                         // for updating dead player
                        BlockObject[Vf][Hf]=BlockObject[Vi][Hi];
                        BlockObject[Vi][Hi]=0;
                        Turn--;
                    }
                    else if(done==1) Error(4);   // move are invalid
                    else Error(5);   // there are some player b/t positions
               }
           }
           else {Error(2);   GameProgress();}
       }
       else Error(1);
    }
}



int main()
{
    Chess chess;
    chess.SetPlayerName();
    chess.ResetBoard();
    chess.DisplayBoard();
    chess.GameProgress();
}


void Chess::Position(int i,int j)
{
    char c=-78;
    int l=BlockObject[i][j];
    switch(l)
    {
        case 0: if((i+j)%2==0)  cout<<c<<c<<c<<c<<c<<c;
                else cout<<"      ";break;
        //white
       case 5:  cout<<" KING "; break;
       case 4: cout<<" QUEEN";  break;
       case 1: case 8: cout<<" ROOK "; break;
       case 3: case 6: cout<<"BISHOP"; break;
       case 2: case 7: cout<<"KNIGHT"; break;
       case 9: case 10: case 11: case 12: case 13: case 14: case 15: case 16: cout<<" PAWN "; break;
       //Black
       case 29: cout<<" king "; break;
       case 28: cout<<" queen"; break;
       case 25: case 32: cout<<" rook "; break;
       case 27: case 30: cout<<"bishop"; break;
       case 26: case 31: cout<<"knight"; break;
       case 17: case 18: case 19: case 20: case 21: case 22: case 23: case 24: cout<<" pawn "; break;
       default: break;
    }
}

void Chess::DisplayBoard()
{
    char a=-33,b=-36,c=-37,d=-78;
    system("CLS");   Error(0);
    for(int i=0;i<82; i++) cout<<b; cout<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d;         Position(1,1);
    cout<<d<<d<<"  ";      Position(1,2);
    cout<<"  "<<d<<d;      Position(1,3);
    cout<<d<<d<<"  ";      Position(1,4);
    cout<<"  "<<d<<d;      Position(1,5);
    cout<<d<<d<<"  ";      Position(1,6);
    cout<<"  "<<d<<d;      Position(1,7);
    cout<<d<<d<<"  ";      Position(1,8);        cout<<"  "<<c<<"\tMove : "<<Player1Move<<endl;
    cout<<c<<d<<d<<d<<d<<"01"<<d<<d<<d<<d<<"    02    "<<d<<d<<d<<d<<"03"<<d<<d<<d<<d<<"    04    "<<d<<d<<d<<d<<"05"<<d<<d<<d<<d<<"    06    "<<d<<d<<d<<d;
    cout<<"07"<<d<<d<<d<<d<<"     08   "<<c;    if(Turn==1) cout<<"\tYour Turn"; if(check==1) cout<<"\tcheck";    cout<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    //first row completed
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"  ";          Position(2,1);
    cout<<"  "<<d<<d;       Position(2,2);
    cout<<d<<d<<"  ";       Position(2,3);
    cout<<"  "<<d<<d;       Position(2,4);
    cout<<d<<d<<"  ";       Position(2,5);
    cout<<"  "<<d<<d;       Position(2,6);
    cout<<d<<d<<"  ";       Position(2,7);
    cout<<"  "<<d<<d;       Position(2,8);   cout<<d<<d<<c<<"\t"<<Player1<<" killed :  ";    DeadPlayer(1);            cout<<endl;
    cout<<c<<"    09    "<<d<<d<<d<<d<<"10"<<d<<d<<d<<d<<"    11    "<<d<<d<<d<<d<<"12"<<d<<d<<d<<d<<"     13   "<<d<<d<<d<<d<<"14"<<d<<d<<d<<d;
    cout<<"    15    "<<d<<d<<d<<d<<"16"<<d<<d<<d<<d<<c;
    cout<<"\t\t   "; DeadPlayer(2); cout<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    //second row completed
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d;         Position(3,1);
    cout<<d<<d<<"  ";       Position(3,2);
    cout<<"  "<<d<<d;       Position(3,3);
    cout<<d<<d<<"  ";       Position(3,4);
    cout<<"  "<<d<<d;         Position(3,5);
    cout<<d<<d<<"  ";       Position(3,6);
    cout<<"  "<<d<<d;       Position(3,7);
    cout<<d<<d<<"  ";       Position(3,8);    cout<<"  "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<"17"<<d<<d<<d<<d<<"    18    "<<d<<d<<d<<d<<"19"<<d<<d<<d<<d<<"    20    "<<d<<d<<d<<d<<"21"<<d<<d<<d<<d<<"    22    ";
    cout<<d<<d<<d<<d<<"23"<<d<<d<<d<<d<<"    24    "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    //third row completed
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"  ";         Position(4,1);
    cout<<"  "<<d<<d;       Position(4,2);
    cout<<d<<d<<"  ";       Position(4,3);
    cout<<"  "<<d<<d;       Position(4,4);
    cout<<d<<d<<"  ";       Position(4,5);
    cout<<"  "<<d<<d;       Position(4,6);
    cout<<d<<d<<"  ";       Position(4,7);
    cout<<"  "<<d<<d;       Position(4,8);   cout<<d<<d<<c<<endl;
    cout<<c<<"    25    "<<d<<d<<d<<d<<"26"<<d<<d<<d<<d<<"    27    "<<d<<d<<d<<d<<"28"<<d<<d<<d<<d<<"     29   "<<d<<d<<d<<d<<"30"<<d<<d<<d<<d;
    cout<<"    31    "<<d<<d<<d<<d<<"32"<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    //fourth row completed
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<"\tPlayer2 : "<<Player2<<endl;
    cout<<c<<d<<d;         Position(5,1);
    cout<<d<<d<<"  ";       Position(5,2);
    cout<<"  "<<d<<d;       Position(5,3);
    cout<<d<<d<<"  ";       Position(5,4);
    cout<<"  "<<d<<d;       Position(5,5);
    cout<<d<<d<<"  ";       Position(5,6);
    cout<<"  "<<d<<d;       Position(5,7);
    cout<<d<<d<<"  ";       Position(5,8);               cout<<"  "<<c<<"\tMove : "<<Player2Move<<endl;
    cout<<c<<d<<d<<d<<d<<"33"<<d<<d<<d<<d<<"    34    "<<d<<d<<d<<d<<"35"<<d<<d<<d<<d<<"    36    "<<d<<d<<d<<d<<"37"<<d<<d<<d<<d<<"    38    ";
    cout<<d<<d<<d<<d<<"39"<<d<<d<<d<<d<<"    40    "<<c;   if(Turn==2) cout<<"\tYour Turn";if(check==2) cout<<"\tcheck"; cout<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    //5th row completed
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"  ";         Position(6,1);
    cout<<"  "<<d<<d;       Position(6,2);
    cout<<d<<d<<"  ";       Position(6,3);
    cout<<"  "<<d<<d;       Position(6,4);
    cout<<d<<d<<"  ";       Position(6,5);
    cout<<"  "<<d<<d;       Position(6,6);
    cout<<d<<d<<"  ";       Position(6,7);
    cout<<"  "<<d<<d;       Position(6,8);   cout<<d<<d<<c<<"\t"<<Player2<<" killed : ";                 DeadPlayer(3); cout<<endl;
    cout<<c<<"    41    "<<d<<d<<d<<d<<"42"<<d<<d<<d<<d<<"    43    "<<d<<d<<d<<d<<"44"<<d<<d<<d<<d<<"     45   "<<d<<d<<d<<d<<"46"<<d<<d<<d<<d;
    cout<<"    47    "<<d<<d<<d<<d<<"58"<<d<<d<<d<<d<<c;
    cout<<"\t\t  "; DeadPlayer(4); cout<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    //6th row completed
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    cout<<c<<d<<d;         Position(7,1);
    cout<<d<<d<<"  ";       Position(7,2);
    cout<<"  "<<d<<d;       Position(7,3);
    cout<<d<<d<<"  ";       Position(7,4);
    cout<<"  "<<d<<d;       Position(7,5);
    cout<<d<<d<<"  ";       Position(7,6);
    cout<<"  "<<d<<d;       Position(7,7);
    cout<<d<<d<<"  ";       Position(7,8);    cout<<"  "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<"49"<<d<<d<<d<<d<<"    50    "<<d<<d<<d<<d<<"51"<<d<<d<<d<<d<<"    52    "<<d<<d<<d<<d<<"53"<<d<<d<<d<<d<<"    54    ";
    cout<<d<<d<<d<<d<<"55"<<d<<d<<d<<d<<"    56    "<<c<<endl;
    cout<<c<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          ";
    cout<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<c<<endl;
    //7th row completed
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"  ";         Position(8,1);
    cout<<"  "<<d<<d;       Position(8,2);
    cout<<d<<d<<"  ";       Position(8,3);
    cout<<"  "<<d<<d;       Position(8,4);
    cout<<d<<d<<"  ";       Position(8,5);
    cout<<"  "<<d<<d;       Position(8,6);
    cout<<d<<d<<"  ";      Position(8,7);
    cout<<"  "<<d<<d;       Position(8,8);   cout<<d<<d<<c<<endl;
    cout<<c<<"    57    "<<d<<d<<d<<d<<"58"<<d<<d<<d<<d<<"    59    "<<d<<d<<d<<d<<"60"<<d<<d<<d<<d<<"     61   "<<d<<d<<d<<d<<"62"<<d<<d<<d<<d;
    cout<<"    63    "<<d<<d<<d<<d<<"64"<<d<<d<<d<<d<<c<<endl;
    cout<<c<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d;
    cout<<"          "<<d<<d<<d<<d<<d<<d<<d<<d<<d<<d<<c<<"\tenter position to position : \n";
    for(int i=0;i<82; i++) cout<<a; cout<<endl;
    //8th row completed
}

void Chess::DeadPlayer(int m)
{
    int P1=0,P2=0;
    switch(m)
    {
        case 1: if(LiveStatus[1][1][0]!=0) cout<<" rook ";  if(LiveStatus[1][1][7]!=0) cout<<" rook ";
                if(LiveStatus[1][1][1]!=0) cout<<" knight "; if(LiveStatus[1][1][6]!=0) cout<<" knight ";
                if(LiveStatus[1][1][2]!=0) cout<<" bishop "; break;
        case 2: if(LiveStatus[1][1][3]!=0) cout<<" queen ";  if(LiveStatus[1][1][4]!=0) cout<<" king ";
                if(LiveStatus[1][1][5]!=0) cout<<" bishop ";
                for(int k=0; k<8; k++)  if(LiveStatus[1][0][k]!=0) P1++;
                if(P1 !=0) cout<<" "<<P1<<" X  pawn "; break;
        case 3: if(LiveStatus[0][0][0]!=0) cout<<" ROOK ";  if(LiveStatus[0][0][7]!=0) cout<<" ROOK ";
                if(LiveStatus[0][0][1]!=0) cout<<" KNIGHT "; if(LiveStatus[0][0][6]!=0) cout<<" KNIGHT ";
                if(LiveStatus[0][0][2]!=0) cout<<" BISHOP "; break;
        case 4: if(LiveStatus[0][0][3]!=0) cout<<" QUEEN ";  if(LiveStatus[0][0][4]!=0) cout<<" KING ";
                if(LiveStatus[0][0][5]!=0) cout<<" BISHOP ";
                for(int k=0; k<8; k++)  if(LiveStatus[0][1][k]!=0) P2++;
                if(P2 !=0) cout<<" "<<P2<<" X  PAWN "; break;
    }
}

void Chess::Error(int p)
{
    if(p!=0) ErrorCount[Err++]=p;
    else
    {
        for(int j=0; j<Err; j++)
        {
            switch(ErrorCount[j])
            {
                case 1: cout<<"Exeed Position\t\t"; break;
                case 2: cout<<"You are not Moving Your Player \t\t"; break;
                case 3: cout<<"Destination position has Your Player\t\t"; break;
                case 4: cout<<"Invalid travelling\t\t"; break;
                case 5: cout<<"There are Player between moves\t\t"; break;
            }
        }
        cout<<endl; Err=0;
    }
}


void Chess::ResetBoard()
{
    int i=8;
    Player1Move=0;  Player2Move=0;  GameAbort=4; Turn=1; Err=0; check=0;
    //white player setting

    BlockObject[1][1]=1; BlockObject[1][8]=8; //rook set
    BlockObject[1][2]=2; BlockObject[1][7]=7; //knight ser
    BlockObject[1][3]=3; BlockObject[1][6]=6; //bishop set
    BlockObject[1][4]=4; BlockObject[1][5]=5; // queen  and king set
    BlockObject[2][1]=9; BlockObject[2][2]=10; BlockObject[2][3]=11; BlockObject[2][4]=12; //pawn set
    BlockObject[2][5]=13; BlockObject[2][6]=14; BlockObject[2][7]=15;  BlockObject[2][8]=16; //pawn set
    //empty block setting


    for(int j=3; j<7; j++) for(i=1; i<9; i++)  BlockObject[j][i]=0;


    //black player setting


    BlockObject[7][1]=17; BlockObject[7][2]=18; BlockObject[7][3]=19; BlockObject[7][4]=20; //pawn set
    BlockObject[7][5]=21; BlockObject[7][6]=22; BlockObject[7][7]=23; BlockObject[7][8]=24; //pawn set
    BlockObject[8][1]=25; BlockObject[8][8]=32; //rook set
    BlockObject[8][2]=26; BlockObject[8][7]=31; //knight set
    BlockObject[8][3]=27; BlockObject[8][6]=30;  //bishop set
    BlockObject[8][4]=28; BlockObject[8][5]=29;   //queen set and king set


    //ressting LiveStatus
    for(int i=0; i<2; i++) for(int j=0; j<2; j++) for(int k=0; k<8; k++) LiveStatus[i][j][k]=0;
}

void Chess::UpdateDead(int l)
{
    if(l<9) LiveStatus[0][0][l-1]++;
    else if(l<17 && l>8) LiveStatus[0][1][l-9]++;
    else if(l<25 && l>16) LiveStatus[1][0][l-17]++;
    else LiveStatus[1][1][l-25]++;
}

