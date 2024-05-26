class Solution
{
public:
    int maximumSumSubsequence(vector<int> &num, vector<vector<int>> &q)
    {

        int ans = 0;
        int MOD = 1e9 + 7;

        int prev = max(0, num[0]);
        int prev2 = max(prev, num[1]);

        for (int i = 2; i < num.size(); ++i)
        {

            int curr = max(prev, prev2 + num[i]);
            curr %= MOD;

            prev2 = prev;
            prev = curr;
        }

        return prev % MOD;
    }
};