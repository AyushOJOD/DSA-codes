#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    void helper(int idx, int n, vector<int> &res)
    {
        if (idx > n)
        {
            return;
        }

        res.push_back(idx);

        for (int i = 0; i <= 9; i++)
        {
            int newNum = (idx * 10) + i;

            if (newNum > n)
            {
                return;
            }
            helper(newNum, n, res);
        }
    }

public:
    vector<int> lexicalOrder(int n)
    {
        vector<int> res;

        for (int idx = 1; idx <= 9; idx++)
        {
            helper(idx, n, res);
        }

        return res;
    }
};

int main()
{

    return 0;
}