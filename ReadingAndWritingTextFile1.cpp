#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        cout<<"Usage: output <filename>"<<endl;
        return 1;
    }
    ofstream out(argv[1]);  //output , normal file
    if(!out)
    {
        cout<<"Cannot open output file. "<<endl;
        return 1;
    }
    char str[80];
    cout<<"Write strings to disk.Enter ! to stop."<<endl;
    do
    {
        cout<<": ";
        cin>>str;
        out<<str<<endl;
    }while(*str !='!');
    out.close();
    return 0;
}
