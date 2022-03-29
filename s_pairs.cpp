#include"default.h"

void first_pairs(){
    /*
    pair<typename,typename> pairname(firstval,secondval);
    pair can be compared. 

    
    */
   pair<int,string> p1(5,"name");

   pair<int,string> p2=make_pair(6,"umang");

   if(p1==p2) cout<<true;
}

void second_sort(){
    /*
    we can use sort for sorting any data types.
    sort can sort string,pair also.

    


    */
}


void solve(){
    first_pairs();
}