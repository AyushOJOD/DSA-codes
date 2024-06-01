#include <bits/stdc++.h>
using namespace std;

int func(int arr[], int n, int sum, int currSum, int cnt, int idx)
{

    if (currSum == sum)
    {
        return 1;
    }

    for (int i = idx; i < n; i++)
    {
        currSum += arr[i];

        cnt += func(arr, n, sum, currSum, cnt, i + 1);

        currSum -= arr[i];
    }

    return cnt % 100000007;
}

int perfectSum(int arr[], int n, int sum)
{
    // Your code goes here
    return func(arr, n, sum, 0, 0, 0);
}

int main()
{

    return 0;
}