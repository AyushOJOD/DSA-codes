#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int findLengthOfShortestSubarray(std::vector<int> &arr)
    {
        int n = arr.size();

        int i = 0, j = n - 1;

        while (j > 0 && arr[j] >= arr[j - 1])
        {
            j--;
        }

        if (j == 0)
            return 0;

        int ans = j;

        while (i < j && (i == 0 || arr[i] >= arr[i - 1]))
        {
            while (j < n && arr[j] < arr[i])
            {
                j++;
            }
            ans = min(ans, j - i - 1);
            i++;
        }

        return ans;
    }
};

int main()
{

    return 0;
}