#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    vector<int> SieveOfEratosthenes(int n)
    {
        bool prime[n + 1];
        memset(prime, true, sizeof(prime));
        vector<int> primes;

        for (int p = 2; p * p <= n; p++)
        {
            if (prime[p] == true)
            {
                for (int i = p * p; i <= n; i += p)
                    prime[i] = false;
            }
        }

        for (int p = 2; p <= n; p++)
            if (prime[p])
                primes.push_back(prime[p]);

        return primes;
    }

public:
    bool primeSubOperation(vector<int> &nums)
    {
    }
};

int main()
{

    return 0;
}