#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> subsets(vector<int> &nums)
{
    set<vector<int>> sub;

    vector<int> temp = {};

    sub.insert(temp);

    for (int i = 0; i < nums.size(); i++)
    {
        vector<int> temp1 = temp.push_back(nums[i] + 1);
        vector<int> temp2 = temp;
    }
}

int main()
{

    return 0;
}