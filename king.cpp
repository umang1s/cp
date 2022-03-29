#include<bits/stdc++.h>
#define int long long

using namespace std;

typedef struct tree{
    int val,lev;
    vector<tree *> child;
    tree(int a){
        val=a;
        lev=0;
    }
} Tree;

vector<pair<int,int>> data;

void dfsS(Tree *home){
    int i=0;
    while(i<home->child.size()){
        Tree *temp=home->child[i++];
        dfsS(temp);
    }

    if(home->child.size()==0) data.push_back({home->lev,home->val+1});

}

void dfs(Tree *home,int val){
    home->lev=val;
    int i=0;
    while(i<home->child.size()){
        Tree *temp=home->child[i++];
        dfs(temp,val+1);
    }
}

void createTree(Tree *node,vector<vector<int>> &a, vector<bool> &reached){
    reached[node->val]=1;
    int i=0;
    while(i<a[node->val].size()){
        if(reached[a[node->val][i++]]) continue;
        else {
            Tree *temp=new Tree(a[node->val][i]);
            node->child.push_back(temp);
        }
        i++;
    }
    i=0;
    while(i<node->child.size()) createTree(node->child[i++],a,reached);
}

int32_t main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--){
        int n;
        bool tog;
        cin>>n;
        vector<vector<int>> d;
        for(int i=0; i<n-1; i++){
            int u,v;
            cin>>u>>v;
            d[u-1].push_back(v);
            d[v-1].push_back(u);
        }
        Tree *root=new Tree(0);
        vector<bool> reached(n,false);
        createTree(root,d,reached);

        dfs(root,0);
        vector<pair<int,int>> ans;
        for(int i=0; i<root->child.size(); i++){
            dfsS(root->child[i]);
            vector<pair<int,int>> temp;
            pair<int,int> rec;
            sort(data.begin(),data.end());
            rec=data[0];
            temp.push_back(rec);
            int tempVal=rec.first;
            int r=1;
            tog=false;
            while(r<data.size()){
                while(r<data.size() && data[r].first==tempVal){
                    if(tog) temp.push_back({rec.first+1,data[r].second});
                    else temp.push_back(data[r]);
                    r++;
                }
                if(i<data.size()){
                    temp.clear();
                    tog=true;
                    rec.second=data[r].second;
                    temp.push_back({rec.first+1,data[r].second});
                    tempVal=data[r].first;
                    r++;
                }
            }
            data.clear();
            for(auto x:temp) ans.push_back(x);


        }
        sort(ans.begin(),ans.end());
        int p=ans[0].first;
        vector<int> ttt;
        for(int i=0; i<ans.size(); i++){
            if(ans[i].first==p) ttt.push_back(ans[i].second);
            else break;
        }
        cout<<ttt.size()<<" "<<p<<endl;
        for(int m=0; m<ttt.size(); m++) cout<<m<<" ";
        cout<<endl;

    }
}