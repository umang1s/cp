#include"default.h"

class MedianBuffer{
    priority_queue<int> left;
    priority_queue<int,vector<int>,greater<int>> right;
    public:
    void insert(int val){
        if(left.empty() || left.top()>=val) left.push(val);
        else right.push(val);
        if(left.size()>right.size()+1){
            right.push(left.top());
            left.pop();
        }else if(left.size()<right.size()){
            left.push(right.top());
            right.pop();
        }
    }

    int median(){
        if(left.size()==right.size()) return left.top()+right.top();
        return left.top();
    }
};

void solve(){
    int n;
    cin>>n;
    MedianBuffer mf=MedianBuffer();
    while(n--){
        int a,b;
        cin>>a>>b;
        if(a) mf.insert(b);
        else cout<<mf.median()<<nl;
    }

}