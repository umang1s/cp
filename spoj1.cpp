#include<iostream>
#define m case
#define n break
#define r return
using namespace std;
int ret(int l,int a,int b,int c=0,int d=0){
    if(c==0){l%=2; if(l==0) r b;else r a;} 
    if(l==1) r a; if(l==2) r b; if(l==3) r c; r a;
}
int main(){
    int t,p,y,z; cin>>t;
    while(t--){
        long long a,b; cin>>a>>b; a=abs(a); y=a%10; p=b%4;
        switch(y){ m 0: z=0; n; m 1: z=1; n; m 2: z=ret(p,2,4,8,6); n; m 3: z=ret(p,3,9,7,1); n;
            m 4: z=ret(p,4,6); n; m 5: z=5; n; m 6: z=6; n; m 7: z=ret(p,7,9,3,1); n;
            m 8: z=ret(p,8,4,2,6); n; m 9: z=ret(p,9,1); n;}
        if(b==0)z=1;
        cout<<z<<endl;
    }
}