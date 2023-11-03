#include<bits/stdc++.h>
using namespace std;

int bubbleSrt(int arr[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(arr[j]>arr[j+1]){
                swap(arr[j+1],arr[j]);
            }
        }
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

    bubbleSrt(a,n);

    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }

    return 0;
}