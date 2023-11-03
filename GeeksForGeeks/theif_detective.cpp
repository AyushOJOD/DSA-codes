#include<bits/stdc++.h>
using namespace std;


    bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
        if (nums.size() < 2 || k == 0)
            return false;
        deque<int> solDeq;
        multiset<long> windows;
        for (int i = 0; i < nums.size(); i++) {
            if (windows.size() > k) {
                int num = solDeq.front();
                solDeq.pop_front();
                windows.erase(windows.find(num));
            }
            auto it = windows.lower_bound((long)nums[i] - (long)t);
            if (it == windows.end() || *it > (long)nums[i] + (long)t) {
                // not found
                windows_deq.push_back(nums[i]);
                windows.insert(nums[i]);
            }
            else return true;
        }
        return false;
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