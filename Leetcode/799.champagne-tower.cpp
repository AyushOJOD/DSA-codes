#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    double champagneTower(int poured, int query_row, int query_glass)
    {
        vector<vector<double>> dp(101, vector<double>(101, 0.0));

        dp[0][0] = poured;

        for (int row = 0; row <= query_row; row++)
        {
            for (int col = 0; col <= row; col++)
            {
                if (dp[row][col] > 1)
                {
                    double excess = dp[row][col] - 1.0;
                    dp[row][col] = 1.0;
                    dp[row + 1][col] += excess / 2.0;
                    dp[row + 1][col + 1] += excess / 2.0;
                }
            }
        }

        return dp[query_row][query_glass];
    }
};

int main()
{

    return 0;
}