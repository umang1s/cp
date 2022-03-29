#include<bits/stdc++.h>
using namespace std;

bool SHOWCASE=false;
bool TESTCASEACTIVE=true;
bool OUTPUT=false;

void solve(int);
void giveOutput();

int main(){


	long testCase=1,inc=1;
	if(TESTCASEACTIVE) cin>>testCase;
	while(testCase--){//programming area
        solve(inc);
		if(SHOWCASE) cout<<"Case #"<<inc<<": ";
		inc++;
		cout<<endl;
	}

	if(OUTPUT) giveOutput();
}


void giveOutput(){
	char fileLocation[50]={"D:/chrome/program.cpp"};
	FILE *out;
	out=fopen(fileLocation,"w");
	fprintf(out,"This is a program \n");

	fclose(out);
	cout<<fileLocation<<endl;
}