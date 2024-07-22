#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    // Function to find the minimum number of platforms required at the
    // railway station such that no train waits.
    int findPlatform(int arr[], int dep[], int n)
    {
        // Your code here
        vector<pair<int, char>> plateform;

        for (int i = 0; i < n; i++)
        {
            plateform.push_back({arr[i], 'A'});
            plateform.push_back({dep[i], 'D'});
        }

        sort(plateform.begin(), plateform.end());

        int cnt = 0, maxVal = INT_MIN;

        for (auto it : plateform)
        {
            char work = it.second;

            if (work == 'A')
            {
                cnt++;
                maxVal = max(maxVal, cnt);
            }
            else
            {
                cnt--;
            }
        }

        return maxVal;
    }
};

int main()
{

    return 0;
}