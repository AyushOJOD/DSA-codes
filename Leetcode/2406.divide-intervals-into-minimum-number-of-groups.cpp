#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    int minGroups(vector<vector<int>> &intervals)
    {
        vector<int> start_time, end_time;

        for (int i = 0; i < intervals.size(); i++)
        {
            start_time.push_back(intervals[i][0]);
            end_time.push_back(intervals[i][1]);
        }

        sort(begin(start_time), end(start_time));
        sort(begin(end_time), end(end_time));

        int idx = 0, count = 0;

        for (int i : start_time)
        {
            if (i > end_time[idx])
            {
                idx++;
            }
            else
            {
                count++;
            }
        }

        return count;
    }
};

int main()
{

    return 0;
}