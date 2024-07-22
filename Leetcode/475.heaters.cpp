#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool canCover(vector<int> &houses, vector<int> &heater, int radius)
    {
        sort(heater.begin(), heater.end());

        int n = houses.size();
        int m = heater.size();

        int i = 0, j = 0;

        while (i < n)
        {
            if (j < m && abs(houses[i] - heater[j]) <= radius)
            {
                i++;
            }
            else if (j + 1 < m && heater[j + 1] - houses[i] <= radius)
            {
                j++;
            }
            else
            {
                return false;
            }
        }

        return true;
    }

public:
    int findRadius(vector<int> &houses, vector<int> &heaters)
    {
        sort(houses.begin(), houses.end());

        int left = 0, right = houses[houses.size() - 1] - houses[0];

        while (left <= right)
        {
            int mid = left + (right - left) / 2;

            if (canCover(houses, heaters, mid))
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