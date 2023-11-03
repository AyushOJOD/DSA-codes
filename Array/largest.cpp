#include<bits/stdc++.h>
using namespace std;

int largestEle(int arr[], int n){
    

    for(int i=0;i<n;i++){
        bool flag = true;
        for(int j=0;j<n;j++){
            if(arr[j]>arr[i]){
                flag = false;
                break;
            }
        }
        if(flag == true){
            return i;
        }
        else{
            return -1;
        }
    }
}

int main(){

    int a[5] = {5,8,7,9,6};

    cout<<largestEle(a, 5);

    return 0;
}