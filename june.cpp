#include<bits/stdc++.h>
#define ll long long
using namespace std;
void solve();
int main(){
    def();
    int t;
    cin>>t;
    while(t--) solve();
}



ll findMinimumArea(vector<pair<ll,ll>> dimension,int n){
    sort(dimension.begin(),dimension.end());
    ll leftArea,rightArea,lf,tempArea,biggestGap,tempH,tempW;

    biggestGap=0;
    tempH=dimension[0].second;
    tempW=tempH;
    lf=0;
    for(int i=1; i<n; i++){
        //cout<<dimension[i].second<<endl;
        tempH=max(dimension[i].second,tempH);
        tempW=min(dimension[i].second,tempW);
        if(dimension[i-1].first!=dimension[i].first){
            tempArea=(tempH-tempW)*(dimension[i].first-dimension[i-1].first);
            cout<<tempH<<" "<<tempW<<" "<<tempArea<<endl;
            if(biggestGap<tempArea){
                lf=i-1;
                biggestGap=tempArea;
            }
            if(i<n-1){
                tempH=dimension[i].second;
                tempW=tempH;
            }
        }
    }

    //cout<<biggestGap<<endl;
    ll uB=dimension[0].second,lB=dimension[0].second;
    for(int i=1; i<=lf; i++){
        if(dimension[i].second>uB) uB=dimension[i].second;
        else if(dimension[i].second<lB) lB=dimension[i].second;

    }
    ll ub=dimension[lf+1].second,lb=dimension[lf+1].second;
    for(int i=lf+2; i<n; i++){
        if(dimension[i].second>ub) ub=dimension[i].second;
        else if(dimension[i].second<lb) lb=dimension[i].second;
    }

    //if we found biggest gap than calculate leftarea and right area
    leftArea=(dimension[lf].first-dimension[0].first)*(uB-lB);
    rightArea=(dimension[n-1].first-dimension[lf+1].first)*(ub-lb);

    cout<<endl<<leftArea<<" "<<rightArea<<endl<<endl;
    return leftArea+rightArea;
}

void solve(){
    int n;
    cin>>n;
    vector<pair<ll,ll>> x(n),y(n);
    for(int i=0; i<n; i++){
        cin>>x[i].first>>x[i].second;
        y[i].first=x[i].second;
        y[i].second=x[i].first;
    }
    ll area=0;
    if(n>2) area=min(findMinimumArea(x,n),findMinimumArea(y,n));
    cout<<area<<endl;
}