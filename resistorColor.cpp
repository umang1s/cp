#include<iostream>
#include<windows.h>
using namespace std;
class Resistance
{
    int TotalColor,ColorValue[6];
    float answer;
public:
    Resistance(int a) {TotalColor=a;}
    ~Resistance();
    void setColor();
    float showResistance();
    void setGloable();
};
void setColor(short int z)
{
    ;
}
void showColorSet()
{
    ;
}
int main()
{
    int k,x=1;
    while(x)
    {
        cout<<"enter the total number of color  : ";
        cin>>x;
        if(x==4 || x==5 || x==6)
        {
            Resistance px(x);
            px.setColor();
            cout<<" Your Register color is : "<<px.showResistance()<<endl;
            px.setGloable();
        }
        else if(x<4 && x==0) cout<<"you enter less color please enter write color number {4,5,6}\n";
        else if(x>6) cout<<"You entered too many color \n";
        else ;
    }
    cout<<endl<<"                         HISTORY\nS.N\tResistance\tColor1\tColor2\tColor3\tColor4\tColor5\tColor6\n";
    for(int i=0; i<k; i++)
    {
        c
    }
}
