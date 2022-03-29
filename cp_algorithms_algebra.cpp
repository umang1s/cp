#include"default.h"

//for caluculating the power of a number in log_n
int binary_exponentiation(int value,int power){
    int ans=1;
    while(power>0){
        if(power & 1) ans*=value;
        value*=value;
        power=power>>1;
    }
    return ans;
}

//Euclidean algorithm for computing gcd
int greatest_common_divisor(int first,int second){
    if(second==0) return first;
    return greatest_common_divisor(second,first%second);
}



void solve(){
    cout<<binary_exponentiation(2,23)<<nl;
    cout<<greatest_common_divisor(100,120)<<nl;
    cout<<(100 | 120)<<nl;
}