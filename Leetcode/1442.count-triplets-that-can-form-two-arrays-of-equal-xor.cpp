#include <bits/stdc++.h>
using namespace std;

int countTriplets(vector<int> &arr)
{
    int n = arr.size();
    int cnt = 0;

    for (int i = 0; i < n; i++)
    {
        int val = arr[i];

        for (int j = i + 1; j < n; j++)
        {
            val ^= arr[j];
            if (val == 0)
            {
                res += (j - i);
            }
        }
    }
    return res;
}

int main()
{

    return 0;
}