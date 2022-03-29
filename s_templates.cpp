#include"default.h"

// Function

template <typename T>
T findMax(T x,T y){
    return x>y?x:y;
}

template <typename T>
class Array {
private:
    T *ptr;
    int size;
public:
    Array(T arr[], int s);
    void prints();
    void show(){
        for(int i=0; i<size; i++) cout<<" "<<*(ptr+i);
        cout<<nl;
    }
};
 
template <typename T>
Array<T>::Array(T arr[], int s) {
    cout<<"Initialized \n";
    ptr = new T[s];
    size = s;
    for(int i = 0; i < size; i++)
        ptr[i] = arr[i];
}
 
template <typename T>
void Array<T>::prints() {
    for (int i = 0; i < size; i++)
        cout<<" "<<*(ptr + i);
    cout<<endl;
}




int solve(){
    //first calling
    cout<<findMax<int>(5,12)<<nl;
    return 0;

    //
    int arr[5] = {1, 2, 3, 4, 5};
    Array<int> a(arr, 5);
    a.prints();
    //a.show();
}