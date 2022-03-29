#include<bits/stdc++.h>

using namespace std;

vector<int> getBinary(long long val){
    vector<int> ret;
    while(val>1){
        ret.push_back(val%2);
        val/=2;
    }
    ret.push_back(val);
    vector<int> ret2;
    int len=ret.size();

    for(int i=len-1; i>-1; i--) ret2.push_back(ret[i]);
    return ret2;
}