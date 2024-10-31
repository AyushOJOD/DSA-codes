#include <bits/stdc++.h>
using namespace std;

// x -> 1
// y -> -1

class Solution
{
public:
    int sameOccurrence(vector<int> &arr, int x, int y)
    {
        unordered_map<int, int> mp; //{sum->freq}
        int sum = 0;
        int ans = 0;

        mp[0] = 1;

        for (int i = 0; i < arr.size(); i++)
        {
            if (arr[i] == x)
            {
                sum++;
            }
            else if (arr[i] == y)
            {
                sum--;
            }

            if (mp.find(sum) != mp.end())
            {
                ans += mp[sum];
                mp[sum]++;
            }
            else
            {
                mp[sum] = 1;
            }
        }

        return ans;
    }
};

int main()
{

    return 0;
}