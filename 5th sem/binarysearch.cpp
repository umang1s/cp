#include<iostream>
#include"umang.h"
using namespace std;
int main()
{
    int unsort[210],temp;
    getch();
    setcolor(black,white);
    for(int i=0; i<210; i++)
    {
        temp=rand()%50;
        for(int j=50-temp; j<50; j++){
          setConsole(i,j);
          cout<<" ";
        }
    }
    wait(2000);
    for(int j=0; j<209; j++)
    {
        if(unsort[j]>unsort[j+1])
        {
            temp=unsort[j];
            unsort[j]=unsort[j+1];
            unsort[j+1]=temp;
            int i=j;
            while(unsort[j]<unsort[j-1])
            {

            }
            for(int i=j; i>0; i-- )
        }
        for(int i=0; i<j; i++)
        {
            setcolor(black,green);
            for(int k=50-unsort[i]; k<50; k++)
            {
                setConsole(i,k);
                cout<<" ";
            }
            setcolor(black,red);
            for(int k=50-unsort[i]; k<50; k++)
            {
                setConsole(i,k);
                cout<<" ";
            }
            if(unsort[i]>unsort[i+1]){
                temp=unsort[i];
                unsort[i]=unsort[i+1];
                unsort[i+1]=temp;
            }
            wait(50);
            setcolor(black,white);
            for(int k=50-unsort[i]; k<50; k++)
            {
                setConsole(i,k);
                cout<<" ";
            }
            for(int k=50-unsort[i]; k<50; k++)
            {
                setConsole(i,k);
                cout<<" ";
            }
            wait(50);
        }
    }
    wait(1000);
    setcolor(black,yellow);
    for(int i=0; i<210; i++)
    {
        temp=rand()%50;
        for(int j=50-temp; j<50; j++){
          setConsole(i,j);
          cout<<" ";
        }
    }
    setcolor(7);
    getch();
    //sorting algorithims
    //every step show and sort
}
