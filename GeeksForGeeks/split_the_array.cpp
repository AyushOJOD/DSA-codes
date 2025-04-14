#include <bits/stdc++.h>
using namespace std;

class Solution
{
private:
    int helper(vector<int> &arr, int xor1, int xor2, int idx)
    {
        if (idx >= arr.size())
        {
            return (xor1 == xor2);
        }

        int take1 = helper(arr, xor1 ^ arr[idx], xor2, idx + 1);
        int take2 = helper(arr, xor1, xor2 ^ arr[idx], idx + 1);

        return take1 + take2;
    }

public:
    int countgroup(vector<int> &arr)
    {
        return helper(arr, 0, 0, 0);
    }
};

int main()
{

    return 0;
}