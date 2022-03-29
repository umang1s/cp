/// best(om)                n^2
/// worst(O)                n^2
/// aver(theta)             n^2

#include<iostream>
#include<cstdlib>
#include"sorting.h"
using namespace std;
int main()
{
    cout<<"***************selection sort***************       n^2  n^2  n^2   "<<endl;
    cout<<"Welcome to you in sorting algorithms\n";
    cout<<"filling random data \n";
    int unsortData[100];
    for(int i=1; i<101; i++)
    {
        unsortData[i-1]= rand()%100;
        cout<<unsortData[i-1]<<"\t";
        if(i%15==0) cout<<endl;
    }
    cout<<endl<<"starts sorting data \n";
    cout<<lengthOfArray(unsortData)<<endl;
    //selectionSort(unsortData,100);
    cout<<"sorted data \n";
    for(int i=1; i<101; i++)
    {
        cout<<unsortData[i-1]<<"\t";
        if(i%15==0) cout<<endl;
    }
}
