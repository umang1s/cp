#include<iostream>
#include<fstream>
using namespace std;
void Example4()
{
    // this is for input
    cout<<"Example 4 "<<endl;
    ifstream in("INVENTRY");
    if(!in) {cout<<"cannot open inventry file.\n";}
    char c;
    in>>c;
    cout<<c;
    in.close();
    cout<<"END"<<endl;
}
void Example5()
{
    // this is for out put //
    cout<<"Example 5 "<<endl;
    ofstream out("INVENTRY");
    if(!out) {cout<<"Cannot open Inventry file \n";}
    out<<"tt "<<12<<endl;
    out<<"yy "<<23<<endl;
    out.close();
    cout<<"End"<<endl;
}
void Example3()
{
    cout<<"Example 3 "<<endl;
    ifstream mystream("myfile");
    mystream.close();       //for closing a file
    bool is_open();
    if(!mystream.is_open()) {cout<<" File is not open  "<<endl;}
    cout<<"  END  "<<endl;
}
void Example2()
{
    cout<<"Example 2"<<endl;
    ifstream mystream("myfile");    //open file for output
    if(!mystream)
    {
        cout<<"Cannot open file ."<<endl;
    }
    cout<<"END"<<endl;

}
void Example1()
{
    cout<<"this is example one "<<endl;
    ofstream out;   //ifstream is use for in and fstream is use for both
    out.open("test",ios::out);  //default to outpot and normal file
    cout<<"end"<<endl<<endl;
}
int main()
{
    /********file handling ****************/
    Example1();
    Example2();
    Example3();
    Example4();

}

