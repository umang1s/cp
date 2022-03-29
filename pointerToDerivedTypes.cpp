#include<iostream>
using namespace std;
class base
{
    int i;
public:
    void SetI(int num)  {i=num;}
    int GetI(){return i;}
};
class deriv: public base   // can't do this private and by default it private
{
    int j;
public:
    void SetJ(int num){j=num;}
    int GetJ(){return j;}
};
int main()
{
    base *bp;
    deriv d;
    bp = &d;        // base pointer to deriv object
    bp->SetI(10);
    cout<<bp->GetI()<<" ";
 //    bp->SetJ(88); // error you can't access elements of a deriv class using a base class pointer
   //  cout<<bp->getJ();  // error
   //for accessing we can use this
   ((deriv *)bp)->SetJ(88);
   cout<<((deriv *)bp)->GetJ()<<endl;
   cout<<"other examples "<<endl;
   deriv lg[3];
   base *dp;
   dp = lg;
   lg[0].SetI(10);
   lg[1].SetI(12);
   lg[2].SetI(15);
   cout<<dp->GetI()<<endl;
   dp++;    //relative to base , not derived
   cout<<dp->GetI()<<endl;  // it shows garbage value

    return 0;

}
