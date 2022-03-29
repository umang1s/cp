
//this function check the prime number and return true or false
bool checkPrime(long long num){
    if(num<2) return false;
    if(num==2) return true;
    if(num%2==0) return false;
    for(long long i=3; i*i<=num; i+=2) if(num%i==0) return false;
    return true;
}