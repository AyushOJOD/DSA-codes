#include<bits/stdc++.h>
using namespace std;

int leftRotate(int arr[], int n){
    for(int i=1;i<n;i++){
        swap(arr[i],arr[i-1]);
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

    leftRotate(a,n);

    cout<<"After Rotation: ";
    for(int i=0;i<n;i++){
        cout<<a[i]<<" ";
    }
    return 0;
}