#include <bits/stdc++.h>
using namespace std;

// Memoization

// int f(int idx, vector<int> &heights, vector<int> &dp)
// {
//     if (idx == 0)
//         return 0;

//     if (dp[idx] != -1)
//     {
//         return dp[idx];
//     }

//     int left = f(idx - 1, heights, dp) + abs(heights[idx] - heights[idx - 1]);
//     int right = INT_MAX;

//     if (idx > 1)
//     {
//         right = f(idx - 2, heights, dp) + abs(heights[idx] - heights[idx - 2]);
//     }

//     return dp[idx] = min(left, right);
// }

int frogJump(int n, vector<int> &heights)
{

    int prev = 0;
    int prev2 = 0;

    for (int i = 1; i < n; i++)
    {
        int left = prev + abs(heights[i] - heights[i - 1]);
        int right = INT_MAX;

        if (i > 1)
        {
            right = prev2 + abs(heights[i] - heights[i - 2]);
        }

        curr = min(left, right);
        prev2 = prev;
        prev = curr;
    }

    return prev;

    // return f(n - 1, heights, dp); // n-1 because we are using 0 based indexing
}

int main()
{

    return 0;
}