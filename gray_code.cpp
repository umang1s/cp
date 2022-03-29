#include"default.h"

//gray code is number differ one bit from other
//0-1-1-0       //1bit
//00-01-0


int binary_to_gray_code(int n){
    //return gray code number to binary
    //first bit will be same for both
    //let we have b3 b2 b1 b0
    //binary code b3 b3^b2 b2^b1 b1^b0
    return n^(n>>1);

}

int gray_code_to_binary(int x){
    int res=0;
    while(x>0){
        res^=x;
        x=x>>1;
    }return res;
}

int solve(){
    int p=binary_to_gray_code(200);
    cout<<p<<spc<<gray_code_to_binary(p);
    return 0;
}