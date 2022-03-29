#include<bits/stdc++.h>

using namespace std;





#algebra
long long binpow(long long a, long long b) {
    long long res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}



int main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif
    int x=21;
    x>>=1;
    cout<<x<<endl;
    cout<<binpow(10,5);
    cout<<endl;
}