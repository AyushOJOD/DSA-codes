#include<bits/stdc++.h>
using namespace std;

int removeDuplicates(int arr[], int n){
    int temp[n];
    temp[0]=arr[0];
    int size=1;

    for(int i=1;i<n;i++){
        if(temp[size-1] != arr[i]){
            temp[size] = arr[i];
            size++;
        }
    }

    for(int i=0;i<n;i++){
        arr[i]=temp[i];
    }

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
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

    cout<<removeDuplicates(a,n);

    return 0;
}