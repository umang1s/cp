//      bank account 08feb  assignment0401
#include<iostream>
using namespace std;
class BankAccount
{
    float AccountBalance;
    string AccountHolderName;
    int AccountNumber,AccountType;
public:
    void SetAccount(int AcN) ;
    //static Bank();
    void CreditInAccount(float Amount) {AccountBalance+=Amount;}
    float DebitFromAccount();
    void DisplayAccount()
    {
        cout<<AccountNumber<<"\t\t"<<AccountHolderName<<"\t\t"<<AccountBalance<<"\t\t";
        if(AccountType==1) cout<<"Saving"<<endl;
        else cout<<"Current"<<endl;
    }
};
float BankAccount::DebitFromAccount()
{
    int k=7;
    float Amount;
    while(k=7)
    {
        cout<<"Your Balance is : "<<AccountBalance<<"\tenter Amount to withdraw : ";
        cin>>Amount;
        if(Amount<=AccountBalance)
        {
            AccountBalance-=Amount; return Amount;
        }
        else cout<<"you enter invalid amount "<<endl;
    }
}
void BankAccount::SetAccount(int AcN)
{
    cout<<"enter name : ";  getline(cin,AccountHolderName);
    cout<<"enter account type 1. for saving 0.current : ";  cin>>AccountType;
    cout<<"Set amount in account : "; cin>>AccountBalance;
    cout<<" Your a/c number is : "<<1000+AcN<<endl;
    AccountNumber=1000+AcN;
}
int main()
{
    int Customer,j=9,AccountNumber,d;
    float Amount;
    BankAccount AccountHolder[10];
    cout<<"How many account to Add : ";
    cin>>Customer;
    for(int i=0; i<Customer; i++) AccountHolder[i].SetAccount(i);
    cout<<"You created "<<Customer<<"  account successfully"<<endl<<endl;
    while(j!=0)
    {
        cout<<"CHOOSE AN OPTION\t1\tCredit Money in Account\n\t\t\t2\tDebit Money from Account\n\t\t\t3\tDisplay all Account\n\t\t\t0\tEXIT"<<endl;
        cin>>j;
        if(j==0) return 0;
        else
        {
            if(j==1 || j==2)
            {
                d=6;
                while(d!=0){
                cout<<" enter account number : ";
                cin>>AccountNumber;
                if(AccountNumber>999 && AccountNumber<1000+Customer) d=0;
                else cout<<"You enterd Invalid A/c no.";
                }
                if(j==1)    { cout<<"enter amount to add : ";  cin>>Amount; AccountHolder[AccountNumber-1000].CreditInAccount(Amount);}
                else    cout<<"Rs. "<<AccountHolder[AccountNumber-1000].DebitFromAccount()<<" debited"<<endl;
            }
            else if(j==3)
            {
                cout<<"S.N\tA/c No.\t\tA/c. Name\t\tA/c Balance\tA/c Type"<<endl;
                for(int k=0; k<Customer; k++) {cout<<k+1<<"\t"; AccountHolder[k].DisplayAccount();}
            }
            else continue;
            cout<<endl;
        }
    }
}
