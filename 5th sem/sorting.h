
#include<iostream>
#include<cmath>
using namespace std;
int lengthOfArray(int data[]){
    return sizeof(data) / sizeof(data[0]);
}
int getMax(int arr[], int n){
    int mx = arr[0];
    for (int i = 1; i < n; i++) if (arr[i] > mx)    mx = arr[i];
    return mx;
}
void swapping(int *first,int *second){
    int temp=*first;
    *first=*second;
    *second=temp;
}
void quickSort(int data[],int low,int high){
    if(low<high){
        ///getting random pivot element
        int pivot,n=rand(),temp=low;
        pivot=low+ n%(high-low+1);

        /// now changing pivot to high position
        swapping(&data[high],&data[pivot]);

        pivot=high;
        /// creating partition
        for(int i=low; i<high; i++){
            if(data[i]<data[pivot]) swapping(&data[i],&data[temp++]);
            else continue;
        }
        swapping(&data[temp],&data[high]);

        quickSort(data, low, temp-1);
        quickSort(data, temp+1, high);
    }
}
void selectionSort(int data[],int length){
    for(int i=0; i<length-1; i++)
    {
        for(int j=i+1; j<length; j++)
        {
            //if()
        }
    }
}
void countSort(int arr[], int n, int exp){
    int output[n];
    int i, count[10] = { 0 };
    for (i = 0; i < n; i++)
        count[(arr[i] / exp) % 10]++;
    for (i = 1; i < 10; i++)
        count[i] += count[i - 1];
    for (i = n - 1; i >= 0; i--) {
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (i = 0; i < n; i++)
        arr[i] = output[i];
}
void radixsort(int arr[], int n){
    int m = getMax(arr, n);
    for (int exp = 1; m / exp > 0; exp *= 10)
        countSort(arr, n, exp);
}
