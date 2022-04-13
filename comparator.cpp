#include"default.h"
class Student{
    public:
    int id;
    string name;
    int classroom;

    Student(int id,string name,int classroom){
        this->classroom=classroom;
        this->id=id;
        this->name=name;
    }

    bool operator <(const Student &s){
        return name<s.name;
        return id<s.id;
    }

    bool compareByName(const Student &x){
        return name<x.name;
    }
    bool compareByClassRoom(const Student &x){
        return classroom<x.classroom;
    }
    bool operator ==(const Student &x){
        return id==x.id;
    }
    string toString(){
        return "{ ID : "+to_string(id)+" , Name : "+name+" , Class : "+to_string(classroom)+" }";
    }
};

void print(vector<Student> &arr){
    for(auto i: arr) cout<<i.toString()<<nl;
    cout<<nl;
}


void solve(){
    vector<Student> arr;
    for(int i=0; i<10; i++){
        string name="name"+to_string(100-i);
        Student temp=Student(i+1,name,i%3);
        arr.push_back(temp);
    }
    print(arr);
    sort(arr.begin(),arr.end());
    print(arr);


}