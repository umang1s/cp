#include"default.h"

int count_digits(int num){
    return floor(log10(num)+1);
}

int trailing_zerors_in_factorial(int num){
    int cnt=0;
    int five=5;
    while(num>five){
        cnt+=num/five;
        five*=5;
    }
    return cnt;
}

int greatest_common_divisor(int a,int b){
    if(b==0) return a;
    return greatest_common_divisor(b,a%b);
}

int lowest_common_multiple(int a,int b){
    return a*b/greatest_common_divisor(a,b);
}

bool check_prime(int num){
    if(num==1) return false;
    if(num==2 || num==3) return true;
    if(num%2==0 || num%3==0) return false;
    for(int i=5; i*i<=num; i+=6) if(num%i==0 || num%(i+2)==0) return false;
    return true;
}

int solve(){
    cout<<count_digits(23232)<<nl;
    cout<<trailing_zerors_in_factorial(1000)<<nl;
    cout<<greatest_common_divisor(51,34)<<nl;
    cout<<lowest_common_multiple(51,34)<<nl;
    return 0;
}