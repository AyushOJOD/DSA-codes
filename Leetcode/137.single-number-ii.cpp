#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int singleNumber(vector<int> &nums)
    {
        int finalNumber = 0;

        for (int bitIdx = 0; bitIdx < 32; bitIdx++)
        {
            int setBits = 0;

            for (int i = 0; i < nums.size(); i++)
            {
                if ((nums[i]) & (1 << bitIdx))
                {
                    setBits++;
                }
            }
            if (setBits % 3 == 1)
            {
                finalNumber = finalNumber | (1 << bitIdx);
            }
        }

        return finalNumber;
    }
};

int main()
{

    return 0;
}