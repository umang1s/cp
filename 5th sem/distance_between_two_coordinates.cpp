// C++ program to calculate Distance
// Between Two Points on Earth
#include <bits/stdc++.h>
#define M_PI 3.14159

using namespace std;
// Utility function for
// converting degrees to radians
long double toRadians(const long double degree)
{
    long double one_deg = (M_PI) / 180;
    return (one_deg * degree);
}

long double distance(long double lat1, long double long1,long double lat2, long double long2)
{
    lat1 = toRadians(lat1);
    long1 = toRadians(long1);
    lat2 = toRadians(lat2);
    long2 = toRadians(long2);
    long double dlong = long2 - long1;
    long double dlat = lat2 - lat1;
    long double ans = pow(sin(dlat / 2), 2) + cos(lat1) * cos(lat2) *pow(sin(dlong / 2), 2);
    ans = 2 * asin(sqrt(ans));
    long double R = 6371;
    ans = ans * R;
    return ans;
}

int main()
{
    long double lat1 = 53.32055555555556;
    long double long1 = -1.7297222222222221;
    long double lat2 = 53.31861111111111;
    long double long2 = -1.6997222222222223;
    while(1){
        cout<<"enter first lattitude  and longitude ";
    cin>>lat1>>long1;
    cout<<"enter second lattitude and longitude ";
    cin>>lat2>>long2;

    // call the distance function
    cout << setprecision(15) << fixed;
    double jj=distance(lat1, long1,lat2, long2);
    cout<<jj*1000<<" K.M"<<endl;
    cout<<jj*1094<<" Yard "<<endl;
    }



    return 0;
}

