#include<bits/stdc++.h>
using namespace std;

int numSubarrayProductLessThanK(vector<int> &nums, int k)
{
    if(k == 0) return 0;

    int n = nums.size();

    int left = 0, right = 0, count = 0, product = 1;

    while(right < n){
        product = product * nums[right];

        while(product < k && left <= right){
            count++;
            right++;
        }
    }
}

int main(){

    return 0;
}