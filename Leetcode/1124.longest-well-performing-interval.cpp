#include <bits/stdc++.h>
using namespace std;

// 9 9 6 0 6 6 9

class Solution
{
public:
    int longestWPI(vector<int> &hours)
    {
        int n = hours.size();

        for (int i = 0; i < n; i++)
        {
            if (hours[i] > 8)
            {
                hours[i] = 1;
            }
            else
            {
                hours[i] = -1;
            }
        }

        unordered_map<int, int> prefix_map;
        int curr_sum = 0, max_len = 0;

        for (int i = 0; i < n; i++)
        {
            curr_sum += hours[i];

            if (curr_sum > 0)
            {
                max_len = i + 1;
            }
            else
            {
                if (prefix_map.find(curr_sum - 1) != prefix_map.end())
                {
                    max_len = max(max_len, (i - prefix_map[curr_sum - 1]));
                }
                if (prefix_map.find(curr_sum) == prefix_map.end())
                {
                    prefix_map[curr_sum] = i;
                }
            }
        }

        return max_len;
    }
};

int main()
{

    return 0;
}