#include<iostream>
#include<fstream>
using namespace std;
int main(int argc, char *argv[])
{
    if(argc!=2)
    {
        cout<<"Usase : output <filename>"<<endl;
        retur 1;
    }
    ofstream out(argv[1];)      //output , normal file
    if(!out)
    {
        cout<<"Cannot open output file ."<<endl;
        return 1;
    }
    char str[23];
    cout<<"enter name and ! for stop"<<endl;
    do
    {
        cout<<": ";
        cin<<str;
        out<<str<<endl;
    }while(*str !='!')
    out.close();
    return 0;
}
