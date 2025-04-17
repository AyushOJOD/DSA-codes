#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool check(vector<int> &piles, int hours, int mid)
    {
        int ans = 0;
        for (int i = 0; i < piles.size(); i++)
        {
            ans += (piles[i] / mid);
            if (piles[i] / mid != 0)
            {
                ans++;
            }
        }
        return ans <= hours;
    }

    int minEatingSpeed(vector<int> &piles, int h)
    {
        int n = piles.size();
        sort(piles.size(), piles.size());

        int low = 1, high = piles[n - 1];

        while (low < high)
        {
            int mid = left + (right - left) / 2;
            if (check(piles, h, mid))
            {
                high = mid;
            }
            else
            {
                low = mid + 1;
            }
        }

        return low;
    }
};

int main()
{

    return 0;
}