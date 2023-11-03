// We are given an array in which low to mid element is sorted and mid to high are sorted so we need to make the array sorted

//Approach: We create two sorted array and left an right and apply merge of two sorted array

#include<bits/stdc++.h>
using namespace std;

int sortInside(int arr[], int low, int mid, int high){
    int left[mid+1];
    int right[high-mid];

    for(int i=0;i<mid+1;i++){
        left[i]=arr[i];
    }

    for(int i=0; i<high-mid; i++){
        right[i]=arr[high-mid+i+1];
    }

    int m=0;
    int n=0;

    while(m<mid+1 && n<high-mid){
        if(left[m]>=right[n]){
            arr[]
        }
    }
}

int main(){
    int low;
    cout<<"Enter the number of elements: ";
    cin>>low;

    int mid;
    cout<<"Enter the number of elements: ";
    cin>>mid;

    int high;
    cout<<"Enter the number of elements: ";
    cin>>high;
    
    

    int a[high];
    for(int i=0;i<high;i++){
        cin>>a[i];
    }

    return 0;
}