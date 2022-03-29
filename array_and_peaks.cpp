#include<bits/stdc++.h>
using namespace std;

bool SHOWCASE=false;
bool TESTCASEACTIVE=true;



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	long testCase=1,inc=1;
	if(TESTCASEACTIVE) cin>>testCase;
	while(testCase--){
        int n,k;
        cin>>n>>k;

        int req=1+2*k;
        int comp=0;
        if(req<=n){
            //yes possible
            for(int i=1; i<=n; i++){
                if(i%2==0){
                    if(comp!=k){
                        cout<<i+1<<" "<<i<<" ";
                        i++;
                        comp++;
                    }else cout<<i<<" ";
                }else cout<<i<<" ";
            }
        }else cout<<"-1";
		//programming area



		//output area
		if(SHOWCASE) cout<<"Case #"<<inc++<<": ";




		cout<<endl;
	}
}