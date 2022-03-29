#include"def.h"


void solve(int x){
    int n,a,b,c,d,p,q,y;
    cin>>n>>a>>b>>c>>d>>p>>q>>y;
    vector<int> arr(n+1);
    for(int i=1; i<=n; i++) cin>>arr[i];
    bool byFootGo=false;

    //by foot
    int byfoot=(arr[b]-arr[a])*p;

    //by train
    int byTrain=(arr[d]-arr[c])*q; //train time
    int a_c_time=abs(arr[c]-arr[a])*p;
    int d_b_time=abs(arr[b]-arr[d])*p;
    int wait_time=y-a_c_time;
    if(wait_time<0) cout<<byfoot;
    else{
        byTrain+=y+d_b_time;
        //cout<<byfoot<<" "<<byTrain<<endl;
        if(byfoot>byTrain) cout<<byTrain;
        else cout<<byfoot;
    }

    
}