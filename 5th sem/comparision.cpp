#include<iostream>
#include<cstring>
#include"dart.h"
using namespace std;
char unsorted[200][100];
char result[10][200][100];
int currentX=100,currentY=1;
void showSearchResult()
{
    for(int i=0; i<)
}
void showUnsorted()
{

}
int main()
{
    char x[50][50];
    char temp[100];
    char key=' ';
    while(key!='~'){
        key=getch();
        setConsole(currentX,currentY);
        if(key!=8) {
                cout<<key;
                currentX++;
                if(currentX%20==0)
                {
                    currentY++;
                    currentX=100;
                }
        }
        else{
            currentX--;
            if(current)
        }

    }
}
