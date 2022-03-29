/*

    tuple can be any size of length
    tuple is like struct in c
        tuple<typename1,typename2 ....>

    it is initialized by make_tuple(data)

    we access tuples by
     get<index>(variable_name)

     get<0>(p)

    size of tuple 
        tuple_size<decltype(variable_name)>::value

    we can change decltype-->tuple<datatype1,datatype2,...>

    we use tie to rechange data to their form
    tie(var_name1,var_name2,..)=tupele_name
        lets we have tuple ->   tuple<int,int> j=make_tuple(4,5);
        tie(p,q)=j;
        //here p=4 and q=5

    we can use ignore to not use that variable
        tie(ignore,p)=j;
        //p=5


    we can use tuple_cat to concate two tuples
        tuple<int,int> x=make_tuple(5,3);
        tuple<string,string> y= make_tuple("hi","umang");

        auto z=tuple_cat(x,y);
        //now z will be five elemnets   5 3,hi,umang


*/
#include"default.h"

int solve(){
    tuple<int,string,int> p=make_tuple(1,"area",2);
    cout<<get<0>(p)<<nl;
    get<0>(p)=5;
    cout<<get<0>(p)<<nl;

    cout<<"Tuple size "<<tuple_size<decltype(p)>::value<<nl;
    //cout<<"Tuple size "<<tuple_size<tuple<int,string,int>(p)>::value<<nl;

    int x,z;
    string y;
    tie(x,y,z)=p;
    cout<<x<<spc<<y<<spc<<z<<nl;

    //we can also use ignore for not allocating
    tuple<int,int> j=make_tuple(4,5);
    int h;
    tie(ignore,h)=j;
    cout<<h<<nl;

    //we can use tuple_cat to concate two tuples.
    tuple<int,int> f1=make_tuple(7,2);
    tuple<string,string> f2=make_tuple("hii","umang");

    auto f3=tuple_cat(f1,f2);
    cout<<get<0>(f3)<<spc<<get<1>(f3)<<spc<<get<2>(f3)<<spc<<get<3>(f3)<<nl;


    return 0;
}