#include <bits/stdc++.h>
using namespace std;

bool isPrime(int n)
{
    if (n <= 1)
        return false;
    if (n <= 3)
        return true;
    if (n % 2 == 0 || n % 3 == 0)
        return false;

    for (int i = 5; i * i < n; i += 6)
    {
        if (n % i == 0 || n % (i + 2) == 0)
        {
            return false;
        }
    }

    return true;
}

vector<int> getPrimes(int n)
{
    vector<int> primes;
    int num = 2;

    while (primes.size() < n)
    {
        if (isPrime(num))
        {
            primes.push_back(num);
        }
        num++;
    }

    return primes;
}

int helper(vector<int> &primes, int idx, int target, vector<vector<int>> &dp)
{
    // base case
    if (idx == 0)
    {
        if (target % primes[idx] == 0)
        {
            return target / primes[idx];
        }
        else
        {
            return INT_MAX - 1;
        }
    }

    if (dp[idx][target] != -1)
    {
        return dp[idx][target];
    }

    int notPick = helper(primes, idx - 1, target, dp);

    int pick = INT_MAX;

    if (target >= primes[idx])
    {
        pick = helper(primes, idx, target - primes[idx], dp) + 1;
    }

    return dp[idx][target] = min(pick, notPick);
}

int solve(int n, int m)
{
    vector<int> primes = getPrimes(m);

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));

    return helper(primes, m - 1, n, dp);
}

int main()
{

    int n = 10, m = 1;

    cout << solve(n, m);

    return 0;
}