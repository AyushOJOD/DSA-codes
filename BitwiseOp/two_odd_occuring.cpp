#include<iostream>
using namespace std;

int twoOdd(int arr[],int n){
    for(int i=0;i<n;i++){
        int count=0;
        for(int j=0;j<n;j++){
            if(arr[i] == arr[j]){
                count++;
            }
            if(count%2 != 0){
                cout<<arr[i]<<endl;
            }
        }
    }
}

int main(){
    int n = 8;
    int arr[] = {2,2,8,8,4,4,7,9};

    cout<<twoOdd(arr,n);

    return 0;
}