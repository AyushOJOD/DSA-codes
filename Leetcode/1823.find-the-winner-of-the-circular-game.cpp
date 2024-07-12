#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int solve(int n, int k)
    {
        if (n == 1)
        {
            return 0;
        }

        return ((solve(n - 1, k) + k) % n);
    }

public:
    int findTheWinner(int n, int k)
    {
        return solve(n, k) + 1;
    }
};

int main()
{

    return 0;
}