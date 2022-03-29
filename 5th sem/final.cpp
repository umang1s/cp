#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;
char FILENAME[10];

class Student{
    public:
    char firstName[20],middleName[20],lastName[20];
    char section;
    short roll,Class,dd,mm,yy;
    long mobileNumber;
    Student(){}
    void save(char *f,char *m,char *l,char s,short ro,short cl,short ddd,short mmm,short yyy,long mob){
        strcpy(middleName,m);
        strcpy(firstName,f);
        strcpy(lastName,l);
        dd=ddd; mm=mmm; yy=yyy; mobileNumber=mob; section=s; roll=ro; Class=cl;
    }
    void showDetails(){
        cout<<"Name : "<<firstName<<" "<<middleName<<" "<<lastName<<endl;
        cout<<"Class : "<<Class<<" "<<section<<endl;
        cout<<"R.no : "<<roll<<endl;
        cout<<"DOB : "<<dd<<"-"<<mm<<"-"<<yy<<endl;
        cout<<"mobile number : "<<mobileNumber;
    }
    bool matchClassAndRollNumber(short rollN,short Classs){
        if(roll==rollN && Class == Classs) return true;
        return false;
    }
};

void  getFileName(short x,char section){
    char fileName[10];
    fileName[0]=x+48;
    fileName[1]='(';
    fileName[2]=section;
    char ending[6]=").txt";
    strcat(fileName,ending);
    strcpy(FILENAME,fileName);
}
int main(){
    bool loop=true,matched=false;
    Student student[5][2][60],temp;
    int filledStudent[5][2];
    char sh,das;


    for(int i=0; i<5; i++) for(int j=0; j<2; j++) filledStudent[i][j]=0;

    ///reading data
    for(int i=0; i<5; i++){
        for(int j=0; j<2; j++){
            if(j==0) sh='A';
            else sh='B';
            ifstream read;
            getFileName(i+1,sh);
            cout<<FILENAME<<endl;
            read.open(FILENAME);
            while (read)
            {
                read>>temp.roll>>temp.firstName>>temp.middleName>>temp.lastName>>
                temp.Class>>temp.dd>>das>>temp.mm>>das>>temp.yy>>temp.mobileNumber;
                temp.section=sh;
                student[i][j][filledStudent[i][j]++]=temp;

            }
            read.close();

        }
    }
    int option;
    while(loop){
        cout<<"Please choose one option\n\t1.\tSearch students by mobile number\n";
        cout<<"\t2.\tSearch students by class and Roll number\n\t-1.\tExit\n";
        cin>>option;
        matched=false;
        switch(option){
            case 1: cout<<"enter mobile number: "; cin>>temp.mobileNumber;
                    for(int i=0; i<5; i++){
                        for(int j=0; j<2; j++){
                            for(int k=0; k<filledStudent[i][j]; k++){
                                if(student[i][j][k].mobileNumber==temp.mobileNumber){
                                    student[i][j][k].showDetails();
                                    i=5;j=2; k=60;
                                    matched=true;
                                }
                            }
                        }
                    }
                    if(!matched)  cout<<"no data found"<<endl;
                    break;

            case 2:  cout<<"enter Class : ";       cin>>temp.Class;
                     cout<<"enter RollNumber : "; cin>>temp.roll;
                    if(filledStudent[temp.Class][0]<=temp.roll){
                        if(student[temp.Class][0][temp.roll].matchClassAndRollNumber(temp.Class,temp.roll)){
                                    student[temp.Class][0][temp.roll].showDetails();
                                    matched=true;
                        }
                    }
                    if(filledStudent[temp.Class][1]<=temp.roll){
                        if(student[temp.Class][1][temp.roll].matchClassAndRollNumber(temp.Class,temp.roll)){
                                    student[temp.Class][1][temp.roll].showDetails();
                                    matched=true;
                        }
                    }
                    if(!matched)  cout<<"no data found"<<endl;
                    break;

            case -1: loop=false; break;
        }
    }
}
