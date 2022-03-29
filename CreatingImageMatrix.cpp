#include<iostream>
#include"graphic.h"
using namespace std;
int normal=7;
void showColorShade()
{
    for(int i=0; i<16; i++) cout<<"   "<<i<<"   "; cout<<endl;
    for(int i=0; i<16; i++)
    {
        setcolor(i*15); cout<<"       ";
    }
    setcolor(normal);
    char x=19;
    for(int i=5; i<25; i++)
        {   for(int j=0; j<100; j++) cout<<" ";
            for(int j=100; j<200; j++)
        cout<<x; cout<<endl;}
}
void displayImage(int x, int y,int color)
{
    HANDLE xx= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Location;
    Location.X=x+100;
    Location.Y=y+5;
    setcolor(color*16);
    SetConsoleCursorPosition(xx,Location);
    cout<<"  ";
    setcolor(normal);
}
void displayInput(int x, int y, int color)
{
    HANDLE xx= GetStdHandle(STD_OUTPUT_HANDLE);
    COORD Location;
    Location.X=x;
    Location.Y=y+5;
    SetConsoleCursorPosition(xx,Location);
    cout<<color;
    if(color <10) cout<<"    ";
    else if(color<100 || color>9) cout<<"   ";
    else cout<<"  ";
}
int main()
{
    int x1=0,x2=0, y=0;
    int i=0, j=0,x;
    cout<<"enter 22 for delete 33 for next line  44 for complete 55 for color shade"; cin>>x; cout<<endl;
    showColorShade();
    cout<<"\n\n";
    int take,arrayL[100][100];
    while(take!=44)
    {
        cin>>take;
        if(take<16 && take>-1)
        {
            x1+=4;  x2+=2;
            displayImage(x2,y,take);
            displayInput(x1,y,take);
            arrayL[i][j++] = take;


        }
        else if(take==22) //delete an element
        {
            x1-=4;  x2-=2;
            displayImage(x2,y,take);
            displayInput(x1,y,take);
            j--;
        }
        else if(take==33) //next line
        {
            x1=x2+=i=0;
            displayImage(x2,y,take);
            displayInput(x1,y,take);
            j++;
            y++;
        }
        else if(take==55) showColorShade();
        else ;
    }

}
