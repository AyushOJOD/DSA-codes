#include <bits/stdc++.h>
using namespace std;

class Solution
{

private:
    void helper(vector<string> &res, string curr, int n)
    {
        // base
        if (curr.length() == n)
        {
            res.push_back(curr);
            return;
        }

        helper(res, curr + '1', n);

        if (curr.empty() || curr.back() != '0')
        {
            helper(res, curr + '0', n);
        }
    }

public:
    vector<string> validStrings(int n)
    {
        string curr = "";
        vector<string> res;

        helper(res, curr, n);

        return res;
    }
};

int main()
{

    return 0;
}