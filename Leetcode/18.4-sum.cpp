#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> fourSum(vector<int> &nums, int target)
{
    vector<vector<int>> result;
    sort(nums.begin(), nums.end());
    
    for(int i=0; i<nums.size(); i++){
        
        int counter = target - nums[i] - nums[i+1];
        int left = nums[i+2];
        int right = nums[nums.size() - 1];

        while (left<right)
        {
            if()
        }
         
    }

}

int main(){

    return 0;
}