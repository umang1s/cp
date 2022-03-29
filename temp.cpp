#include<iostream>

int main(){
    std::cout<<"Hello\n";

    int arr[10];

    for(int i=0; i<10; i++) arr[i]=i;
    
    for(int i=0; i<10; i++) std::cout<<arr[i]<<" ";
    std::cout<<"\n";
}