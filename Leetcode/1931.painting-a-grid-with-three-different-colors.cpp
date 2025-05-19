#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    const int MOD = 1e9 + 7;
    vector<vector<int>> dp;

    void generateStates(string curr, char prev, int currLen, int m, vector<string> &columnStates)
    {
        if (currLen == m)
        {
            columnStates.push_back(curr);
        }

        for (char ch : {'R', 'G', 'B'})
        {
            if (ch == prev)
                continue;

            generateStates(curr + ch, ch, currLen + 1, m, columnStates);
        }
    }

    int solve(int remainingCols, int prevIdx, int m, vector<string> &columnStates, vector<vector<int>> &dp)
    {
        if (remainingCols == 0)
        {
            return 1;
        }

        if (dp[remainingCols][prevIdx] != -1)
        {
            return dp[remainingCols][prevIdx];
        }

        int ways = 0;
        string prevState = columnStates[prevIdx];

        for (int i = 0; i < columnStates.size(); i++)
        {
            if (i == prevIdx)
            {
                continue;
            }

            string currState = columnStates[i];
            bool valid = true;

            for (int j = 0; j < currState.length(); j++)
            {

                if (prevState[j] == currState[j])
                {
                    valid = false;
                    break;
                }
            }

            if (valid)
            {
                ways = (ways + solve(remainingCols - 1, i, m, columnStates, dp)) % MOD;
            }
        }

        return dp[remainingCols][prevIdx] = ways;
    }

    int colorTheGrid(int m, int n)
    {
        string currState = "";
        vector<string> columnStates;
        generateStates(currState, '#', 0, m, columnStates);

        int states = columnStates.size();

        dp = vector<vector<int>>(n, vector<int>(states, -1));

        int result = 0;
        for (int i = 0; i < columnStates.size(); i++)
        {
            result = (result + solve(n - 1, i, m, columnStates, dp)) % MOD;
        }

        return result;
    }
};

int main()
{

    return 0;
}