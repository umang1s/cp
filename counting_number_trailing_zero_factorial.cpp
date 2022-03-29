#include"default.h"

void solve(){
    int c;
    cin>>c;
    int cnt=0;
    int five=5;
    while(five<=c){
        cnt+=c/five;
        five*=5;
    }
    cout<<cnt;
}