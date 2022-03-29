long long binPow(long long a, long long b){
    if(b==0) return 1;
    long long ret=binPow(a,b/2);
    if(b%2==1) return ret*ret*a;
    else return ret*ret;
}

long long binPowR(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

