#include <bits/stdc++.h>
using namespace std;

int maxSatisfied(vector<int> &customers, vector<int> &grumpy, int minutes)
{
    int n = customers.size();

    int currProfit = 0;
    for (int i = 0; i < n; i++)
    {
        currProfit += customers[i] * (1 - grumpy[i]);
    }

    int maxExtra = 0;
    for (int i = 0; i < minutes; i++)
    {
        maxExtra += customers[i] * grumpy[i];
    }

    int extra = maxExtra;
    for (int i = minutes; i < n; i++)
    {
        extra += customers[i] * grumpy[i] - customers[i - minutes] * grumpy[i - minutes];
        maxExtra = max(maxExtra, extra);
    }

    return currProfit + maxExtra;
}

int main()
{

    return 0;
}