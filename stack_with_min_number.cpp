class stc{
    public:
    stack<pair<int,int>> arr;
    void push(int j){
        int m=j;
        if(!arr.empty()) m=min(m,arr.top().second);
        arr.push(make_pair(j,m));
    }

    void pop(){if(!arr.empty()) arr.pop();}

    int getMin(){
        int ret=-1;
        if(!arr.empty())ret=arr.top().second;
        cout<<ret<<" ";
        return ret;
    }
};


void solve(){
    stc x;
    x.push(20);
    x.push(10);
    x.getMin();
    x.push(5);
    x.getMin();
    x.pop();
    x.getMin();
    x.pop();
    x.getMin();
}