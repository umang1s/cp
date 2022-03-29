#include<iostream>
using namespace std;
class Cube
{
    int scaleX,scaleY,scaleZ;
    int positionX,positionY,positionZ;
    int colorR,colorG,colorB;
    int rotationX,RotationY,RotationZ;
public:
    void setColor(int red,int green, int blue)
    {
        colorR=red; colorG=green; colorB=blue;
    }
    void setRotation(int aboutX, int aboutY, int aboutZ)
    {
        rotationX=aboutX;   RotationY=aboutY; RotationZ=aboutZ;
    }
    void setScale(int sizeX , int sizeY ,int sizeZ)
    {
        scaleX=sizeX;   scaleY=sizeY; scaleZ=sizeZ;
    }
    void setPosition(int inX, int inY, int inZ)
    {
        positionX=inX;  positionY=inY;  positionZ=inZ;
    }
    void showCube();
};
void Cube::showCube()
{
    int scaleX,scaleY,scaleZ;
    int positionX,positionY,positionZ;
    int colorR,colorG,colorB;
    int rotationX,RotationY,RotationZ;

}
int main()
{
    Cube a;
    a.setScale(5,5,5);
    a.setRotation(0,0,0);
    a.setPosition(10,10,0);
    a.showCube();
}
