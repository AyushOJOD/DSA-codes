#include<bits/stdc++.h>
using namespace std;

int partition(int arr[], int l, int h){
    int i=l-1;
    int j=h+1;
    int pivot = arr[l];

    while(true){
        do
        {
            i++;
        } while (arr[i]<pivot);
        do
        {
            j--;
        } while (arr[j]>pivot);

        if(i>=j){
            return j; //returning the index of last element smaller than or equal to pivot.
        }
        swap(arr[i], arr[j]);
        
        
    }
}

int main(){
    int n;
    cout<<"Enter the number of elements: ";
    cin>>n;

    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }

    return 0;
}