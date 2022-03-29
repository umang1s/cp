#include<iostream>
using namespace std;
template <typename X> void swapargs(X &a , X &b)
{
    X temp; // no changes when class is replaced to typename in context
    temp =a;
    a=b;
    b=temp;
}
