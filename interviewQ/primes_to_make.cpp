#include <bits/stdc++.h>
using namespace std;

// N: number to e formed
// M: first M primes used

vector<int> findPrimes(int m)
{
    vector<int> primes;
    int num = 2;

    while (primes.size() < m)
    {
        bool isPrime = true;

        for (int i = 2; i <= sqrt(num); i++)
        {
            if (num % i == 0)
            {
                isPrime = false;
                break;
            }
        }

        if (isPrime)
        {
            primes.push_back(num);
        }

        num++;
    }

    return primes;
}

int helper(int target, vector<int> &primes, int idx)
{
    // Base case
    if (idx == primes.size())
    {
        return
    }

    if (target == 0)
    {
        return 0;
    }

    // Recursion

    int notTake = helper(target, primes, idx + 1);

    int take = INT_MAX;

    while (target > primes[idx])
    {
        take = helper(target - primes[idx], primes, idx);
    }

    return min(take, notTake);
}

int solve(int N, int M)
{
    vector<int> primes = findPrimes(M);
}

int main()
{

    return 0;
}