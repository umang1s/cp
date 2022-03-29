#include <iostream>
#include <fstream>
using namespace std;

int main()
{
    ofstream fout;
    string line;
    string maxx;
    cout<<line;
    fout.open("sample.txt");
    while (fout) {
        getline(cin, line);
        if (line == "-1")
            break;
        fout << line << endl;
    }
    fout.close();
    ifstream fin;
    fin.open("sample.txt");
    char val[20];
    int pax;
    while (fin) {
        if(!(fin>>val>>pax)) break;
        cout << val <<" "<<pax<< endl;
    }
    fin.close();

    return 0;
}
