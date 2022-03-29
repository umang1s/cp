#include"default.h"


template <typename T>
class MinHeap{
    int [] arr;
    public:
    int size;
    int capecity;

    MinHeap(int c){
        arr= new int[c];
        size=0;
        capecity=c;
    }

    int left(int i){
        return (2*i+1);
    }

    int right(int i){
        return (2*i+2);
    }

    int parent(int i){
        return (i-1)/2;
    }
};

void solve(){
    MinHeap<int> mnheap(5);
    
}