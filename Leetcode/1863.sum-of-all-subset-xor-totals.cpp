#include <bits/stdc++.h>
using namespace std;

int dfs(vector<int> &nums, int index, int total)
{
    if (index == nums.size())
    {
        return total;
    }

    int pick = dfs(nums, index + 1, total ^ nums[index]);
    int notPick = dfs(nums, index + 1, total);

    return pick + notPick;
}

int subsetXORSum(vector<int> &nums)
{
    return dfs(nums, 0, 0); // {vector, index, total}
}

int main()
{

    return 0;
}