#include<bits/stdc++.h>
using namespace std;

int maxProfit(int arr[],int n){
    int profit=0;
    for(int i=0;i<n;i++){
        if(arr[i]>arr[i-1]){
            profit=profit+(arr[i]-arr[i-1]);
        }
    }
    return profit;
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    cout<<maxProfit(a,n);

    return 0;
}