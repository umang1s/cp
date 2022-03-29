#include"default.h"

//Heap
///greater<typename> change order.

/*Application
    Dijkstra Algorithm.
    Prim Algorithm.
    Huffman Algorithm,
    Heap Sort,
    And other place where heap is used.


*/

struct Person{
    int age;
    float h;
    Person(int Age,float H){age=Age; h=H;}
};

struct myComp{
    bool operators(const Person  &a,Person const &b){
        return a.h<b.h; 
    }
};


int solve(){
    priority_queue<int> pq; //max heap by default
    priority_queue<int , vi,greater<int>> pqg; ///min heaps


    pq.push(20);
    pq.push(10);
    pq.push(5);
    cout<<pq.top()<<nl; //always return maximum 
    /*      20
           /
          10
         /
        5
    */

    pqg.push(20);
    pqg.push(10);
    pqg.push(5);
    cout<<pqg.top()<<nl; //always return minimum 
    /*      5
           / \
          20 10
    */


   //we can also create priority queue by array
   int arr[]={1,5,6};
   priority_queue<int> pqa(arr,arr+3);//begin_address,last_address

   //we can also create min heap by max heap
   //we push all elements in -ve format
   priority_queue<int> pqm; //min heap by max heap
   pqm.push(-20);
    pqm.push(-10);
    pqm.push(-5);
    cout<<-pqm.top()<<nl;


    //we can also customize heap according to us
    priority_queue<Person,vector<Person>,myComp> pqc;


    return 0;
}


/* time complexity
    push,pop            O(log n)
    empty ,size, top    O(1)
*/
