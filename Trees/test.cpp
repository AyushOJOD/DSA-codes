#include <bits/stdc++.h>
using namespace std;

int missingNumber(vector<int> &array, int n)
{

    long long sum = 0;
    long long reqSum = n * (n + 1) / 2;

    for (long long i = 0; i < n; i++)
    {
        sum = sum + (i + 1 - array[i]);
    }

    return sum;
}

int main()
{

    vector<int> array = {1, 2, 3, 5};
    int n = 5;
    cout << missingNumber(array, n);

    return 0;
}