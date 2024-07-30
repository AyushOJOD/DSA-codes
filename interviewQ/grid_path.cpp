#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

const int MOD = 1e9 + 7;
const int MAXN = 100005;

int memo[MAXN][2];
vector<vector<int>> a;
int N;

int maxPathSum(int i, int j)
{
    // Base case: if we are at the last row, return the value of the current cell
    if (i == N - 1)
    {
        return a[i][j];
    }

    // If this state has been computed, return the cached value
    if (memo[i][j] != -1)
    {
        return memo[i][j];
    }

    long long maxNext = 0;
    // Explore both cells in the next row
    for (int k = 0; k < 2; ++k)
    {
        if (a[i + 1][k] > a[i][j])
        {
            maxNext = max(maxNext, static_cast<long long>(maxPathSum(i + 1, k)));
        }
    }

    // Store the computed value in the memoization table
    return memo[i][j] = (a[i][j] + maxNext) % MOD;
}

int main()
{
    cin >> N;
    a.resize(N, vector<int>(2));
    for (int i = 0; i < N; ++i)
    {
        cin >> a[i][0] >> a[i][1];
    }

    // Initialize memoization table with -1 (indicating uncomputed states)
    memset(memo, -1, sizeof(memo));

    // Compute the result starting from both possible cells in the first row
    int result = max(maxPathSum(0, 0), maxPathSum(0, 1));

    cout << result << endl;

    return 0;
}
