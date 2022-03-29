#include"default.h"
/*
    We use static member for storing an value which is initialized by last value methods.
    We can use global as well .

    use static function for accessing static member. we can use normal function for accessing
    static member. But using static function is good for programming.


*/

class st{
    
    public:
    static int p;
    st(){
        cout<<p<<spc<<"New\n";
        p++;
    }
};
int st::p=0;

int solve(){
    st s=st();
    st p=st();
    st q=st();
    st r=st();
    cout<<st::p<<nl; //using scope resolution
    cout<<r.p<<nl; //using .
    return 0;
}