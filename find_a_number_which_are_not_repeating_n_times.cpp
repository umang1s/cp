void solve(int t){
    int n;
    cin>>n;

    vector<int> temp(32,0);
    int ans=0;
    while(n--){
        int a;
        cin>>a;

        int st=0;
        while(a>0){
            temp[st]+=a&1;
            st++;
            a=a>>1;
        
        }
    }
    for(int i=0; i<32; i++) if(temp[i]%3) ans=ans | (1<<i); //3 means a number is repeating thrice in the array


    cout<<ans;
    

    
}