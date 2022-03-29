#include"default.h"

class TrieNode{
    public:
    TrieNode *child[26]; //we are taking 26 characters
    int isEnd=0;

    TrieNode(){
        isEnd=false;
        for(int i=0; i<26; i++) child[i]=nullptr;
    }
};

class Trie{
    TrieNode *root;
    public:
    Trie(){
        root=new TrieNode();
    }

    void insert_data(string &x){
        TrieNode *curr=root;
        for(int i=0; i<x.length(); i++){
            int index=x[i]-'a';
            if(curr->child[index]==nullptr)
                curr->child[index]=new TrieNode();
            curr=curr->child[index];
        }
        curr->isEnd++;
    }

    bool search_data(string &x){
        TrieNode *curr=root;
        for(int i=0; i<x.length(); i++){
            int index=x[i]-'a';
            if(curr->child[index]==nullptr) return false;
            curr=curr->child[index];
        }
        return curr->isEnd!=0;
    }

    void delete_operation(string &x){
        TrieNode *curr=root;
        for(int i=0; i<x.length(); i++){
            int index=x[i]-'a';
            if(curr->child[index]==nullptr) return;
            curr=curr->child[index];
        }
        if(curr->isEnd==0) return;
        curr->isEnd--;
    }
};

int solve(){
    int n;
    cin>>n;
    Trie trie= Trie();
    vector<string> x(n);
    for(int i=0; i<n; i++){
        cin>>x[i];
        trie.insert_data(x[i]);
    }

    int k;
    cin>>k;
    for(int i=0; i<k;i++){
        int j;
        string y;
        cin>>j>>y;
        if(j==0) trie.insert_data(y);
        else if(j==1) trie.delete_operation(y);
        else{
            bool value=trie.search_data(y);
            cout<<(value?"YES\n":"NO\n");
        }
    }
    return 0;
}