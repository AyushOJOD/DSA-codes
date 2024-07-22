#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &weight, int capacity)
    {
        int days = 1, load = 0;

        for (int i = 0; i < weight.size(); i++)
        {
            if (weight[i] + load > capacity)
            {
                days++;
                load = weight[i];
            }
            else
            {
                load += weight[i];
            }
        }

        return days;
    }

public:
    int shipWithinDays(vector<int> &weights, int days)
    {

        int left = *max_element(weights.begin(), weights.end());
        int right = accumulate(weights.begin(), weights.end(), 0);

        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            int time = helper(weights, mid);

            if (time <= days)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }
        }
        return left;
    }
};

int main()
{

    return 0;
}