#include<iostream>
#include<thread>
using namespace std;

int main()
{
    int val=200;
    thread t1{threadfn,ref(val),2000};
    cout<<"multithread example "<<endl;
    t1.join();
    cout<<"value in mainThread is "<<val;
    threadfn(10,23);
    
}
