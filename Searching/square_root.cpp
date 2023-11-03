#include<bits/stdc++.h>
using namespace std;

int findRoot(int n){  // The square root will be between 1 to n 
    int high=n;
    int low=1;
    int ans = -1;

    while (low<=high) {
        int mid=(low+high)/2;
        int mSq=mid*mid;
        if(mSq == n){
            return mid;
        }
        else if(mSq>n){
            high=mid-1;
        }
        else{
            low=mid+1;
            ans=mid;
        }
    }
    return ans;
}

int main(){

    int n;
    cout<<"Enter the value of n: ";
    cin>>n;

    cout<<findRoot(n);

    return 0;
}