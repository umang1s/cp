#include"default.h"


void transposeMatrix(int arr[5][5]){
    for(int i=1; i<5; i++) for(int j=0; j<i; j++) swap(arr[i][j],arr[j][i]);
}


void printMatrix(int arr[5][5]){
    for(int i=0; i<5; i++) { for(int j=0; j<5; j++) cout<<arr[i][j]<<spc; cout<<nl;}
    cout<<nl<<nl;
}

void reverseMatrix(int arr[5][5]){
    int low=0; 
    int high=4;
    while(low<high){
        for(int i=0; i<5; i++) swap(arr[high][i],arr[low][i]);
        low++;
        high--;
    }
}

void rotate90(int arr[5][5]){
    transposeMatrix(arr);
    reverseMatrix(arr);
}

void printSpiral(int arr[5][5]){
    int total=0;
    int inside=0;

    while(total<25){
        for(int i=left; i<=right; i++) cout<<arr[top][i]<<spc;
        for(int i=top+1; i<=bottom; i++) cout<<arr[i][right]<<spc;
        for(int i=right-1; i>=left; i--) cout<<arr[bottom][i]<<spc;
        for(int i=bottom-1; i>top; i--) cout<<arr[i][left]<<spc;
    }

    while(left<right && top<bottom){
        for(int i=left; i<=right; i++) cout<<arr[top][i]<<spc;
        for(int i=top+1; i<=bottom; i++) cout<<arr[i][right]<<spc;
        for(int i=right-1; i>=left; i--) cout<<arr[bottom][i]<<spc;
        for(int i=bottom-1; i>top; i--) cout<<arr[i][left]<<spc;
        left++;
        right--;
        top++;
        bottom--;
    }
    cout<<nl;

    cout<<left<<spc<<right<<spc<<top<<spc<<bottom<<nl;

    // if(top<bottom){
    //     for(int i=top+1; i<=bottom; i++) cout<<arr[i][right]<<spc;
    //     top++;
    //     bottom--;
    // }

    // if(left<right){
    //     for(int i=left; i<=right; i++) cout<<arr[top][i]<<spc;
    //     left++;
    //     right--;
    // }
}

int solve(){
    int mat[5][5];

    int t=1;
    for(int i=0; i<5; i++) for(int j=0; j<5; j++) mat[i][j]=t++;

    printMatrix(mat);
    transposeMatrix(mat);
    printMatrix(mat);
    rotate90(mat);
    printMatrix(mat);
    printSpiral(mat);

    return 0;
}