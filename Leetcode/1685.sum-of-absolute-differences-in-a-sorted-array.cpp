#include <bits/stdc++.h>
using namespace std;

vector<int> getSumAbsoluteDifferences(vector<int> &nums)
{
    vector<int> result;

    int sum = 0;
    int n = nums.size();

    for (auto i : nums)
    {
        sum += i;
    }

    for (int i = 0; i < n; i++)
    {
        result[i] = abs((nums[i] * n) - sum);
    }

    return result
}

int main()
{

    return 0;
}