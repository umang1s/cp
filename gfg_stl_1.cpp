#include"default.h"
/*
    Iterators

    1.  begin()
    2.  end()   
    3.  next()
    4.  prev()
    5.  advance()

    Iterators is different from pointer.

*/

void iterators_example(){
    vi v={1,3,4,5,6,7};
    vi::iterator i=v.begin();
    ///we can use auto which is equal to vi::iterator.

    cout<<(*i)<<nl; //1
    i++;
    cout<<*i<<nl;   //3

    i=v.end();      //points to garbage value
    cout<<*i<<nl;   //garbage value.
    i--;
    cout<<*i<<nl;   //7

    ///next()   //if we not pass parameter than it get next elements.
    i=next(i,-2);   //we can use also - and it show correct.
    cout<<*i<<nl;   //5

    //prev()
    i=prev(i,1);
    cout<<*i<<nl;   //4

    //advance() //is slightly different from next() it iterate that location.
    advance(i,3);
    cout<<*i<<nl;   //7
}

void solve(){
    iterators_example();
}