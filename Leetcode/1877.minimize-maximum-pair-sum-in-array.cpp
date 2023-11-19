#include<bits/stdc++.h>
using namespace std;

int minPairSum(vector<int> &nums)
{
    int n = nums.size();

    sort(nums.begin(), nums.end());

    return nums[0] + nums[n-1];
}

int main(){

    return 0;
}