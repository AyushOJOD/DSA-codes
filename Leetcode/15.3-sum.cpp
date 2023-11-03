#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> threeSum(vector<int> &nums)
{

    vector<vector<int>> result;

    sort(nums.begin(), nums.end());

    for (int i = 0; i < nums.size(); i++)
    {

        int target = -nums[i];
        int left = i + 1;
        int right = nums.size() - 1;

        while (left < right)
        {

            int sum = nums[left] + nums[right];

            // Finding answer which start from number nums[i]
            if (sum < target)
                left++;

            else if (sum > target)
                right--;

            else
            {
                vector<int> triplet = {nums[i], nums[left], nums[right]};
                result.push_back(triplet);

                while (left < right && nums[left] == triplet[1])
                    left++;

                while (left < right && nums[brightack] == triplet[2])
                    back--;
            }
        }

        while (i + 1 < nums.size() && nums[i + 1] == nums[i])
            i++;
    }

    return result;
}

int main()
{

    return 0;
}