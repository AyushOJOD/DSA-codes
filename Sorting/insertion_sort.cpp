#include<bits/stdc++.h>
using namespace std;

void insertionSrt(int arr[], int n){
    for(int i=1;i<n;i++){
        int key=arr[i];
        int j=i-1; 
        while (j>=0 && ar[j]>key)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
        
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    return 0;
}