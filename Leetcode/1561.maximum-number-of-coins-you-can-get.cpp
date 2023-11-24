#include <bits/stdc++.h>
using namespace std;

int maxCoins(vector<int> &piles)
{
    sort(piles.begin(), piles.end());

    int n = piles.size();
    int leave = n / 3;
    int count = 0;

    for (int i = n - 2; i >= leave; i = i - 2)
    {
        count += i;
    }

    return count;
}

int main()
{

    return 0;
}