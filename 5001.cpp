// umang maurya 2k18 055
// date: 19/08/20
#include<iostream>
#include<cstdlib>
using namespace std;
int main(){
    int input[100];
    int temp;
    /// taking input as particuler order
    cout<<"Let this is 100 element to sorts in particuler order"<<endl;
    for(int i=0; i<100; i++){
        //rand() will give only positive element
        if(rand()%2==0) input[i]=rand()%100;
        else input[i]=-1*rand()%100;
        cout<<input[i]<<" , ";
    } cout<<endl<<endl;
    //insertion sort

    /// ascending order
    cout<<"arranging in ascending order "<<endl;
    for(int i=0; i<99; i++){
        if(input[i]>input[i+1]){
            swap(input[i+1],input[i]);
            for(int j=i; j>0; j--){
                if(input[j]<input[j-1]) swap(input[j],input[j-1]);
            }
        }
    }
    for(int i=0; i<100; i++) cout<<input[i]<<" , ";
    cout<<endl<<endl<<" arranging in descending order "<<endl;

    /// descending order
    for(int i=0; i<99; i++){
        if(input[i]<input[i+1]){
            swap(input[i+1],input[i]);
            for(int j=i; j>0; j--){
                if(input[j]>input[j-1]) swap(input[j],input[j-1]);
            }
        }
    }
    for(int i=0; i<100; i++) cout<<input[i]<<" , ";
    cout<<endl;
}
