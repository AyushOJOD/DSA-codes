#include <bits/stdc++.h>
using namespace std;

int maximumElementAfterDecrementingAndRearranging(vector<int> &arr)
{
    if (arr.size() == 1)
    {
        return arr[0];
    }

    sort(arr.begin(), arr.end());

    int curr = 0;
    int penult = 0;

    arr[0] = 1;

    for (int i = 1; i < arr.size(); i++)
    {

        curr = arr[i];
        penult = arr[i - 1];

        if (curr == penult)
        {
            continue;
        }
        else
        {
            arr[i] = penult + 1;
        }
    }
    return arr[arr.size() - 1];
}

int main()
{

    return 0;
}