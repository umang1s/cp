#include"default.h"
string intToString(int num){
    string x="0";
    x[0]+=num;
    return x;
}

void printNum(int arr[],int n,int l){
    vi num(l);
    for(int i=0; i<l; i++) num[i]=arr[i];
    sort(num.begin(),num.end());
    
    queue<string> qu;
    for(int i=0; i<l; i++) qu.push(intToString(num[i]));

    int cnt=0;
    while(cnt<n){
        string top=qu.front();
        cout<<top<<nl;
        qu.pop();
        for(int i=0; i<l; i++) qu.push(top+intToString(num[i]));
        cnt++;
    }
}


void solve(){
    int arr[]={5,6};
    printNum(arr,10,2);
}