#include<bits/stdc++.h>
using namespace std;
void solve();

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    def();
    int t;
    cin>>t;
    while(t--)solve();
}

void solve(){
    int n;
    cin>>n;

    bool f = false;
        for (int i = 1; i <= n; i++) {
            int x;
            cin >> x;
            if (x < 0) f = true;
        }
        if (f) {
            cout << "NO\n";
        }
        else {
            cout << "YES\n";
            cout << 101 << '\n';
            for (int i = 0; i <= 100; i++) cout << i << " ";
            cout << '\n';
        }

    // vector<int> num(n);
    // bool valid=true;

    // for(int i=0; i<n; i++){ cin>>num[i]; if(num[i]<0) valid=false;}
    // sort(num.begin(),num.end());
    // int k=n;

    // if(valid){
    //     bool loop=true;
    //     while(loop && k<=300){
    //         loop=false;
    //         for(int i=1; i<k && k<301; i++){
    //             int temp=abs(num[i-1]-num[i]);
    //             bool isPresent=false;
    //             for(int j=0; j<k && !isPresent; j++) if(num[j]==temp) isPresent=true;
    //             if(!isPresent) { num[k++]=temp; loop=true;}
    //         }
    //     }

    //     if(k>300) valid=false;
    //     if(valid){
    //         cout<<"YES\n";
    //         cout<<k<<endl;
    //         for(int i=0; i<k; i++) cout<<num[i]<<" ";
    //         cout<<endl;
    //     }

    // }
    
    // if(!valid) cout<<"NO\n";
}

