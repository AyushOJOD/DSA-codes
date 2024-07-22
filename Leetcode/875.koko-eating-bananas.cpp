#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &piles, int speed)
    {
        int time = 0;

        for (int i = 0; i < piles.size(); i++)
        {
            time += (piles[i] + speed - 1) / speed;
        }

        return time;
    }

public:
    int minEatingSpeed(vector<int> &piles, int h)
    {
        int left = 1, right = *max_element(piles.begin(), piles.end());

        while (left < right)
        {
            int mid = left + (right - left) / 2;
            int time = helper(piles, mid);

            if (time <= h)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
            }

            return left;
        }
    }
};

int main()
{

    return 0;
}