#include<iostream>
using namespace std;

class Queue{
    int arr[1000];
    int front=0,rear=0;
public:
    void pushData(int x){
        if(front<999) arr[front++]=x;
        else cout<<"Queue is full\n";
    }
    int pop(){
        if(rear==front){cout<<"arr is empty"; }
        else return arr[rear++];
    }

    void print(){
        if(rear==front){cout<<"no data found\n"; return;}
        for(int i=rear; i<front; i++) cout<<arr[i]<<' ';
        cout<<endl;
    }
};


int main(){
    Queue a;
    a.print();
    for(int i=0; i<5; i++) a.pushData(i);
    a.print();
    for(int i=0; i<5; i++){a.pop(); a.print();}
}