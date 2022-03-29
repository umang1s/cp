#include<iostream>
using namespace std;
class Cuboid
{
    int length,width,height;
    int x,y,z;  //for position
    int R,G,B;  //for color
    int Rx,Ry,Rz;   //rotation about axis
public:
    Cuboid(int i=1,int j=1 ,int k=1);
    ~Cuboid(){;}
    void setColor(int i,int j=0,int k=0);
    void setPosition(int ,int j=0,int z=0);
    void setRotation(int ,int j=0; int k=0);
    void show();

};
void Cuboid::show()
{

}
void Cuboid::setRotation(int i, int j, int k)
{
    Rx=i;
    Ry=j;
    Rz=k;
}
void Cuboid::setPosition(int i, int j,int k)
{
    x=i;
    y=j;
    z=k;
}

void Cuboid::setColor(int i,int j, int k)
{
    R=i;
    G=j;
    B=k;
}


Cuboid::Cuboid(int i,int j,int k)
{
    length=i;
    width=j;
    height=k;
    x=y=z=R=G=B=Rx=Ry=Rz=0;
}
int main()
{
    Cuboid box(1);
    box.show();
}
