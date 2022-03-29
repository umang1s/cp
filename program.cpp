#include <iostream>
#include<stdio.h>
using namespace std;

int main() {
	FILE *file=fopen("input.txt","r");
	int c=9;
	while (c != EOF) {
		cout<<c<<endl;
        c = getc(file);
        
    }
	return 0;
}
