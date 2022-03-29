#include"default.h"

class TrieNode{
    public:
    int isEnd;
    TrieNode arr[26];

    TrieNode(){
        isEnd=false;
        for(int i=0; i<26; i++) arr[i]=TrieNode();
    }

    TrieNode next(char c){return arr[c-'a'];}
};

class Trie{
    TrieNode root;

    public:

    Trie(){
        root=TrieNode();
    }
    void addString(string x){
        TrieNode temp=root;
        while(root)
    }

    list<string> searchText(String x){

    }

    void deleteString(string x){

    }

}

void solve(){

}