#include<bits/stdc++.h>
using namespace std;

int freqSorted(int arr[], int n){
    int freq=1;
    int i=1;

    while(i<n){
        while(i<n && arr[i]==arr[i-1]){
        freq++;
        i++;
    }
    cout<<arr[i-1]<<" "<<freq<<endl;
    freq=1;
    i++;
    }

    if(n==1 || arr[n-1] != arr[n-2]){
        cout<<arr[0]<<" "<<"1"<<endl;
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

    freqSorted(a,n);

    return 0;
}