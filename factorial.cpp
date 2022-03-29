#include <iostream>
using namespace std;

int multiply(int arr[],int num,int len){
    int carry=0;
    for(int i=0; i<len; i++){
        int temp=arr[i]*num+carry;
        carry=temp/10;
        arr[i]=temp%10;
    }
    while(carry){
        arr[len++]=carry%10;
        carry/=10;
    }
    return len;
}

int main() {
	// your code goes here
	int test;
	int arr[1000];
	int len=1;
	arr[0]=1;
	cin>>test;
	while(test--){
	    int num;
	    cin>>num;
	    int len=1;
	    arr[0]=1;

	    for(int i=2; i<=num; i++) len=multiply(arr,i,len);

	    //output
	    for(int i=len-1; i>=0; i--) cout<<arr[i];
	    cout<<endl;
	}
	return 0;
}
