#include<bits/stdc++.h>
#define mod 1000000007
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


int main(){
    int test;
    cin>>test;
    while(test--){
        int N;
        cin>>N;
        long long answer=1;

        vector<int> bi=getBinary(N-1);
        long long ss=2;
        for(int i=bi.size()-1; i>=0; i--){
            if(bi[i]==1) answer*=ss;
            ss*=ss;
            ss%=mod;
            answer%=mod;
        }
        //answer=pow(2,N);

        cout<<answer<<endl;
    }
}
