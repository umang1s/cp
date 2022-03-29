#include<bits/stdc++.h>
using namespace std;

bool SHOWCASE=false;
bool TESTCASEACTIVE=true;

void solve(int);
void code();

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
#endif

	long testCase=1,inc=1;
	if(TESTCASEACTIVE) cin>>testCase;
	while(testCase--){//programming area
        //solve(inc);
        code();
		if(SHOWCASE) cout<<"Case #"<<inc<<": ";
		inc++;
		cout<<endl;
	}
}


/*
void solve(int testCase){
    int n;
    cin>>n;
    vector<char> ini(n),fin(n);
    for(int i=0; i<n; i++) cin>>ini[i];
    for(int i=0; i<n; i++) cin>>fin[i];

    bool failed=false;
    for(int i=n-1; i>-1 && !failed; i--){
        if(ini[i]!=fin[i]){
            int n0=0,n1=0;
            for(int j=0; j<=i; j++){
                if(ini[j]=='0'){
                    n0++;
                    ini[j]='1';
                }
                else {n1++; ini[j]='0';}
            }
            i--;
            //cout<<n0<<" "<<n1<<endl;
            if(n0!=n1)  failed=true;
        }
    }

    if(failed) cout<<"NO";
    else cout<<"YES";
}



void solve(int testCase){
    long n,x;
	cin>>n>>x;
	vector<long> a(n);
	for(long i=0; i<n; i++) cin>>a[i];
	    
	sort(a.begin(),a.end());
	long sb=1;
	for(long i=1; i<n; i++){
	    if(a[i]!=a[i-1]) sb++;
    }
	        
	    long eatable=n-x;
	    if(sb>eatable) sb=eatable;
	    cout<<sb;
}

*/

void solve(int testCase){
    long n,r;
    cin>>n>>r;
    vector<long long> a(n);
    vector<long> b(n);
    long answer=0;

    for(long i=0; i<n;i++) cin>>a[i];
    for(long j=0; j<n; j++){ cin>>b[j]; answer+=b[j];}

    long relax=0;
    answer=a[0];
    for(long j=1; j<n; j++){
        relax=a[j]-a[j-1];
        if(relax*r>b[j]) relax=0;
        answer+=b[j]-relax*r;
    }

    //cout<<max(10,12)<<endl;

    cout<<answer;



}

	void code(){
		  long long int n,r,cnt=0;
		  long long int sum=0,time=0;
		  cin>>n>>r;
		long long int a[n],b[n];
		  for(long long int i=0;i<n;i++){
		  	cin>>a[i];
		  }
		  for(long long int i=0;i<n;i++){
		  	cin>>b[i];
		  }

			 long long int m=b[0];
			 long long int z=b[0];
			 long long int x =0;
		  for(int i=1;i<n;i++){
		  	time=(a[i]-a[i-1]);
		  	z=max(x,z-r*time);
		  z+=b[i];
		  m=max(m,z);
		  }
		 
		// cout<<time<<endl;  
cout<<m<<endl;
	
	


  }