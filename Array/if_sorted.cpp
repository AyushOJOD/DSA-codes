#include<bits/stdc++.h>
using namespace std;

bool isSorted(int arr[], int n){

    bool res=true;
    for (int i = 0;i <n ; i++){
        if(arr[i]>arr[i+1]){
            res=false;
        }
    }
    return res;
}

int main(){

    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];

    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<isSorted(a,n);

    return 0;
}