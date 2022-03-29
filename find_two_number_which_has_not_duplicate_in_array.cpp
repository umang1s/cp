void solve(int t){
    int arr[]={11111118,11111119,11111118,11111111,11111111,11111119,11111117,11111117,11111118,11111116};

    int x=0;
    for(int i=0; i<10; i++) x^=arr[i];

    int bit=1;
    while(bit<100){
        cout<<bit<<nl;
        int first=0,second=0;
        for(int i=0; i<10; i++) { if(arr[i]&bit) first^=arr[i]; else second^=arr[i];}
        if(x&bit){
            cout<<first<<spc<<second;
            break;
        }
        bit=bit<<1;
    }
    
}