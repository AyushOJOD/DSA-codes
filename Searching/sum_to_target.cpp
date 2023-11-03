#include<bits/stdc++.h>
using namespace std;

bool sumtoTarget(int arr[], int n, int k){
    int i = 0;
    int j = n-1;

    while(i<j){
        if(arr[i]+arr[j] == k){
        return true;
    }
    else if(arr[i]+arr[j]>k){
        j=-1;
    }
    else{
        i-=1;
    }
    }x
    
    return false;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    int k;
    cout<<"Enter the target element";
    cin>>k;

    cout<<sumtoTarget(a,n,k);

    return 0;
}