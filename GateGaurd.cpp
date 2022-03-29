#include<iostream>
#include<ctime>
#include<windows.h>
using namespace std;
int main()
{
    for(int i=0; i< 34; i++)
    {
        time_t tis;
        struct tm * tiss;
        time(&tis);
        tiss = localtime(&tis);
        cout<<i<<"    "<<asctime(tiss)<<endl;
        Sleep(100);

    }
}
