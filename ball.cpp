#include"def.h"

void solve(int i){
    long n,m;
    cin>>n>>m;
    vector<long long> x(n),y(m),u(n),v(m);
    for(long i=0; i<n; i++) cin>>x[i]>>u[i];
    for(long j=0; j<m; j++) cin>>y[j]>>v[j];

    long colide=0;
    long blue=0,red=0;

    //max time
    for(long i=0; i<n; i++){
        for(long j=0; j<m; j++){
            if(x[i]!=-1){
                double t=(y[j]*1.0)/u[i];
                double t1=(x[i]*1.0)/v[j];
                cout<<t<<"  "<<t1<<endl;
                    if(t==t1){
                        colide++;
                        x[i]=-1;
                    }
            }
        }
    }


    cout<<colide;
}