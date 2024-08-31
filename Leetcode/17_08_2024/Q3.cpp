#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long maximumValueSum(vector<vector<int>> &board)
    {
        int m = board.size();
        int n = board[0].size();
        long maxSum = LLONG_MIN;

        for (int i = 0; i < m; ++i)
        {
            for (int j = 0; j < n; ++j)
            {
                long currentSum = board[i][j];
                vector<bool> rowUsed(m, false);
                vector<bool> colUsed(n, false);
                rowUsed[i] = true;
                colUsed[j] = true;

                long secondMax = LLONG_MIN;
                int secondRow = -1, secondCol = -1;

                for (int r = 0; r < m; ++r)
                {
                    if (rowUsed[r])
                        continue;
                    for (int c = 0; c < n; ++c)
                    {
                        if (colUsed[c])
                            continue;
                        if (board[r][c] > secondMax)
                        {
                            secondMax = board[r][c];
                            secondRow = r;
                            secondCol = c;
                        }
                    }
                }

                if (secondMax != LLONG_MIN)
                {
                    currentSum += secondMax;
                    rowUsed[secondRow] = true;
                    colUsed[secondCol] = true;

                    long thirdMax = LLONG_MIN;

                    for (int r = 0; r < m; ++r)
                    {
                        if (rowUsed[r])
                            continue;
                        for (int c = 0; c < n; ++c)
                        {
                            if (colUsed[c])
                                continue;
                            if (board[r][c] > thirdMax)
                            {
                                thirdMax = board[r][c];
                            }
                        }
                    }

                    if (thirdMax != LLONG_MIN)
                    {
                        currentSum += thirdMax;
                    }

                    maxSum = max(maxSum, currentSum);
                }
            }
        }

        return maxSum;
    }
};

int main()
{

    return 0;
}