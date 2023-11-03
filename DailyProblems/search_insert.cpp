#include<bits/stdc++.h>
using namespace std;

int searchInsert(vector<int>& nums, int target, int high, int low) {
        int size = nums.size();
        int low = 0;
        int high = size-1;

        int mid=(high+low)/2;

        if(low>high){
            cout<<mid<<endl;
        }


        if(nums[mid]>target){
            return searchInsert(nums, target, mid-1, low);
        }
        else if(nums[mid]<target){
            return searchInsert(nums, target, high, mid+1);
        }
        else{
            cout<<mid<<endl;
        }
    }

int main(){

    return 0;
}