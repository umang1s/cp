#include"def.h"


void solve(int x){
    int R,C;
    cin>>R>>C;
    vector<vector<int>> g(R,vector<int>(C));

    for(int i=0; i<R; i++) for(int j=0; j<C; j++) cin>>g[i][j];


    long count=0;

    
    int left,current,right,sub;
    //horizontal counting
    for(int i=0; i<R; i++){
        for(int j=1; j<C; j++){
            left=g[i][j]-g[i][j-1];
            if(j==C-1){
                if(left>1){
                    count+=left-1;
                    g[i][j-1]=g[i][j]-1;
                } else if(left<-1){
                    count+=abs(left)-1;
                    g[i][j]=g[i][j-1]-1;
                }
            }else{
                left=g[i][j-1];
                right=g[i][j+1];
                current=g[i][j];
                if(left>current){
                    if(right>current){ 
                        if(left>right){//left right current
                            sub=left-current;
                            if(sub>1){
                                count+=sub-1;
                                g[i][j]=g[i][j-1]-1;
                            }
                            sub=g[i][j]-right;
                            if(sub>1){
                                count+=sub-1;
                                g[i][j-1]=g[i][j]-1;
                            }
                        }else if(left==current){
                        }else{

                        }

                    }else if(right==current){

                    }else{

                    }
                }else if(left==current){
                    if(right>current){

                    }else if(right==current){

                    }else{

                    }
                }
                else{
                    if(right>current){

                    }else if(right==current){

                    }else{

                    }
                }
            }
            //right data
        }
        //get big
    }
    


    cout<<"Case #"<<x<<": "<<count;
}