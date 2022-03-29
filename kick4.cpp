#include"def.h"
typedef struct pos{
    int X,Y;
    int hrs;
}Pos;

void solve(int test){
    int N;
    cin>>N;
    vector<vector<int>> A(N,vector<int>(N));
    vector<vector<int>> B(N,vector<int>(N));
    vector<int> C(N);
    vector<int> R(N);
    vector<Pos> unsolved;

    int answer=0;
    int countn=0;
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>A[i][j];
    for(int i=0; i<N; i++) for(int j=0; j<N; j++) cin>>B[i][j];
    for(int i=0; i<N; i++)  cin>>R[i];
    for(int i=0; i<N; i++)  cin>>C[i];

    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        if(A[i][j]==-1 && B[i][j]==0){ A[i][j]=1; countn++;}
    }

    for(int i=0; i<N; i++) for(int j=0; j<N; j++){
        if(A[i][j]==-1){
            Pos ss;
            ss.hrs=B[i][j];
            ss.X=j;
            ss.Y=i;
            unsolved.push_back(ss);
        }
    }

    for(int i=0; i<unsolved.size(); i++) cout<<unsolved[i].hrs<<" ";
    cout<<endl;
    sort(unsolved.begin(),unsolved.end());
    for(int i=0; i<unsolved.size(); i++) cout<<unsolved[i].hrs<<" ";
    cout<<endl;
    



    //for low 

        cout<<"Case #"<<test<<": "<<answer;


}