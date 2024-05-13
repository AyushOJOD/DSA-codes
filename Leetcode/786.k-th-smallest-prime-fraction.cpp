#include <bits/stdc++.h>
using namespace std;

vector<int> kthSmallestPrimeFraction(vector<int> &arr, int k)
{
    int n = arr.size();

    vector<pair<int, int>> fractions;

    for (int i = 0; i < n; i++)
    {
        for (int j = i; j < n; j++)
        {
            fractions.push_back({arr[i], arr[j]});
        }
    }

    sort(fractions.begin(), fractions.end(), [](const pair<int, int> &a, const pair<int, int> &b)
         { return a.first * b.second < a.second * b.first; });

    return {fractions[k - 1].first, fractions[k - 1].second};
}

int main()
{

    return 0;
}