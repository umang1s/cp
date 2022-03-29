#include<iostream>
#include<ctime>
using namespace std;                // 9 and 10 store position
int word[9][9],virt[9][9],z=0,input=0,guessStore[81][11],guessValue[81],use=0,F;        //z for number of solution and input stand for taken input
void display(int xl); //0 for word 1 for virt
void guessNumber(int ,int);
void remainFinder(int x[],int l)
{
    int pz=0,o=0;
    for(int i=1; i<10; i++)
    {
        pz=0;
        for(int j=0;j<l; j++)   if(x[j]==i) pz++;
        if(pz==0)   guessStore[use][o++]=i;
    }
    guessValue[use++]=9-l;
}
int matching(int x[]) //return 1 if matched return 0 if no matched
{
    for(int i=0; i<8; i++)    for(int k=i+1; k<9; k++)   if(x[i]==x[k])  return 1;
    return 0;
}
int validityCheck() // return 1 for valid,,,, 2 for not completed,,,,0 for invalid
{
    int k=0,j,temp[9]; // if k= 0 than no error
    int cx=0,cy=0;
    for(int i=0; i<9; i++) for(j=0; j<9; j++) if(virt[i][j]==0) return 2;   //if any place has unfilled
    for(int i=0; i<9; i++)      //checking validity
    {
        for(j=0; j<9; j++) temp[j]=virt[i][j];      //storing horizontal
        k+=matching(temp); cout<<"      ";
        for(j=0; j<9; j++) temp[j]=virt[j][i];      //storing vertical
        k+=matching(temp); j=0; cout<<"      ";
        for(int ll=0; ll<3; ll++) for(int mm=0;mm<3; mm++) temp[j++]=virt[cy+ll][cx+mm]; // block wise storing
        cx+=3; if(cx==9){cx=0; cy+=3;}
        k+=matching(temp);  cout<<endl;
    }
    if(k==0) //displaying if virtual input is right
    {
        z++; //increasing the number of solutions
        cout<<"\nsolution :"<<z<<endl;
        display(1);
        return 1;
    }
    return 0;
}
void solving()
{
    int a,b=1,c;      // b =0 loop is closed
    a=81-input;
    cout<<"input : "<<input<<endl;
    //if multiple solution found than send to validity check
    while(b)
    {
        F=use=0;
        cout<<"tested : "<<b++<<endl;
        for(int i=0; i<9; i++)  for(int j=0; j<9; j++)  if(word[i][j]==0) guessNumber(i,j);
        if(use==0)
        {
            for(int fa=0; fa<9; fa++) for(int xa=0; xa<9; xa++) virt[fa][xa]=word[fa][xa];
            c=validityCheck();
            if(c==1) b=0;
            if(c==2) {cout<<"NOT Completed set are throwing "<<endl; b=0;}
        }
        if(F<0) {cout<<"this puzzle can't be solved by this program "<<endl; b=0;}
    }
}
int main()
{
    char p;
    cout<<"Please enter your data linewise and if no element than fill zero \n\n";
    for(int i=0; i<9; i++)
    {

        cout<<"line : "<<i+1<<"  ";
        for(int j=0; j<9; j++)
        {
            cin>>p;
            if(p<58 && 47>0) {word[i][j]=p-48; if(p!=48) input++; }
            else
            {
                cout<<"wrong input please fill 0 to 9";
                j--;
            }
        }
        cout<<"line completed \n";
    }
    cout<<"your input is this \n";
    display(0);
    //                                                                */
    cout<<"soving your puzzle ";
    time_t pp;  time(&pp); //taking starting time
    solving();
    time_t xx;  time(&xx); //taking ending time
    cout<<"total taken time : "<<xx-pp<<"  seconds\n";
    cout<<"total solution founded : "<<z<<endl;
}
void display(int xl)
{
    for(int i=0; i<9; i++)
    {
        for(int j=0; j<9; j++)
        {
            if(xl==0)   cout<<word[i][j]<<"   ";
            else cout<<virt[i][j]<<"   ";
            if(j==2 || j==5) cout<<"|   ";
            else cout<<" ";
        }
        cout<<endl;
        if(i==2 || i==5) {for(int i=0; i<48; i++) cout<<"-"; cout<<endl; }
    }
}

void guessNumber(int i, int j)  // i is vertical
{
   int x[9],l=0,xy=0,yx=0;    // k for guessValue
   guessStore[use][9]=i;     // storing vertical position
   guessStore[use][10]=j;   //storing horizontal position
   //horizontal matching and storing
   for(int k=0; k<9; k++)
       if(word[i][k]!=0)
        {
            for(int p=0; p<l; p++)  if(x[p]!=word[i][k])  x[l++]=word[i][k];
            if(l==0) x[l++]=word[i][k];
        }
   //veritcal matching and storing
   for(int k=0; k<9; k++)
        if(word[k][j]!=0)
        {
            for(int p=0; p<l; p++)  if(x[p]!=word[k][j])  x[l++]-word[k][j];
            if(l==0) x[l++]=word[k][j];
        }
   //block matching and storing
   for(int xx=i/3; xx<3; xx++)
        for(int yy=j/3; yy<3; yy++)
            if(word[xx][yy]!=0)
            {
                for(int p=0; p<l; p++)  if(x[p]!=word[xx][yy])  x[l++]=word[xx][yy];
                if(l==0) x[l++]=word[xx][yy];
            }
   if(l==8)
   {
                 for(int xxx=1; xxx<10; xxx++)
                 {
                     int ppp=0;
                     for(int xyx=0; xyx<8; xyx++ ) if(x[xyx]==xxx) ppp++;
                     if(ppp!=0) word[i][j]=xxx;
                 }
                cout<<"Position "<<i+1<<" "<<j+1<<"  found "<<endl;
                F++;
   }
   else remainFinder(x,l);
}
