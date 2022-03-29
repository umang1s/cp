#include"default.h"

/*
    you are given a,b and k
    count total number between a to b such that their digit sum is k.
    for ex-
        2 20 9
        
        9 18



*/
void int_to_array(int n,int len,vi &arr){
    for(int i=len-1; i>=0; i--){
        arr[i]=n%10;
        n/=10;
    }
}

void printNum(vi arr){
    int s=0;
    while(arr[s]==0) s++;
    for(int j=s; j<arr.size(); j++) cout<<arr[j];
    cout<<nl;
}

int makeNumber(vi a,int c,int sum,const vi &upper,int len,bool cmp){
    
    int cnt=0;
    if(c==len) return 0;
    if(c==len-1){
        if(sum>9) return 0;
        a[c]=sum;
        //printNum(a);
        return 1;
    }
    if(cmp && a[c]<upper[c]) cmp=false;


    int starting=a[c];
    int temp=(len-c-1)*9;
    if(sum>temp+9) return 0;
    if(temp-sum>0) starting=0;

    int lim=upper[c];
    if(!cmp) lim=9;
    if(sum<9) lim=sum;

    for(int i=starting; i<lim; i++){
        a[c]=i;
        cnt+=makeNumber(a,c+1,sum-i,upper,len,cmp);
    }
    a[c]=lim;
    if(!cmp && a[c]==upper[c]) cmp=true;
    cnt+=makeNumber(a,c+1,sum-a[c],upper,len,cmp);

    return cnt;
}

void solve(){
    int lower,bigger,sum;
    cin>>lower>>bigger>>sum;
    if(lower>bigger) swap(lower,bigger);
    int len=log10(bigger)+1;
    vi l(len),b(len);
    int_to_array(lower,len,l);
    int_to_array(bigger,len,b);
    
    int cnt=makeNumber(l,0,sum,b,len,false);
    cout<<cnt;
}