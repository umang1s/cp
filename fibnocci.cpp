#include"def.h"

pair<int, int> fib (int n) {
    if (n == 0)
        return {0, 1};

    auto p = fib(n >> 1);
    int c = p.first * (2 * p.second - p.first);
    int d = p.first * p.first + p.second * p.second;
    if (n & 1)
        return {d, c + d};
    else
        return {c, d};
}

void solve(int i){
    pair<int, int> num=fib(10);
    cout<<num.first<<"  "<<num.second<<endl;
    auto x=34.334;
    cout<<x<<endl;
}