#include<bits/stdc++.h>
using namespace std;
int binarySearchString(string arr[], string x, int n) {
   int lower = 0;
   int upper = n - 1;
   while (lower <= upper) {
      int mid = lower + (upper - lower) / 2;
      int res;
      if (x == (arr[mid]))
         res = 0;
      if (res == 0)
         return mid;
      if (x > (arr[mid]))
         lower = mid + 1;
      else
         upper = mid - 1;
   }
   return -1;
}
int main () {
   string arr[] = {"I", "Love", "Programming" , "tutorials" , "point","lox","umang"};
   string x = "point";
   int n = 7;
   int result = binarySearchString(arr, x, n);
   if(result == -1)
      cout<<("Element not present\n");
   else
      cout<<("Element found at index ")<<result<<endl;

    string zz="umang";
    string yy="umanj";
    cout<<(zz>yy);
}
