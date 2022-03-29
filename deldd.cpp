#include <iostream>
#include<cstring>
using namespace std;

bool match(char board[],int a,int b,int c, char pla){
    if(board[a]==pla && board[b]==pla && board[c]==pla) return true;
    return false;
}

int checkWinner(char board[],char player){
    //cross checking
    if(match(board,1,2,3,player)) return 1;
    if(match(board,4,5,6,player)) return 1;
    if(match(board,7,8,9,player)) return 1;

    if(match(board,1,4,7,player)) return 1;
    if(match(board,2,5,8,player)) return 1;
    if(match(board,3,6,9,player)) return 1;

    if(match(board,1,5,9,player)) return 1;
    if(match(board,3,5,7,player)) return 1;

    //check draw also
    return 0;
}

bool printed=false;
void p(int v){
    if(printed) return ;
    else cout<<v<<endl;
    printed=true;
}


int main() {
	// your code goes here
	int test;
	cin>>test;
	while(test--){
	    printed=false;
	    char first[10];
	    for(int i=1; i<10; i++) cin>>first[i];
	    int dT=0,xT=0,oT=0;
	    for(int i=1; i<10; i++){  if(first[i]=='X') xT++; else if(first[i]=='O') oT++; else dT++;}
	    if( xT<oT) p(3);
	    if(xT-oT>1) p(3);
	    if(dT>5) p(2);
	    else{
	        int cd=checkWinner(first,'X');
	        cd+=checkWinner(first,'O');
	        if(dT==0 && cd==0) p(1);
	        if(cd==0) p(2);
	        else if(cd==1) p(1);
	        else p(3);
	    }

	}
	return 0;
}
