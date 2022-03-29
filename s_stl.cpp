#include"default.h"

/* Use of all STL
    priority_queue->
        max heap by default
        can be create min heap
        function

        top
        empty
        pop
        push
        emplace
        swap
        size

    queue->

        front
        back
        pop
        push
        size
        empty
        emplace
        swap

    stack->
        top
        pop
        push
        size
        empty
        emplace
        swap

    dequeue->





*/

void print_data(deque<int> a){
    while(!a.empty()){
        cout<<a.top()<<spc;
        a.pop();
    }
    cout<<nl;
}

int solve(){
    deque<int> arr;
    int n,a;
    cin>>n;
    while(n--) {
        cin>>a;
        arr.push(a);
        print_data(arr);
    }
    return 0;


}