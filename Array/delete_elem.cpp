#include<bits/stdc++.h>
using namespace std;

int deleteEle(int arr[], int n,int x){
    for(int i=0;i<n;i++){
        if(arr[i] == x){
            break;
        }
    if(i==n){
        return n;
    }
    for(j=i;j<n;j++){
        j[i+1]=j[i];
    }
    }
}

int main(){

    return 0;
}