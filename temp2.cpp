#include <iostream>
using namespace std;

int main() {
	// your code goes here
    def();
	int n;
	cin>>n;
    while(n--){
        long long k,a,b;
        cin>>k>>a>>b;
        long long sum=a+b;
        if(a+b==5) cout<<"NO\n";
        if(k==2){
            if(sum%3==0) cout<<"YES\n";
            else cout<<"NO\n";
        }else if(k==3){
            sum+=sum%10;
            if(sum%3==0) cout<<"YES\n";
            else cout<<"NO\n";
        }else{
            sum+=sum%10;
            int last=sum%10;
            int lastD=k%4;

            
            long long mod4=k/4 - 1;
             sum+=(mod4*20);
             
            int p[3]={8,6,2};
            if(last==2){ p[0]=4; p[1]=8; p[2]=6;}
            else if(last==6){ p[0]=2; p[1]=4; p[2]=8;} 
            else if(last==8){ p[0]=6; p[1]=2; p[2]=4;}
            sum+=last;
            if(lastD==1) sum+=p[0];
            else if(lastD==2) sum+=p[0]+p[1];
            else if(lastD==3) sum+=p[0]+p[1]+p[2];

            cout<<sum<<endl;
            if(sum%3==0) cout<<"YES"<<endl;
            else cout<<"NO\n";
        }
    }
	return 0;
}

