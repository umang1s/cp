#include"default.h"

string lcs(string first,int lenf,string second,int lens,string cal){
    if(lenf==0 || lens==0) return cal;
    if(first[lenf-1]==second[lens-1]){
        cal=first[lenf-1]+cal;
        return lcs(first,lenf-1,second,lens-1,cal);
    }
    string lf=lcs(first,lenf-1,second,lens,cal);
    string rf=lcs(first,lenf,second,lens-1,cal);
    if(lf.length()>=rf.length()) return lf;
    return rf;
}

string getSuperStringMin(string first,string second,int lenf,int lens){
    string lc=lcs(first,lenf,second,lens,"");
    int lenr=lc.length();
    string ret="";
    int s=0,r=0,f=0;
    while(r<lenr){
        if(f<lenf) {while(first[f]!=lc[r]) ret+=first[f++]; f++;}
        if(s<lens) {while(second[s]!=lc[r]) ret+=second[s++]; s++;}
        ret+=lc[r++];
    }
    return ret;

}

int minInsAndDelToConvEqual(string first,string second,int lenf,int lens){
    string input=lcs(first,lenf,second,lens,"");
    int l=input.length();
    return lenf-l+lens-l;//lenf-l deletion and lens-l insertion
}

string longestPalindromicSubSeq(string first,int lenf){
    string second="";
    for(int i=lenf-1; i>=0; i--) second+=first[i];
    return lcs(first,lenf,second,lenf,"");
}


void solve(){
    // string first,second,answer="";
    // cin>>first>>second;
    // int lenf=first.length(),lens=second.length();
    // answer=lcs(first,lenf,second,lens,answer);
    // cout<<answer<<endl;
    // answer=getSuperStringMin(first,second,lenf,lens);
    // cout<<nl<<minInsAndDelToConvEqual(first,second,lenf,lens)<<nl<<answer<<nl;
    string first;
    cin>>first;
    cout<<longestPalindromicSubSeq(first,first.length());
}