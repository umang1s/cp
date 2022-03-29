#include<bits/stdc++.h>
#define int long long
#define vi vector<int>
#define pii pair<int,int>
#define psi pair<string,int>
#define vii vector<vector<int>>
#define spc ' '
#define nl '\n'
#define inf LONG_LONG_MAX
#define mod 1000000007
using namespace std;
#define scanA(arr,total) for(int i=1; i<=total; i++) cin>>arr[i]
#define sortA(x) sort(x.begin(),x.end())
#define printA(z) for(auto in:z) cout<<in<<' '
#define dec(num,b) std::fixed<<std::setprecision(b)<<num
#define google(i) "Case #"<<i<<": "
bool OPTION=false;
bool TESTCASE=false;

void solve(int);
void saveIt(string);
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin); //freopen("output.txt","w",stdout);
    OPTION=true;
#endif
    ios_base::sync_with_stdio(false);   cin.tie(NULL);  cout.tie(NULL);
    

    int n;
    cin>>n;
    multiset<int> ms;
    vector<int> v;
    bool start = false;
    int l = 0;
    while(n--){
        int j,x;
        cin>>j;
        if(j==1){
            cin>>x;
            ms.insert(x);
            v.emplace_back(x);
        }else if(j==2){
            if (ans == -1){
                cout << v[l] << "\n";
                ans = v[++l];
                auto it = ms.find(v[0]);
                ms.erase(it);
            }
            else if (start){
               cout << arr.top() << '\n';
               arr.pop();
               ans = arr.top();
               start = false;
            }else{
               
            }
        }else{
            start=true;
            // ans=arr.top();
        }
    }
}