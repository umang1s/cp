// turning off monitor for 3 sec and turn on
#include<windows.h>
#include<iostream>
using namespace std;
int main()
{
    cout<<" wait for 5 second  to turn off the monitor\n remaining time : 0";
    for(int i=6; i>0; i--) {cout<<"\b"<<i-1; Sleep(1000);}
    SendMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,(LPARAM)2)  ;   // turns off the monitor
    Sleep(3000);
    SendMessage(HWND_BROADCAST,WM_SYSCOMMAND,SC_MONITORPOWER,(LPARAM)-1) ;   // turn back on the monitor
    cout<<"\n\nThree seconds has been passed away and program is completed\n\n";
}
