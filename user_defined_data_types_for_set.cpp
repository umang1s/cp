// #include<iostream>
// #include<set>
// using namespace std;


// struct Test{
//     int x;
//     bool operator<(const Test &t)const{
//         return (this->x<t.x);
//     }
// };

// int main(){
//     set<Test> s; //set uses red black data structres
//     s.insert({5});
//     s.insert({20});
//     s.insert({10});

//     for(auto t: s) cout<<t.x<<" ";
//     cout<<endl;
// }


// this is shopping cart
#include<iostream>
using namespace std;
class mall
{
    int cart[20],i,j,CartItem[20],TotalCartItem=0,TotalItem=0,Quantity[20];
    float ItemPrice[20],CartPrice=0;
    string ItemName[20];
public:
    void SetItemInMall();
    void ShowItem();
    void AddInCart(int o);
    void ShowCart();
    void DeleteFromCart(int A);
};
void mall::SetItemInMall()
{
    TotalItem=5;
    ItemName[0]="Shoes";    ItemPrice[0]=700.4;
    ItemName[1]="Bag";      ItemPrice[1]=600;
    ItemName[2]="Pen";      ItemPrice[2]=20;
    ItemName[3]="Fan";      ItemPrice[3]=1499;
    ItemName[4]="Mobile";   ItemPrice[4]=18599;
    ItemName[5]="Laptop";   ItemPrice[5]=82949;
    ItemName[6]="Pan";      ItemPrice[6]=699.30;
    ItemName[7]="Charger";  ItemPrice[7]=140.2;
    ItemName[8]="T-Shirt";  ItemPrice[8]=799;
}
void mall::AddInCart(int o)
{
    int The=50;
    for(int i=0; i<TotalCartItem; i++)  if(cart[i]==o) The=i;
    if(The!=50) Quantity[The]++;
    else
    {
        cart[TotalCartItem]=o;
        Quantity[TotalCartItem]=1;
        TotalCartItem++;
    }
    CartPrice += ItemPrice[o];
    cout<<"========================="<<ItemName[o]<<" Added in cart \ttotal price of cart : "<<CartPrice<<"========================="<<endl<<endl;
    ShowItem();
}
void mall::DeleteFromCart(int A)
{
    int c=cart[A],p;
    if(Quantity[A]>1) Quantity[A]--;
    else
    {
        for(p=A; p<TotalCartItem; p++) cart[p]=cart[p+1];
        TotalCartItem--;
    }
    CartPrice -= ItemPrice[c];
    cout<<"========================="<<ItemName[c]<<" Deleted from cart \ttotal price of cart : "<<CartPrice<<"========================="<<endl<<endl;
    ShowCart();
}
void mall::ShowItem()
{
    int G;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl<<"* *              SHOPPING      MALL                   * *"<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n*\tS.N\t\tItem\t\tPrice\t\t*"<<endl;
    if(TotalItem==0){cout<<"No Item in mall\t\t\t\t**"<<endl; return ;}
    for(int k=0; k<TotalItem; k++)
    {
        cout<<"*\t"<<k+1<<"\t\t"<<ItemName[k]<<"\t\t"<<ItemPrice[k]<<"\t\t*"<<endl;
    }
    cout<<"*\t0.\t\tShow Cart\t\t\t*\n*      -1\t\tEXIT\t\t\t\t*\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<"  Select S.N to add item in Cart : ";
    cin>>G;
    if(G>0 && G<=TotalItem) AddInCart(G-1);
    else if(G==0) ShowCart();
    else if(G==-1) return ;
    else {cout<<"you enterd wrong input "<<endl; ShowItem();}
}
void mall::ShowCart()
{
    int B,C;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<endl;
    cout<<"* * *                     SHOPPING       CART                       * * *"<<endl;
    cout<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *\n"<<"*\tS.N\t\tItem\t\tPrice\t\tQuantity\t*"<<endl;
    if(TotalCartItem==0){cout<<"No Item in Cart !"<<endl; ShowItem();}
    for(int k=0; k<TotalCartItem; k++)
    {
        B=cart[k];
        cout<<"*\t"<<k+1<<"\t\t"<<ItemName[B]<<"\t\t"<<ItemPrice[B]<<"\t\t"<<Quantity[k]<<"\t\t*"<<endl;
    }
    cout<<"*\t\t\tTotal price\t"<<CartPrice<<"\t\t\t\t*"<<endl;
    cout<<"*\t0.\t\tShow Mall\t\t\t\t\t*"<<endl<<"* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *"<<" enter option to delete  item : ";
    cin>>C;
    if(C==0) ShowItem() ;
    else if(C>0 && C<=TotalCartItem) DeleteFromCart(C-1);
    else {cout<<"wrong input"<<endl; ShowCart();}
}
int main()
{
    int i=5;
    mall Mall;
    Mall.SetItemInMall();
    Mall.ShowItem();
}