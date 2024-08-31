#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool canSplit(vector<int> &arr)
    {
        // code here
        int n = arr.size();

        int sumfromLeft = 0, sumfromRight = 0;

        for (int i = 0; i < n; i++)
        {
            sumfromLeft += arr[i];
        }

        bool isEqual = false;

        for (int i = n - 1; i >= 0; i--)
        {
            sumfromLeft -= arr[i];
            sumfromRight += arr[i];

            if (sumfromLeft == sumfromRight)
            {
                isEqual = true;
                break;
            }
        }

        return isEqual;
    }
};

int main()
{

    return 0;
}