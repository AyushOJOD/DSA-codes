#include <bits/stdc++.h>
using namespace std;

bool canMake(int mid, vector<int> &bloomDay, int m, int k)
{
    long conscutiveDays = 0, bouquets = 0;

    for (int i = 0; i < bloomDay.size(); i++)
    {
        if (bloomDay[i] <= mid)
        {
            conscutiveDays++;
        }
        else
        {
            conscutiveDays = 0;
        }

        if (conscutiveDays == k)
        {
            bouquets++;
        }
    }

    return (bouquets >= m);
}

int minDays(vector<int> &bloomDay, int m, int k)
{
    int n = bloomDay.size();
    int l = 1, r = *max_element(bloomDay.begin(), bloomDay.end()), ans = -1;

    if (long(m * k) > n)
    {
        return -1;
    }

    while (l <= r)
    {
        int mid = l + ((r - l) / 2);

        if (canMake(mid, bloomDay, m, k))
        {
            ans = mid;
            r = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    return ans;
}

int main()
{

    return 0;
}