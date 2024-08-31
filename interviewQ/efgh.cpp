#include <bits/stdc++.h>
using namespace std;

int solve(int i, int x, int y, int z, vector<int> &a, int n, vector<vector<vector<vector<int>>>> &dp)
{
    if (i >= n && x == 0 && y == 0 && z == 0)
        return 0;
    if (i >= n)
        return 1e9;
    if (dp[i][x][y][z] != -1)
        return dp[i][x][y][z];

    int f = 1e9, s = 1e9, t = 1e9;
    if (x > 0)
    {
        f = a[i] + solve(i + 1, x - 1, y, z, a, n, dp);
    }
    if (y > 0 && n - i >= 2)
    {
        s = a[i] + a[i + 1] + solve(i + 2, x, y - 1, z, a, n, dp);
    }
    if (z > 0 && n - i >= 3)
    {
        t = a[i] + a[i + 1] + a[i + 2] + solve(i + 3, x, y, z - 1, a, n, dp);
    }
    int op = solve(i + 1, x, y, z, a, n, dp);

    return dp[i][x][y][z] = min({f, s, t, op});
}

int solution(vector<int> arr, int p, int q, int r)
{
    int n = arr.size();
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        sum += arr[i];
    }

    vector<vector<vector<vector<int>>>> dp(n + 1,
                                           vector<vector<vector<int>>>(p + 1,
                                                                       vector<vector<int>>(q + 1, vector<int>(r + 1, -1))));

    int ans = solve(0, p, q, r, arr, n, dp);
    return sum - ans;
}

int main()
{

    vector<int> v = {3, 1, 0, 5, 1, 6, 5, -1, -100};
    int p

        return 0;
}