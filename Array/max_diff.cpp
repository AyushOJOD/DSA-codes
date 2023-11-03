#include<bits/stdc++.h>
using namespace std;

int maxDiff(int arr[], int n){
    int minVal=arr[0];
    int res = arr[1]-arr[0];
    for(int j=1;j<n;j++){
        res=max(res, arr[j]-minVal);
        minVal=min(minVal,arr[j]);
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

    cout<<maxDiff(a,n);

    return 0;
}