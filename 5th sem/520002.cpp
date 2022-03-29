#include<iostream>
#include<fstream>
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

char* getFileName(short Class,char section){
    char fileName[10];
    fileName[0]=Class+48;
    fileName[1]='(';
    fileName[2]=section;
    char ending=").txt";
    strcat(fileName,ending);
    return fileName;
}



short scanClass(){
    short Class;
    do{
        cout<<"Please enter class between 1 to 5 "<<endl<<"Class : ";
        cin>>Class;
    } while(Class<6 && Class>0);
    return Class;
}
char scanSection(){
    char section='s';

    bool loop=true;
    do{
        cout<<"enter section (A/B) : ";
        cin>>section;
        if(section=='A' || section=='B') loop=false;
        if(section=='a' || section=='b'){section-=32; loop=false;}
    } while(loop);
    return section;
}


class Student{
    Date DOB;
    char firstName[20],middleName[20],lastName[20],section;
    short Class , rollNumber,option;
    long mobileNumber;
    public:
    Student(){}
    ~Student(){}
    saveData(char *FirstName,char *MiddleName,char *LastName,Date dob,
                    long MobileNumber,char Section,short class_,short roll){
        DOB=dob;
        mobileNumber=MobileNumber;
        section=Section;
        Class=class_;
        rollNumber=roll;
        strcpy(firstName,FirstName);
        strcpy(middleName,MiddleName);
        strcpy(lastName,LastName);
    }

    void scanData(){

    }

    void setRollNumber(short roll){
        rollNumber=roll;
        cout<<"Your Roll number is "<<roll<<endl;
    }

    bool matchMobileNumber(long MobileNumber){
        if(MobileNumber==mobileNumber) return true;
        return false;
    }

    bool matchClassAndRollNumber(short class_,short roll){
        if(class_==Class && rollNumber==roll) return true;
        return false;
    }
    void showMobileNumber(){
        cout<<"mobile number : "<<mobileNumber<<endl;
    }
    void showDetails(){
        cout<<"FirstName : "<<firstName<<endl<<"MiddleName : "<<middleName
            <<endl<<"LastName : "<<lastName<<endl;
        cout<<"Class : "<<Class<<"\t"<<section<<endl<<"R.no : "<<rollNumber<<endl;
        DOB.show();
        cout<<"M.no  : "<<mobileNumber<<endl;
    }
};


int main(){
    char firstName[20],middleName[20],lastName[20];
    char section,das,sh;
    short Class , rollNumber,option,dd,mm,yy;
    long mobileNumber;
    bool loop=true,matched=false;
    Date current;

    Student student[5][2][60],temp;
    int filledStudent[5][2];
    for(int i=0; i<5; i++) for(int j=0; j<2; j++) filledStudent[i][j]=0;
    ///reading data
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++){

            j==0 ? sh='A' :sh='B';
            read=fopen(getFileName(i,sh));
            while (read) {
                if(!read>>rollNumber>>firstName>>middleName>>lastName>>
                   Class>>dd>>das>>mm>>das>>mobileNumber) break;
                   current.saveDate(dd,mm,yy);
                student[i][j][filledStudent[i][j]++]=Student(firstName,middleName,lastName,
                                current,mobileNumber,sh,Class,rollNumber);

            }
            read.close();

        }
    }
    read=fopen("");
    //scan all data
    //and fill

    while(loop){
        cout<<"Please choose one option\n\t1.\tAdd student \n\t2.\tSearch students by mobile number\n";
        cout<<"\t3.\tSearch students by class and Roll number\n\t4.\tExit\n";
        cin>>option;
        matched=false;
        switch(option){
            case 1: cout<<"enter student name\nFirstName : "; cin>>firstName;
                    cout<<"MiddleName : "; cin>>middleName;
                    cout<<"Last Name : "; cin>>lastName;
                    Class=scanClass();
                    section=scanSection();
                    cout<<"Mobile number : "; cin>>mobileNumber;
                    do{current.scan();} while(!current.isCorrect());
                    int j=0;
                    if(section=='B')j=1;
                    if(matched) cout<<"Students already registered\n";
                    else{
                        ofstream write;
                        file=fopen(getFileName(Class,section));
                        int j=0;
                        while(j<filledStudent[Class][j]){
                            write<<rollNumber<<firstName<<middleName<<lastName<<current.dd<<'-'<<current.mm
                            '-'<<current.yy<<mobileNumber;
                        }

                    }
                    break;

            case 2: cout<<"enter mobile number: "; cin>>mobileNumber;
                    for(int i=0; i<5; i++){
                        for(int j=0; j<2; j++){
                            for(int k=0; k<filledStudent[i][j]; k++){
                                if(student[i][j][k].matchMobileNumber(mobileNumber)){
                                    student[i][j][k].showDetails();
                                    i=5;j=2; k=60;
                                    matched=true;
                                }
                            }
                        }
                    }
                    if(!matched)  cout<<"no data found"<<endl;
                    break;

            case 3: Class=scanClass();
                    do{
                        cout<<"enter RollNumber : "; cin>>rollNumber;
                    } while(rollNumber>0)
                    if(filledStudent[Class][0]<=rollNumber){
                        if(student[Class][0][rollNumber].matchClassAndRollNumber(Class,rollNumber)){
                                    student[Class][0][rollNumber].showDetails();
                                    matched=true;
                        }
                    }
                    if(filledStudent[Class][1]<=rollNumber){
                        if(student[Class][1][rollNumber].matchClassAndRollNumber(Class,rollNumber)){
                                    student[Class][1][rollNumber].showDetails();
                                    matched=true;
                        }
                    }
                    if(!matched)  cout<<"no data found"<<endl;
                    break;

            case 4: loop=false; break;
        }
    }
}
