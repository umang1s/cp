#include<iostream>
#include<cstring>
using namespace std;


class Statements{
    char statements[100];
    public:
    Statements(char * statement){
        strcpy(statements,statement);
    }
    void lexicalAnalysis(){

    }
};

int main(){
    char program[1000]="int i,j;  i=4; j=i*i; int sum=i+j;";
    int temp=0;
    for(int i=0; i<strlen(program); i++){
        switch (program[i])
        {
        case '#':   break;
        
        default:
            break;
        }
    }
}