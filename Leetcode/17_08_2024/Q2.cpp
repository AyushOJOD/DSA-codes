#include <bits/stdc++.h>
using namespace std;

#include <vector>
using namespace std;

class Solution
{
public:
    vector<int> resultsArray(vector<int> &nums, int k)
    {
        vector<int> result;
        int length = nums.size();

        bool isTrue = true;

        for (int i = 1; i < k; ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                isTrue = false;
            }
        }

        result.push_back(isTrue ? nums[k - 1] : -1);

        for (int i = k; i < length; ++i)
        {
            if (nums[i] != nums[i - 1] + 1)
            {
                isTrue = false;
            }

            if (nums[i - k + 1] != nums[i - k] + 1)
            {
                isTrue = true;
                for (int j = i - k + 2; j <= i; ++j)
                {
                    if (nums[j] != nums[j - 1] + 1)
                    {
                        isTrue = false;
                        break;
                    }
                }
            }

            result.push_back(isTrue ? nums[i] : -1);
        }

        return result;
    }
};

int main()
{

    return 0;
}