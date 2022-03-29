#include<iostream>
#include<fstream>
using namespace std;
        // ofstream    it is used to create files and write on files
        //ifstream      it is used to read from files
        //fstream       it can perform the function of both ofstream and ifstream which means it can create , read , write files


        // opening files
        // ios::app             opens a text file for appending .(appending means to add text at the end)
        // ios::ate             opens a file for output and move the read/write control to the end of the file
        // ios::in              opens a text file for reading
        // ios::out             opens a text file for writing
        // ios::trunc           truncates the content before opening a file, if file exits.

        // if(file.is_open()) than file can be open else not
int main()
{
    char text[200];
    fstream file; file.open("example.txt",ios::in | ios::out);
    cout<<"enter the text in files "<<endl;
    cin.getline(text,sizeof(text));

    //writing on file
    file<<text<<endl;

    //reading from file
    file>>text;
    cout<<text<<endl;

    // closing a file
    file.close();
    return 0;
}

