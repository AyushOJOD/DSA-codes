#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    long long maximumImportance(int n, vector<vector<int>> &roads)
    {
        vector<long long> degree(n, 0);

        for (auto it : roads)
        {
            degree[it[0]]++;
            degree[it[1]]++;
        }

        sort(degree.begin(), degree.end());

        long long sum = 0;

        for (int i = 0; i < n; i++)
        {
            sum += (degree[i] * (i + 1));
        }

        return sum;
    }
};

int main()
{

    return 0;
}