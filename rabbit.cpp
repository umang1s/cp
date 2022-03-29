#include<bits/stdc++.h>
#include<iostream>
using namespace std;
long long solve(){
    int r,c;
    cin>>c>>r;

    vector<vector<long long>> p(c,vector<long long>(r));

    for(int i=0; i<c; i++) for(int j=0; j<r; j++) cin>>p[i][j];
    long long answer=0;

    //horizontal
    for(int i=0; i<c; i++){
        for(int j=1; j<r; j++){
            long long diff=p[i][j]-p[i][j-1];
            long long current;
            if(diff>1){
                current=p[i][j]-1;
                for(int k=j-1; k>=0; k--,current--){
                    if(current>p[i][k]){
                        answer+=current-p[i][k];
                        p[i][k]=current;
                    }else break;
                }
            }
            if(diff<-1){
                current=p[i][j-1]-1;
                for(int k=j; k<r; k++,current--){
                    if(current>p[i][k]){
                        answer+=current-p[i][k];
                        p[i][k]=current;
                    }else break;
                }
            }
        }
    }
    for(int i=0; i<r; i++){
        for(int j=1; j<c; j++){
            long long diff=p[j][i]-p[j-1][i];
            long long current;
            if(diff>1){
                current=p[j][i]-1;
                for(int k=j-1; k>=0; k--,current--){
                    if(current>p[k][i]){
                        answer+=current-p[k][i];
                        p[k][i]=current;
                    }else break;
                }
            }
            if(diff<-1){
                current=p[j-1][i]-1;
                for(int k=j; k<r; k++,current--){
                    if(current>p[k][i]){
                        answer+=current-p[k][i];
                        p[k][i]=current;
                    }else break;
                }
            }
        }
    }

    for(int i=0; i<c; i++){
        for(int j=0; j<r; j++) cout<<p[i][j]<<" ";
        cout<<endl;
    }


    return answer;
    
}

int main(){
    def();
    int t;
    cin>>t;
    for(int i=1; i<=t; i++){
        long long ans=solve();
        cout<<"Case #"<<i<<": "<<ans<<endl;
    }
}