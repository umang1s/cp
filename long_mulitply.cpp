#include <iostream>
using namespace std;

int first[17],answer[17],temp[17];
int count=0,count1=0;

void resetIt(){
    for(int i=0; i<17; i++) temp[i]=0;
}

void addTemp(){
    int carry=0;
    for(int i=16; i>=0; i--){
        int t=answer[i]+temp[i]+carry;
        carry=t/10;
        answer[i]=t%10;
    }
    resetIt();
}

void multiply(){
    int loop=0;
    for(int i=16; i>5; i--){
        int start=16-loop;
        int carry=0,ttt=0;
        for(int j=16; j>7; j--){
            ttt=first[i]*first[j];
            ttt+=carry;
            carry=ttt/10;
            temp[start--]=ttt%10;
        }
        temp[start]=carry;
        addTemp();
        loop++;
    }
        //cout<<first<<endl;
}

void addition(){
    int carry=0;
    for(int i=16; i>=0; i--){
        int t=answer[i]+first[i]+carry;
        carry=t/10;
        answer[i]=t%10;
    }
}

int main() {
	// your code goes here
	int n;
	cin>>n;

    for(int i=0; i<17; i++) first[i]=answer[i]=temp[i]=0;
	
	int last=16;
	while(n>9){
	    first[last]=n%10;
        n/=10;
        last--;
        count++;
	}
    first[last]=n;
    count++;
	
	
	multiply();
    bool zeroComp=false;
    for(int i=0; i<17; i++){
        if(zeroComp) cout<<answer[i];
        else{
            if(answer[i]!=0){
                cout<<answer[i];
                zeroComp=true;
            }
        }
    }
	cout<<" ";
	addition();
    zeroComp=false;
    for(int i=0; i<17; i++){
        if(zeroComp) cout<<answer[i];
        else{
            if(answer[i]!=0){
                cout<<answer[i];
                zeroComp=true;
            }
        }
    }
	cout<<endl;
	
	return 0;
}
