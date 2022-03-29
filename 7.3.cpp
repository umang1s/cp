#include<iostream>
#include<cmath>
using namespace std;
class MAT
{
    double matrix[100][100];
    int M,N;
public:
    MAT(int m=0,int n=0)   //constructor which define to size of matrix
    {
        M=m; N=n;
    }
    ~MAT(){}
    void setValue(double g[])
    {
        int k=0;
        for(int i=0; i<M; i++) for(int j=0; j<N; j++) matrix[i][j]=g[k++];
    }
    void show()
    {
        cout<<endl;
        for(int i=0; i<M; i++)
        {
            for(int j=0; j<N; j++) cout<<matrix[i][j]<<"  ";
            cout<<endl;
        }
    }
    MAT transpose()
    {
        MAT E(N,M);
        for(int i=0; i<N; i++) for(int j=0; j<M; j++) E.matrix[i][j]=matrix[j][i];
        return E;
    }
    MAT operator+(MAT d)
    {
        MAT E(M,N);
        if(d.M==M && d.N==N)    for(int i=0; i<M; i++) for(int j=0; j<N; j++)
            E.matrix[i][j]=d.matrix[i][j] + matrix[i][j];
        else cout<<endl<<"this matrix can't be add"<<endl;
        return E;
    }
    MAT operator-(MAT d)
    {
        MAT E(M,N);
        if(d.M==M && d.N==N)    for(int i=0; i<M; i++)  for(int j=0; j<N; j++)
            E.matrix[i][j]=d.matrix[i][j] - matrix[i][j];
        else cout<<endl<<"this matrix can't be subtract"<<endl;
        return E;
    }
    MAT operator*(MAT d)
    {
        MAT E(M,d.N);
        if(N==d.M)  for(int i=0; i<M; i++)  for(int j=0; j<d.N; j++) for(int l=0; l<N; l++)
            E.matrix[i][j]+=d.matrix[l][j]*matrix[i][l];
        else cout<<endl<<"this matrix can't be multiply"<<endl;
        return E;
    }
};
int main()
{
    int M=3, N=2;   //setted size of matrix
    double p[M*N]={1,2,3,4,5,6};
    double q[M*N]={4,5,6,7};
    MAT x(M,N),y(M-1,N),z;
    x.setValue(p);
    y.setValue(q);

    x.show();
    y.show();
    z=x+y;
    z.show();
    z=x-y;
    z.show();
    z=x*y;
    z.show();
    z=z.transpose();
    z.show();
}
