#include<iostream>
#include<fstream>
using namespace std;
void firstFile()
{
    int i,m,o;
    string name;
    fstream read;
    read.open("txt01.txt");
    cout<<"enter the total number of students you want to resistor in txt01.txt file"<<endl;
    cin>>i;
    cout<<"enter their name and rollnumber and class"<<endl;
    for(int k=0; k<i; k++)
    {
        cout<<"name :"; cin>>name;
        cout<<"roll :"; cin>>m;
        cout<<"class :"; cin>>o;
        read<<name<<"\t"<<m<<"\t"<<o<<endl;
    }
}
int main()
{
    int i=23;
    cout<<"umang is my name and i came here for knowing about file handling and basic file creation"<<endl;
    cout<<"after this line this program is terminated to fist file handling which creat file"<<endl;
    firstFile();
    //secondFile();
    return 0;
}
