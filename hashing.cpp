#include"default.h"

/*
    Hashing takes genrally O(1) for insertion, deletion and searching.
        On inserteion it override the value if any duplicacy found in hash table.

    Hashing is not useful when
        Finding closest value. (it means lower bound and upper bound)
        Sorted data (In this data is not in sorted order)
            //for using first and second use 
                Self balancing binary tree.
                AVL Tree
                Red black tree.
        Prefix searching.\
            //For implementing this use trie data structure.

    Application of Hashing.
        Dictionaries
        Database indexing
        Cryptography
        Caches
        Symbol tables in compilers/Interpreter
        Routes
        Getting data form database
        Many more

    Direct address table
        We make a array of bool when we insert we make it to one
        array_size=upper_range-lower_range

        Problems
            It does not handle large values
            It does not handle string,floating values


    Hashing makes Large values in smaller key values
    Lets we have string data str="fdfdsfsd"
        hash(str):
            str[0]*x0 + str[1]*x1 + ...
    we choose size of hash which is generally a prime number and it shoud not be close to
        power of 2 or power of 10.
    hash(large_value)=large_value % m   //m is size of hash tables.

    Collision handlling
        If we know keys in advance then we can make perfect hashing.
        if we don't know than we use following methods
            Chaining
            Open addressing
                Linear probling
                Quadratic probling
                Double hashing.

        Chaining
            we use linked list for this
            hash(key)= key%m

            example
                lets m=7
                keys={50,21,58,17,15,49,56,22,23,25}

                keys    data
                0       21->49->56
                1       50->15->22
                2       48->23
                3       17->
                4       25->
                6
            Performance
                let n= no of keys to be inserted
                    m= No of slots in hash tables

                load factor alfa = n/m
                
                expected chain length= alfa
                expected time for search,delete and insert O(1+alfa)

        Open addressing
            we use only one array for this
            m>=n it should be like this
    


*/

class ChainingHashing{
    vector<vector<int>> data;
    int m;

    int key(int val){return val%m;}
    public:
    ChainingHashing(int n){
        m=n;
        data=vector<vector<int>>(m);
    }

    void insertion(int val){
        data[key(val)].insert(val);
    }

    void deletion(int val){
        //we are not using linked list now so we 
        int k=key(val);
        int at=-1;
        for(int i =0; i<data[key].size(); i++) if(data[k][i]==val){ at=i; break;}
        if(at!=-1){
            for(int i=at; i<data[key].size()-1; i++) data[k][i]=data[k][i+1];
            data[k][data[key].size()-1]=NULL;
            cout<<"Deleted";
        }else cout<<"Data not present";
    }

    bool searching(int val){
        int k=key(val);
        for(auto i: data[k]) if(i==val)return true;
        return false;
    }
};

class OpenAddressingHashing{
    vector<int> data;
    int m;
    int key(int val){return val%m;}

    public:
    OpenAddressingHashing(int n){
        m=n;
        data=vector<int>(m);
    }

    void insertion(int val){
        int k=key(val);
        

    }
}

class QuadraticHashing{
    vector<int> data;
    int m;
    int key(int val,int at=0){
        if(at>=m) return -1;
        int ind=((val%m) + at*at)%m;
        if(data[ind]==-1) return ind;
        return key(val,at+1);
    }
    public:
    
    QuadraticHashing(int n){
        m=n;
        data=vector<int>(m,-1);
    }
    void insert(int val){
        int k=key(val);
        if(k!=-1) data[k]=val;
    }
}



int solve(){
    //hashing takes average O(1) for insertion,deletion and searching.
    //I
}