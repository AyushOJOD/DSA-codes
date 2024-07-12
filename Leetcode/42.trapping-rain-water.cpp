#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> getLeftMax(vector<int> &height, int n)
    {
        int maxUntill = -1;

        for (int i = 0; i < n; i++)
        {
            if (maxUntill != -1)
            {
                maxUntill = max(maxUntill, height[i]);
                height[i] = maxUntill;
            }
        }

        return height;
    }

    vector<int> getRightMax(vector<int> &height, int n)
    {
        int maxUntill = -1;

        for (int i = n - 1; i >= 0; i++)
        {
            if (maxUntill != -1)
            {
                maxUntill = max(maxUntill, height[i]);
                height[i] = maxUntill;
            }
        }

        return height;
    }

public:
    int trap(vector<int> &height)
    {
        int n = height.size();

        vector<int> leftMax = getLeftMax(height, n);
        vector<int> rightMax = getRightMax(height, n);

        int water_collected = 0;

        for (int i = 0; i < n; i++)
        {
            int water = min(leftMax[i], rightMax[i]) - height[i];

            water_collected += water;
        }

        return water_collected;
    }
};

int main()
{

    return 0;
}