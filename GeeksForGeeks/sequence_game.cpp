#include<bits/stdc++.h>
using namespace std;

bool solution(vector<int>& nums, int indexDiff, int valueDiff, int i = 0, int j = 1) {
    if (i >= nums.size() || j >= nums.size()) {
        return false; 
    }

    if (i != j && abs(nums[i] - nums[j]) == valueDiff && abs(i - j) == indexDiff) {
        return true; 
    }

    // Recursive calls
    bool found = solution(nums, indexDiff, valueDiff, i, j + 1);
    if (!found && j < i + indexDiff) {
        
        found = solution(nums, indexDiff, valueDiff, i, j);
    }

    return found;
}


int main(){

    vector<int> nums;
    
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    nums.push_back(1);

    int indexDiff = 3;
    int valueDiff = 0;



    return 0;
}