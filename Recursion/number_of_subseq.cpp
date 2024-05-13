#include <bits/stdc++.h>
using namespace std;

int printS(int idx, int currS, int sum, int arr[], int n)
{
    if (idx == n)
    {
        if (currS == sum)
        {
            return 1; // one answer is found
        }
        return 0;
    }

    currS += arr[idx];

    int l = printS(idx + 1, currS, sum, arr, n); // number of possible answer

    currS -= arr[idx];

    int r = printS(idx + 1, currS, sum, arr, n); // number of possible answer

    return l + r; // total number of possible answer
}

int main()
{

    return 0;
}