//using pointers

#include"default.h"
class A{
    int x;
    public:
    A(int x){
        this->x=x;
    }
    int getVal(){return x;}
    A &setX(int x){
        this->x=x;
        return *this;
    }
};

int solve(){
    A a= A(5);
    cout<<a.getVal()<<nl;
    //a.setX(43).setX(23) this is also correct way. This way is called chaining
    //cout<<a<<" "<<b; in this example cout<<a returns object which is used to call the next
    A b=a.setX(43);
    cout<<b.getVal()<<nl;
    cout<<b.setX(23).setX(12).setX(15).getVal()<<nl;
    return 0;
}