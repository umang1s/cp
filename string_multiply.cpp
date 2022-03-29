vector<int> multi(vector<int> num,int dig){
        int carry=0;
        vector<int> ans;
        for(int i=num.size()-1; i>=0; i--){
            int p=dig*num[i]+carry;
            ans.push_back(p%10);
            carry=p/10;
        }
        if(carry) ans.push_back(carry);
        return ans;
    }
    
    string multiply(string num1, string num2) {
        int n=num1.length(),m=num2.length();
        if(n<5 && m<5) return to_string(stoi(num1)*stoi(num2));


        vector<int> n1(n),n2(m);
        for(int i=0; i<n; i++) n1[i]=num1[i]-'0';
        for(int i=0; i<m; i++) n2[i]=num2[i]-'0';
        vector<int> mul(n+m+2,0);
        string ret="";
        vector<vector<int>> dp(10);
        for(int i=1; i<10; i++) dp[i]=multi(n1,i);
        for(int i=0; i<m;  i++){
            if(n2[m-i-1]==0) continue;
            int op=n+m-i,d=n2[m-i-1],s=dp[d].size();
            int carry=0;
            for(int j=0; j<s; j++){
                int sum=mul[op]+dp[d][j]+carry;
                mul[op--]=sum%10;
                carry=sum/10;
            }
            if(carry) mul[op]=carry;
        }
        int zero=0;
        while(mul[zero]==0 && zero<=n+m) zero++;
        for(int j=zero; j<n+m+1; j++) ret+=to_string(mul[j]);
        return ret; 
    }
