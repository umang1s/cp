import java.util.*;
import java.io.*;
public class Sudoku {
    public static void mergeArray(int [] arr,int low,int high){
        int mid=(low+high)/2;
        int temp[]=new int[high-low+1];
        int filled=0,i=low,j=mid+1;
        while(i<=mid && j<=high){
            if(arr[i]>arr[j]) temp[filled++]=arr[j++];
            else temp[filled++]=arr[i++];
        }
        while(i<=mid) temp[filled++]=arr[i++];
        while(j<=high)  temp[filled++]=arr[j++];
        filled=0;
        while(filled<temp.length) arr[filled+low]=temp[filled++];
    }
    public static void mergeSort(int[] arr,int low,int high){
        if(low>=high) return;
        int mid=(low+high)/2;
        mergeSort(arr, low, mid);
        mergeSort(arr, mid+1, high);
        mergeArray(arr, low, high);
    }

    public static void main(String args[]){
        File file=new File("input.txt");
        try{
            Scanner s=new Scanner(file);
            int n=s.nextInt();
            int arr[]=new int[n];
            for(int i=0; i<n; i++) arr[i]=s.nextInt();
            for(int i=0; i<n; i++) System.out.print(arr[i]+" ");
            System.out.println("");
            //mergeSort(arr, 0, n-1);
            System.out.println(arr);
        }catch(Exception e){
            System.out.println("File Exception found");
        }

    }
}