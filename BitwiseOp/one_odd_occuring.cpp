#include<iostream>
using namespace std;

int oddOccuring(int arr[], int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i]==arr[j]){
                count++;
            }
            if(count%2!=0){
        return arr[i];
    }
}
        }
    }
    

int main(){
    int n=9;
    int arr[]={4,5,4,4,4,7,7,5,3};

    cout<<oddOccuring(arr,n);

    return 0;
}