#include<iostream>
#include<windows.h>
#include<conio.h>
#include<iomanip>
using namespace std;
HANDLE hIn,hOut;
using namespace std;
bool Continue = TRUE;
int start=1;
void setcolor(unsigned short color)
{    //begining of set color funtion

    HANDLE hCon = GetStdHandle(STD_OUTPUT_HANDLE);      //gets std handle
    SetConsoleTextAttribute(hCon,color);     //Sets Console Text Attribute HCon color.
}
void Mouse()
{
    setcolor(1000);
    COORD MouseWhere  = {30, 20};
    COORD DClickWhere = {32,22};
    DWORD EventCount;
    int LoopCount = 0;
    int KeyEvents = 0;
    INPUT_RECORD InRec;
    DWORD NumRead;
    hIn = GetStdHandle(STD_INPUT_HANDLE);
    hOut = GetStdHandle(STD_OUTPUT_HANDLE);
    cout << "Mouse is at    : " << endl;
    cout << "Double Click at : " << endl;
    while (Continue)
    {
        Sleep(10); // To slow it down!!
        GetNumberOfConsoleInputEvents(hIn,&EventCount);
        while (EventCount > 0)
        {
          ReadConsoleInput(hIn,&InRec,1,&NumRead);

            if (InRec.EventType == KEY_EVENT)
            {setcolor(1000);
                if (InRec.Event.KeyEvent.uChar.AsciiChar == 'x')
                {
                            cout << "Exiting..." << endl;
                            Continue = FALSE;
                }
            }
            else if (InRec.EventType == MOUSE_EVENT)
            {setcolor(1000);

                if (InRec.Event.MouseEvent.dwEventFlags == MOUSE_MOVED)
                {
                    setcolor(1000);
                    SetConsoleCursorPosition(hOut,
                                            MouseWhere);setcolor(1000);
                    cout << InRec.Event.MouseEvent.dwMousePosition.X << "," <<
                            InRec.Event.MouseEvent.dwMousePosition.Y << "  " << flush;
                }
                else if (InRec.Event.MouseEvent.dwEventFlags == DOUBLE_CLICK)
                {

                    setcolor(1000);SetConsoleCursorPosition(hOut,
                                            DClickWhere);
                    setcolor(1000);
                    cout << InRec.Event.MouseEvent.dwMousePosition.X << ","<<flush;
                    if(InRec.Event.MouseEvent.dwMousePosition.Y==5){start=1;break;}
                }
            }

          GetNumberOfConsoleInputEvents(hIn,&EventCount);
        }
    }
}
