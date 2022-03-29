#include<iostream>
using namespace std;
int main()
{
    int dd,mm,yy,i=0;
    string date;
    int MM[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
    while(i==0)
    {
        cout<<"enter date (DD/MM/YY): ";
        cin>>date;
        dd=(date[0]-48)*10 + (date[1]-48);  mm=(date[3]-48)*10 + (date[4]-48);
        if(date[8] !='\0') yy = (date[6]-48)*1000 + (date[7]-48)*100 + (date[8]-48)*10 + (date[9]-48);
        else yy=(date[6]-48)*10 + (date[7]-48)+2000;
        cout<<dd<<mm<<yy;
        if(mm<13 && mm>0)
        {
            if(yy<2500 && yy>1600)
            {
                if(yy%4==0) MM[2]=29;
                if(dd<MM[mm] && dd>0) i=6;
                else cout<<"You enterd incorrect date "<<endl;
            }
            cout<<"You enterd wrong Year "<<endl;
        }
        else cout<<"You enterd wrong months "<<endl;
    }
    cout<<"Previous DATE : ";
    if(dd>1) {if(dd<11) cout<<"0"<<dd-1;  else cout<<dd-1; cout<<"/";}
    else
    {
        if(mm==1) {cout<<"31/12/"<<yy-1<<endl<<"Next Date    : 02/01"<<"/"<<yy<<endl; return 0; }
        else {  cout<<MM[mm-1]<<"/";    if(mm<10) cout<<"0"; cout<<yy<<endl<<"THE NEXT DATE : ";}
    } // previous dates sets
    if(dd+1<=MM[mm]) {if(dd<9) cout<<"0";  cout<<dd+1; cout<<"/"; if(mm<10) cout<<"0"; cout<<mm<<"/"<<yy<<endl;}
    else
    {
        if(mm==12) {cout<<"01/01/"<<yy+1<<endl;}
        else {      cout<<"01/";  if(mm<9) cout<<"0"; cout<<mm+1<<"/"<<yy<<endl;    }
    }
}
