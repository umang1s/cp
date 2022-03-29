#include<bits/stdc++.h>
using namespace std;

bool SHOWCASE=false;
bool TESTCASEACTIVE=true;

void solve(int);

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	long testCase=1,inc=1;
	if(TESTCASEACTIVE) cin>>testCase;
	while(testCase--){//programming area
        solve(inc);
		if(SHOWCASE) cout<<"Case #"<<inc<<": ";
		inc++;
		cout<<endl;
	}
}

void solve(int m){
    int n;
    cin>>n;
    char s[n];
    cin>>s;
    char a[n],b[n];

    int bracA=0,bracB=0;
    bool failed=false;
    for(int i=0; i<n && !failed; i++){
        if(s[i]=='1'){
            if(bracA){
                bracA--;
                bracB--;
                a[i]=')';
                b[i]=')';
            }else{
                bracA++;
                bracB++;
                a[i]='(';
                b[i]='(';
            }
        }else{
            if(bracA){
                bracA--; bracB++;
                a[i]=')'; b[i]='(';
            }else{
                bracA++; bracB--;
                a[i]='('; b[i]=')';
            }
        }
        if(bracA==-1 || bracB==-1) failed=true;
    }

    if(failed) cout<<"NO";
    else   { cout<<"YES"<<endl; for(int i=0; i<n; i++) cout<<a[i]; cout<<endl;
    for(int i=0; i<n; i++) cout<<b[i]; }

}