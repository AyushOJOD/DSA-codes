#include <bits/stdc++.h>
using namespace std;

bool printS(int idx, vector<int> &ds, int currSum, int sum, int arr[], int n)
{
    if (idx == n)
    {
        if (currSum == sum)
        {
            for (auto it : ds)
            {
                cout << it << " ";
                cout << endl;
            }
        }
        return false;
    }

    ds.push_back(arr[idx]);
    currSum += arr[idx];

    if (printS(idx + 1, ds, currSum, sum, arr, n))
    {
        return true;
    }

    s -= arr[idx];
    ds.pop_back();

    // not pick

    if (printS(idx + 1, ds, currSum, sum, arr, n))
    {
        return true;
    }

    return false;
}

int main()
{

    return 0;
}