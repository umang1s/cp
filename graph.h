#include<bits/stdc++.h>
using namespace std;

//Directed weighted Graph
template <typename T>
class Graph_DW{
    public:
    vector<vector<pair<T,int>>> adj;
    int Node;

    Graph_DW(int node){
        Node=node;
        adj=vector<vector<pair<T,int>>>(node);
    }

    void scan(int times=1){
        for(int i=0; i<times; i++){
            T a,b;
            int c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
        }
    }

    //Calculate shortest path between two node.
    vector<T> shortest_path(T source,T destination){
        vector<T> ret;


        return ret;
    }

    //Calculate shortest path source node to all node
    vector<vector<T>> single_node_to_all(T source){

    }

};


//Undirected Weighted Graph
template <typename T>
class Graph_UdW{
    public:
    vector<vector<pair<T,int>>> adj;
    int Node;

    Graph_UdW(int node){
        Node=node;
        adj=vector<vector<pair<T,int>>>(node);
    }

    void scan(int times=1){
        for(int i=0; i<times; i++){
            T a,b;
            int c;
            cin>>a>>b>>c;
            adj[a].push_back({b,c});
            adj[b].push_back({a,c});
        }
    }

    //Calculate shortest path between two node.
    vector<T> shortest_path(T source,T destination){
        vector<T> ret;


        return ret;
    }

    //Calculate shortest path source node to all node
    vector<vector<T>> single_node_to_all(T source){

    }
};


//Directed Unweighted Graph
template <typename T>
class Graph_DUw{

};


//Undirected Unweighted Graph
template <typename T>
class Graph_UdUw{

};