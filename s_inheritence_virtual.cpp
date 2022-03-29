#include"default.h"

class A{
    int x,y;
    public:
    A(int x,int y){
        this->x=x;
        this->y=y;
    }
    int multiply(){return x*y;}
};

class B:public A{
    int z;
    public:
    B(int x,int y,int z){
        this->super(x,y);
        this->z=z;
    }
    B(A a,int z){
        this->super(a.x)
    }
    int ans(){
        return this->multiply*z;
    }
};

int solve(){
    B b=B
}