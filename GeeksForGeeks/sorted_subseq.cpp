#include <bits/stdc++.h>
using namespace std;

// Function to find three numbers in the given array
// such that arr[smaller[i]] < arr[i] < arr[greater[i]]

class Solution
{
public:
    vector<int> find3Numbers(vector<int> &arr)
    {
        // Code here
        int smallest = arr[0];
        int preSmallest = smallest;
        int secSmallest = 1e9;
        int n = arr.size();

        for (int i = 1; i < n; i++)
        {
            if (arr[i] > secSmallest)
                return {preSmallest, secSmallest, arr[i]};
            else if (arr[i] < smallest)
            {
                smallest = arr[i];
            }
            else if (arr[i] < secSmallest && arr[i] > preSmallest)
            {
                secSmallest = arr[i];
            }
            else if (arr[i] > smallest)
            {
                preSmallest = smallest;
                secSmallest = arr[i];
            }
        }
        return {};
    }
};

int main()
{

    return 0;
}