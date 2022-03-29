#include"default.h"

void using_find(){
    //It returns only iterator
    //It search linearly 
    vi arr={32,12,11,65,23,122,312,1};
    auto it=find(arr.begin(),arr.end(),1);
    if(it==arr.end()) cout<<"Not founds\n";
    else{
        cout<<(*it)<<nl;
        cout<<"Found at : "<<(it-arr.begin());
    }
}

void using

int solve(){
    using_find();

    return 0;
}