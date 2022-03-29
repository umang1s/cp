#include <iostream>
using namespace std;
class mans
{
    int name;
public:
    void getname()
    {
        cin>>name;
    }
    void outname()
    {
        cout<<name<<endl;
    }
};
int main()
{
    mans m[4];
    for(int i=0; i<4; i++) {m[i].getname(); m[i].outname();}
}
