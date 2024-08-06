#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(vector<vector<int>> &books, int idx, int shelfWidth, int currentHeight, int remainingWidth, vector<vector<int>> &dp)
    {
        if (idx >= books.size())
        {
            return currentHeight;
        }

        if (dp[idx][remainingWidth] != -1)
        {
            return dp[idx][remainingWidth];
        }

        int bookW = books[idx][0];
        int bookH = books[idx][1];

        int keep = INT_MAX;
        if (remainingWidth >= bookW)
        {
            keep = solve(books, idx + 1, shelfWidth, max(currentHeight, bookH), remainingWidth - bookW, dp);
        }

        int skip = currentHeight + solve(books, idx + 1, shelfWidth, bookH, shelfWidth - bookW, dp);

        return dp[idx][remainingWidth] = min(keep, skip);
    }

public:
    int minHeightShelves(vector<vector<int>> &books, int shelfWidth)
    {
        int n = books.size();

        vector<vector<int>> dp(n + 1, vector<int>(shelfWidth + 1, -1));

        return solve(books, 0, shelfWidth, 0, shelfWidth, dp);
    }
};

int main()
{

    return 0;
}