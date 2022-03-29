#include<iostream>
#include<cstdio>
using namespace std;
class date
{
    int dd,mm,yy;
    public:
    date(char *);
    showDate()
    {
        cout<<dd<<"/"<<mm<<"/"<<yy<<endl;
    }
};
date::date(char *p)
{
    sscanf(p,"%d%*c%d%c%d",&dd,&mm,&yy);
}
int main()
{
    date d("32/12/72");
    d.showDate();
}
