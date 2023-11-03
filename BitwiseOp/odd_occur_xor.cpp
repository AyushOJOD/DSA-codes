#include<iostream>
using namespace std;

int oneOdd(int arr[], int n){
    int res=arr[0];
    for(int i=1;i<n;i++){
        res=res^arr[i];
    }
    return res;
}

int main(){
    int n=7;
    int arr[]={1,1,1,1,1,1,2};

    cout<<oneOdd(arr,n);

    return 0;
}