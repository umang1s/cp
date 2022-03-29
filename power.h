#include<bits/stdc++.h>

using namespace std;

long long getPower(long long val,long long power){
    long long answer=1;
    long long tempVal=power;
    int len=0;
    vector<int> ret;
    while(tempVal>1){
        ret.push_back(tempVal%2);
        tempVal/=2;
        len++;
    }
    ret.push_back(tempVal);
    len++;


    long long pushPower=val;
    for(int i=0; i<len; i++){
        if(ret[i]!=0){
            answer*=pushPower;
        }
        pushPower*=pushPower;
    }

    return answer;
}