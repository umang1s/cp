#include<iostream>
#include<cmath>
using namespace std;
class Polar
{
    double radius,angle;
public:
    Polar() //constructor
    {
       radius=angle=0;
    }
    ~Polar(){}  //deconstructor
    void setPolar(double Radius,double Angle)
    {
        radius=Radius;
        angle=Angle;
    }
    void show() //for displaying value
    {
        cout<<endl<<"Radius : "<<radius<<"  Angle : "<<angle<<endl;
    }
    Polar operator+(Polar p) //arithmetic operator
    {
        Polar g;
        double x1,x2,x3,y1,y2,y3,r1,r2,r3;
        //converting both input into rectangular coordinates
        r1=(p.angle/180)*3.14159;       //converting angle in radian
        x1=cos(r1) * p.radius;
        y1=sin(r1) * p.radius;

        r2=(angle/180)*3.14159;         //converting angle in radian
        x2=cos(r2)  *  radius;
        y2=sin(r2)  *  radius;

        x3=x1+x2;
        y3=y1+y2;

        //now converting back into polar coordiantes
        r3= atan(y3/x3);
        g.angle  = (r3*180) /3.14159;
        g.radius = sqrt(x3*x3 + y3*y3);

        return g;
    }
};
int main()
{
    Polar x,y,z;
    cout<<"please take angle in degree ";
    x.setPolar(1,45);
    x.show();
    y.setPolar(6,0);
    y.show();
    z=x+y;
    z.show();
}
