////////////////////////////////////////
#include<iostream>
#include<ctime>
using namespace std;
int main()
{
    time_t x(&current_time);
    cout<<x;
}
