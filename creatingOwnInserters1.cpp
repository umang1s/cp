#include<iostream>
using namespace std;
class box
{
    int x, y;
public:
    box(int i, int j)
    {
        x=i; y=j;
    }
    friend ostream &operator<<(ostream &stream, box o); //creating own inserters
};
ostream &operator<<(ostream &stream, box o)
{
    register int i,j;
    for(i=0; i<o.x; i++)    stream<<"*";
    stream<<endl;
    for(j=1; j<o.y-1; j++)
    {
        for(i=0; i<o.x; i++)
            if(i==0 || i==o.x-1) stream<<"*";
            else stream<<" ";
        stream<<endl;
    }
    for(i=0; i<o.x; i++) stream<<"*";
    stream<<endl;
    return stream;
}
int main()
{
    box a(14,6) ,b(30,7) ,c(40,5);
    cout<<"Here are some boxes: "<<endl<<a<<b<<c<<endl;
    return 0;
}
