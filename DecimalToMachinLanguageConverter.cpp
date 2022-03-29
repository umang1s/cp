#include<iostream>
#include<cstring>
#include<cstdlib>
using namespace std;
char x[50];
long y;
bool CheckingDecimal()
{
    int y=0,i;
    for(i=0; i<strlen(x); i++)
    {
        if(x[i]>='0' && x[i]<='9') y++;
    }
    if(y==i) return true;
    return false;
}
bool CheckingBinary()
{
    int y=0,i;
    for(i=0; i<strlen(x); i++)
    {
        if(x[i]=='0' && x[i]=='1') y++;
    }
    if(y==i) return true;
    return false;
}
bool CheckingOctal()
{
    int y=0,i;
    for(i=0; i<strlen(x); i++)
    {
        if(x[i]>='0' && x[i]<='7') y++;
    }
    if(y==i) return true;
    return false;
}
bool CheckingHexa()
{
    int y=0,i;
    for(i=0; i<strlen(x); i++)
    {
        if(x[i]>='0' && x[i]<='9') y++;
        else if(x[i]>='A' && x[i]<='F') y++;
        else if(x[i]>='a' && x[i]<='f') y++;
        else ;
    }
    if(y==i) return true;
    return false;
}
void BinaryConversion()
{
    int bc[100],bcp=0;
    long yCopy=y;
    while(yCopy>1)
    {
        bc[bcp++]=yCopy%2;
        yCopy/=2;
    }
    cout<<"Binary       :   "<<yCopy;
    for(int i=bcp-1; i>=0; i--) cout<<bc[i];
    cout<<endl;
}
void HexaConversion()
{
    int bc[100],bcp=0;
    char xxx;
    long yCopy=y;
    while(yCopy>15)
    {
        bc[bcp++]=yCopy%16;
        yCopy/=16;
    }
    cout<<"HexaDecimal  :   ";
    if(y>15) cout<<yCopy;
    else bc[bcp++]=yCopy;
    for(int i=bcp-1; i>=0; i--)
    {
        if(bc[i]<10)    cout<<bc[i];
        else
        {
            xxx=bc[i]+55;
            cout<<xxx;
        }
    }
    cout<<endl;
}
void OctalConversion()
{
    int bc[100],bcp=0;
    long yCopy=y;
    while(yCopy>7)
    {
        bc[bcp++]=yCopy%8;
        yCopy/=8;
    }
    cout<<"OctaDecimal  :   "<<yCopy;
    for(int i=bcp-1; i>=0; i--) cout<<bc[i];
    cout<<endl;
}
void DecimalConversion(int z)
{
    long multpl=1; y=0;
    if(z==10)
    {
        for(int i=strlen(x)-1; i>=0; i--)
        {
            y+=(x[i]-48)*multpl;
            multpl*=z;
        }
    }
    else
    {
        if(z==2 || z==8)
        {
            for(int i=strlen(x)-1; i>=0; i--)
            {
                y+=(x[i]-48)*multpl;
                multpl*=z;
            }
        }
        else
        {
            for(int i=strlen(x)-1; i>=0; i--)
            {
                if(x[i]<='9' && x[i]>='0') y+=(x[i]-48)*multpl;
                else if(x[i]<='f' && x[i]>='a') y+=(x[i]-87)*multpl;
                else y+=(x[i]-55)*multpl;
                multpl*=z;
            }
        }
        cout<<"Decimal      :   "<<y<<endl;
    }
}
int main()
{
    bool applied;
    while(x[0]!='z')
    {
        cout<<"****************************************************************************************\n";
        cout<<"enter z for exit and x for clear screen\n";
        cout<<"Please enter your Number : ";
        cin>>x;
        applied=false;
        if(x[0]!='Z')
        {
            if(CheckingDecimal())
            {
                cout<<"This number is looks like in Decimal******\n";
                DecimalConversion(10);
                BinaryConversion();
                OctalConversion();
                HexaConversion();
                cout<<"\n";
                applied= true;
            }
            if(CheckingBinary())
            {
                cout<<"This number is looks like in Binary********\n";
                DecimalConversion(2);
                OctalConversion();
                HexaConversion();
                cout<<endl;
                applied=true;
            }
            if(CheckingOctal())
            {
                cout<<"This number is looks like in Octal**********\n";
                DecimalConversion(8);
                BinaryConversion();
                HexaConversion();
                cout<<"\n";
                applied= true;
            }
            if(CheckingHexa())
            {
                cout<<"This number is looks like in Hexa*************\n";
                DecimalConversion(16);
                BinaryConversion();
                OctalConversion();
                cout<<"\n";
                applied= true;
            }
            if(!applied && x[0]!='z') cout<<"You entered mismatch input\n\n";
            if(x[0]=='x') system("CLS");
        }
        cout<<"****************************************************************************************\n";
    }
}
