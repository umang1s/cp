#include<iostream>
#include<fstream>
using namespace std;
void secondExampleFile()
{
    ifstream in("INVENTRY");    //input
    if(!in)
    {
        cout<<"Cannot open Inventry file. "<<endl; return ;
    }
    char item[20];
    float cost;
    in>>item>>cost;
    cout<<item<<"  "<<cost<<endl;
    in>>item>>cost;
    cout<<item<<" "<<cost<<endl;
    in.close();
}
int main()
{
    ofstream out("INVENTRY");   //output , normal file
    if(!out)
    {
        cout<<"Cannot open IVNVENTORY file."<<endl;
        return 1;
    }
    out<<"Radios "<<39.32<<endl<<"toasters "<<121.32<<endl<<"Mixers "<<34.43<<endl;
    out.close();
    ifstream in("INVENTRY");    //input
    if(!in)
    {
        cout<<"Cannot open Inventry file. "<<endl; return 1;
    }
    char item[20];
    float cost;
    in>>item>>cost;
    cout<<item<<"  "<<cost<<endl;
    in>>item>>cost;
    cout<<item<<" "<<cost<<endl;
    secondExampleFile();  //second example
    return 0;
}
