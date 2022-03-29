#include"default.h"

void print_all_permutation(vector<char> &str, int ind){
    int n=str.size();
    if(ind>=n-1){
        for(char i: str) cout<<i;
        cout<<nl;
        return ;
    }
    for(int i=ind; i<str.size(); i++){
        swap(str[ind],str[i]);
        print_all_permutation(str,ind+1);
        swap(str[ind],str[i]);
    }
}

void naive_solution(vector<char> &str,int l,int r){
    
}

void solve(){
    string str="abc";
    vector<char> chr;
    for(auto i: str)chr.push_back(i);
    print_all_permutation(chr,0);
    //
}