#include <bits/stdc++.h>
using namespace std;

bool isArraySpecial1(vector<int> &nums, int start, int end)
{
    for (int i = start; i < end - 1; ++i)
    {
        if ((nums[i] % 2) == (nums[i + 1] % 2))
        {
            return false;
        }
    }
    return true;
}

vector<bool> isArraySpecial(vector<int> &nums, vector<vector<int>> &queries)
{
    int n = nums.size();
    if (n == 1)
    {
        vector<bool> result(queries.size(), true);
        return result;
    }

    vector<int> sameParityPrefixSum(n, 0);
    for (int i = 1; i < n; i++)
    {
        sameParityPrefixSum[i] = sameParityPrefixSum[i - 1] + ((nums[i] % 2) == (nums[i - 1] % 2) ? 1 : 0);
    }

    vector<bool> result(queries.size());
    for (int q = 0; q < queries.size(); q++)
    {
        int from = queries[q][0];
        int to = queries[q][1];
        int sameParityCount = sameParityPrefixSum[to] - sameParityPrefixSum[from];
        result[q] = (sameParityCount == 0);
    }

    return result;
}

int main()
{

    return 0;
}