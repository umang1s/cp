#include"default.h"
int testcase=5;

//If cummulative sum has repeating element than sum will be zero.
//cummulative sum means a,a+b,a+b+c...
int solve(){
    int n;
    cin>>n;
    unordered_set<int> a;
    int temp=0;
    int val;
    bool find=false;
    for(int i=0; i<n; i++){
        cin>>val;
        auto it=a.find(val+temp);
        if(it==a.end()){
            temp+=val;
            a.insert(temp);
        }else{
            cout<<(*it)<<nl;
            find=true;
            break;
            
        }
    }
    if(!find) cout<<"Not found";


    return 0;
}