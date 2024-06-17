#include <bits/stdc++.h>
using namespace std;

long long countCompleteDayPairs(vector<int> &hours)
{
    unordered_map<int, long long> freq;
    long long count = 0;

    for (int hour : hours)
    {
        int remainder = hour % 24;
        int comp = (24 - remainder) % 24;

        if (freq.find(comp) != freq.end())
        {
            count += freq[comp];
        }

        freq[remainder]++;
    }

    return count;
}

int main()
{

    return 0;
}