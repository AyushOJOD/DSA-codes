#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    bool comp(int a, int b)
    {
        return to_string(a) + to_string(b) > to_string(b) + to_string(a);
    }

public:
    string largestNumber(vector<int> &nums)
    {
        sort(nums.begin(), nums.end(), comp);

        string res = "";

        for (int it : nums)
        {
            res += to_string(it);
        }

        return res;
    }
};

int main()
{

    return 0;
}