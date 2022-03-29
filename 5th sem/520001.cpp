#include<stdio.h>
#include<iostream>
#include<cstring>
using namespace std;
class Date{
    public:
    short dd,mm,yy;
    void saveDate(short DD,short MM, short YY)
    {dd=DD; mm=MM; yy=YY;}

    void scan(){
        cout<<"enter the DOB of student\nDD : ";
        cin>>dd;cout<<"MM : "; cin>>mm; cout<<"YY : "; cin>>yy;
    }
    bool isCorrect(){
        short month[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};
        if(yy<100) yy+=2000;
        if(yy%4==0) month[2]=29;
        //checking condition
        if(yy<1980 || yy>2020) return false;
        if(mm>12 || mm<1) return false;
        if(dd<1 || dd>month[mm]) return false;
        return true;
    }
    void show(){
        cout<<"DOB : "<<dd<<"-"<<mm<<"-"<<yy<<endl;
    }
};



class Name{
    public:
    char firstName[20],middleName[20],lastName[20];
    void takeData(char *f, char *m, char *l){
        for(int i=0; i<strlen(f); i++) firstName[i]=f[i];
        for(int i=0; i<strlen(m); i++) middleName[i]=m[i];
        for(int i=0; i<strlen(l); i++) lastName[i]=l[i];
    }
    void scan(){
        cout<<"enter Student Name \nFirst Name :  ";
        cin>>firstName; cout<<"Second Name :  "; cin>>middleName;
        cout<<"Last Name :   "; cin>>lastName;
    }
    void show(){
        cout<<"Name : "<<firstName<<"   "<<middleName<<"   "<<lastName<<endl;
    }
};

class Student{
    public:
    Name studentName;
    Date DOB;
    long  MobileNumber;
    short RollNumber;
    char Section;
    short Class_;
    void takeData(Name name,Date dob,long mobileNumber,char section,short class_,short roll){
        studentName=name;
        DOB=dob;
        MobileNumber=mobileNumber;
        Section=section;
        Class_=class_;
        RollNumber=roll;
    }
    void scanData(){
        studentName.scan();
        DOB.scan();
        bool dataCorrect=false;
        cout<<"enter Class : ";
        cin>>Class_;
        while(Class_<1 || Class_>6) {cout<<"Wrong"<<endl; cin>>Class_;}
        cout<<"enter section A/B : "; cin>>Section;
        if(Section=='a' ) Section='A';
        else if(Section=='b') Section=='B';
        else if(Section!='A' && Section!='B') Section='B';
        cout<<"enter RollNumber "<<endl; cin>>RollNumber;
        while(RollNumber>60 || RollNumber<1){cout<<"Wrong"<<endl; cin>>RollNumber;}
        cout<<"enter  mobile number "<<endl;
        cin>>MobileNumber;

    }
    void showMobileNumber(){
        cout<<"mobile number : "<<MobileNumber<<endl;
    }
    void showDetails(){
        studentName.show();
        cout<<"Class : "<<Class_<<"\t"<<Section<<endl<<"R.no : "<<RollNumber<<endl;
        DOB.show();
        cout<<"M.no  : "<<MobileNumber<<endl;
    }
};

int main(){
    bool progress=true;
    Student student[5][2][60]; //class,section,students
    int filledStudent[5][2];    // stores students count
    // scanning data from file
    FILE *read;
    char fileName[7]={"00.txt"};
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++){
            fileName[0]=i+48;
            fileName[1]= j==0 ? 'A':'B';
            read=fopen(fileName,"r");
            filledStudent[i][j]=0;
            // get data

            fclose(read);
        }
    }

    int input=0;
    bool found=false;
    Student temp;
    while(progress){
        for(int i=0; i<5; i++) {
            cout<<i+1;
                for(int j=0; j<2; j++){
                        j==0 ? cout<<"=> A(" : cout<<",B(";
                        cout<<filledStudent[i][j]<<")";
                }
            cout<<"\t\t";
        }
        cout<<"\nchoose on option \n\t1.\tGet Students details by contact number\n";
        cout<<"\t2.\tGet mobile number by roll number and class\n\t3.\tAdd Student\n";
        cout<<"\t9.\tEXIT"<<endl;
        cin>>input;
        if(input==9) progress=false;
        else if(input==1){
            cout<<"Enter mobile number : ";
            cin>>temp.MobileNumber;
            for(int i=0; i<5; i++){ for(int j=0; j<2; j++){
                for(int k=0; k<filledStudent[i][j]; i++){
                     if(student[i][j][k].MobileNumber==temp.MobileNumber){
                        student[i][j][k].showDetails();
                        k=100; j=4; i=5; found=true;
                     }
                }
            }}
            if(!found) {cout<<"No data founds "<<endl;  found=false;}
        } else if(input==2){
            do{
                cout<<"enter class : "; cin>>temp.Class_;
                cout<<"enter Roll Number : "; cin>>temp.RollNumber;
            }while(temp.Class_<1 || temp.Class_>6 || temp.RollNumber>61 || temp.RollNumber<1);
            for(int i=0; i<2; i++){
                if(filledStudent[temp.Class_][i]<=temp.RollNumber){
                    student[temp.Class_][i][temp.RollNumber].showMobileNumber();
                    found=true;
                }
            }
            if(!found) {cout<<"No data founds "<<endl;  found=false;}
        } else if(input==3){
            temp.scanData();
            int num=filledStudent[temp.Class_][temp.Section=='A' ? 0: 1];
            cout<<num<<endl;
            student[temp.Class_][temp.Section][num++]=temp;

            cout<<"saved"<<endl;
        }
        cout<<endl<<endl<<endl;
    }
}
