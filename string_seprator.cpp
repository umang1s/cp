#include<bits/stdc++.h>
using namespace std;
int stringNumSeprator(string z,vector<pair<int,int>> &number,vector<pair<string,int>> &text){
    int order=1,len=z.length();
    vector<pair<string,bool>> temp;
    string current="";
    bool isNumber=z[0]>47 && z[0]<58?true:false;
    for(auto c: z){
        bool wasNumber=isNumber;
        isNumber=c>47 && c<58?true:false;
        if(wasNumber==isNumber) current+=c;
        else{temp.push_back({current,wasNumber}); current=c;}
    }
    temp.push_back({current,isNumber});
    for(auto p:temp){
        if(p.second){
            int val=0;
            int length=p.first.length();
            int ten=1;
            for(int i=length-1; i>=0; i--){
                val+=(p.first[i]-48)*ten;
                ten*=10;
            }
            number.push_back({val,order++});
        }else  text.push_back({p.first,order++});
    }
    return temp.size();
}