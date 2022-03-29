#include<bits/stdc++.h>
#define int long long
#define pi vector<int>
#define space ' '
#define mod 1000000007
#define loop(vrbl,inVl,lptl) for(int vrbl=inVl; vrbl<=lptl; vrbl++) 
using namespace std;

void solve();

vector<vector<int>> adj;
void createAdjList();
int32_t main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	//freopen("output.txt","w",stdout);
#endif
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    createAdjList();
    int n;
    cin>>n;
    while(n--) solve();
}
int getNumber(string a){
    return (a[1]-48)*10+(a[0]-96);
}
void pushData(int current,int i,int j){
    adj[current].push_back(i*10+j);
}
void createAdjList(){
    adj=vector<vector<int>>(90);
    for(int i=1; i<9; i++){
        for(int j=1; j<9; j++){
            int current=i*10+j;
            vector<int> temp;
            if(i<7){
                if(j<8) pushData(current,i+2,j+1);
                if(j>1) pushData(current,i+2,j-1);
            }
            if(i<8){
                if(j<7) pushData(current,i+1,j+2);
                if(j>2) pushData(current,i+1,j-2);
            }
            if(i>2){
                if(j<8) pushData(current,i-2,j+1);
                if(j>1) pushData(current,i-2,j-1);
            }
            if(i>1){
                if(j<7) pushData(current,i-1,j+2);
                if(j>2) pushData(current,i-1,j-2);
            }

        }
    }
}



void solve(){
    string start,dest;
    cin>>start>>dest;
    int first=getNumber(start);
    int second=getNumber(dest);

    //apply bfs
     vector<bool> visited(90,false);
    vector<int> dis(90,0);
    queue<int> q;
    visited[first]=true;
    q.push(first);

    while(!q.empty()){
        int current=q.front();
        q.pop();
        for(auto j: adj[current]){
            //cout<<j<<'-';
            if(!visited[j]){
                visited[j]=true;
                q.push(j);
                dis[j]=dis[current]+1;
            }
        }
    }
    cout<<dis[second]<<endl;

}