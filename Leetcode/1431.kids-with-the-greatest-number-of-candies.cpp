#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    vector<bool> kidsWithCandies(vector<int> &candies, int extraCandies)
    {
        int n = candies.size();
        int currMax = INT_MIN;

        for (int i = 0; i < n; i++)
        {
            if (candies[i] > currMax)
            {
                currMax = candies[i];
            }
        }

        vector<bool> res(n, false);

        for (int i = 0; i < n; i++)
        {
            if (candies[i] + extraCandies >= currMax)
            {
                res[i] = true;
            }
        }

        return res;
    }
};

int main()
{

    return 0;
}