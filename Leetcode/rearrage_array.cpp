#include <bits/stdc++.h>
using namespace std;

vector<int> rearrangeArray(vector<int> &nums)
{
    vector<int> pos;
    vector<int> neg;

    for (auto num : nums)
    {
        if (num > 0)
        {
            pos.push_back(num);
        }
        else
        {
            neg.push_back(num);
        }
    }

    vector<int> res;

    for (int i = 0; i < pos.size(); i++)
    {
        res.push_back(pos[i]);
        res.push_back(neg[i]);
    }

    return res;
}

int main()
{

    return 0;
}